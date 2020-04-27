// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Components/MeshComponent.h"
#include "RuntimeMeshComponentLibrary.generated.h"



UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetMaterials : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetMaterials();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetMaterialIndex : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetMaterialIndex();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetMaterialSlotNames : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetMaterialSlotNames();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_IsMaterialSlotNameValid : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_IsMaterialSlotNameValid();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};