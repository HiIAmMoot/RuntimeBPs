// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeCharacterLibrary.h"
#include "RuntimeBpConstructor.h"

UCharacter_CacheInitialMeshOffset::UCharacter_CacheInitialMeshOffset()
{
	NodeName = "Cache Initial Mesh Offset";
	NodeDescription = "Cache mesh offset from capsule. This is used as the target for network smoothing interpolation, when the mesh is offset with lagged smoothing.This is automatically called during initialization; call this at runtime if you intend to change the default mesh offset from the capsule.@see GetBaseTranslationOffset(), GetBaseRotationOffset()";
	NodeCategory = "Character";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	InputPins[2].MakeNodePin("Mesh Relative Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Mesh Relative Rotation", EVariableTypes::Rotator);// PinName + PinType
	InputPins[3].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_CacheInitialMeshOffset::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->CacheInitialMeshOffset(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetRotatorArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_Jump::UCharacter_Jump()
{
	NodeName = "Jump";
	NodeDescription = "Make the character jump on the next update.If you want your character to jump according to the time that the jump key is held,then you can set JumpKeyHoldTime to some non-zero value. Make sure in this case tocall StopJumping() when you want the jump's z-velocity to stop being applied (suchas on a button up event), otherwise the character will carry on receiving thevelocity until JumpKeyHoldTime is reached.";
	NodeCategory = "Character";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_Jump::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->Jump();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_StopJumping::UCharacter_StopJumping()
{
	NodeName = "Stop Jumping";
	NodeDescription = "Stop the character from jumping on the next update.Call this from an input event (such as a button 'up' event) to cease applyingjump Z-velocity. If this is not called, then jump z-velocity will be applieduntil JumpMaxHoldTime is reached.";
	NodeCategory = "Character";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_StopJumping::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->StopJumping();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_CanJump::UCharacter_CanJump()
{
	NodeName = "Can Jump";
	NodeDescription = "Check if the character can jump in the current state.The default implementation may be overridden or extended by implementing the custom CanJump event in Blueprints.@Return Whether the character can jump in the current state.";
	NodeCategory = "Character";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[0].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UCharacter_CanJump::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetCharacterArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetCharacterArg()->CanJump());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_IsJumpProvidingForce::UCharacter_IsJumpProvidingForce()
{
	NodeName = "Is Jump Providing Force";
	NodeDescription = "True if jump is actively providing a force, such as when the jump key is held and the time it has been held is less than JumpMaxHoldTime.@see CharacterMovement->IsFalling";
	NodeCategory = "Character";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[0].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UCharacter_IsJumpProvidingForce::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetCharacterArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetCharacterArg()->IsJumpProvidingForce());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_LaunchCharacter::UCharacter_LaunchCharacter()
{
	NodeName = "Launch Character";
	NodeDescription = "Set a pending launch velocity on the Character. This velocity will be processed on the next CharacterMovementComponent tick,and will set it to the 'falling' state. Triggers the OnLaunched event.@PARAM LaunchVelocity is the velocity to impart to the Character@PARAM bXYOverride if true replace the XY part of the Character's velocity instead of adding to it.@PARAM bZOverride if true replace the Z component of the Character's velocity instead of adding to it.";
	NodeCategory = "Character";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	InputPins[2].MakeNodePin("Launch Velocity", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b XYOverride", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	InputPins[4].MakeNodePin("b ZOverride", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_LaunchCharacter::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->LaunchCharacter(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_OnJumped::UCharacter_OnJumped()
{
	NodeName = "On Jumped";
	NodeDescription = "Event fired when the character has just started jumping";
	NodeCategory = "Character";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_OnJumped::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->OnJumped();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_OnWalkingOffLedge::UCharacter_OnWalkingOffLedge()
{
	NodeName = "On Walking Off Ledge";
	NodeDescription = "Event fired when the Character is walking off a surface and is about to fall because CharacterMovement->CurrentFloor became unwalkable.If CharacterMovement->MovementMode does not change during this event then the character will automatically start falling afterwards.@note Z velocity is zero during walking movement, and will be here as well. Another velocity can be computed here if desired and will be used when starting to fall.@param  PreviousFloorImpactNormal Normal of the previous walkable floor.@param  PreviousFloorContactNormal Normal of the contact with the previous walkable floor.@param  PreviousLocation	Previous character location before movement off the ledge.@param  TimeTick	Time delta of movement update resulting in moving off the ledge.";
	NodeCategory = "Character";
	
	InputPins.SetNum(6); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	InputPins[2].MakeNodePin("Previous Floor Impact Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Previous Floor Contact Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[3].Value.Array[0].SetVectorArg(); // Default value

	InputPins[4].MakeNodePin("Previous Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[4].Value.Array[0].SetVectorArg(); // Default value

	InputPins[5].MakeNodePin("Time Delta", EVariableTypes::Float);// PinName + PinType
	InputPins[5].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_OnWalkingOffLedge::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->OnWalkingOffLedge(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetVectorArg(), GetConnectedPinValue(InputPins[4]).GetVectorArg(), GetConnectedPinValue(InputPins[5]).GetFloatArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_Crouch::UCharacter_Crouch()
{
	NodeName = "Crouch";
	NodeDescription = "Request the character to start crouching. The request is processed on the next update of the CharacterMovementComponent.@see OnStartCrouch@see IsCrouched@see CharacterMovement->WantsToCrouch";
	NodeCategory = "Character|bClientSimulation";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	InputPins[2].MakeNodePin("b Client Simulation", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_Crouch::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->Crouch(GetConnectedPinValue(InputPins[2]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_UnCrouch::UCharacter_UnCrouch()
{
	NodeName = "Un Crouch";
	NodeDescription = "Request the character to stop crouching. The request is processed on the next update of the CharacterMovementComponent.@see OnEndCrouch@see IsCrouched@see CharacterMovement->WantsToCrouch";
	NodeCategory = "Character|bClientSimulation";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	InputPins[2].MakeNodePin("b Client Simulation", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_UnCrouch::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->UnCrouch(GetConnectedPinValue(InputPins[2]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_ClientCheatWalk::UCharacter_ClientCheatWalk()
{
	NodeName = "Client Cheat Walk";
	NodeDescription = "";
	NodeCategory = "Character";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_ClientCheatWalk::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->ClientCheatWalk();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_ClientCheatFly::UCharacter_ClientCheatFly()
{
	NodeName = "Client Cheat Fly";
	NodeDescription = "";
	NodeCategory = "Character";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_ClientCheatFly::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->ClientCheatFly();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCharacter_ClientCheatGhost::UCharacter_ClientCheatGhost()
{
	NodeName = "Client Cheat Ghost";
	NodeDescription = "";
	NodeCategory = "Character";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Character", EVariableTypes::Character);// PinName + PinType
	InputPins[1].Value.Array[0].SetCharacterArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UCharacter_ClientCheatGhost::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetCharacterArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetCharacterArg()->ClientCheatGhost();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

