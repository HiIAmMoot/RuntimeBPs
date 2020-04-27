// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeBpConstructor.h"
#include "RuntimeBpLibrary.h"
#include "RuntimeBpJsonLibrary.h"
#include "Nodes/CustomNodes.h"

FMultiThreadScript* URuntimeBpConstructor::Thread = nullptr;

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
void URuntimeBpConstructor::InitScript(UPARAM(ref)TArray<FNodeStruct>& InNodes, UPARAM(ref)TArray<FSaveableVariable>& InVariables, UPARAM(ref)TArray<FRuntimeFunction>& InFunctions, bool Multithread)
{
	NodeStructs = InNodes;
	Variables = InVariables;
	Functions = InFunctions;

	ConstructBPNodes(NodeStructs, Multithread);
}

void URuntimeBpConstructor::InitScript(const FString& ScriptName, bool Multithread)
{
	UJsonSaveGame* SaveGame = NewObject<UJsonSaveGame>(this);

	if (SaveGame)
	{
		if (SaveGame->LoadTextFile(ScriptName))
		{
			FRuntimeBpJsonFormat RuntimeBpJson;

			if (URuntimeBpJsonLibrary::JsonStringToScript(SaveGame->GetJsonString(), RuntimeBpJson))
			{
				NodeStructs = RuntimeBpJson.Nodes;
				Variables = RuntimeBpJson.Variables;
				Functions = RuntimeBpJson.Functions;
				ConstructBPNodes(NodeStructs, Multithread);
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
		CallBeginPlay();
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

float URuntimeBpConstructor::GetWorldDeltaSeconds()
{
	return UGameplayStatics::GetWorldDeltaSeconds(this);
}

void URuntimeBpConstructor::CallBeginPlay()
{ 
	if (BeginPlayNode != nullptr)
	{
		BeginPlayNode->Execute(0);
	}
}

void URuntimeBpConstructor::CallEndPlay()
{
	if (EndPlayNode != nullptr)
	{
		EndPlayNode->Execute(0);
	}
}

void URuntimeBpConstructor::CallTick(float DeltaSeconds)
{

}

void URuntimeBpConstructor::CallOnActorBeginOverlap(AActor * OtherActor)
{

}

void URuntimeBpConstructor::CallOnActorEndOverlap(AActor * OtherActor)
{
}

void URuntimeBpConstructor::CallOnComponentBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

}

void URuntimeBpConstructor::CallOnComponentEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int OtherBodyIndex)
{

}

void URuntimeBpConstructor::CallOnEventHit(UPrimitiveComponent * MyComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, bool SelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult & Hit)
{
}

void URuntimeBpConstructor::CallOnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{

}

void URuntimeBpConstructor::CallOnComponentWake(UPrimitiveComponent * WakingComponent, FName BoneName)
{

}

void URuntimeBpConstructor::CallOnComponentSleep(UPrimitiveComponent * SleepingComponent, FName BoneName)
{

}