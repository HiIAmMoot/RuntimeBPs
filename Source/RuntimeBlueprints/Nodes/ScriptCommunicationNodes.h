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

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};