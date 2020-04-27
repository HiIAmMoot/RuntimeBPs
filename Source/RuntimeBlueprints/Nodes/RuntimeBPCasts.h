// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "RuntimeBpCasts.generated.h"

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToActor();
	
	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToPlayerController : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToPlayerController();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToCharacter : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToCharacter();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToSceneComponent : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToSceneComponent();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToStaticMeshComponent : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToStaticMeshComponent();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToLightComponent : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToLightComponent();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToParticleSystemComponent : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToParticleSystemComponent();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};

UCLASS()
class RUNTIMEBLUEPRINTS_API UCastObjectToGrenade : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCastObjectToGrenade();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;
};