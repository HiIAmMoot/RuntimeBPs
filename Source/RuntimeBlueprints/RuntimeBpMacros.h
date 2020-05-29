// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Engine\EngineTypes.h"

#define NODE_VAR_ARG_UNION \
TLongUnion< bool, /* 0 */ \
	uint8, /* 1 */ \
	int,  /* 2 */ \
	float, /* 3 */ \
	FVector, /* 4 */ \
	FRotator, /* 5 */ \
	FTransform, /* 6 */ \
	FVector2D, /* 7 */ \
	FVector4, /* 8 */ \
	FLinearColor, /* 9 */ \
	FIntVector, /* 10 */ \
	FIntVector4D, /* 11 */ \
	UObject*, /* 12 */ \
	UClass*, /* 13 */ \
	AActor*, /* 14 */ \
	USceneComponent*, /* 15 */ \
	APlayerController*, /* 16 */ \
	ACharacter*, /* 17 */ \
	UStaticMeshComponent*, /* 18 */ \
	ULightComponent*, /* 19 */ \
	UParticleSystemComponent*, /* 20 */ \
	UStaticMesh*, /* 21 */ \
	UMaterialInterface*, /* 22 */ \
	UParticleSystem*, /* 23 */ \
	UPrimitiveComponent*, /* 24 */ \
	APawn*, /* 25 */ \
	ARuntimeBpGrenade*, /* 26 */ \
	UDamageType*, /* 27 */ \
	FHitResult > /* 28 */ \

// Make a constructor for a variable type
#define NODE_VAR_ARG_CONSTRUCTOR(Type) \
FNodeVarArgs(Type Value) \
{ \
	VariableData.SetSubtype<Type>(Value); \
} \

// Make a getter for a variable type
#define NODE_VAR_ARG_GETTER(Type, TypeName) \
Type Get##TypeName##Arg() const \
{ \
	return VariableData.GetSubtype<Type>(); \
} \

// Make a setter for a variable type
#define NODE_VAR_ARG_SETTER(Type, TypeName, Default) \
void Set##TypeName##Arg(Type Value = Default) \
{ \
	VariableData.SetSubtype<Type>(Value); \
} \

// Make a constructor, getter and setter for a variable type
#define NODE_VAR_ARG_FUNCTIONS(Type, TypeName, Default) \
NODE_VAR_ARG_CONSTRUCTOR(Type) \
NODE_VAR_ARG_GETTER(Type, TypeName) \
NODE_VAR_ARG_SETTER(Type, TypeName, Default) \

/*
#define NODE_VAR_ARG_GET_SUBTYPE(Type) \
if (VariableData.HasSubtype<Type>()) \
{ \
	return VariableData.GetSubtype<Type>(); \
} \*/
/*
template<typename First, typename... Rest>
auto getSubTypeForEach(NODE_VAR_ARG_UNION Var)
{
	if (Var.HasSubtype<First>())
	{
		return Var.GetSubtype<First>();
	}
	return getSubTypeForEach<Rest...>(Var);
}

template<>
auto getSubTypeForEach(NODE_VAR_ARG_UNION Var)
{
	return nullptr;
}*/
/*
template<typename Last>
auto getSubTypeForEach(NODE_VAR_ARG_UNION Var)
{
	return Var.GetSubtype<Last>();
}*

template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
/*
#define NODE_VAR_ARG_GETTER_OBJECT(Type, TypeName, Union, Types) \
Type Get##TypeName##Arg() const \
{ \
	return getSubTypeForEach<Type, (argument_type<void(Types)>)::type>(Union); \
} \*/

/*
// Gets the variable in the form of an AActor
AActor* GetActorArg() const
{
	if (VariableData.HasSubtype<APawn*>())
	{
		return VariableData.GetSubtype<APawn*>();
	}

	if (VariableData.HasSubtype<ACharacter*>())
	{
		return VariableData.GetSubtype<ACharacter*>();
	}

	return VariableData.GetSubtype<AActor*>();
}*/

// Make a constructor, getter and setter for a variable array type
#define NODE_VAR_ARRAY_FUNCTIONS(Type, TypeName) \
FNodeVarArgsArray(const TArray<Type>& Values) \
{ \
	Array.Empty(); \
	Array.Reserve(Values.Num()); \
	for (Type Value : Values) \
	{ \
		Array.Add(FNodeVarArgs(Value)); \
	} \
} \
TArray<Type> Get##TypeName##Arg() \
{ \
	TArray<Type> Values; \
	Values.Reserve(Array.Num()); \
	for (FNodeVarArgs& Args : Array) \
	{ \
		Values.Add(Args.Get##TypeName##Arg()); \
	} \
	return Values; \
} \
void Set##TypeName##Arg(const TArray<Type>& Values = {}) \
{ \
	Array.Empty(); \
	if (Values.Num() > 0) \
	{ \
		Array.Reserve(Values.Num()); \
		for (Type Value : Values) \
		{ \
			Array.Add(FNodeVarArgs(Value)); \
		} \
	} \
} \

// Saveable Variable Arrays
#define SAVEABLE_PROPERTY_ARRAY(Type, TypeName, StructName) \
virtual TArray<FNodeVarArgs> GetNodeVarArgs(EVariableTypes VariableType) override \
{ \
	TArray<FNodeVarArgs> NodeVars; \
	NodeVars.Reserve(Array.Num()); \
	for (Type Element : Array) \
	{ \
		NodeVars.Add(FNodeVarArgs(Element)); \
	} \
	return NodeVars; \
} \
virtual void SetValue(TArray<FNodeVarArgs> NodeVarArgs, EVariableTypes VariableType) override \
{ \
	if (VariableType == EVariableTypes::TypeName) \
	{ \
		Array.Empty(); \
		Array.Reserve(NodeVarArgs.Num()); \
		for (FNodeVarArgs NodeVarArg : NodeVarArgs) \
		{ \
			Array.Add(NodeVarArg.Get##TypeName##Arg()); \
		} \
	} \
} \
virtual FString ToJson(int Indent = 0, bool PrettyPrint = false) override \
{ \
	FString JsonString; \
	FJsonObjectConverter::UStructToJsonObjectString<StructName>(*this, JsonString, 0, 0, Indent, nullptr, PrettyPrint); \
	return JsonString; \
} \
virtual TArray<TSharedPtr<FJsonValue>> ToJsonValue() override \
{ \
	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject<StructName>(*this, 0, 0, nullptr); \
	return JsonObject->GetArrayField("array"); \
} \
virtual bool FromJsonValue(TArray<TSharedPtr<FJsonValue>> JsonValue) override \
{ \
	TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject()); \
	JsonObject->SetArrayField("array", JsonValue); \
	return FJsonObjectConverter::JsonObjectToUStruct<StructName>(JsonObject, this, 0, 0); \
} \

// Constructor function for cast nodes
#define RUNTIME_BP_CAST_CONSTRUCTOR(In, InName, OutName) \
NodeName = UKismetStringLibrary::JoinStringArray({"Cast to ", #OutName}, ""); \
NodeDescription = UKismetStringLibrary::JoinStringArray({"Tries to identify(cast) an ", #InName, " into a ", #OutName, ". Do not use the ", #OutName, " output pin if the cast failed!"}, ""); \
NodeCategory = "Casts"; \
 \
InputPins.SetNum(2); \
InputPins[0].MakeNodePin(); \
InputPins[1].MakeNodePin(#InName, EVariableTypes::InName); \
InputPins[1].Value.Array[0].Set##InName##Arg(); \
 \
OutputPins.SetNum(3); \
OutputPins[0].MakeNodePin("Then"); \
OutputPins[1].MakeNodePin("Cast Failed"); \
OutputPins[2].MakeNodePin(#OutName, EVariableTypes::OutName); \

// Execute function for cast nodes
#define RUNTIME_BP_CAST_EXECUTE(InName, Out, OutName) \
if (GetConnectedPinValue(InputPins[1]).Get##InName##Arg()) \
{ \
	Out* CastObject = Cast<Out>(GetConnectedPinValue(InputPins[1]).Get##InName##Arg()); \
	if (CastObject) \
	{ \
		OutputPins[2].Value.Array[0].Set##OutName##Arg(CastObject); \
		Super::Execute(0, FromLoopIndex); \
	} \
	else \
	{ \
		Super::Execute(1, FromLoopIndex); \
	} \
} \
else \
{ \
	Super::Execute(1, FromLoopIndex); \
} \

// Used in ScriptValueToJsonValue
#define SCRIPT_TO_JSON_CASE(StructName) \
{ \
	StructName Variable; \
	Variable.SetValue(Value, VariableType); \
	Success = true; \
	return Variable.ToJsonValue(); \
} \

// Used in JsonValueToScriptValue
#define JSON_TO_SCRIPT_CASE(StructName) \
{ \
	StructName Variable; \
	Success = Variable.FromJsonValue(Value); \
	return Variable.GetNodeVarArgs(VariableType); \
} \

// Used in PinValueToJson
#define PINVALUE_TO_JSON_CASE(StructName) \
{ \
	StructName Variable; \
	Variable.SetValue(NodePin.Value.Array, NodePin.VariableType); \
	return Variable.ToJson(); \
} \

#define NODE_VAR_ARG_GETTER_SAFE(Type, TypeName) \
TArray<Type> Value; \
/* We check if the values are valid or if they even exist first. */ \
if ((Values.Num() == 0 && !Array) || Values.Num() > 0 && !Values[0].VariableData.HasSubtype<Type>()) \
{ \
	Values.Empty(); \
	Values.Add(FNodeVarArgs(EVariableTypes::TypeName)); \
	Value = { Values[0].Get##TypeName##Arg() }; \
	return Value; \
} \
/* If they do, we reserve the memory */ \
Value.Reserve(Values.Num()); \
/* Turn the array of FNodeVarArgs to the respective value type. */ \
for (FNodeVarArgs Args : Values) \
{ \
	if (Args.VariableData.HasSubtype<Type>()) \
	{ \
		Value.Add(Args.Get##TypeName##Arg()); \
	} \
} \
return Value; \


#define NODE_VAR_ARG_SETTER_SAFE(Type, TypeName) \
Values.SetNum(Value.Num()); \
int i = 0; \
for (Type Val : Value) \
{ \
	Values[i].Set##TypeName##Arg(Val); \
	i++; \
} \

#define NODE_VAR_STRING_GETTER_SAFE(Type, TypeName) \
TArray<Type> Value; \
/* We check if the values are valid or if they even exist first.*/ \
if ((Values.Num() == 0 && !Array)) \
{ \
	Values.Add(FNodeVarArgs()); \
	Value = { Values[0].Get##TypeName##Arg() }; \
	return Value; \
} \
/* If they do, we reserve the memory */ \
Value.Reserve(Values.Num()); \
/* Turn the array of FNodeVarArgs to the respective value type. */ \
for (FNodeVarArgs Args : Values) \
{ \
	Value.Add(Args.Get##TypeName##Arg()); \
} \
return Value; \