// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "RuntimeBpLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Async.h"
#include "Async/ParallelFor.h"
#include "ExampleNodes.generated.h"

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBeginPlay : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBeginPlay();

protected:
	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

};


/**
 * 
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPrint : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPrint();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
	
};

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBranch : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBranch();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

UCLASS()
class RUNTIMEBLUEPRINTS_API UForLoop : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UForLoop();

	int CurrentLoopIndex;

	int LastIndex;

	int ReceivedFromLoopIndex;

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

	virtual void Next() override;
	
};

UCLASS()
class RUNTIMEBLUEPRINTS_API USpawn : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	// This variable is set once the actor is spawned. Reason why it needs to be a variable here and not a local variable in the function is because of multithreading
	// Spawning can only happen in the gamethread, and if this node is called from an async thread then it needs to make sure the actor is spawned in the gamethread
	// While making sure the actor reference is returned properly so it can be accessed by the async thread.
	AActor* SpawnedActor;

	USpawn();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UStartTimer : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FTimerHandle TimerHandle;

	UStartTimer();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

	UFUNCTION()
	void Heartbeat();

	UFUNCTION()
	void HeartbeatAsync();

};

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFlipFlop : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	bool IsA;

	UFlipFlop();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

	virtual void ResetInternalFunctionValues() override;

};

UCLASS()
class RUNTIMEBLUEPRINTS_API USequence : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	int CurrentLoopIndex;

	int LastIndex;

	int ReceivedFromLoopIndex;

	USequence();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

	virtual void Next() override;

};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetAllActorsOfClass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	TArray<AActor*> OutActors;

	UGetAllActorsOfClass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActorHasScript : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActorHasScript();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};