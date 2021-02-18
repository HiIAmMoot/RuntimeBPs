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
	
	bool res = IsValid(Actor) && IsValid(Actor->GetComponentByClass(URuntimeBpConstructor::StaticClass()));
	OutputPins[1].Value.Array[0].SetBoolArg(res);

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

	InputPins.SetNum(4);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Script", EVariableTypes::String);
	InputPins[1].Value.Array[0].SetStringArg(); // Default value
	InputPins[1].Meta = "Script";
	InputPins[2].MakeNodePin("Actor Containing Script", EVariableTypes::Actor);
	InputPins[2].Value.Array[0].SetActorArg(); // Default value
	InputPins[3].MakeNodePin("Add script if invalid", EVariableTypes::Bool);
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Success", EVariableTypes::Bool);

	NodeType = ENodeType::ExternalFunction;
}

void UCallFunctionFromScript::Execute(int Index, int FromLoopIndex)
{
	StoredFromLoopIndex = FromLoopIndex;
	OutputPins[1].Value.Array[0].SetBoolArg(false);

	AActor* Actor = GetConnectedPinValue(InputPins[2]).GetActorArg();
	if (Actor)
	{
		// The script this node is supposed to call is stored inside the Connected Node Index of the input pin
		int ReferenceIndex = InputPins[0].ConnectedNodeIndex;
		Constructor = Cast<URuntimeBpConstructor>(Actor->GetComponentByClass(URuntimeBpConstructor::StaticClass()));
		// The function name is the string value of the pin, reason why we use save the function name instead of the function index is because the function indices can change more easy over time.
		FString FunctionName = GetConnectedPinValue(InputPins[1]).GetStringArg();
		FString ScriptName = "";
		if (BPConstructor->ScriptReferences.IsValidIndex(ReferenceIndex))
		{
			ScriptName = BPConstructor->ScriptReferences[ReferenceIndex];
		}

		if (ScriptName == "" || FunctionName == "")
		{
			Super::Execute(0, FromLoopIndex);// 0 here is the output pins array index
			return;
		}

		if (!Constructor && GetConnectedPinValue(InputPins[3]).GetBoolArg())
		{
			if (BPConstructor->GetMultiThread())
			{
				Continue = false;

				// We must execute the component creation inside the GameThread, a crash will occur otherwise
				AsyncTask(ENamedThreads::GameThread, [this, Actor, ScriptName, FromLoopIndex]()
				{
					Constructor = NewObject<URuntimeBpConstructor>(Actor);
					Constructor->RegisterComponent();
					Constructor->InitScriptFromSave(ScriptName, true);
					Continue = true;

					//URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
				});

				// We must wait until Constructor is valid.
				while (!Continue)
				{}

			}
			else
			{
				Constructor = NewObject<URuntimeBpConstructor>(Actor);
				Constructor->RegisterComponent();
				Constructor->InitScriptFromSave(ScriptName, false);
			}
		}

		if (Constructor && Constructor->JsonFile == ScriptName)
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
				//InputPins must be shortened
				TArray<FPinStruct> CalledInputs = InputPins;
				CalledInputs.RemoveAt(1, 3, true); // remove the input pins 1, 2 & 3 when updating the output as to not input the external function call pins
				Constructor->FunctionNodes[FunctionCallIndex].Nodes[0]->UpdateCustomOutput(this, CalledInputs);
				
				// Restore retrieved values back to InputPins
				int i2 = 3;
				for (FPinStruct& Pin : CalledInputs)
				{
					// We skip the first iteration of Called Inputs because it's an exec
					if (i2 > 3)
					{
						InputPins[i2] = Pin;
					}
					
				}

				// Reset any values first
				for (URuntimeBpObject* Node : Constructor->FunctionNodes[FunctionCallIndex].Nodes)
				{
					Node->ResetInternalFunctionValues();
				}

				// Reset local variables
				Constructor->Functions[FunctionCallIndex].LocalVariables = Constructor->LocalVariableDefaults[FunctionCallIndex].Variables;
				OutputPins[1].Value.Array[0].SetBoolArg(true);
				Constructor->FunctionNodes[FunctionCallIndex].Nodes[0]->Execute(0);
				//Nodes[ConnectedFunctionStartIndex]->Execute(ConnectedPinStartIndex);
				return;
			}
		}
	}
	Super::Execute(0, FromLoopIndex);// 0 here is the output pins array index
}

void UCallFunctionFromScript::Then(int Index, int FromLoopIndex)
{
	Super::Then(Index, StoredFromLoopIndex);
}

void UCallFunctionFromScript::UpdateCustomOutput(URuntimeBpObject* CalledFrom, TArray<FPinStruct>& Pins, int StartIndex) // Start index is 2 to skip the exec and the success pin
{
	if (CalledFrom)
	{
		for (int i = StartIndex; i < OutputPins.Num(); i++)
		{
			// Skip the first 2 output pins
			if (i > 1)
			{
				// We do - 1 because the external function call output params are shifted 1 index forward because of the Success output parameter
				OutputPins[i].Value = CalledFrom->GetConnectedPinArray(Pins[i - 1]);
			}
		}
	}
}

void UCallFunctionFromScript::ResetCustomOutput(int StartIndex) // Start index is 2 to skip the exec and the success pin
{
	Super::ResetCustomOutput();
	/*for (int i = StartIndex; i < OutputPins.Num(); i++)
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
	}*/
}