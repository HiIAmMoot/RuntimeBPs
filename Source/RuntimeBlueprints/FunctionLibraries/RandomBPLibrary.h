// Copyright notice here..

#pragma once

#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include "RandomBPLibrary.generated.h"


UCLASS()
class RUNTIMEBLUEPRINTS_API URandomBPLibrary : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:

	/**
	* Generates a set of points around a sphere
	*/
	UFUNCTION(BlueprintCallable, Category = "Geometry")
	static TArray<FVector> DistributePointsAroundSphere(float SphereRadius, FVector SphereCenterLocation, int AmountOfPoints, bool Randomize);

};

