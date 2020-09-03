// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorGraph.h"
#include "RuntimeBpMacros.h"

void UEditorGraph::ClearNodeStructArray()
{
	Nodes.Empty();
}

void UEditorGraph::AddNodeStructToArray(FVector2D NodeCoords, TArray<FPinStruct> InputPins, TArray<FPinStruct> OutputPins, int NodeIndex, TSubclassOf<URuntimeBpObject> NodeClass)
{
	FNodeStruct NodeStruct;
	NodeStruct.NodeCoords = NodeCoords;
	NodeStruct.InputPins = InputPins;
	NodeStruct.OutputPins = OutputPins;
	NodeStruct.NodeIndex = NodeIndex;
	NodeStruct.NodeClass = NodeClass;
	Nodes.Add(NodeStruct);
}

int UEditorGraph::AddVariable()
{
	FSaveableVariable DefaultVariable = FSaveableVariable();
	DefaultVariable.v.Add(FNodeVarArgs(false));
	DefaultVariable.t = EVariableTypes::Bool;

	Variables.Add(DefaultVariable);
	int LastArrayIndex = Variables.Num() - 1;
	OnVariableAdded(Variables[LastArrayIndex]);
	return LastArrayIndex;
}

int UEditorGraph::AddLocalVariable(int FunctionIndex)
{
	if (FunctionIndex < 0)
	{
		return -1;
	}

	FSaveableVariable DefaultVariable = FSaveableVariable();
	DefaultVariable.v.Add(FNodeVarArgs(false));
	DefaultVariable.t = EVariableTypes::Bool;

	CustomFunctions[FunctionIndex].LocalVariables.Add(DefaultVariable);
	int LastArrayIndex = CustomFunctions[FunctionIndex].LocalVariables.Num() - 1;
	OnLocalVariableAdded(FunctionIndex, CustomFunctions[FunctionIndex].LocalVariables[LastArrayIndex]);
	return LastArrayIndex;
}

int UEditorGraph::AddFunction()
{
	FRuntimeFunction DefaultFunction = FRuntimeFunction();

	CustomFunctions.Add(DefaultFunction);
	int LastArrayIndex = CustomFunctions.Num() - 1;
	OnFunctionAdded(CustomFunctions[LastArrayIndex]);
	return LastArrayIndex;
}

FString UEditorGraph::ValueToString(UPARAM(ref) TArray<FNodeVarArgs>& Values, EVariableTypes VariableType, bool Array)
{
	if (Array) { return ""; }

	switch (VariableType)
	{
		case EVariableTypes::Bool: return URuntimeBpLibrary::GetBoolArg(Values)[0] ? TEXT("true") : TEXT("false");
		case EVariableTypes::Byte: return FString::FromInt(URuntimeBpLibrary::GetByteArg(Values)[0]);
		case EVariableTypes::Int: return FString::FromInt(URuntimeBpLibrary::GetIntArg(Values)[0]);
		case EVariableTypes::Float: return FString::SanitizeFloat(URuntimeBpLibrary::GetFloatArg(Values)[0]);
		case EVariableTypes::Name: return URuntimeBpLibrary::GetStringArg(Values)[0];
		case EVariableTypes::String: return URuntimeBpLibrary::GetStringArg(Values)[0];
		case EVariableTypes::Text: return URuntimeBpLibrary::GetStringArg(Values)[0];
		case EVariableTypes::Vector: return URuntimeBpLibrary::GetVectorArg(Values)[0].ToString();
		case EVariableTypes::Rotator: return URuntimeBpLibrary::GetRotatorArg(Values)[0].ToString();
		case EVariableTypes::Transform: return URuntimeBpLibrary::GetTransformArg(Values)[0].ToString();
		case EVariableTypes::Vector2D: return URuntimeBpLibrary::GetVector2DArg(Values)[0].ToString();
		case EVariableTypes::Vector4: return URuntimeBpLibrary::GetVector4Arg(Values)[0].ToString();
		case EVariableTypes::LinearColor: return URuntimeBpLibrary::GetLinearColorArg(Values)[0].ToString();
		case EVariableTypes::IntVector: return URuntimeBpLibrary::GetIntVectorArg(Values)[0].ToString();
		case EVariableTypes::Class: return URuntimeBpLibrary::GetClassArg(Values)[0] ? URuntimeBpLibrary::GetClassArg(Values)[0]->GetName() : "None";
		case EVariableTypes::StaticMesh: return URuntimeBpLibrary::GetStaticMeshArg(Values)[0] ? URuntimeBpLibrary::GetStaticMeshArg(Values)[0]->GetName() : "None";
		case EVariableTypes::MaterialInterface: return URuntimeBpLibrary::GetMaterialInterfaceArg(Values)[0] ? URuntimeBpLibrary::GetMaterialInterfaceArg(Values)[0]->GetName() : "None";
		case EVariableTypes::ParticleSystem: return URuntimeBpLibrary::GetParticleSystemArg(Values)[0] ? URuntimeBpLibrary::GetParticleSystemArg(Values)[0]->GetName() : "None";
		case EVariableTypes::HitResult: return URuntimeBpLibrary::GetHitResultArg(Values)[0].ToString();
		default: return "";
	}
}

FString UEditorGraph::PinValueToJson(UPARAM(ref)FPinStruct& NodePin)
{
	switch (NodePin.VariableType)
	{
		case EVariableTypes::Bool: PINVALUE_TO_JSON_CASE(FSaveableBoolArray)
		case EVariableTypes::Byte: PINVALUE_TO_JSON_CASE(FSaveableByteArray)
		case EVariableTypes::Int: PINVALUE_TO_JSON_CASE(FSaveableIntArray)
		case EVariableTypes::Float: PINVALUE_TO_JSON_CASE(FSaveableFloatArray)
		case EVariableTypes::Name: PINVALUE_TO_JSON_CASE(FSaveableStringArray)
		case EVariableTypes::String: PINVALUE_TO_JSON_CASE(FSaveableStringArray)
		case EVariableTypes::Text: PINVALUE_TO_JSON_CASE(FSaveableStringArray)
		case EVariableTypes::Vector: PINVALUE_TO_JSON_CASE(FSaveableVectorArray)
		case EVariableTypes::Rotator: PINVALUE_TO_JSON_CASE(FSaveableRotatorArray)
		case EVariableTypes::Transform: PINVALUE_TO_JSON_CASE(FSaveableTransformArray)
		case EVariableTypes::Vector2D: PINVALUE_TO_JSON_CASE(FSaveableVector2DArray)
		case EVariableTypes::Vector4: PINVALUE_TO_JSON_CASE(FSaveableVector4Array)
		case EVariableTypes::LinearColor: PINVALUE_TO_JSON_CASE(FSaveableLinearColorArray)
		case EVariableTypes::IntVector: PINVALUE_TO_JSON_CASE(FSaveableIntVectorArray)
		case EVariableTypes::Class: PINVALUE_TO_JSON_CASE(FSaveableClassArray)
		case EVariableTypes::StaticMesh: PINVALUE_TO_JSON_CASE(FSaveableStaticMeshArray)
		case EVariableTypes::MaterialInterface: PINVALUE_TO_JSON_CASE(FSaveableMaterialInterfaceArray)
		case EVariableTypes::ParticleSystem: PINVALUE_TO_JSON_CASE(FSaveableParticleSystemArray)
		case EVariableTypes::HitResult: PINVALUE_TO_JSON_CASE(FSaveableHitResultArray)
		default: return "";
	}
}

void UEditorGraph::DuplicateEditorGraph(UEditorGraph* OutEditorGraph)
{
	FObjectDuplicationParameters Params = FObjectDuplicationParameters(this, OutEditorGraph);
	StaticDuplicateObjectEx(Params);
}
