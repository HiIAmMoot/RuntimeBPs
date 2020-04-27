// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Components/PrimitiveComponent.h"
#include "RuntimePrimitiveComponentLibrary.generated.h"


/**
* If true, this component will generate overlap events when it is overlapping other components (eg Begin Overlap).
* Both components (this and the other) must have this enabled for overlap events to occur.
*
* @see [Overlap Events](https:// Docs.unrealengine.com/latest/INT/Engine/Physics/Collision/index.html#overlapandgenerateoverlapevents)
* @see UpdateOverlaps(), BeginComponentOverlap(), EndComponentOverlap()
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetGenerateOverlapEvents : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetGenerateOverlapEvents();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Modifies value returned by GetGenerateOverlapEvents() */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetGenerateOverlapEvents : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetGenerateOverlapEvents();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tells this component whether to ignore collision with all components of a specific Actor when this component is moved.
* Components on the other Actor may also need to be told to do the same when they move.
* Does not affect movement of this component when simulating physics.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_IgnoreActorWhenMoving : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_IgnoreActorWhenMoving();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tells this component whether to ignore collision with another component when this component is moved.
* The other components may also need to be told to do the same when they move.
* Does not affect movement of this component when simulating physics.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_IgnoreComponentWhenMoving : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_IgnoreComponentWhenMoving();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Check whether this component is overlapping another component.
* @param OtherComp Component to test this component against.
* @return Whether this component is overlapping another component.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_IsOverlappingComponent : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_IsOverlappingComponent();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Check whether this component is overlapping any component of the given Actor.
* @param Other Actor to test this component against.
* @return Whether this component is overlapping any component of the given Actor.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_IsOverlappingActor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_IsOverlappingActor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a list of actors that this component is overlapping.
* @param OverlappingActors		[out] Returned list of overlapping actors
* @param ClassFilter			[optional] If set, only returns actors of this class or subclasses
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetOverlappingActors : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetOverlappingActors();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns unique list of components this component is overlapping. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetOverlappingComponents : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetOverlappingComponents();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Try and retrieve the material applied to a particular collision face of mesh. Used with face index returned from collision trace.
*	@param	FaceIndex		Face index from hit result that was hit by a trace
*	@param	SectionIndex	Section of the mesh that the face belongs to
*	@return					Material applied to section that the hit face belongs to
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetMaterialFromCollisionFaceIndex : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetMaterialFromCollisionFaceIndex();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Sets whether or not a single body should use physics simulation, or should be 'fixed' (kinematic).
*	Note that if this component is currently attached to something, beginning simulation will detach it.
*
*	@param	bSimulate	New simulation state for single body
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetSimulatePhysics : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetSimulatePhysics();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add an impulse to a single rigid body. Good for one time instant burst.
*
*	@param	Impulse		Magnitude and direction of impulse to apply.
*	@param	BoneName	If a SkeletalMeshComponent, name of body to apply impulse to. 'None' indicates root body.
*	@param	bVelChange	If true, the Strength is taken as a change in velocity instead of an impulse (ie. mass will have no effect).
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddImpulse : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddImpulse();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add an angular impulse to a single rigid body. Good for one time instant burst.
*
*	@param	AngularImpulse	Magnitude and direction of impulse to apply. Direction is axis of rotation.
*	@param	BoneName	If a SkeletalMeshComponent, name of body to apply angular impulse to. 'None' indicates root body.
*	@param	bVelChange	If true, the Strength is taken as a change in angular velocity instead of an impulse (ie. mass will have no effect).
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddAngularImpulseInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddAngularImpulseInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add an angular impulse to a single rigid body. Good for one time instant burst.
*
*	@param	AngularImpulse	Magnitude and direction of impulse to apply. Direction is axis of rotation.
*	@param	BoneName	If a SkeletalMeshComponent, name of body to apply angular impulse to. 'None' indicates root body.
*	@param	bVelChange	If true, the Strength is taken as a change in angular velocity instead of an impulse (ie. mass will have no effect).
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddAngularImpulseInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddAngularImpulseInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add an impulse to a single rigid body at a specific location.
*
*	@param	Impulse		Magnitude and direction of impulse to apply.
*	@param	Location	Point in world space to apply impulse at.
*	@param	BoneName	If a SkeletalMeshComponent, name of bone to apply impulse to. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddImpulseAtLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddImpulseAtLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add a force to a single rigid body.
*  This is like a 'thruster'. Good for adding a burst over some (non zero) time. Should be called every frame for the duration of the force.
*
*	@param	Force		 Force vector to apply. Magnitude indicates strength of force.
*	@param	BoneName	 If a SkeletalMeshComponent, name of body to apply force to. 'None' indicates root body.
*  @param  bAccelChange If true, Force is taken as a change in acceleration instead of a physical force (i.e. mass will have no effect).
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddForce : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddForce();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add a force to a single rigid body at a particular location in world space.
*  This is like a 'thruster'. Good for adding a burst over some (non zero) time. Should be called every frame for the duration of the force.
*
*	@param Force		Force vector to apply. Magnitude indicates strength of force.
*	@param Location		Location to apply force, in world space.
*	@param BoneName		If a SkeletalMeshComponent, name of body to apply force to. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddForceAtLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddForceAtLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add a force to a single rigid body at a particular location. Both Force and Location should be in body space.
*  This is like a 'thruster'. Good for adding a burst over some (non zero) time. Should be called every frame for the duration of the force.
*
*	@param Force		Force vector to apply. Magnitude indicates strength of force.
*	@param Location		Location to apply force, in component space.
*	@param BoneName		If a SkeletalMeshComponent, name of body to apply force to. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddForceAtLocationLocal : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddForceAtLocationLocal();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add a torque to a single rigid body.
*	@param Torque		Torque to apply. Direction is axis of rotation and magnitude is strength of torque.
*	@param BoneName		If a SkeletalMeshComponent, name of body to apply torque to. 'None' indicates root body.
*  @param bAccelChange If true, Torque is taken as a change in angular acceleration instead of a physical torque (i.e. mass will have no effect).
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddTorqueInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddTorqueInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Add a torque to a single rigid body.
*	@param Torque		Torque to apply. Direction is axis of rotation and magnitude is strength of torque.
*	@param BoneName		If a SkeletalMeshComponent, name of body to apply torque to. 'None' indicates root body.
*	@param bAccelChange If true, Torque is taken as a change in angular acceleration instead of a physical torque (i.e. mass will have no effect).
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_AddTorqueInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_AddTorqueInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the linear velocity of a single body.
*	This should be used cautiously - it may be better to use AddForce or AddImpulse.
*
*	@param NewVel			New linear velocity to apply to physics.
*	@param bAddToCurrent	If true, NewVel is added to the existing velocity of the body.
*	@param BoneName			If a SkeletalMeshComponent, name of body to modify velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetPhysicsLinearVelocity : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetPhysicsLinearVelocity();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Get the linear velocity of a single body.
*	@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetPhysicsLinearVelocity : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetPhysicsLinearVelocity();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Get the linear velocity of a point on a single body.
*	@param Point			Point is specified in world space.
*	@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetPhysicsLinearVelocityAtPoint : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetPhysicsLinearVelocityAtPoint();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the linear velocity of all bodies in this component.
*
*	@param NewVel			New linear velocity to apply to physics.
*	@param bAddToCurrent	If true, NewVel is added to the existing velocity of the body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetAllPhysicsLinearVelocity : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetAllPhysicsLinearVelocity();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the angular velocity of a single body.
*	This should be used cautiously - it may be better to use AddTorque or AddImpulse.
*
*	@param NewAngVel		New angular velocity to apply to body, in radians per second.
*	@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of the body.
*	@param BoneName			If a SkeletalMeshComponent, name of body to modify angular velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetPhysicsAngularVelocityInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetPhysicsAngularVelocityInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the angular velocity of a single body.
*	This should be used cautiously - it may be better to use AddTorque or AddImpulse.
*
*	@param NewAngVel		New angular velocity to apply to body, in degrees per second.
*	@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of the body.
*	@param BoneName			If a SkeletalMeshComponent, name of body to modify angular velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetPhysicsAngularVelocityInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetPhysicsAngularVelocityInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the maximum angular velocity of a single body.
*
*	@param NewMaxAngVel		New maximum angular velocity to apply to body, in degrees per second.
*	@param bAddToCurrent	If true, NewMaxAngVel is added to the existing maximum angular velocity of the body.
*	@param BoneName			If a SkeletalMeshComponent, name of body to modify maximum angular velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetPhysicsMaxAngularVelocityInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetPhysicsMaxAngularVelocityInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the maximum angular velocity of a single body.
*
*	@param NewMaxAngVel		New maximum angular velocity to apply to body, in radians per second.
*	@param bAddToCurrent	If true, NewMaxAngVel is added to the existing maximum angular velocity of the body.
*	@param BoneName			If a SkeletalMeshComponent, name of body to modify maximum angular velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetPhysicsMaxAngularVelocityInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetPhysicsMaxAngularVelocityInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Get the angular velocity of a single body, in degrees per second.
*	@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetPhysicsAngularVelocityInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetPhysicsAngularVelocityInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Get the angular velocity of a single body, in radians per second.
*	@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetPhysicsAngularVelocityInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetPhysicsAngularVelocityInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Get the center of mass of a single body. In the case of a welded body this will return the center of mass of the entire welded body (including its parent and children)
*   Objects that are not simulated return (0,0,0) as they do not have COM
*	@param BoneName			If a SkeletalMeshComponent, name of body to get center of mass of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetCenterOfMass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetCenterOfMass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the center of mass of a single body. This will offset the physx-calculated center of mass.
*	Note that in the case where multiple bodies are attached together, the center of mass will be set for the entire group.
*	@param CenterOfMassOffset		User specified offset for the center of mass of this object, from the calculated location.
*	@param BoneName			If a SkeletalMeshComponent, name of body to set center of mass of. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetCenterOfMass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetCenterOfMass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	'Wake' physics simulation for a single body.
*	@param	BoneName	If a SkeletalMeshComponent, name of body to wake. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_WakeRigidBody : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_WakeRigidBody();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Force a single body back to sleep.
*	@param	BoneName	If a SkeletalMeshComponent, name of body to put to sleep. 'None' indicates root body.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_PutRigidBodyToSleep : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_PutRigidBodyToSleep();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Changes the value of bNotifyRigidBodyCollision */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetNotifyRigidBodyCollision : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetNotifyRigidBodyCollision();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Set Collision Profile Name
* This function is called by constructors when they set ProfileName
* This will change current CollisionProfileName to be this, and overwrite Collision Setting
*
* @param InCollisionProfileName : New Profile Name
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetCollisionProfileName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetCollisionProfileName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the collision profile name */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetCollisionProfileName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetCollisionProfileName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the distance and closest point to the collision surface.
* Component must have simple collision to be queried for closest point.
*
* @param Point				World 3D vector
* @param OutPointOnBody		Point on the surface of collision closest to Point
* @param BoneName			If a SkeletalMeshComponent, name of body to set center of mass of. 'None' indicates root body.
*
* @return		Success if returns > 0.f, if returns 0.f, it is either not convex or inside of the point
*				If returns < 0.f, this primitive does not have collsion
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetClosestPointOnCollision : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetClosestPointOnCollision();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Utility to see if there is any form of collision (query or physics) enabled on this component. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_K2_IsCollisionEnabled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_K2_IsCollisionEnabled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Utility to see if there is any query collision enabled on this component. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_K2_IsQueryCollisionEnabled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_K2_IsQueryCollisionEnabled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Utility to see if there is any physics collision enabled on this component. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_K2_IsPhysicsCollisionEnabled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_K2_IsPhysicsCollisionEnabled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the angular velocity of all bodies in this component.
*
*	@param NewAngVel		New angular velocity to apply to physics, in degrees per second.
*	@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of all bodies.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetAllPhysicsAngularVelocityInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetAllPhysicsAngularVelocityInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Set the angular velocity of all bodies in this component.
*
*	@param NewAngVel		New angular velocity to apply to physics, in radians per second.
*	@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of all bodies.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetAllPhysicsAngularVelocityInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetAllPhysicsAngularVelocityInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Ensure simulation is running for all bodies in this component.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_WakeAllRigidBodies : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_WakeAllRigidBodies();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Enables/disables whether this component is affected by gravity. This applies only to components with bSimulatePhysics set to true. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetEnableGravity : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetEnableGravity();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns whether this component is affected by gravity. Returns always false if the component is not simulated. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_IsGravityEnabled : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_IsGravityEnabled();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Sets the linear damping of this component. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetLinearDamping : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetLinearDamping();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the linear damping of this component. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetLinearDamping : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetLinearDamping();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Sets the angular damping of this component. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetAngularDamping : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetAngularDamping();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the angular damping of this component. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetAngularDamping : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetAngularDamping();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Change the mass scale used to calculate the mass of a single physics body */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetMassScale : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetMassScale();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the mass scale used to calculate the mass of a single physics body */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetMassScale : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetMassScale();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Change the mass scale used fo all bodies in this component */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetAllMassScale : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetAllMassScale();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Override the mass (in Kg) of a single physics body.
*	Note that in the case where multiple bodies are attached together, the override mass will be set for the entire group.
*	Set the Override Mass to false if you want to reset the body's mass to the auto-calculated physx mass.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetMassOverrideInKg : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetMassOverrideInKg();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the mass of this component in kg. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetMass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetMass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inertia tensor of this component in kg cm^2. The inertia tensor is in local component space.*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_GetInertiaTensor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_GetInertiaTensor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Scales the given vector by the world space moment of inertia. Useful for computing the torque needed to rotate an object.*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_ScaleByMomentOfInertia : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_ScaleByMomentOfInertia();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Returns if any body in this component is currently awake and simulating.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_IsAnyRigidBodyAwake : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_IsAnyRigidBodyAwake();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Changes the value of CullDistance.
* @param NewCullDistance - The value to assign to CullDistance.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_SetCullDistance : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_SetCullDistance();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Return true if the given Pawn can step up onto this component.
* This controls whether they can try to step up on it when they bump in to it, not whether they can walk on it after landing on it.
* @param Pawn the Pawn that wants to step onto this component.
* @see CanCharacterStepUpOn
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComponents_CanCharacterStepUp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComponents_CanCharacterStepUp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};