// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeRandomLibrary.h"
#include "RuntimeBpConstructor.h"

UDistributePointsAroundSphere::UDistributePointsAroundSphere()
{
	NodeName = "Distribute Points Around Sphere";
	NodeDescription = "Generates a set of points around a sphere";
	NodeCategory = "Geometry";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Sphere Radius", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1000.f); // Default value

	InputPins[2].MakeNodePin("Sphere Center Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Amount Of Points", EVariableTypes::Int);// PinName + PinType
	InputPins[3].Value.Array[0].SetIntArg(16); // Default value

	InputPins[4].MakeNodePin("Randomize", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodeArray("Return", EVariableTypes::Vector);// PinName + PinType
}


void UDistributePointsAroundSphere::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[1].Value.SetVectorArg(URandomBPLibrary::DistributePointsAroundSphere(GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetIntArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

