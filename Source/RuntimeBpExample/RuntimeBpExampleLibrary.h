// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RuntimeBpGrenade.h"
#include "RuntimeBlueprints/RuntimeBpData.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RuntimeBpExampleLibrary.generated.h"

UCLASS()
class RUNTIMEBPEXAMPLE_API URuntimeBpExampleLibrary : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:


	// Gets the variable in the form of an ARuntimeBpGrenade
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Grenade"))
	static TArray<ARuntimeBpGrenade*> GetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an ARuntimeBpGrenade
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Grenade"))
	static void SetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ARuntimeBpGrenade*> Value);

};