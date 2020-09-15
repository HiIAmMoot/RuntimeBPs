// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBlueprints/RuntimeBpConstructor.h"
#include "GrenadeScript.generated.h"

class ARuntimeBpGrenade;

/**
 * 
 */
UCLASS()
class RUNTIMEBPEXAMPLE_API UGrenadeScript : public URuntimeBpConstructor
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void CallGrenadeExplosion(ARuntimeBpGrenade* Self, APawn* Instigator, const FTransform ExplosionTransform);

	URuntimeBpObject* GrenadeExplosionNode;
	
};