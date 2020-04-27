// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeBpCasts.h"
#include "RuntimeBpMacros.h"
#include "Kismet/KismetStringLibrary.h"
#include "RuntimeBpConstructor.h"

#include "RuntimeBpGrenade.h"

UCastObjectToActor::UCastObjectToActor()
{
	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, Actor)
}

void UCastObjectToActor::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, AActor, Actor)
}

UCastObjectToPlayerController::UCastObjectToPlayerController()
{
	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, PlayerController)
}

void UCastObjectToPlayerController::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, APlayerController, PlayerController)
}

UCastObjectToCharacter::UCastObjectToCharacter()
{

	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, Character)
}

void UCastObjectToCharacter::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, ACharacter, Character)
}

UCastObjectToSceneComponent::UCastObjectToSceneComponent()
{
	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, SceneComponent)
}

void UCastObjectToSceneComponent::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, USceneComponent, SceneComponent)
}

UCastObjectToStaticMeshComponent::UCastObjectToStaticMeshComponent()
{
	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, StaticMeshComponent)
}

void UCastObjectToStaticMeshComponent::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, UStaticMeshComponent, StaticMeshComponent)
}

UCastObjectToLightComponent::UCastObjectToLightComponent()
{
	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, LightComponent)
}

void UCastObjectToLightComponent::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, ULightComponent, LightComponent)
}

UCastObjectToParticleSystemComponent::UCastObjectToParticleSystemComponent()
{
	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, ParticleSystemComponent)
}

void UCastObjectToParticleSystemComponent::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, UParticleSystemComponent, ParticleSystemComponent)
}

UCastObjectToGrenade::UCastObjectToGrenade()
{
	RUNTIME_BP_CAST_CONSTRUCTOR(UObject, Object, Grenade)
}

void UCastObjectToGrenade::Execute(int Index, int FromLoopIndex)
{
	RUNTIME_BP_CAST_EXECUTE(Object, ARuntimeBpGrenade, Grenade)
}