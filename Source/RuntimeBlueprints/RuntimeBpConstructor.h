// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"

#include "Private/Windows/WindowsRunnableThread.h"
#include "HAL/ThreadSafeBool.h"
#include "Containers/Queue.h"
#include "Async.h"

#include "JsonSaveGame.h"
#include "RuntimeBpData.h"
#include "RuntimeBpObject.h"
#include "RuntimeBlueprints.h"
#include "RuntimeBpConstructor.generated.h"

class URuntimeBpJsonLibrary;

struct FNodeExecuteInstruction
{
	URuntimeBpConstructor* Constructor;

	int Node;

	int Execute;

	int FromLoop;

	int Function;

	FNodeExecuteInstruction()
	{}

	FNodeExecuteInstruction(URuntimeBpConstructor* RuntimeBPConstructor, int NodeIndex, int ExecuteIndex, int FromLoopIndex, int FunctionIndex) :
		Constructor(RuntimeBPConstructor),
		Node(NodeIndex),
		Execute(ExecuteIndex),
		FromLoop(FromLoopIndex),
		Function(FunctionIndex)
	{}

};

// Multi Threading
class FMultiThreadScript : public FRunnable
{
	friend class TAsyncRunnable<void*>;
public:

	// Thread to run the worker FRunnable on
	FRunnableThread* Thread;

	// Sync event 
	FEvent* SyncEvent;

	// Stop this thread? Uses Thread Safe Counter
	FThreadSafeCounter StopTaskCounter;

	// The RuntimeBp Constructor
	URuntimeBpConstructor* ScriptConstructor;

	// Mutex to make sure that when the thread continues where it left off won't be overloaded with requests to do so
	FCriticalSection Mutex;

	// Pause
	FThreadSafeBool Paused;

	// Kill
	FThreadSafeBool Kill;

	// Whether this is the thread's first run
	FThreadSafeBool FirstRun;

	// Whether this is the thread's first run
	FThreadSafeBool ContinueExec;

	// Which Node to call when Run is called
	uint32 Node = -1;

	// Which Execute function to call when Run is called
	uint32 Execute = -1;

	// The node index of the loop this node is called from, if applicable
	uint32 FromLoop = -1;

	// The function index of the node this was called from
	uint32 Function = -1;

	TQueue<FNodeExecuteInstruction> ExecuteQueue;

	// Thread Core Functions

	// Constructor / Destructor
	FMultiThreadScript(URuntimeBpConstructor* Script, const FString& ThreadName);
	virtual ~FMultiThreadScript();

	// Begin FRunnable interface.
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	uint32 ContinueExecute(URuntimeBpConstructor* RuntimeBPConstructor, uint32 NodeIndex, uint32 ExecuteIndex, uint32 FromLoopIndex, uint32 FunctionIndex);

	/** Makes sure this thread has stopped properly */
	void EnsureCompletion();

	//~~~ Starting and Stopping Thread ~~~

	/*
		Start the thread and the worker from static (easy access)!
		This code ensures only 1 Prime Number thread will be able to run at a time.
		This function returns a handle to the newly started instance.
	*/
	static FMultiThreadScript* ScriptInit(URuntimeBpConstructor* Script, const FString& ThreadName);

	/** Shuts down the thread. Static so it can easily be called from outside the thread context */
	void Shutdown();

	bool IsThreadFinished();

};

USTRUCT()
struct FArrayOfNodes
{
	GENERATED_BODY()

	UPROPERTY()
	URuntimeBpObject* FunctionCaller = nullptr;

	UPROPERTY()
	TArray<URuntimeBpObject*> Nodes = TArray<URuntimeBpObject*>();
};

USTRUCT()
struct FArrayOfVariables
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FSaveableVariable> Variables;

	FArrayOfVariables()
	{}

	FArrayOfVariables(TArray<FSaveableVariable>& ArrayOfVariables)
	{
		Variables = ArrayOfVariables;
	}
};

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class RUNTIMEBLUEPRINTS_API URuntimeBpConstructor : public UActorComponent
{

	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly)
	bool EnableMultithread;

public:

	// The script thread
	static FMultiThreadScript* Thread;

	static TMap<FString, FRuntimeBpJsonFormat> LoadedScripts;

	static FString LocalScriptPath;

	// The filename of the json script
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Nodes", Keywords = "Constructor class Json File"))
	FString JsonFile;

	// All BP Nodes
	UPROPERTY()
	TArray<URuntimeBpObject*> BPNodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Nodes", Keywords = "Node Structs"))
	TArray<FNodeStruct> NodeStructs;

	// All Variables, these are still used during runtime and thus should not be cleared!
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Nodes", Keywords = "Node Variables"))
	TArray<FSaveableVariable> Variables;

	// In case a variable needs to be gotten by ref but the variable requested is invalid, we return this empty null variable
	FSaveableVariable NullVariable;

	// All custom functions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Nodes", Keywords = "Node Functions"))
	TArray<FRuntimeFunction> Functions;

	// Local variable default values for when a function is called and it needs to reset the local variables which may have been adjusted during the previous run of this function
	TArray<FArrayOfVariables> LocalVariableDefaults;

	// Array of scripts this script is referring to. The order of the array is important because the index is what is saved not the name of the script.
	TArray<FString> ScriptReferences;

	// Called when this script is supposed to be destroyed.
	bool Kill;

	// Nodes for each custom function
	UPROPERTY()
	TArray<FArrayOfNodes> FunctionNodes;

	// Spawn Actor function for the nodes because UObjects(which is what the nodes inherit from) can't spawn actors, so this can be called instead.
	AActor* SpawnActor(UClass* ActorToSpawn, FTransform const& Transform);

	FORCEINLINE bool GetMultiThread() const { return EnableMultithread; }

	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Values", Keywords = "Get Loaded Scripts"))
	static TMap<FString, FRuntimeBpJsonFormat>& GetLoadedScripts();

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values", Keywords = "Add Loaded Script"))
	static void RegisterLoadedScript(const FString& ScriptName, const FRuntimeBpJsonFormat& Script);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values", Keywords = "Add Loaded Script"))
	static void UnregisterLoadedScript(const FString& ScriptName);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values", Keywords = "Find loaded script"))
	static bool FindLoadedScript(const FString& ScriptName, FRuntimeBpJsonFormat& Script, bool LoadIfNotFound = true);
	
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Nodes", Keywords = "Init Script"))
	void InitScript(const FString& ScriptName, UPARAM(ref) TArray<FNodeStruct>& InNodes, UPARAM(ref) TArray<FSaveableVariable>& InVariables, UPARAM(ref) TArray<FRuntimeFunction>& InFunctions, UPARAM(ref)TArray<FString>& InReferences, bool Multithread = true);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Nodes", Keywords = "Init Script from Save"))
	void InitScriptFromSave(const FString& ScriptName, bool Multithread = true);

	void ContinueExecute(URuntimeBpConstructor* RuntimeBPConstructor, int NodeIndex, int ExecuteIndex, int FromLoopIndex, int FunctionIndex);

	void ConstructBPNodes(UPARAM(ref) TArray<FNodeStruct>& Nodes, bool Multithread);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Nodes", Keywords = "Clear Node Structs"))
	void ClearNodeStructs();

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Nodes", Keywords = "Clear Node Struct Array"))
	void ClearVariables();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	/*
	** Functions that the nodes can't call themselves because they're UObjects
	*/

	float GetWorldDeltaSeconds();

	/*
	** Functions called from actual code which triggers the runtime BPs
	*/

	// Begin play is not bound but rather it's manually called once all nodes are created. The Actor's Begin Play has likely already fired when this component is made.
	void CallOnBeginPlay();

	URuntimeBpObject* BeginPlayNode;

	UFUNCTION()
	void CallOnEndPlay(EEndPlayReason::Type EndPlayReason);

	// Same story for End Play, we use the Component's End Play rather than the Actor's
	UPROPERTY()
	URuntimeBpObject* EndPlayNode;

	UFUNCTION()
	void CallOnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* DamageInstigator, AActor* DamageCauser);

	UPROPERTY()
	URuntimeBpObject* TakeAnyDamageNode;

	UFUNCTION()
	void CallOnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY()
	URuntimeBpObject* ActorBeginOverlapNode;

	UFUNCTION()
	void CallOnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY()
	URuntimeBpObject* ActorEndOverlapNode;

	UFUNCTION()
	void CallOnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY()
	URuntimeBpObject* ActorHitNode;

};