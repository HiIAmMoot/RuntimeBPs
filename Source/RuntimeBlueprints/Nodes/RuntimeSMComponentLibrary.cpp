// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeSMComponentLibrary.h"
#include "RuntimeBpConstructor.h"

UComponents_SetStaticMesh::UComponents_SetStaticMesh()
{
	NodeName = "Set Static Mesh";
	NodeDescription = "Change the StaticMesh used by this instance.";
	NodeCategory = "Components|StaticMesh";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Static Mesh Component", EVariableTypes::StaticMeshComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetStaticMeshComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Mesh", EVariableTypes::StaticMesh);// PinName + PinType
	InputPins[2].Value.Array[0].SetStaticMeshArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_SetStaticMesh::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetStaticMeshComponentArg())
    {
         
	OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetStaticMeshComponentArg()->SetStaticMesh(GetConnectedPinValue(InputPins[2]).GetStaticMeshArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[1].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetLocalBounds::UComponents_GetLocalBounds()
{
	NodeName = "Get Local Bounds";
	NodeDescription = "Get Local bounds";
	NodeCategory = "Components|StaticMesh";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Static Mesh Component", EVariableTypes::StaticMeshComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetStaticMeshComponentArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Min", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Max", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetLocalBounds::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetStaticMeshComponentArg())
    {
         FVector Min;
	FVector Max;
	GetConnectedPinValue(InputPins[1]).GetStaticMeshComponentArg()->GetLocalBounds(Min, Max);
         
	OutputPins[1].Value.Array[0].SetVectorArg(Min);
	OutputPins[2].Value.Array[0].SetVectorArg(Max);

    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

