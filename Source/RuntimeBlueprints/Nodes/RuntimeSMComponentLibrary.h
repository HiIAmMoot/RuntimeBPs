// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Components/StaticMeshComponent.h"
#include "RuntimeSMComponentLibrary.generated.h"


/** Change the StaticMesh used by this instance. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetStaticMesh : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetStaticMesh();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get Local bounds
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetLocalBounds : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetLocalBounds();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};