// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeMeshComponentLibrary.h"
#include "RuntimeBpConstructor.h"

UComponents_GetMaterials::UComponents_GetMaterials()
{
	NodeName = "Get Materials";
	NodeDescription = "";
	NodeCategory = "Components|Mesh";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Static Mesh Component", EVariableTypes::StaticMeshComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetStaticMeshComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodeArray("Return", EVariableTypes::MaterialInterface);// PinName + PinType
}


void UComponents_GetMaterials::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg())
    {
         
	OutputPins[0].Value.SetMaterialInterfaceArg(GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg()->GetMaterials());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.SetMaterialInterfaceArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetMaterialIndex::UComponents_GetMaterialIndex()
{
	NodeName = "Get Material Index";
	NodeDescription = "";
	NodeCategory = "Components|Mesh";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Static Mesh Component", EVariableTypes::StaticMeshComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetStaticMeshComponentArg(); // Default value

	InputPins[1].MakeNodePin("Material Slot Name", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UComponents_GetMaterialIndex::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetIntArg(GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg()->GetMaterialIndex(GetConnectedPinValue(InputPins[1]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetIntArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetMaterialSlotNames::UComponents_GetMaterialSlotNames()
{
	NodeName = "Get Material Slot Names";
	NodeDescription = "";
	NodeCategory = "Components|Mesh";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Static Mesh Component", EVariableTypes::StaticMeshComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetStaticMeshComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodeArray("Return", EVariableTypes::Name);// PinName + PinType
}


void UComponents_GetMaterialSlotNames::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg())
    {
         
	OutputPins[0].Value.SetNameArg(GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg()->GetMaterialSlotNames());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.SetNameArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_IsMaterialSlotNameValid::UComponents_IsMaterialSlotNameValid()
{
	NodeName = "Is Material Slot Name Valid";
	NodeDescription = "";
	NodeCategory = "Components|Mesh";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Static Mesh Component", EVariableTypes::StaticMeshComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetStaticMeshComponentArg(); // Default value

	InputPins[1].MakeNodePin("Material Slot Name", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_IsMaterialSlotNameValid::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetStaticMeshComponentArg()->IsMaterialSlotNameValid(GetConnectedPinValue(InputPins[1]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

