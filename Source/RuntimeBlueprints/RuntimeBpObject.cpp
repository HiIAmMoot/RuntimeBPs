// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeBpObject.h"
#include "RuntimeBpData.h"
#include "RuntimeBpConstructor.h"
#include "Nodes/CustomNodes.h"

// Sets default values for this component's properties
URuntimeBpObject::URuntimeBpObject()
{
	Pure = true;
	Latent = false;
}

void URuntimeBpObject::ConstructNode(URuntimeBpConstructor * ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	BPConstructor = ConstructorClass;
	NodeIndex = ConstructedNodeIndex;
	NodeName = ConstructedNodeName;
	InputPins = ConstructedInputPins;
	OutputPins = ConstructedOutputPins;

	// Check if any inputs contain Exec types, if so this node isn't pure
	for (FPinStruct& InputPin : InputPins)
	{
		InputPin.Input = true;
		if (InputPin.VariableType == EVariableTypes::Exec)
		{
			Pure = false;
		}
	}

	// Check if outputs have any exec if the input didn't have any
	if (Pure)
	{
		for (FPinStruct& InputPin : OutputPins)
		{
			if (InputPin.VariableType == EVariableTypes::Exec)
			{
				Pure = false;
				break;
			}
		}
	}
}

void URuntimeBpObject::Execute(int Index, int FromLoopIndex)
{
	Then(Index, FromLoopIndex);
}

void URuntimeBpObject::Then(int Index, int FromLoopIndex)
{
	if (BPConstructor && !BPConstructor->Kill)
	{
		if (!Pure && OutputPins.IsValidIndex(Index))
		{
			TArray<URuntimeBpObject*> Nodes = GetNodeFamily();
			FPinStruct Pin = OutputPins[Index];
			int ConnectedNodeIndex = Pin.ConnectedNodeIndex;

			// If this node is inside a function, and the index equals -1, that means it is not connected to anything and thus will mean the function must close
			if (FunctionIndex != -1)
			{
				if (ConnectedNodeIndex < 0)
				{
					// Check if this node is part of a loop first
					if (FromLoopIndex != -1)
					{
						// If there is no continuation of the chain, we tell the loop to continue its heartbeat
						URuntimeBpObject* LoopingNode = Nodes[FromLoopIndex];
						LoopingNode->Next();
						return;
					}
					GetFunctionCall()->ResetCustomOutput();
					GetFunctionCall()->Then(0, -1);
				}
				else if (Nodes.IsValidIndex(ConnectedNodeIndex))
				{
					URuntimeBpObject* ConnectedNode = Nodes[ConnectedNodeIndex];
					ConnectedNode->Execute(Pin.ConnectedPinIndex, FromLoopIndex);
				}
				return;
			}

			if (ConnectedNodeIndex != -1 && Nodes.IsValidIndex(ConnectedNodeIndex))
			{
				URuntimeBpObject* ConnectedNode = Nodes[ConnectedNodeIndex];
				ConnectedNode->Execute(Pin.ConnectedPinIndex, FromLoopIndex);
				// For latent functions, we tell the loop this is coming from to continue its heartbeat
				if (ConnectedNode->Latent && FromLoopIndex != -1 && Nodes.IsValidIndex(FromLoopIndex))
				{
					URuntimeBpObject* LoopingNode = Nodes[FromLoopIndex];
					LoopingNode->Next();
				}
				return;
			}
			else if (!Latent && FromLoopIndex != -1 && Nodes.IsValidIndex(FromLoopIndex))
			{
				// If not a latent function and there is no continuation of the chain, we tell the loop to continue its heartbeat 
				URuntimeBpObject* LoopingNode = Nodes[FromLoopIndex];
				LoopingNode->Next();
			}
		}
	}
}

void URuntimeBpObject::Next()
{}

URuntimeBpObject*& URuntimeBpObject::GetFunctionCall()
{
	return BPConstructor->FunctionNodes[FunctionIndex].FunctionCaller;
}

TArray<URuntimeBpObject*>& URuntimeBpObject::GetNodeFamily()
{
	if (FunctionIndex > -1)
	{
		return BPConstructor->FunctionNodes[FunctionIndex].Nodes;
	}

	return BPConstructor->BPNodes;
}

void URuntimeBpObject::UpdateCustomOutput(TArray<FPinStruct>& Pins)
{
	for (int i = 1; i < Pins.Num(); i++)
	{
		OutputPins[i].Value = GetConnectedPinArray(Pins[i]);
	}
}

void URuntimeBpObject::ResetCustomOutput()
{
	for (int i = 1; i < OutputPins.Num(); i++)
	{
		if (OutputPins[i].Array)
		{
			OutputPins[i].Value.Array.Empty();
		}
		else
		{
			for (FNodeVarArgs Value : OutputPins[i].Value.Array)
			{
				Value = FNodeVarArgs(OutputPins[i].VariableType);
			}
		}
	}
}

void URuntimeBpObject::ResetInternalFunctionValues()
{
}

void URuntimeBpObject::ClearEditorValues()
{
	NodeDescription = "";
	NodeCategory = "";
	NodeName = "";
}

FNodeVarArgs URuntimeBpObject::GetConnectedPinValue(const FPinStruct& Pin)
{
	if (Pin.ConnectedNodeIndex > -1 && BPConstructor != nullptr)
	{
		URuntimeBpObject* ConnectedNode = GetNodeFamily()[Pin.ConnectedNodeIndex];
		if (ConnectedNode->Pure)
		{
			ConnectedNode->Execute(0);
		}
		FPinStruct ConnectedPin = ConnectedNode->OutputPins[Pin.ConnectedPinIndex];
		return ConnectedNode->GetConnectedPinValue(ConnectedPin);
	}
	// If constructor is invalid or node index is -1(which means it's not connected to anything), use the default value of this pin.
	else
	{
		// In case the array is empty, we simply return an empty uobject value as dynamic objects should only have this happen. We should never hit this though.
		if (Pin.Value.Array.Num() == 0)
		{
			FNodeVarArgs Args = FNodeVarArgs(Pin.VariableType);
			return Args;
		}
		return Pin.Value.Array[0];
	}
}

FNodeVarArgsArray URuntimeBpObject::GetConnectedPinArray(const FPinStruct& Pin)
{
	if (Pin.ConnectedNodeIndex > -1 && BPConstructor != nullptr)
	{
		URuntimeBpObject* ConnectedNode = GetNodeFamily()[Pin.ConnectedNodeIndex];
		if (ConnectedNode->Pure)
		{
			ConnectedNode->Execute(0);
		}
		FPinStruct ConnectedPin = ConnectedNode->OutputPins[Pin.ConnectedPinIndex];
		return ConnectedNode->GetConnectedPinArray(ConnectedPin);
	}
	else
	{
		// If constructor is invalid or node index is -1(which means it's not connected to anything), use the default value of this pin.
		return FNodeVarArgsArray(Pin.Value);
	}
}

FSaveableVariable& URuntimeBpObject::GetConnectedVariableRef(const FPinStruct & Pin)
{
	if (Pin.ConnectedNodeIndex > -1)
	{
		URuntimeBpObject* ConnectedNode = GetNodeFamily()[Pin.ConnectedNodeIndex];
		// If we are dealing with a variable we can return the actual variable reference here.
		switch (ConnectedNode->NodeType)
		{
			case ENodeType::VariableGetter:
			{
				return BPConstructor->Variables[ConnectedNode->OutputPins[0].ConnectedPinIndex];
			}
			case ENodeType::VariableSetter:
			{
				return BPConstructor->Variables[ConnectedNode->OutputPins[1].ConnectedPinIndex];
			}
			case ENodeType::LocalVariableGetter:
			{
				return BPConstructor->Functions[ConnectedNode->OutputPins[0].ConnectedNodeIndex].LocalVariables[ConnectedNode->OutputPins[0].ConnectedPinIndex];
			}
			case ENodeType::LocalVariableSetter:
			{
				return BPConstructor->Functions[ConnectedNode->OutputPins[1].ConnectedNodeIndex].LocalVariables[ConnectedNode->OutputPins[1].ConnectedPinIndex];
			}
			default:
			{
				return BPConstructor->NullVariable;
			}
		}
	}
	return BPConstructor->NullVariable;
}