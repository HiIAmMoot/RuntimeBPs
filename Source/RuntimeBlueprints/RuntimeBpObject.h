// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpData.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetNodeHelperLibrary.h"
#include "UObject/NoExportTypes.h"
#include "CoreGlobals.h"
#include "Components/ActorComponent.h"
#include "RuntimeBpObject.generated.h"

class URuntimeBpConstructor;
class UForLoop;

// This class acts as a wrapper class for the C++ class, this class is added as a component attached to the constructor class
UCLASS(BlueprintType, ClassGroup = (Custom))
class RUNTIMEBLUEPRINTS_API URuntimeBpObject : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URuntimeBpObject();

	// Called when the constructor constructs the BP nodes
	virtual void ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins);

	// The class which constructs and governs the BP nodes
	UPROPERTY()
	class URuntimeBpConstructor* BPConstructor;

	// The index of the array this node is in, this is used for pins to connect to other nodes
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NodeIndex;

	// The index of the function this node belongs to
	int FunctionIndex = -1;

	// The index of the array this node is in, this is used for pins to connect to other nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ENodeType NodeType;

	// The description of node that will show up with tooltips
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NodeDescription;

	// The category this node belongs to, sub-categories are applied using |
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NodeCategory;

	// The name of this node
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NodeName;

	// An array of all input pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPinStruct> InputPins;

	// An array of all output pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPinStruct> OutputPins;

	// Whether this node is a pure function or not, this is determined by whether the in and output pins have any Exec variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 Pure : 1;

	// Whether this node is a latent function which means that it will wait at least one frame before continueing
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 Latent : 1;

	// Whether this node is contains dynamic inputs than can be specified by the user
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 DynamicInput : 1;

	// Whether this node is contains dynamic outputs than can be specified by the user
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 DynamicOutput : 1;

	// Clears the unneeded text variables from the node that are used during editor for recognition and help
	UFUNCTION(BlueprintCallable)
	void ClearEditorValues();

	// Get the single value of the specified pin, only used for non-Execs
	FORCEINLINE virtual FNodeVarArgs GetConnectedPinValue(const FPinStruct& Pin);

	// Get the array value of the specified pin, only used for non-Execs
	FORCEINLINE virtual FNodeVarArgsArray GetConnectedPinArray(const FPinStruct& Pin);

	// Get the variable this pin is connected to, if applicable. This is used for setting variables by ref
	FSaveableVariable& GetConnectedVariableRef(const FPinStruct& Pin);

	// Executes an event based on the index of the pin
	FORCEINLINE virtual void Execute(int Index, int FromLoopIndex = -1);

	// Executes the next event the specified (output) pin index is connected to
	FORCEINLINE void Then(int Index, int FromLoopIndex);

	// Function for loops to trigger the next iteration
	virtual void Next();

	URuntimeBpObject*& GetFunctionCall();

	TArray<URuntimeBpObject*>& GetNodeFamily();

	void UpdateCustomOutput(TArray<FPinStruct>& Pins);

	FORCEINLINE void ResetCustomOutput();

	// Function in order to reset any local values inside a node in case it is inside a function. For example: Resetting a FlipFlop.
	FORCEINLINE virtual void ResetInternalFunctionValues();
};