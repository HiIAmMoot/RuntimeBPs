// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Components/PrimitiveComponent.h"
#include "RuntimeCharacterLibrary.generated.h"


/**
* Cache mesh offset from capsule. This is used as the target for network smoothing interpolation, when the mesh is offset with lagged smoothing.
* This is automatically called during initialization; call this at runtime if you intend to change the default mesh offset from the capsule.
* @see GetBaseTranslationOffset(), GetBaseRotationOffset()
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_CacheInitialMeshOffset : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_CacheInitialMeshOffset();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Make the character jump on the next update.
* If you want your character to jump according to the time that the jump key is held,
* then you can set JumpKeyHoldTime to some non-zero value. Make sure in this case to
* call StopJumping() when you want the jump's z-velocity to stop being applied (such
* as on a button up event), otherwise the character will carry on receiving the
* velocity until JumpKeyHoldTime is reached.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_Jump : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_Jump();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Stop the character from jumping on the next update.
* Call this from an input event (such as a button 'up' event) to cease applying
* jump Z-velocity. If this is not called, then jump z-velocity will be applied
* until JumpMaxHoldTime is reached.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_StopJumping : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_StopJumping();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Check if the character can jump in the current state.
*
* The default implementation may be overridden or extended by implementing the custom CanJump event in Blueprints.
*
* @Return Whether the character can jump in the current state.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_CanJump : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_CanJump();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* True if jump is actively providing a force, such as when the jump key is held and the time it has been held is less than JumpMaxHoldTime.
* @see CharacterMovement->IsFalling
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_IsJumpProvidingForce : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_IsJumpProvidingForce();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set a pending launch velocity on the Character. This velocity will be processed on the next CharacterMovementComponent tick,
* and will set it to the "falling" state. Triggers the OnLaunched event.
* @PARAM LaunchVelocity is the velocity to impart to the Character
* @PARAM bXYOverride if true replace the XY part of the Character's velocity instead of adding to it.
* @PARAM bZOverride if true replace the Z component of the Character's velocity instead of adding to it.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_LaunchCharacter : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_LaunchCharacter();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Event fired when the character has just started jumping */
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_OnJumped : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_OnJumped();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Event fired when the Character is walking off a surface and is about to fall because CharacterMovement->CurrentFloor became unwalkable.
* If CharacterMovement->MovementMode does not change during this event then the character will automatically start falling afterwards.
* @note Z velocity is zero during walking movement, and will be here as well. Another velocity can be computed here if desired and will be used when starting to fall.
*
* @param  PreviousFloorImpactNormal Normal of the previous walkable floor.
* @param  PreviousFloorContactNormal Normal of the contact with the previous walkable floor.
* @param  PreviousLocation	Previous character location before movement off the ledge.
* @param  TimeTick	Time delta of movement update resulting in moving off the ledge.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_OnWalkingOffLedge : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_OnWalkingOffLedge();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Request the character to start crouching. The request is processed on the next update of the CharacterMovementComponent.
* @see OnStartCrouch
* @see IsCrouched
* @see CharacterMovement->WantsToCrouch
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_Crouch : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_Crouch();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Request the character to stop crouching. The request is processed on the next update of the CharacterMovementComponent.
* @see OnEndCrouch
* @see IsCrouched
* @see CharacterMovement->WantsToCrouch
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_UnCrouch : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_UnCrouch();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_ClientCheatWalk : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_ClientCheatWalk();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_ClientCheatFly : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_ClientCheatFly();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UCharacter_ClientCheatGhost : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCharacter_ClientCheatGhost();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};