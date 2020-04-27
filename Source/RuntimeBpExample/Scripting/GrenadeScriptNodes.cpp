// Fill out your copyright notice in the Description page of Project Settings.

#include "GrenadeScriptNodes.h"

/**
* Called when an explosion starts
*/
UGrenadeExplode::UGrenadeExplode()
{
	NodeName = "On Grenade Explosion";
	NodeDescription = "Called when this grenade explodes";
	NodeCategory = "Start";

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Grenade", EVariableTypes::Grenade);
	OutputPins[2].MakeNodePin("Instigator", EVariableTypes::Actor);
	OutputPins[3].MakeNodePin("Transform", EVariableTypes::Transform);

}

void UGrenadeExplode::ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	// Register this node in the constructor
	if (ConstructorClass)
	{
		Cast<UGrenadeScript>(ConstructorClass)->GrenadeExplosionNode = this;
	}

	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);
}
