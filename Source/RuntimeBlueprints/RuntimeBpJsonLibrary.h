// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectConverter.h"
#include "RuntimeBpData.h"
#include "RuntimeBpLibrary.h"
#include "Nodes/CustomNodes.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RuntimeBpJsonLibrary.generated.h"

UCLASS()
class RUNTIMEBLUEPRINTS_API URuntimeBpJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "JSON", meta = (Keywords = "Json String to Runtime BP Data"))
	static bool RuntimeBpDataFromJson(const FString& Json, FRuntimeBpJsonFormat& RuntimeBpData);

	/**
	* Receives any kind of struct and converts it into a Json string
	* @param AnyStruct The struct you want to convert to Json
	* @param Indent determines the amount of indents in the string
	* @param PrettyPrint determines wether to use Pretty Print for the string
	*/
	UFUNCTION(BlueprintCallable, Category = "JSON", CustomThunk, meta = (CustomStructureParam = "AnyStruct", Keywords = "Any Struct to Json String"))
	static FString StructToJson(const int32& AnyStruct, int Indent, bool PrettyPrint);

	DECLARE_FUNCTION(execStructToJson)
	{
		// Steps into the stack, walking to the next property in it
		Stack.Step(Stack.Object, NULL);

		// Grab the last property found when we walked the stack
		// This does not contains the property value, only its type information
		FStructProperty* StructProperty = ExactCastField<FStructProperty>(Stack.MostRecentProperty);

		// Grab the base address where the struct actually stores its data
		// This is where the property value is truly stored
		void* StructPtr = Stack.MostRecentPropertyAddress;

		// Get the input param options
		P_GET_PROPERTY(FIntProperty, Indent);
		P_GET_PROPERTY(FBoolProperty, PrettyPrint);

		// We need this to wrap up the stack
		P_FINISH;

		P_NATIVE_BEGIN;
		FString JsonString = TEXT("");
		if (StructProperty)
		{
			UScriptStruct* Struct = StructProperty->Struct;
			bool Success = FJsonObjectConverter::UStructToJsonObjectString(Struct, StructPtr, JsonString, 0, 0, Indent, nullptr, PrettyPrint);
		}

		*(FString*)RESULT_PARAM = JsonString;
		P_NATIVE_END;
	}

	static TArray<TSharedPtr<FJsonValue>> ScriptValueToJsonValue(const TArray<FNodeVarArgs>& Value, EVariableTypes VariableType, bool& Success);

	// Static const TArray<TSharedPtr<FJsonValue>>* ScriptValueToJsonValue2(const FPinStruct& Pin);

	static bool ScriptToJsonObject(const FRuntimeBpJsonFormat& Script, TSharedRef<FJsonObject> JsonObject);

	UFUNCTION(BlueprintCallable, Category = "JSON", meta = (Keywords = "Script to Json String"))
	static bool ScriptToJsonString(const FRuntimeBpJsonFormat& Script, FString& JsonString, bool PrettyPrint, int Indent);

	static void UpdateRuntimeScriptNodeDefaults(FRuntimeBpJsonFormat& Script, FSaveableBPJsonFormat& SaveableScript, TArray<FNodeStruct>& RuntimeNodes, TArray<FSaveableNode>& SaveableNodes, const FString& ThisScriptName, const TMap<FIntPoint, FString>& FunctionReferences, int Index);

	//static void UpdateRuntimeScriptExternalFunction(TArray<FNodeStruct>& RuntimeNodes, TMap <FString, TArray<FSaveableFunction>> ExternalFunctions)

	static TArray<FNodeVarArgs> JsonValueToScriptValue(TArray<TSharedPtr<FJsonValue>> Value, EVariableTypes VariableType, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "JSON", meta = (Keywords = "Json String to Script"))
	static bool JsonStringToScript(const FString& InString, FRuntimeBpJsonFormat& Script, const FString& ThisScriptName, bool LoadExternals);
};