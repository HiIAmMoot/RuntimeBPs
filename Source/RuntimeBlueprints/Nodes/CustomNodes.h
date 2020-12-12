// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "RuntimeBpLibrary.h"
#include "CustomNodes.generated.h"

/**
*
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCallFunction : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCallFunction();

	// We manually store the FromLoopIndex before a function call because it's lost when a function is called. This is used in the overridden Then function
	int StoredFromLoopIndex;

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

	virtual void Then(int Index, int FromLoopIndex) override;

};

UCLASS()
class RUNTIMEBLUEPRINTS_API UFunctionStart : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFunctionStart();

};

UCLASS()
class RUNTIMEBLUEPRINTS_API UFunctionEnd : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFunctionEnd();

protected:
	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API USetVariable : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USetVariable();

	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

	virtual FNodeVarArgs GetConnectedPinValue(FPinStruct& Pin) override;
	
	virtual FNodeVarArgsArray GetConnectedPinArray(FPinStruct& Pin) override;

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetVariable : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetVariable();

	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;
	
	virtual FNodeVarArgs GetConnectedPinValue(FPinStruct& Pin) override;
	
	virtual FNodeVarArgsArray GetConnectedPinArray(FPinStruct& Pin) override;

};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API USetLocalVariable : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USetLocalVariable();

	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

	virtual FNodeVarArgs GetConnectedPinValue(FPinStruct& Pin) override;

	virtual FNodeVarArgsArray GetConnectedPinArray(FPinStruct& Pin) override;

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
 *
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetLocalVariable : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetLocalVariable();

	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins) override;

	virtual FNodeVarArgs GetConnectedPinValue(FPinStruct& Pin) override;

	virtual FNodeVarArgsArray GetConnectedPinArray(FPinStruct& Pin) override;

};