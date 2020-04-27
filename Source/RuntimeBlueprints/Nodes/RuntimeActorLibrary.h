// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "GameFramework/Actor.h"
#include "RuntimeActorLibrary.generated.h"

/**
* Get the actor-to-world transform.
* @return The transform that transforms from actor space to world space.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the location of the RootComponent of this Actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_GetActorLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_GetActorLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns rotation of the RootComponent of this Actor. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_GetActorRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_GetActorRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the forward (X) vector (length 1.0) from this Actor, in world space.  */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorForwardVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorForwardVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the up (Z) vector (length 1.0) from this Actor, in world space.  */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorUpVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorUpVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the right (Y) vector (length 1.0) from this Actor, in world space.  */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorRightVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorRightVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the bounding box of all components that make up this Actor (excluding ChildActorComponents).
* @param	bOnlyCollidingComponents	If true, will only return the bounding box for components with collision enabled.
* @param	Origin						Set to the center of the actor in world space
* @param	BoxExtent					Set to half the actor's size in 3d space
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorBounds : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorBounds();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the RootComponent of this Actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_GetRootComponent : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_GetRootComponent();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns velocity (in cm/s (Unreal Units/second) of the rootcomponent if it is either using physics or has an associated MovementComponent */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetVelocity : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetVelocity();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set the Actor's rotation instantly to the specified rotation.
*
* @param	NewRotation	The new rotation for the Actor.
* @param	bTeleportPhysics Whether we teleport the physics state (if physics collision is enabled for this object).
*			If true, physics velocity for this object is unchanged (so ragdoll parts are not affected by change in location).
*			If false, physics velocity is updated based on the change in position (affecting ragdoll parts).
* @return	Whether the rotation was successfully set.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_SetActorRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_SetActorRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Set the Actor's world-space scale. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetActorScale3D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetActorScale3D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the Actor's world-space scale. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorScale3D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorScale3D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the distance from this Actor to OtherActor. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetDistanceTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetDistanceTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the squared distance from this Actor to OtherActor. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetSquaredDistanceTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetSquaredDistanceTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the distance from this Actor to OtherActor, ignoring Z. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetHorizontalDistanceTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetHorizontalDistanceTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the distance from this Actor to OtherActor, ignoring XY. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetVerticalDistanceTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetVerticalDistanceTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the dot product from this Actor to OtherActor. Returns -2.0 on failure. Returns 0.0 for coincidental actors. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetDotProductTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetDotProductTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the dot product from this Actor to OtherActor, ignoring Z. Returns -2.0 on failure. Returns 0.0 for coincidental actors. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetHorizontalDotProductTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetHorizontalDotProductTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set the actor's RootComponent to the specified relative scale 3d
* @param NewRelativeScale	New scale to set the actor's RootComponent to
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetActorRelativeScale3D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetActorRelativeScale3D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Return the actor's relative scale 3d */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorRelativeScale3D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorRelativeScale3D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Allows enabling/disabling collision for the whole actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetActorEnableCollision : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetActorEnableCollision();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get current state of collision for the whole actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorEnableCollision : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorEnableCollision();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Destroy the actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_DestroyActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_DestroyActor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** See if this actor's Tags array contains the supplied name tag */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_ActorHasTag : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_ActorHasTag();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get ActorTimeDilation - this can be used for input control or speed control for slomo.
* We don't want to scale input globally because input can be used for UI, which do not care for TimeDilation.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorTimeDilation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorTimeDilation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Gets whether this actor can tick when paused. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetTickableWhenPaused : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetTickableWhenPaused();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Sets whether this actor can tick when paused. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetTickableWhenPaused : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetTickableWhenPaused();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** The number of seconds (in game time) since this Actor was created, relative to Get Game Time In Seconds. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetGameTimeSinceCreation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetGameTimeSinceCreation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Set the lifespan of this actor. When it expires the object will be destroyed. If requested lifespan is 0, the timer is cleared and the actor will not be destroyed. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetLifeSpan : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetLifeSpan();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the remaining lifespan of this actor. If zero is returned the actor lives forever. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetLifeSpan : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetLifeSpan();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set this actor's tick functions to be enabled or disabled. Only has an effect if the function is registered
* This only modifies the tick function on actor itself
* @param	bEnabled	Whether it should be enabled or not
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetActorTickEnabled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetActorTickEnabled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**  Returns whether this actor has tick enabled or not	 */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_IsActorTickEnabled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_IsActorTickEnabled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Sets the tick interval of this actor's primary tick function. Will not enable a disabled tick function. Takes effect on next tick.
* @param TickInterval	The rate at which this actor should be ticking
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetActorTickInterval : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetActorTickInterval();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**  Returns the tick interval of this actor's primary tick function */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorTickInterval : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorTickInterval();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set the owner of this Actor, used primarily for network replication.
* @param NewOwner	The Actor whom takes over ownership of this Actor
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_SetOwner : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_SetOwner();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the owner of this Actor, used primarily for network replication. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetOwner : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetOwner();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Check whether any component of this Actor is overlapping any component of another Actor.
* @param Other The other Actor to test against
* @return Whether any component of this Actor is overlapping any component of another Actor.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_IsOverlappingActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_IsOverlappingActor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns whether this Actor was spawned by a child actor component */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_IsChildActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_IsChildActor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a list of all actors spawned by our Child Actor Components, including children of children.
* This does not return the contents of the Children array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetAllChildActors : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetAllChildActors();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If this Actor was created by a Child Actor Component returns the Actor that owns that Child Actor Component  */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetParentActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetParentActor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Teleport this actor to a new location. If the actor doesn't fit exactly at the location specified, tries to slightly move it out of walls and such.
*
* @param DestLocation The target destination point
* @param DestRotation The target rotation at the destination
* @return true if the actor has been successfully moved, or false if it couldn't fit.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_TeleportTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_TeleportTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Walk up the attachment chain from RootComponent until we encounter a different actor, and return it. If we are not attached to a component in a different actor, returns nullptr */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetAttachParentActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetAttachParentActor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Walk up the attachment chain from RootComponent until we encounter a different actor, and return the socket name in the component. If we are not attached to a component in a different actor, returns NAME_None */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetAttachParentSocketName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetAttachParentSocketName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find all Actors which are attached directly to a component in this actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetAttachedActors : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetAttachedActors();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the point of view of the actor.
* Note that this doesn't mean the camera, but the 'eyes' of the actor.
* For example, for a Pawn, this would define the eye height location,
* and view rotation (which is different from the pawn rotation which has a zeroed pitch component).
* A camera first person view will typically use this view point. Most traces (weapon, AI) will be done from this view point.
*
* @param	OutLocation - location of view point
* @param	OutRotation - view rotation of actor.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_GetActorEyesViewPoint : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_GetActorEyesViewPoint();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_SetActorLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_SetActorLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set the actor's RootComponent to the specified relative location.
* @param NewRelativeLocation	New relative location of the actor's root component
* @param bSweep					Whether we sweep to the destination location, triggering overlaps along the way and stopping short of the target if blocked by something.
*								Only the root component is swept and checked for blocking collision, child components move without sweeping. If collision is off, this has no effect.
* @param bTeleport				Whether we teleport the physics state (if physics collision is enabled for this object).
*								If true, physics velocity for this object is unchanged (so ragdoll parts are not affected by change in location).
*								If false, physics velocity is updated based on the change in position (affecting ragdoll parts).
*								If CCD is on and not teleporting, this will affect objects along the entire swept volume.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_SetActorRelativeLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_SetActorRelativeLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the relative location of the RootComponent of this Actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_GetActorRelativeLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_GetActorRelativeLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set the actor's RootComponent to the specified relative rotation.
* @param NewRelativeRotation	New relative rotation of the actor's root component.
* @param bSweep					Whether we sweep to the destination location, triggering overlaps along the way and stopping short of the target if blocked by something.
*								Only the root component is swept and checked for blocking collision, child components move without sweeping. If collision is off, this has no effect.
* @param bTeleport				Whether we teleport the physics state (if physics collision is enabled for this object).
*								If true, physics velocity for this object is unchanged (so ragdoll parts are not affected by change in location).
*								If false, physics velocity is updated based on the change in position (affecting ragdoll parts).
*								If CCD is on and not teleporting, this will affect objects along the entire swept volume.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_SetActorRelativeRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_SetActorRelativeRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the relative location of the RootComponent of this Actor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UActor_K2_GetActorRelativeRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UActor_K2_GetActorRelativeRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Attaches the RootComponent of this Actor to the supplied component, optionally at a named socket. It is not valid to call this on components that are not Registered.
* @param ParentActor				Actor to attach this actor's RootComponent to.
* @param SocketName					Socket name to attach to, if any.
* @param LocationRule				How to handle translation when attaching.
* @param RotationRule				How to handle rotation when attaching.
* @param ScaleRule					How to handle scale when attaching.
* @param bWeldSimulatedBodies		Whether to weld together simulated physics bodies.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UAttachActorToActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAttachActorToActor();

protected:
	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};