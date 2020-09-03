// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeBpConstructor.h"
#include "RuntimeBpLibrary.h"
#include "RuntimeBpJsonLibrary.h"
#include "Nodes/CustomNodes.h"

FMultiThreadScript* URuntimeBpConstructor::Thread = nullptr;
TMap<FString, FRuntimeBpJsonFormat> URuntimeBpConstructor::LoadedScripts = TMap<FString, FRuntimeBpJsonFormat>();

//***********************************************************
// Thread Worker Starts as NULL, prior to being instanced
//		This line is essential! Compiler error without it
//***********************************************************

FMultiThreadScript::FMultiThreadScript(URuntimeBpConstructor* Script, const FString& ThreadName)
	: ScriptConstructor(Script)
{
	Paused = false;
	FirstRun = false;

	SyncEvent = FGenericPlatformProcess::GetSynchEventFromPool(false);
	Thread = FRunnableThread::Create(this, *ThreadName, 0, TPri_BelowNormal); // Windows default = 8mb for thread, could specify more
}

FMultiThreadScript::~FMultiThreadScript()
{
	delete Thread;
	Thread = NULL;
}

// Init
bool FMultiThreadScript::Init()
{
	// Init the Data
	return true;
}

// Run
uint32 FMultiThreadScript::Run()
{
	while (!Kill && !Paused)
	{
		if (!ExecuteQueue.IsEmpty())
		{
			FNodeExecuteInstruction NodeExec;

			if (ExecuteQueue.Dequeue(NodeExec) && NodeExec.Constructor)
			{
				if (NodeExec.Function < 0)
				{
					NodeExec.Constructor->BPNodes[NodeExec.Node]->Then(NodeExec.Execute, NodeExec.FromLoop);
				}
				else
				{
					NodeExec.Constructor->FunctionNodes[NodeExec.Function].Nodes[NodeExec.Node]->Then(NodeExec.Execute, NodeExec.FromLoop);
				}
			}
		}
	}

	return 0;
}

// Stop
void FMultiThreadScript::Stop()
{}

uint32 FMultiThreadScript::ContinueExecute(URuntimeBpConstructor* RuntimeBPConstructor, uint32 NodeIndex, uint32 ExecuteIndex, uint32 FromLoopIndex, uint32 FunctionIndex)//, TFunction<void()> Function)
{
	ExecuteQueue.Enqueue(FNodeExecuteInstruction(RuntimeBPConstructor, NodeIndex, ExecuteIndex, FromLoopIndex, FunctionIndex));

	return 0;
}

FMultiThreadScript* FMultiThreadScript::ScriptInit(URuntimeBpConstructor* Script, const FString& ThreadName)
{
	// Create new instance of thread if it does not exist
	// And if the platform supports multi threading!
	if (Script && !Script->Thread && FPlatformProcess::SupportsMultithreading())
	{
		return new FMultiThreadScript(Script, ThreadName);
	}
	return nullptr;
}

void FMultiThreadScript::EnsureCompletion()
{
	Kill = true;
	Stop();
	Thread->WaitForCompletion();
}

void FMultiThreadScript::Shutdown()
{
	if (ScriptConstructor && ScriptConstructor->Thread)
	{
		ScriptConstructor->Thread->EnsureCompletion();
		delete ScriptConstructor->Thread;
	}
}

bool FMultiThreadScript::IsThreadFinished()
{
	return !ScriptConstructor;
}

//***********************************************************
// The actual script constructor class
//***********************************************************
void URuntimeBpConstructor::InitScript(const FString& ScriptName, UPARAM(ref)TArray<FNodeStruct>& InNodes, UPARAM(ref)TArray<FSaveableVariable>& InVariables, UPARAM(ref)TArray<FRuntimeFunction>& InFunctions, bool Multithread)
{
	JsonFile = ScriptName;
	NodeStructs = InNodes;
	Variables = InVariables;
	Functions = InFunctions;

	ConstructBPNodes(NodeStructs, Multithread);

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &URuntimeBpConstructor::CallOnTakeAnyDamage);
	GetOwner()->OnActorBeginOverlap.AddDynamic(this, &URuntimeBpConstructor::CallOnActorBeginOverlap);
	GetOwner()->OnActorEndOverlap.AddDynamic(this, &URuntimeBpConstructor::CallOnActorEndOverlap);
	GetOwner()->OnActorHit.AddDynamic(this, &URuntimeBpConstructor::CallOnActorHit);
}

void URuntimeBpConstructor::InitScriptFromSave(const FString& ScriptName, bool Multithread)
{
	UJsonSaveGame* SaveGame = NewObject<UJsonSaveGame>(this);

	if (SaveGame)
	{
		if (SaveGame->LoadTextFile(ScriptName))
		{
			FRuntimeBpJsonFormat RuntimeBpJson;

			if (URuntimeBpJsonLibrary::JsonStringToScript(SaveGame->GetJsonString(), RuntimeBpJson, false))
			{
				InitScript(ScriptName, RuntimeBpJson.Nodes, RuntimeBpJson.Variables, RuntimeBpJson.Functions, Multithread);
			}
		}
	}
}

void URuntimeBpConstructor::ContinueExecute(URuntimeBpConstructor* RuntimeBPConstructor, int NodeIndex, int ExecuteIndex, int FromLoopIndex, int FunctionIndex)
{
	Thread->ContinueExecute(RuntimeBPConstructor, NodeIndex, ExecuteIndex, FromLoopIndex, FunctionIndex);
}

void URuntimeBpConstructor::ConstructBPNodes(UPARAM(ref) TArray<FNodeStruct>& Nodes, bool MultiThread = true)
{
	for (FNodeStruct& Node : Nodes)
	{
		TSubclassOf<URuntimeBpObject> NodeClass = Node.NodeClass;
		URuntimeBpObject* NodeComponent;

		if (NodeClass != nullptr)
		{
			NodeComponent = NewObject<URuntimeBpObject>(this, NodeClass);

			// Init Node and add to array
			NodeComponent->ConstructNode(this, Node.NodeIndex, Node.Name, Node.InputPins, Node.OutputPins);
			NodeComponent->ClearEditorValues();

		}
		BPNodes.Add(NodeComponent);
	}

	FunctionNodes.Reserve(Functions.Num());
	LocalVariableDefaults.Reserve(Functions.Num());
	int i = 0;
	for (FRuntimeFunction& Function : Functions)
	{
		FArrayOfNodes ArrayOfNodes;
		ArrayOfNodes.Nodes.Reserve(Function.Nodes.Num());

		for (FNodeStruct& NodeStruct : Function.Nodes)
		{
			TSubclassOf<URuntimeBpObject> NodeClass = NodeStruct.NodeClass;
			URuntimeBpObject* NodeComponent;

			if (NodeClass != nullptr)
			{
				NodeComponent = NewObject<URuntimeBpObject>(this, NodeClass);

				// Init Node and add to array
				NodeComponent->ConstructNode(this, NodeStruct.NodeIndex, NodeStruct.Name, NodeStruct.InputPins, NodeStruct.OutputPins);
				NodeComponent->FunctionIndex = i;
				NodeComponent->ClearEditorValues();

			}
			ArrayOfNodes.Nodes.Add(NodeComponent);
		}

		LocalVariableDefaults.Add(FArrayOfVariables(Function.LocalVariables));
		FunctionNodes.Add(ArrayOfNodes);
		i++;
	}

	EnableMultithread = MultiThread;
	if (EnableMultithread)
	{
		if (!Thread)
		{
			Thread = FMultiThreadScript::ScriptInit(this, GetReadableName());
		}

		// Call begin play once nodes are spawned
		if (BeginPlayNode)
		{
			Thread->ContinueExecute(this, BeginPlayNode->NodeIndex, 0, -1, BeginPlayNode->FunctionIndex);
		}
	}
	else
	{
		// Call begin play once nodes are spawned
		CallOnBeginPlay();
	}
}	

void URuntimeBpConstructor::ClearNodeStructs()
{
	NodeStructs.Empty();
}
void URuntimeBpConstructor::ClearVariables()
{
	Variables.Empty();
}
void URuntimeBpConstructor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	CallOnEndPlay(EndPlayReason);

	Kill = true;

	for (URuntimeBpObject* Node : BPNodes)
	{
		if (Node->IsValidLowLevel())
		{
			Node->ConditionalBeginDestroy();
		}
	}

	Super::EndPlay(EndPlayReason);
}
void URuntimeBpConstructor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	// We disable super tick, which allows for Blueprint tick because we're not gonna allow blueprint custom nodes, so this will save some performance
	// Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

AActor * URuntimeBpConstructor::SpawnActor(UClass* ActorToSpawn, FTransform const & Transform)
{
	if (ActorToSpawn != nullptr)
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.Owner = GetOwner();
		UWorld* World = GetWorld();
		AActor* Actor = nullptr;
		AsyncTask(ENamedThreads::GameThread, [&Actor, World, ActorToSpawn, Transform, SpawnParameters]()
		{
			Actor = World->UWorld::SpawnActorAbsolute(ActorToSpawn, Transform, SpawnParameters);
		});
	
		return Actor;
	}
	return nullptr;
}

TMap<FString, FRuntimeBpJsonFormat>& URuntimeBpConstructor::GetLoadedScripts()
{
	return LoadedScripts;
}

void URuntimeBpConstructor::RegisterLoadedScript(const FString & ScriptName, const FRuntimeBpJsonFormat & Script)
{
	LoadedScripts.Add(ScriptName, Script);
}

void URuntimeBpConstructor::UnregisterLoadedScript(const FString & ScriptName)
{
	LoadedScripts.Remove(ScriptName);
}

bool URuntimeBpConstructor::FindLoadedScriptEntry(const FString & ScriptName, FRuntimeBpJsonFormat & Script)
{
	auto FoundPair = LoadedScripts.Find(ScriptName);
	if (FoundPair)
	{
		Script = *FoundPair;
		return true;
	}

	Script = FRuntimeBpJsonFormat();
	return false;
}

float URuntimeBpConstructor::GetWorldDeltaSeconds()
{
	return UGameplayStatics::GetWorldDeltaSeconds(this);
}

void URuntimeBpConstructor::CallOnBeginPlay()
{
	// The multithread version of this call is done with the init of the thread
	if (BeginPlayNode)
	{
		BeginPlayNode->Execute(0);
	}
}

void URuntimeBpConstructor::CallOnEndPlay(EEndPlayReason::Type EndPlayReason)
{
	if (EndPlayNode)
	{
		// Set the parameters that are passed with this call
		EndPlayNode->OutputPins[1].Value.Array[0].SetByteArg(EndPlayReason);
		//EndPlayNode->OutputPins[1].Meta = "EEndPlayReason"; // Enum data

		if (EnableMultithread)
		{
			ContinueExecute(this, EndPlayNode->NodeIndex, 0, -1, EndPlayNode->FunctionIndex);
		}
		else
		{
			EndPlayNode->Execute(0);
		}
	}
}

void URuntimeBpConstructor::CallOnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* DamageInstigator, AActor* DamageCauser)
{
	if (TakeAnyDamageNode)
	{
		// Set the parameters that are passed with this call
		TakeAnyDamageNode->OutputPins[1].Value.Array[0].SetActorArg(DamagedActor);
		TakeAnyDamageNode->OutputPins[2].Value.Array[0].SetFloatArg(Damage);
		TakeAnyDamageNode->OutputPins[5].Value.Array[0].SetActorArg(DamageCauser);

		if (DamageInstigator)
		{
			APlayerController* PlayerController = Cast<APlayerController>(DamageInstigator);
			TakeAnyDamageNode->OutputPins[4].Value.Array[0].SetPlayerControllerArg(PlayerController);
		}

		if (DamageType)
		{
			UDamageType* LocalDamageType = const_cast<UDamageType*>(DamageType);
			if (LocalDamageType)
			{
				TakeAnyDamageNode->OutputPins[3].Value.Array[0].SetDamageTypeArg(LocalDamageType);
			}
		}

		if (EnableMultithread)
		{
			ContinueExecute(this, TakeAnyDamageNode->NodeIndex, 0, -1, TakeAnyDamageNode->FunctionIndex);
		}
		else
		{
			TakeAnyDamageNode->Execute(0);
		}
	}
}

void URuntimeBpConstructor::CallOnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ActorBeginOverlapNode->OutputPins[1].Value.Array[0].SetActorArg(OverlappedActor);
	ActorBeginOverlapNode->OutputPins[2].Value.Array[0].SetActorArg(OtherActor);

	if (EnableMultithread)
	{
		ContinueExecute(this, ActorBeginOverlapNode->NodeIndex, 0, -1, ActorBeginOverlapNode->FunctionIndex);
	}
	else
	{
		ActorBeginOverlapNode->Execute(0);
	}
}

void URuntimeBpConstructor::CallOnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ActorEndOverlapNode->OutputPins[1].Value.Array[0].SetActorArg(OverlappedActor);
	ActorEndOverlapNode->OutputPins[2].Value.Array[0].SetActorArg(OtherActor);

	if (EnableMultithread)
	{
		ContinueExecute(this, ActorEndOverlapNode->NodeIndex, 0, -1, ActorEndOverlapNode->FunctionIndex);
	}
	else
	{
		ActorEndOverlapNode->Execute(0);
	}
}

void URuntimeBpConstructor::CallOnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	ActorHitNode->OutputPins[1].Value.Array[0].SetActorArg(SelfActor);
	ActorHitNode->OutputPins[2].Value.Array[0].SetActorArg(OtherActor);
	ActorHitNode->OutputPins[3].Value.Array[0].SetVectorArg(NormalImpulse);
	ActorHitNode->OutputPins[4].Value.Array[0].SetHitResultArg(Hit);

	if (EnableMultithread)
	{
		ContinueExecute(this, ActorHitNode->NodeIndex, 0, -1, ActorHitNode->FunctionIndex);
	}
	else
	{
		ActorHitNode->Execute(0);
	}
}