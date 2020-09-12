// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimePawnLibrary.h"
#include "RuntimeBpConstructor.h"

UPawn_GetMovementBaseActor::UPawn_GetMovementBaseActor()
{
	NodeName = "Get Movement Base Actor";
	NodeDescription = "Gets the owning actor of the Movement Base Component on which the pawn is standing.";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[0].Value.Array[0].SetPawnArg(); // Default value

	InputPins[1].MakeNodePin("Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[1].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Actor);// PinName + PinType
}


void UPawn_GetMovementBaseActor::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPawnArg())
    {
         
	OutputPins[0].Value.Array[0].SetActorArg(GetConnectedPinValue(InputPins[0]).GetPawnArg()->GetMovementBaseActor(GetConnectedPinValue(InputPins[1]).GetPawnArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetActorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UPawn_IsControlled::UPawn_IsControlled()
{
	NodeName = "Is Controlled";
	NodeDescription = "See if this actor is currently being controlled";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[0].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}

void UPawn_IsControlled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPawnArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPawnArg()->IsPawnControlled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UPawn_GetControlRotation::UPawn_GetControlRotation()
{
	NodeName = "Get Control Rotation";
	NodeDescription = "Get the rotation of the Controller, often the 'view' rotation of this Pawn.";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[0].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UPawn_GetControlRotation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPawnArg())
    {
         
	OutputPins[0].Value.Array[0].SetRotatorArg(GetConnectedPinValue(InputPins[0]).GetPawnArg()->GetControlRotation());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetRotatorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPawn_IsLocallyControlled::UPawn_IsLocallyControlled()
{
	NodeName = "Is Locally Controlled";
	NodeDescription = "Returns true if controlled by a local (not network) Controller.";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[0].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UPawn_IsLocallyControlled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPawnArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPawnArg()->IsLocallyControlled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPawn_IsPlayerControlled::UPawn_IsPlayerControlled()
{
	NodeName = "Is Player Controlled";
	NodeDescription = "Returns true if controlled by a human player (possessed by a PlayerController).";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[0].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UPawn_IsPlayerControlled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPawnArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPawnArg()->IsPlayerControlled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPawn_IsBotControlled::UPawn_IsBotControlled()
{
	NodeName = "Is Bot Controlled";
	NodeDescription = "Returns true if controlled by a bot.";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[0].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UPawn_IsBotControlled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPawnArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPawnArg()->IsBotControlled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPawn_GetBaseAimRotation::UPawn_GetBaseAimRotation()
{
	NodeName = "Get Base Aim Rotation";
	NodeDescription = "Return the aim rotation for the Pawn.If we have a controller, by default we aim at the player's 'eyes' directionthat is by default the Pawn rotation for AI, and camera (crosshair) rotation for human players.";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[0].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UPawn_GetBaseAimRotation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPawnArg())
    {
         
	OutputPins[0].Value.Array[0].SetRotatorArg(GetConnectedPinValue(InputPins[0]).GetPawnArg()->GetBaseAimRotation());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetRotatorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPawn_DetachFromControllerPendingDestroy::UPawn_DetachFromControllerPendingDestroy()
{
	NodeName = "Detach From Controller Pending Destroy";
	NodeDescription = "Call this function to detach safely pawn from its controller, knowing that we will be destroyed soon.";
	NodeCategory = "Pawn|Delete";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[1].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UPawn_DetachFromControllerPendingDestroy::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPawnArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPawnArg()->DetachFromControllerPendingDestroy();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPawn_SpawnDefaultController::UPawn_SpawnDefaultController()
{
	NodeName = "Spawn Default Controller";
	NodeDescription = "Spawn default controller for this Pawn, and get possessed by it.";
	NodeCategory = "Pawn";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[1].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UPawn_SpawnDefaultController::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPawnArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPawnArg()->SpawnDefaultController();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

