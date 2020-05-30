// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "RuntimeBpLibrary.h"
#include "GrenadeScript.h"
#include "GrenadeScriptNodes.generated.h"

UCLASS()
class RUNTIMEBPEXAMPLE_API UGrenadeExplode : public URuntimeBpEventNode
{
	GENERATED_BODY()

public:

	UGrenadeExplode();

protected:
	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

};