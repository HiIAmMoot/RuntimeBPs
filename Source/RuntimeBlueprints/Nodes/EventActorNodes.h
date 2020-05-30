// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "EventActorNodes.generated.h"

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UEndPlay : public URuntimeBpEventNode
{
	GENERATED_BODY()

public:

	UEndPlay();

protected:
	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

};

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UOnTakeAnyDamage : public URuntimeBpEventNode
{
	GENERATED_BODY()

public:

	UOnTakeAnyDamage();

protected:
	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

};

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UOnActorBeginOverlap : public URuntimeBpEventNode
{
	GENERATED_BODY()

public:

	UOnActorBeginOverlap();

protected:
	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

};

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UOnActorEndOverlap : public URuntimeBpEventNode
{
	GENERATED_BODY()

public:

	UOnActorEndOverlap();

protected:
	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

};

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UOnActorHit : public URuntimeBpEventNode
{
	GENERATED_BODY()

public:

	UOnActorHit();

protected:
	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

};