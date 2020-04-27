// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Components/PrimitiveComponent.h"
#include "RuntimePawnLibrary.generated.h"


/** Gets the owning actor of the Movement Base Component on which the pawn is standing. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_GetMovementBaseActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_GetMovementBaseActor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** See if this actor is currently being controlled */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_IsControlled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_IsControlled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the rotation of the Controller, often the 'view' rotation of this Pawn. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_GetControlRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_GetControlRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if controlled by a local (not network) Controller.	 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_IsLocallyControlled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_IsLocallyControlled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if controlled by a human player (possessed by a PlayerController).	 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_IsPlayerControlled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_IsPlayerControlled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if controlled by a bot.	 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_IsBotControlled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_IsBotControlled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Return the aim rotation for the Pawn.
* If we have a controller, by default we aim at the player's 'eyes' direction
* that is by default the Pawn rotation for AI, and camera (crosshair) rotation for human players.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_GetBaseAimRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_GetBaseAimRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Call this function to detach safely pawn from its controller, knowing that we will be destroyed soon.	 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_DetachFromControllerPendingDestroy : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_DetachFromControllerPendingDestroy();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Spawn default controller for this Pawn, and get possessed by it. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPawn_SpawnDefaultController : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPawn_SpawnDefaultController();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};