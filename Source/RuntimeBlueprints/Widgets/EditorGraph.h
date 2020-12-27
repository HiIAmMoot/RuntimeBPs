// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/UObjectGlobals.h"
#include "RuntimeBpData.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RuntimeBpLibrary.h"
#include "EditorGraph.generated.h"

/**
 * 
 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEditorGraph : public UUserWidget
{
	GENERATED_BODY()

protected:
	// All Nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Editor", Keywords = "Nodes Array"))
	TArray<FNodeStruct> Nodes;

	// All Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Editor", Keywords = "Variables Array"))
	TArray<FSaveableVariable> Variables;

	// All Functions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Editor", Keywords = "Custom Functions CustomFunctions Array"))
	TArray<FRuntimeFunction> CustomFunctions;

	// All Script References
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Editor", Keywords = "Script References ScriptReferences Array"))
	TArray<FString> ScriptReferences;

	// Set of nodes that are erroring, if this isn't empty the script won't execute. X = FunctionIndex, Y = NodeIndex, Z = PinIndex
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Runtime Values|Editor", Keywords = "Erroring Nodes Set Error"))
	TSet<FIntVector4D> ErroringNodes;

public:

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Clear Node Struct Array"))
	void ClearNodeStructArray();

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Add Node Struct to Array"))
	void AddNodeStructToArray(FVector2D NodeCoords, const TArray<FPinStruct>& InputPins, const TArray<FPinStruct>& OutputPins, int NodeIndex, TSubclassOf<URuntimeBpObject> NodeClass, EVariableTypes WildCardType = EVariableTypes::WildCard);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Add Variable Added Duplicate"))
	int AddVariable();

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Add Variable Added Duplicate"))
	int AddLocalVariable(int FunctionIndex);

	UFUNCTION(BlueprintImplementableEvent, meta = (Category = "Runtime Values|Editor", Keywords = "On Variable Added"))
	void OnVariableAdded(UPARAM(ref) FSaveableVariable& Variable);

	UFUNCTION(BlueprintImplementableEvent, meta = (Category = "Runtime Values|Editor", Keywords = "On Variable Added"))
	void OnLocalVariableAdded(int FunctionIndex, UPARAM(ref) FSaveableVariable& Variable);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Add Function Added Duplicate"))
	int AddFunction();

	UFUNCTION(BlueprintImplementableEvent, meta = (Category = "Runtime Values|Editor", Keywords = "On Function Added"))
	void OnFunctionAdded(UPARAM(ref) FRuntimeFunction& Variable);

	// Converts the union value struct into a saveable struct
	// UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Saving", Keywords = "Convert Union Struct"))
	// FSaveableProperty ConvertUnionStructValue(UPARAM(ref) FPinStruct& PinStruct, EVariableTypes VariableType, bool Input);

	// Converts each node into a saveable format.
	// UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Saving", Keywords = "Turn Node Struct to Saveable Structs"))
	// TArray<FConvertedNode> TurnNodeStructsToSaveableStructs();

	// Turns a saveable pin into an union pin for runtime use
	// UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Loading", Keywords = "Convert Saveable Pin to Union Pin"))
	// Void ConvertSaveablePinToUnionPin(UPARAM(ref) FConvertedNodePin& SaveablePin, FPinStruct& NodePin);

	// Turns a saveable node into node info for runtime use
	// UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Loading", Keywords = "Turn Saveable Structs to Node Structs"))
	// Void TurnSaveableStructsToNodeStructs(UPARAM(ref) TArray<FConvertedNode>& SaveableStuctArray);
	
	// Turns the pin value into a string to show in the editor graph
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Values to String"))
	FString ValueToString(UPARAM(ref) TArray<FNodeVarArgs>& Values, EVariableTypes VariableType, bool Array);

	// Turns the pin value into a Json format for saving
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Pin Value to Json"))
	FString PinValueToJson(UPARAM(ref) FPinStruct& NodePin);

	/*
	template<typename StructType>
	void SerializeUnion(const StructType& Struct, const TArray<uint8>& Storage);

	template<typename StructType>
	void DeserializeUnion(const TArray<uint8>& Storage, const StructType& Struct);*/

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Values|Editor", Keywords = "Duplicate Editor Graph"))
	void DuplicateEditorGraph(UEditorGraph* OutEditorGraph);
};