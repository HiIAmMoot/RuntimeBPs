// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomNodes.h"
#include "RuntimeBpConstructor.h"

UCallFunction::UCallFunction()
{
	NodeName = "Call Function";
	NodeCategory = "Hidden";

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin();// No args means execute

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");

	NodeType = ENodeType::CustomFunction;
}

void UCallFunction::Execute(int Index, int FromLoopIndex)
{
	StoredFromLoopIndex = FromLoopIndex;
	int FunctionCallIndex = InputPins[0].ConnectedNodeIndex;
	// The function this node is supposed to call is stored inside the Connected Node Index of the input pin
	BPConstructor->FunctionNodes[FunctionCallIndex].FunctionCaller = this;
	BPConstructor->FunctionNodes[FunctionCallIndex].Nodes[0]->UpdateCustomOutput(this, InputPins);

	// Reset any values first
	for (URuntimeBpObject* Node : BPConstructor->FunctionNodes[FunctionCallIndex].Nodes)
	{
		Node->ResetInternalFunctionValues();
	}
	
	// Reset local variables
	BPConstructor->Functions[FunctionCallIndex].LocalVariables = BPConstructor->LocalVariableDefaults[FunctionCallIndex].Variables;

	BPConstructor->FunctionNodes[FunctionCallIndex].Nodes[0]->Execute(0);
	//Nodes[ConnectedFunctionStartIndex]->Execute(ConnectedPinStartIndex);
}

void UCallFunction::Then(int Index, int FromLoopIndex)
{
	Super::Then(Index, StoredFromLoopIndex);
}

UFunctionStart::UFunctionStart()
{
	NodeName = "Function Start";
	NodeCategory = "Hidden";

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");

	NodeType = ENodeType::FunctionStart;
	DynamicInput = true;
	DynamicOutput = true;
}

UFunctionEnd::UFunctionEnd()
{
	NodeName = "Return Node";
	NodeCategory = "Hidden";

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin();// No args means execute

	NodeType = ENodeType::FunctionEnd;
	DynamicInput = true;
	DynamicOutput = true;
}

void UFunctionEnd::Execute(int Index, int FromLoopIndex)
{
	URuntimeBpObject* FunctionCaller = GetFunctionCall();
	FunctionCaller->UpdateCustomOutput(this, InputPins);
	GetFunctionCall() = nullptr;
	FunctionCaller->Then(0, -1);
}

USetVariable::USetVariable()
{
	NodeName = "SET";
	NodeCategory = "Hidden";
	NodeType = ENodeType::VariableSetter;

	InputPins.SetNum(2);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("VariableName", EVariableTypes::Bool);
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("", EVariableTypes::Bool);
}

void USetVariable::ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString & ConstructedNodeName, UPARAM(ref)TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref)TArray<FPinStruct>& ConstructedOutputPins)
{
	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);

	// We store the variable index in the ConnectedPinIndex of the output variable pin to save memory and storage space
	if (ConstructorClass && ConstructorClass->Variables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		// Set the variable type and name
		InputPins[1].VariableType = ConstructorClass->Variables[OutputPins[1].ConnectedPinIndex].t;
		InputPins[1].PinName = ConstructorClass->Variables[OutputPins[1].ConnectedPinIndex].n;
		OutputPins[1].VariableType = ConstructorClass->Variables[OutputPins[1].ConnectedPinIndex].t;
		if (!OutputPins[1].Value.Array.IsValidIndex(0))
		{
			OutputPins[1].Value.Array.SetNum(1);
			OutputPins[1].Value.Array[0] = ConstructorClass->Variables[OutputPins[1].ConnectedPinIndex].v[0];
		}
	}
}

FNodeVarArgs USetVariable::GetConnectedPinValue(FPinStruct& Pin)
{
	if (BPConstructor->Variables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		return BPConstructor->Variables[OutputPins[1].ConnectedPinIndex].v[0];
	}

	return Pin.Value.Array[0];
}

FNodeVarArgsArray USetVariable::GetConnectedPinArray(FPinStruct& Pin)
{
	if (BPConstructor->Variables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		return FNodeVarArgsArray(BPConstructor->Variables[OutputPins[1].ConnectedPinIndex].v);
	}

	return FNodeVarArgsArray(Pin.Value);
}

void USetVariable::Execute(int Index, int FromLoopIndex)
{
	// We store the variable index in the ConnectedPinIndex of the output variable pin to save memory and storage space
	if (BPConstructor && BPConstructor->Variables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		// This is a bit of a workaround because GetConnectedPinArray is overridden to return the variable,
		// So we manually have to get the connected value here instead of calling that function
		if (InputPins[1].ConnectedNodeIndex > -1 && BPConstructor != nullptr)
		{
			URuntimeBpObject* ConnectedNode = GetNodeFamily()[InputPins[1].ConnectedNodeIndex];
			BPConstructor->Variables[OutputPins[1].ConnectedPinIndex].v = ConnectedNode->GetConnectedPinArray(InputPins[1]).Array;
		}
		else
		{
			BPConstructor->Variables[OutputPins[1].ConnectedPinIndex].v = InputPins[1].Value.Array;
		}
	}
	Super::Execute(0, FromLoopIndex);// Index here is the output pins array index
}

UGetVariable::UGetVariable()
{
	NodeName = "GET";
	NodeCategory = "Hidden";
	NodeType = ENodeType::VariableGetter;

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("VariableName", EVariableTypes::Bool);
}

void UGetVariable::ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString & ConstructedNodeName, UPARAM(ref)TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref)TArray<FPinStruct>& ConstructedOutputPins)
{
	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);

	// We store the variable index in the ConnectedPinIndex of the output variable pin to save memory
	if (ConstructorClass && ConstructorClass->Variables.Num() > OutputPins[0].ConnectedPinIndex)
	{
		// Set the variable type and name
		OutputPins[0].VariableType = ConstructorClass->Variables[OutputPins[0].ConnectedPinIndex].t;
		OutputPins[0].PinName = ConstructorClass->Variables[OutputPins[0].ConnectedPinIndex].n;
		if (!OutputPins[0].Value.Array.IsValidIndex(0))
		{
			OutputPins[0].Value.Array.SetNum(1);
			OutputPins[0].Value.Array[0] = ConstructorClass->Variables[OutputPins[0].ConnectedPinIndex].v[0];
		}
	}
}

FNodeVarArgs UGetVariable::GetConnectedPinValue(FPinStruct& Pin)
{
	if (BPConstructor->Variables.Num() > OutputPins[0].ConnectedPinIndex)
	{
		return BPConstructor->Variables[OutputPins[0].ConnectedPinIndex].v[0];
	}

	return Pin.Value.Array[0];
}

FNodeVarArgsArray UGetVariable::GetConnectedPinArray(FPinStruct& Pin)
{
	if (BPConstructor->Variables.Num() > OutputPins[0].ConnectedPinIndex)
	{
		return FNodeVarArgsArray(BPConstructor->Variables[OutputPins[0].ConnectedPinIndex].v);
	}
	return FNodeVarArgsArray(Pin.Value);
}

USetLocalVariable::USetLocalVariable()
{
	NodeName = "SET";
	NodeCategory = "Hidden";
	NodeType = ENodeType::LocalVariableSetter;

	InputPins.SetNum(2);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("VariableName", EVariableTypes::Bool);
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("", EVariableTypes::Bool);
}

void USetLocalVariable::ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString & ConstructedNodeName, UPARAM(ref)TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref)TArray<FPinStruct>& ConstructedOutputPins)
{
	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);

	// We store the variable index in the ConnectedPinIndex of the output variable pin to save memory and storage space
	// Function index is stored in the Connected Node Index
	if (ConstructorClass && ConstructorClass->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		// Set the variable type and name
		InputPins[1].VariableType = ConstructorClass->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables[OutputPins[1].ConnectedPinIndex].t;
		InputPins[1].PinName = ConstructorClass->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables[OutputPins[1].ConnectedPinIndex].n;
		OutputPins[1].VariableType = ConstructorClass->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables[OutputPins[1].ConnectedPinIndex].t;
		if (!OutputPins[1].Value.Array.IsValidIndex(0))
		{
			OutputPins[1].Value.Array.SetNum(1);
			OutputPins[1].Value.Array[0] = ConstructorClass->Variables[OutputPins[1].ConnectedPinIndex].v[0];
		}
	}
}

FNodeVarArgs USetLocalVariable::GetConnectedPinValue(FPinStruct& Pin)
{
	if (BPConstructor->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		return BPConstructor->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables[OutputPins[1].ConnectedPinIndex].v[0];
	}

	return Pin.Value.Array[0];
}

FNodeVarArgsArray USetLocalVariable::GetConnectedPinArray(FPinStruct& Pin)
{
	if (BPConstructor->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		return FNodeVarArgsArray(BPConstructor->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables[OutputPins[1].ConnectedPinIndex].v);
	}

	return FNodeVarArgsArray(Pin.Value);
}

void USetLocalVariable::Execute(int Index, int FromLoopIndex)
{
	// We store the variable index in the ConnectedPinIndex of the output variable pin to save memory and storage space
	// Function index is stored in the Connected Node Index
	if (BPConstructor && BPConstructor->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables.Num() > OutputPins[1].ConnectedPinIndex)
	{
		// This is a bit of a workaround because GetConnectedPinArray is overridden to return the variable,
		// So we manually have to get the connected value here instead of calling that function
		if (InputPins[1].ConnectedNodeIndex > -1 && BPConstructor != nullptr)
		{
			URuntimeBpObject* ConnectedNode = GetNodeFamily()[InputPins[1].ConnectedNodeIndex];
			BPConstructor->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables[OutputPins[1].ConnectedPinIndex].v = ConnectedNode->GetConnectedPinArray(InputPins[1]).Array;
		}
		else
		{
			BPConstructor->Functions[OutputPins[1].ConnectedNodeIndex].LocalVariables[OutputPins[1].ConnectedPinIndex].v = InputPins[1].Value.Array;
		}
	}

	Super::Execute(0, FromLoopIndex);// Index here is the output pins array index
}

UGetLocalVariable::UGetLocalVariable()
{
	NodeName = "GET";
	NodeCategory = "Hidden";
	NodeType = ENodeType::LocalVariableGetter;

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("VariableName", EVariableTypes::Bool);
}

void UGetLocalVariable::ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString & ConstructedNodeName, UPARAM(ref)TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref)TArray<FPinStruct>& ConstructedOutputPins)
{
	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);

	if (ConstructorClass && ConstructorClass->Functions[OutputPins[0].ConnectedNodeIndex].LocalVariables.Num() > OutputPins[0].ConnectedPinIndex)
	{
		// Set the variable type and name
		OutputPins[0].VariableType = ConstructorClass->Functions[OutputPins[0].ConnectedNodeIndex].LocalVariables[OutputPins[0].ConnectedPinIndex].t;
		OutputPins[0].PinName = ConstructorClass->Functions[OutputPins[0].ConnectedNodeIndex].LocalVariables[OutputPins[0].ConnectedPinIndex].n;
		if (!OutputPins[0].Value.Array.IsValidIndex(0))
		{
			OutputPins[0].Value.Array.SetNum(1);
			OutputPins[0].Value.Array[0] = ConstructorClass->Variables[OutputPins[0].ConnectedPinIndex].v[0];
		}
	}
}

FNodeVarArgs UGetLocalVariable::GetConnectedPinValue(FPinStruct& Pin)
{
	if (BPConstructor->Functions[OutputPins[0].ConnectedNodeIndex].LocalVariables.Num() > OutputPins[0].ConnectedPinIndex)
	{
		return BPConstructor->Functions[OutputPins[0].ConnectedNodeIndex].LocalVariables[OutputPins[0].ConnectedPinIndex].v[0];
	}

	return Pin.Value.Array[0];
}

FNodeVarArgsArray UGetLocalVariable::GetConnectedPinArray(FPinStruct& Pin)
{
	if (BPConstructor->Functions[OutputPins[0].ConnectedNodeIndex].LocalVariables.Num() > OutputPins[0].ConnectedPinIndex)
	{
		return FNodeVarArgsArray(BPConstructor->Functions[OutputPins[0].ConnectedNodeIndex].LocalVariables[OutputPins[0].ConnectedPinIndex].v);
	}

	return FNodeVarArgsArray(Pin.Value);
}