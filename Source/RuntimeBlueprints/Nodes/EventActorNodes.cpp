// Fill out your copyright notice in the Description page of Project Settings.

#include "EventActorNodes.h"
#include "RuntimeBpConstructor.h"

/**
* Called when this script ceases to exist
*/
UEndPlay::UEndPlay()
{
	NodeName = "End Play";
	NodeDescription = "Called when this script ceases to exist";
	NodeCategory = "Events";

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("End Play Reason", EVariableTypes::Byte);
	OutputPins[1].Value.Array[0].SetByteArg(); // Default Value
	OutputPins[1].Meta = "EEndPlayReason"; // Enum data
}

void UEndPlay::ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	// Register this EndPlay node in the constructor
	if (ConstructorClass)
	{
		ConstructorClass->EndPlayNode = this;
	}

	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);
}

/**
* Called when this actor takes ANY damage
*/
UOnTakeAnyDamage::UOnTakeAnyDamage()
{
	NodeName = "Any Damage";
	NodeDescription = "Called when the actor that owns this script takes ANY damage";
	NodeCategory = "Events";

	OutputPins.SetNum(6);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Damaged Actor", EVariableTypes::Actor);
	OutputPins[1].Value.Array[0].SetActorArg(); // Default Value
	OutputPins[2].MakeNodePin("Damage", EVariableTypes::Float);
	OutputPins[2].Value.Array[0].SetFloatArg(); // Default Value
	OutputPins[3].MakeNodePin("Damage Type", EVariableTypes::DamageType);
	OutputPins[3].Value.Array[0].SetDamageTypeArg(); // Default Value
	OutputPins[4].MakeNodePin("Damage Instigator", EVariableTypes::PlayerController);
	OutputPins[4].Value.Array[0].SetPlayerControllerArg(); // Default Value
	OutputPins[5].MakeNodePin("Damage Causer", EVariableTypes::Actor);
	OutputPins[5].Value.Array[0].SetActorArg(); // Default Value
}

void UOnTakeAnyDamage::ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	// Register this TakeAnyDamage node in the constructor
	if (ConstructorClass)
	{
		ConstructorClass->TakeAnyDamageNode = this;
	}

	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);
}

/**
 *	Event when the actor that owns this script overlaps another actor, for example a player walking into a trigger.
 *	For events when objects have a blocking collision, for example a player hitting a wall, see 'Hit' events.
 *	@note Components on both this and the other Actor must have bGenerateOverlapEvents set to true to generate overlap events.
 */
UOnActorBeginOverlap::UOnActorBeginOverlap()
{
	NodeName = "Actor Begin Overlap";
	NodeDescription = "Event when the actor that owns this script overlaps another actor, for example a player walking into a trigger."
					"For events when objects have a blocking collision, for example a player hitting a wall, see 'Hit' events."
					"@note Components on both this and the other Actor must have bGenerateOverlapEvents set to true to generate overlap events.";
	NodeCategory = "Events";

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Overlapped Actor", EVariableTypes::Actor);
	OutputPins[1].Value.Array[0].SetActorArg(); // Default Value
	OutputPins[2].MakeNodePin("Other Actor", EVariableTypes::Actor);
	OutputPins[2].Value.Array[0].SetActorArg(); // Default Value
}

void UOnActorBeginOverlap::ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	// Register this ActorBeginOverlap node in the constructor
	if (ConstructorClass)
	{
		ConstructorClass->ActorBeginOverlapNode = this;
	}

	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);
}

/**
 *	Event when an actor no longer overlaps another actor, and they have separated.
 *	@note Components on both this and the other Actor must have bGenerateOverlapEvents set to true to generate overlap events.
 */
UOnActorEndOverlap::UOnActorEndOverlap()
{
	NodeName = "Actor End Overlap";
	NodeDescription = "Event when the actor that owns this script no longer overlaps another actor, and they have separated."
					"@note Components on both this and the other Actor must have bGenerateOverlapEvents set to true to generate overlap events.";
	NodeCategory = "Events";

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Overlapped Actor", EVariableTypes::Actor);
	OutputPins[1].Value.Array[0].SetActorArg(); // Default Value
	OutputPins[2].MakeNodePin("Other Actor", EVariableTypes::Actor);
	OutputPins[2].Value.Array[0].SetActorArg(); // Default Value
}

void UOnActorEndOverlap::ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	// Register this ActorEndOverlap node in the constructor
	if (ConstructorClass)
	{
		ConstructorClass->ActorEndOverlapNode = this;
	}

	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);
}

/**
 * Event when this actor bumps into a blocking object, or blocks another actor that bumps into it.
 * This could happen due to things like Character movement, using Set Location with 'sweep' enabled, or physics simulation.
 * For events when objects overlap (e.g. walking into a trigger) see the 'Overlap' event.
 *
 * @note For collisions during physics simulation to generate hit events, 'Simulation Generates Hit Events' must be enabled.
 * @note When receiving a hit from another object's movement (bSelfMoved is false), the directions of 'Hit.Normal' and 'Hit.ImpactNormal'
 * will be adjusted to indicate force from the other object against this object.
 * @note NormalImpulse will be filled in for physics-simulating bodies, but will be zero for swept-component blocking collisions.
 */
UOnActorHit::UOnActorHit()
{
	NodeName = "Actor Hit";
	NodeDescription = "Event when this actor bumps into a blocking object, or blocks another actor that bumps into it."
					"This could happen due to things like Character movement, using Set Location with 'sweep' enabled, or physics simulation."
					"For events when objects overlap(e.g.walking into a trigger) see the 'Overlap' event."
					""
					"@note For collisions during physics simulation to generate hit events, 'Simulation Generates Hit Events' must be enabled."
					"@note When receiving a hit from another object's movement (bSelfMoved is false), the directions of 'Hit.Normal' and 'Hit.ImpactNormal'"
					"will be adjusted to indicate force from the other object against this object."
					"@note NormalImpulse will be filled in for physics - simulating bodies, but will be zero for swept - component blocking collisions.";
	NodeCategory = "Events";

	OutputPins.SetNum(5);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Self Actor", EVariableTypes::Actor);
	OutputPins[1].Value.Array[0].SetActorArg(); // Default Value
	OutputPins[2].MakeNodePin("Other Actor", EVariableTypes::Actor);
	OutputPins[2].Value.Array[0].SetActorArg(); // Default Value
	OutputPins[3].MakeNodePin("Normal Impulse", EVariableTypes::Vector);
	OutputPins[3].Value.Array[0].SetVectorArg(); // Default Value
	OutputPins[4].MakeNodePin("Hit", EVariableTypes::HitResult);
	OutputPins[4].Value.Array[0].SetHitResultArg(); // Default Value
}

void UOnActorHit::ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	// Register this ActorHit node in the constructor
	if (ConstructorClass)
	{
		ConstructorClass->ActorHitNode = this;
	}

	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);
}