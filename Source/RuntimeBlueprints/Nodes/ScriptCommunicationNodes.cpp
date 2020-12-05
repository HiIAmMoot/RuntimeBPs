// Fill out your copyright notice in the Description page of Project Settings.

#include "ScriptCommunicationNodes.h"
#include "RuntimeBpConstructor.h"

UActorHasScript::UActorHasScript()
{
	NodeName = "Actor Has Script";
	NodeCategory = "Script";

	InputPins.SetNum(2);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Actor", EVariableTypes::Actor);
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Return Value", EVariableTypes::Bool);
}

void UActorHasScript::Execute(int Index, int FromLoopIndex)
{
	AActor* Actor = GetConnectedPinValue(InputPins[1]).GetActorArg();

	if (Actor)
	{
		OutputPins[1].Value.Array[0].SetBoolArg(Actor->GetComponentByClass(URuntimeBpConstructor::StaticClass()));
	}
	else
	{
		OutputPins[1].Value.Array[0].SetBoolArg(false);
	}
	Super::Execute(0, FromLoopIndex);// 0 here is the output pins array index
}

UGetScriptOwner::UGetScriptOwner()
{
	NodeName = "Get Script Owner";
	NodeCategory = "Script";

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin();// No args means execute

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Owner", EVariableTypes::Actor);
}

void UGetScriptOwner::Execute(int Index, int FromLoopIndex)
{
	OutputPins[1].Value.Array[0].SetActorArg(BPConstructor->GetOwner());
	Super::Execute(0, FromLoopIndex);// 0 here is the output pins array index
}

UCallFunctionFromScript::UCallFunctionFromScript()
{
	NodeName = "Call Function From Script";
	NodeCategory = "Script";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Script", EVariableTypes::String);
	InputPins[1].Value.Array[0].SetStringArg(); // Default value
	InputPins[1].Meta = "Script";
	InputPins[2].MakeNodePin("Actor Containing Script", EVariableTypes::Actor);
	InputPins[2].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Success", EVariableTypes::Bool);

	NodeType = ENodeType::ExternalFunction;
}

void UCallFunctionFromScript::Execute(int Index, int FromLoopIndex)
{
	OutputPins[1].Value.Array[0].SetBoolArg(false);

	AActor* Actor = GetConnectedPinValue(InputPins[2]).GetActorArg();
	if (Actor)
	{
		// The script this node is supposed to call is stored inside the Connected Node Index of the input pin
		int ReferenceIndex = InputPins[0].ConnectedNodeIndex;
		URuntimeBpConstructor* Constructor = Cast<URuntimeBpConstructor>(Actor->GetComponentByClass(URuntimeBpConstructor::StaticClass()));
		// The function name is the string value of the pin, reason why we use save the function name instead of the function index is because the function indices can change more easy over time.
		FString FunctionName = GetConnectedPinValue(InputPins[1]).GetStringArg();

		if (FunctionName != "" && Constructor && Constructor->ScriptReferences.IsValidIndex(ReferenceIndex) && Constructor->JsonFile == Constructor->ScriptReferences[ReferenceIndex])
		{
			int FunctionCallIndex = -1;
			int i = 0;
			for (FRuntimeFunction& Function : Constructor->Functions)
			{
				if (FunctionName == Function.FunctionName)
				{
					FunctionCallIndex = i;
					break;
				}
				i++;
			}

			if (FunctionCallIndex > -1 && Constructor->FunctionNodes.Num() > FunctionCallIndex)
			{
				Constructor->FunctionNodes[FunctionCallIndex].FunctionCaller = this;
				Constructor->FunctionNodes[FunctionCallIndex].Nodes[0]->UpdateCustomOutput(InputPins);

				// Reset any values first
				for (URuntimeBpObject* Node : Constructor->FunctionNodes[FunctionCallIndex].Nodes)
				{
					Node->ResetInternalFunctionValues();
				}

				// Reset local variables
				Constructor->Functions[FunctionCallIndex].LocalVariables = BPConstructor->LocalVariableDefaults[FunctionCallIndex].Variables;

				Constructor->FunctionNodes[FunctionCallIndex].Nodes[0]->Execute(0);
				//Nodes[ConnectedFunctionStartIndex]->Execute(ConnectedPinStartIndex);

				OutputPins[1].Value.Array[0].SetBoolArg(true);
			}
		}
	}
	Super::Execute(0, FromLoopIndex);// 0 here is the output pins array index
}