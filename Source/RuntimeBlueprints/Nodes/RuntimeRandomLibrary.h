// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "FunctionLibraries/RandomBPLibrary.h"
#include "RuntimeRandomLibrary.generated.h"


/**
* Generates a set of points around a sphere
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDistributePointsAroundSphere : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDistributePointsAroundSphere();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};