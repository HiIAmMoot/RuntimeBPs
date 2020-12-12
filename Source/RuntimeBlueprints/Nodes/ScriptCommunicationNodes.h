// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "RuntimeBpLibrary.h"
#include "ScriptCommunicationNodes.generated.h"

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

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetScriptOwner : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetScriptOwner();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UCallFunctionFromScript : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCallFunctionFromScript();

	URuntimeBpConstructor* Constructor;

	// Used to wait when creating a constructor if one's not available
	FThreadSafeBool Continue;

	// We manually store the FromLoopIndex before a function call because it's lost when a function is called. This is used in the overridden Then function
	int StoredFromLoopIndex;

	virtual void UpdateCustomOutput(URuntimeBpObject* CalledFrom, TArray<FPinStruct>& Pins, int StartIndex = 1) override;

	virtual void ResetCustomOutput(int StartIndex = 2) override;

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

	virtual void Then(int Index, int FromLoopIndex) override;
};