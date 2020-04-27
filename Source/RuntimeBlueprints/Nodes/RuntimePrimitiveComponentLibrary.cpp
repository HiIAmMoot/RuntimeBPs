// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimePrimitiveComponentLibrary.h"
#include "RuntimeBpConstructor.h"

UComponents_GetGenerateOverlapEvents::UComponents_GetGenerateOverlapEvents()
{
	NodeName = "Get Generate Overlap Events";
	NodeDescription = "If true, this component will generate overlap events when it is overlapping other components (eg Begin Overlap).Both components (this and the other) must have this enabled for overlap events to occur.@see [Overlap Events](https:docs.unrealengine.comlatestINTEnginePhysicsCollisionindex.html#overlapandgenerateoverlapevents)@see UpdateOverlaps(), BeginComponentOverlap(), EndComponentOverlap()";
	NodeCategory = "Components";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_GetGenerateOverlapEvents::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetGenerateOverlapEvents());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetGenerateOverlapEvents::UComponents_SetGenerateOverlapEvents()
{
	NodeName = "Set Generate Overlap Events";
	NodeDescription = "Modifies value returned by GetGenerateOverlapEvents()";
	NodeCategory = "Components";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("b In Generate Overlap Events", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetGenerateOverlapEvents::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetGenerateOverlapEvents(GetConnectedPinValue(InputPins[2]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_IgnoreActorWhenMoving::UComponents_IgnoreActorWhenMoving()
{
	NodeName = "Ignore Actor When Moving";
	NodeDescription = "Tells this component whether to ignore collision with all components of a specific Actor when this component is moved.Components on the other Actor may also need to be told to do the same when they move.Does not affect movement of this component when simulating physics.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[2].Value.Array[0].SetActorArg(); // Default value

	InputPins[3].MakeNodePin("b Should Ignore", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_IgnoreActorWhenMoving::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->IgnoreActorWhenMoving(GetConnectedPinValue(InputPins[2]).GetActorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_IgnoreComponentWhenMoving::UComponents_IgnoreComponentWhenMoving()
{
	NodeName = "Ignore Component When Moving";
	NodeDescription = "Tells this component whether to ignore collision with another component when this component is moved.The other components may also need to be told to do the same when they move.Does not affect movement of this component when simulating physics.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[2].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[3].MakeNodePin("b Should Ignore", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_IgnoreComponentWhenMoving::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->IgnoreComponentWhenMoving(GetConnectedPinValue(InputPins[2]).GetPrimitiveComponentArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_IsOverlappingComponent::UComponents_IsOverlappingComponent()
{
	NodeName = "Is Overlapping Component";
	NodeDescription = "Check whether this component is overlapping another component.@param OtherComp Component to test this component against.@return Whether this component is overlapping another component.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Other Comp", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_IsOverlappingComponent::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->IsOverlappingComponent(GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_IsOverlappingActor::UComponents_IsOverlappingActor()
{
	NodeName = "Is Overlapping Actor";
	NodeDescription = "Check whether this component is overlapping any component of the given Actor.@param Other Actor to test this component against.@return Whether this component is overlapping any component of the given Actor.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Other", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_IsOverlappingActor::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->IsOverlappingActor(GetConnectedPinValue(InputPins[1]).GetActorArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetOverlappingActors::UComponents_GetOverlappingActors()
{
	NodeName = "Get Overlapping Actors";
	NodeDescription = "Returns a list of actors that this component is overlapping.@param OverlappingActors		[out] Returned list of overlapping actors@param ClassFilter			[optional] If set, only returns actors of this class or subclasses";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Class Filter=nullptr", EVariableTypes::Class);// PinName + PinType
	InputPins[2].Value.Array[0].SetClassArg(nullptr); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodeArray("Overlapping Actors", EVariableTypes::Actor);// PinName + PinType
}


void UComponents_GetOverlappingActors::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         TArray<AActor*> OverlappingActors;
	GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->GetOverlappingActors(OverlappingActors, GetConnectedPinValue(InputPins[2]).GetClassArg());
         
	OutputPins[1].Value.SetActorArg(OverlappingActors);

    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetOverlappingComponents::UComponents_GetOverlappingComponents()
{
	NodeName = "Get Overlapping Components";
	NodeDescription = "Returns unique list of components this component is overlapping.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodeArray("Out Overlapping Components", EVariableTypes::PrimitiveComponent);// PinName + PinType
}


void UComponents_GetOverlappingComponents::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         TArray<UPrimitiveComponent*> OutOverlappingComponents;
	GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->GetOverlappingComponents(OutOverlappingComponents);
         
	OutputPins[1].Value.SetPrimitiveComponentArg(OutOverlappingComponents);

    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetMaterialFromCollisionFaceIndex::UComponents_GetMaterialFromCollisionFaceIndex()
{
	NodeName = "Get Material From Collision Face Index";
	NodeDescription = "Try and retrieve the material applied to a particular collision face of mesh. Used with face index returned from collision trace.@param	FaceIndex		Face index from hit result that was hit by a trace@param	SectionIndex	Section of the mesh that the face belongs to@return					Material applied to section that the hit face belongs to";
	NodeCategory = "Components|Mesh";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Face Index", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::MaterialInterface);// PinName + PinType    
    OutputPins[1].MakeNodePin("Section Index", EVariableTypes::Int);// PinName + PinType
}


void UComponents_GetMaterialFromCollisionFaceIndex::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         int SectionIndex;
	OutputPins[0].Value.Array[0].SetMaterialInterfaceArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetMaterialFromCollisionFaceIndex(GetConnectedPinValue(InputPins[1]).GetIntArg(), SectionIndex));
         
	OutputPins[1].Value.Array[0].SetIntArg(SectionIndex);

    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	OutputPins[0].Value.Array[0].SetMaterialInterfaceArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetSimulatePhysics::UComponents_SetSimulatePhysics()
{
	NodeName = "Set Simulate Physics";
	NodeDescription = "Sets whether or not a single body should use physics simulation, or should be 'fixed' (kinematic).Note that if this component is currently attached to something, beginning simulation will detach it.@param	bSimulate	New simulation state for single body";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("b Simulate", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetSimulatePhysics::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetSimulatePhysics(GetConnectedPinValue(InputPins[2]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddImpulse::UComponents_AddImpulse()
{
	NodeName = "Add Impulse";
	NodeDescription = "Add an impulse to a single rigid body. Good for one time instant burst.@param	Impulse		Magnitude and direction of impulse to apply.@param	BoneName	If a SkeletalMeshComponent, name of body to apply impulse to. 'None' indicates root body.@param	bVelChange	If true, the Strength is taken as a change in velocity instead of an impulse (ie. mass will have no effect).";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Impulse", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[4].MakeNodePin("b Vel Change", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddImpulse::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddImpulse(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddAngularImpulseInRadians::UComponents_AddAngularImpulseInRadians()
{
	NodeName = "Add Angular Impulse In Radians";
	NodeDescription = "Add an angular impulse to a single rigid body. Good for one time instant burst.@param	AngularImpulse	Magnitude and direction of impulse to apply. Direction is axis of rotation.@param	BoneName	If a SkeletalMeshComponent, name of body to apply angular impulse to. 'None' indicates root body.@param	bVelChange	If true, the Strength is taken as a change in angular velocity instead of an impulse (ie. mass will have no effect).";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Impulse", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[4].MakeNodePin("b Vel Change", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddAngularImpulseInRadians::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddAngularImpulseInRadians(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddAngularImpulseInDegrees::UComponents_AddAngularImpulseInDegrees()
{
	NodeName = "Add Angular Impulse In Degrees";
	NodeDescription = "Add an angular impulse to a single rigid body. Good for one time instant burst.@param	AngularImpulse	Magnitude and direction of impulse to apply. Direction is axis of rotation.@param	BoneName	If a SkeletalMeshComponent, name of body to apply angular impulse to. 'None' indicates root body.@param	bVelChange	If true, the Strength is taken as a change in angular velocity instead of an impulse (ie. mass will have no effect).";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Impulse", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[4].MakeNodePin("b Vel Change", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddAngularImpulseInDegrees::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddAngularImpulseInDegrees(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddImpulseAtLocation::UComponents_AddImpulseAtLocation()
{
	NodeName = "Add Impulse At Location";
	NodeDescription = "Add an impulse to a single rigid body at a specific location.@param	Impulse		Magnitude and direction of impulse to apply.@param	Location	Point in world space to apply impulse at.@param	BoneName	If a SkeletalMeshComponent, name of bone to apply impulse to. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Impulse", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[3].Value.Array[0].SetVectorArg(); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddImpulseAtLocation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddImpulseAtLocation(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetVectorArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddForce::UComponents_AddForce()
{
	NodeName = "Add Force";
	NodeDescription = "Add a force to a single rigid body.This is like a 'thruster'. Good for adding a burst over some (non zero) time. Should be called every frame for the duration of the force.@param	Force		 Force vector to apply. Magnitude indicates strength of force.@param	BoneName	 If a SkeletalMeshComponent, name of body to apply force to. 'None' indicates root body.@param  bAccelChange If true, Force is taken as a change in acceleration instead of a physical force (i.e. mass will have no effect).";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Force", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[4].MakeNodePin("b Accel Change", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddForce::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddForce(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddForceAtLocation::UComponents_AddForceAtLocation()
{
	NodeName = "Add Force At Location";
	NodeDescription = "Add a force to a single rigid body at a particular location in world space.This is like a 'thruster'. Good for adding a burst over some (non zero) time. Should be called every frame for the duration of the force.@param Force		Force vector to apply. Magnitude indicates strength of force.@param Location		Location to apply force, in world space.@param BoneName		If a SkeletalMeshComponent, name of body to apply force to. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Force", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[3].Value.Array[0].SetVectorArg(); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddForceAtLocation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddForceAtLocation(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetVectorArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddForceAtLocationLocal::UComponents_AddForceAtLocationLocal()
{
	NodeName = "Add Force At Location Local";
	NodeDescription = "Add a force to a single rigid body at a particular location. Both Force and Location should be in body space.This is like a 'thruster'. Good for adding a burst over some (non zero) time. Should be called every frame for the duration of the force.@param Force		Force vector to apply. Magnitude indicates strength of force.@param Location		Location to apply force, in component space.@param BoneName		If a SkeletalMeshComponent, name of body to apply force to. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Force", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[3].Value.Array[0].SetVectorArg(); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddForceAtLocationLocal::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddForceAtLocationLocal(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetVectorArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddTorqueInRadians::UComponents_AddTorqueInRadians()
{
	NodeName = "Add Torque In Radians";
	NodeDescription = "Add a torque to a single rigid body.@param Torque		Torque to apply. Direction is axis of rotation and magnitude is strength of torque.@param BoneName		If a SkeletalMeshComponent, name of body to apply torque to. 'None' indicates root body.@param bAccelChange If true, Torque is taken as a change in angular acceleration instead of a physical torque (i.e. mass will have no effect).";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Torque", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[4].MakeNodePin("b Accel Change", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddTorqueInRadians::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddTorqueInRadians(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_AddTorqueInDegrees::UComponents_AddTorqueInDegrees()
{
	NodeName = "Add Torque In Degrees";
	NodeDescription = "Add a torque to a single rigid body.@param Torque		Torque to apply. Direction is axis of rotation and magnitude is strength of torque.@param BoneName		If a SkeletalMeshComponent, name of body to apply torque to. 'None' indicates root body.@param bAccelChange If true, Torque is taken as a change in angular acceleration instead of a physical torque (i.e. mass will have no effect).";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Torque", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[4].MakeNodePin("b Accel Change", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_AddTorqueInDegrees::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->AddTorqueInDegrees(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetPhysicsLinearVelocity::UComponents_SetPhysicsLinearVelocity()
{
	NodeName = "Set Physics Linear Velocity";
	NodeDescription = "Set the linear velocity of a single body.This should be used cautiously - it may be better to use AddForce or AddImpulse.@param NewVel			New linear velocity to apply to physics.@param bAddToCurrent	If true, NewVel is added to the existing velocity of the body.@param BoneName			If a SkeletalMeshComponent, name of body to modify velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Vel", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetPhysicsLinearVelocity::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetPhysicsLinearVelocity(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetPhysicsLinearVelocity::UComponents_GetPhysicsLinearVelocity()
{
	NodeName = "Get Physics Linear Velocity";
	NodeDescription = "Get the linear velocity of a single body.@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetPhysicsLinearVelocity::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
	OutputPins[1].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->GetPhysicsLinearVelocity(GetConnectedPinValue(InputPins[2]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[1].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetPhysicsLinearVelocityAtPoint::UComponents_GetPhysicsLinearVelocityAtPoint()
{
	NodeName = "Get Physics Linear Velocity At Point";
	NodeDescription = "Get the linear velocity of a point on a single body.@param Point			Point is specified in world space.@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetPhysicsLinearVelocityAtPoint::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
	OutputPins[1].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->GetPhysicsLinearVelocityAtPoint(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[1].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetAllPhysicsLinearVelocity::UComponents_SetAllPhysicsLinearVelocity()
{
	NodeName = "Set All Physics Linear Velocity";
	NodeDescription = "Set the linear velocity of all bodies in this component.@param NewVel			New linear velocity to apply to physics.@param bAddToCurrent	If true, NewVel is added to the existing velocity of the body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Vel", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetAllPhysicsLinearVelocity::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetAllPhysicsLinearVelocity(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetPhysicsAngularVelocityInRadians::UComponents_SetPhysicsAngularVelocityInRadians()
{
	NodeName = "Set Physics Angular Velocity In Radians";
	NodeDescription = "Set the angular velocity of a single body.This should be used cautiously - it may be better to use AddTorque or AddImpulse.@param NewAngVel		New angular velocity to apply to body, in radians per second.@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of the body.@param BoneName			If a SkeletalMeshComponent, name of body to modify angular velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Ang Vel", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetPhysicsAngularVelocityInRadians::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetPhysicsAngularVelocityInRadians(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetPhysicsAngularVelocityInDegrees::UComponents_SetPhysicsAngularVelocityInDegrees()
{
	NodeName = "Set Physics Angular Velocity In Degrees";
	NodeDescription = "Set the angular velocity of a single body.This should be used cautiously - it may be better to use AddTorque or AddImpulse.@param NewAngVel		New angular velocity to apply to body, in degrees per second.@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of the body.@param BoneName			If a SkeletalMeshComponent, name of body to modify angular velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Ang Vel", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetPhysicsAngularVelocityInDegrees::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetPhysicsAngularVelocityInDegrees(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetPhysicsMaxAngularVelocityInDegrees::UComponents_SetPhysicsMaxAngularVelocityInDegrees()
{
	NodeName = "Set Physics Max Angular Velocity In Degrees";
	NodeDescription = "Set the maximum angular velocity of a single body.@param NewMaxAngVel		New maximum angular velocity to apply to body, in degrees per second.@param bAddToCurrent	If true, NewMaxAngVel is added to the existing maximum angular velocity of the body.@param BoneName			If a SkeletalMeshComponent, name of body to modify maximum angular velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Max Ang Vel", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetPhysicsMaxAngularVelocityInDegrees::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetPhysicsMaxAngularVelocityInDegrees(GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetPhysicsMaxAngularVelocityInRadians::UComponents_SetPhysicsMaxAngularVelocityInRadians()
{
	NodeName = "Set Physics Max Angular Velocity In Radians";
	NodeDescription = "Set the maximum angular velocity of a single body.@param NewMaxAngVel		New maximum angular velocity to apply to body, in radians per second.@param bAddToCurrent	If true, NewMaxAngVel is added to the existing maximum angular velocity of the body.@param BoneName			If a SkeletalMeshComponent, name of body to modify maximum angular velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Max Ang Vel", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[4].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[4].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetPhysicsMaxAngularVelocityInRadians::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetPhysicsMaxAngularVelocityInRadians(GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetPhysicsAngularVelocityInDegrees::UComponents_GetPhysicsAngularVelocityInDegrees()
{
	NodeName = "Get Physics Angular Velocity In Degrees";
	NodeDescription = "Get the angular velocity of a single body, in degrees per second.@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetPhysicsAngularVelocityInDegrees::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetPhysicsAngularVelocityInDegrees(GetConnectedPinValue(InputPins[1]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetPhysicsAngularVelocityInRadians::UComponents_GetPhysicsAngularVelocityInRadians()
{
	NodeName = "Get Physics Angular Velocity In Radians";
	NodeDescription = "Get the angular velocity of a single body, in radians per second.@param BoneName			If a SkeletalMeshComponent, name of body to get velocity of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetPhysicsAngularVelocityInRadians::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetPhysicsAngularVelocityInRadians(GetConnectedPinValue(InputPins[1]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetCenterOfMass::UComponents_GetCenterOfMass()
{
	NodeName = "Get Center Of Mass";
	NodeDescription = "Get the center of mass of a single body. In the case of a welded body this will return the center of mass of the entire welded body (including its parent and children)Objects that are not simulated return (0,0,0) as they do not have COM@param BoneName			If a SkeletalMeshComponent, name of body to get center of mass of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetCenterOfMass::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetCenterOfMass(GetConnectedPinValue(InputPins[1]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetCenterOfMass::UComponents_SetCenterOfMass()
{
	NodeName = "Set Center Of Mass";
	NodeDescription = "Set the center of mass of a single body. This will offset the physx-calculated center of mass.Note that in the case where multiple bodies are attached together, the center of mass will be set for the entire group.@param CenterOfMassOffset		User specified offset for the center of mass of this object, from the calculated location.@param BoneName			If a SkeletalMeshComponent, name of body to set center of mass of. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Center Of Mass Offset", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetCenterOfMass::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetCenterOfMass(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_WakeRigidBody::UComponents_WakeRigidBody()
{
	NodeName = "Wake Rigid Body";
	NodeDescription = "'Wake' physics simulation for a single body.@param	BoneName	If a SkeletalMeshComponent, name of body to wake. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_WakeRigidBody::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->WakeRigidBody(GetConnectedPinValue(InputPins[2]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_PutRigidBodyToSleep::UComponents_PutRigidBodyToSleep()
{
	NodeName = "Put Rigid Body To Sleep";
	NodeDescription = "Force a single body back to sleep.@param	BoneName	If a SkeletalMeshComponent, name of body to put to sleep. 'None' indicates root body.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_PutRigidBodyToSleep::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->PutRigidBodyToSleep(GetConnectedPinValue(InputPins[2]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetNotifyRigidBodyCollision::UComponents_SetNotifyRigidBodyCollision()
{
	NodeName = "Set Notify Rigid Body Collision";
	NodeDescription = "Changes the value of bNotifyRigidBodyCollision";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("b New Notify Rigid Body Collision", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetNotifyRigidBodyCollision::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetNotifyRigidBodyCollision(GetConnectedPinValue(InputPins[2]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetCollisionProfileName::UComponents_SetCollisionProfileName()
{
	NodeName = "Set Collision Profile Name";
	NodeDescription = "Set Collision Profile NameThis function is called by constructors when they set ProfileNameThis will change current CollisionProfileName to be this, and overwrite Collision Setting@param InCollisionProfileName : New Profile Name";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("In Collision Profile Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetCollisionProfileName::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetCollisionProfileName(GetConnectedPinValue(InputPins[2]).GetNameArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetCollisionProfileName::UComponents_GetCollisionProfileName()
{
	NodeName = "Get Collision Profile Name";
	NodeDescription = "Get the collision profile name";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Name);// PinName + PinType
}


void UComponents_GetCollisionProfileName::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetNameArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetCollisionProfileName());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetNameArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetClosestPointOnCollision::UComponents_GetClosestPointOnCollision()
{
	NodeName = "Get Closest Point On Collision";
	NodeDescription = "Returns the distance and closest point to the collision surface.Component must have simple collision to be queried for closest point.@param Point				World 3D vector@param OutPointOnBody		Point on the surface of collision closest to Point@param BoneName			If a SkeletalMeshComponent, name of body to set center of mass of. 'None' indicates root body.@return		Success if returns > 0.f, if returns 0.f, it is either not convex or inside of the pointIf returns < 0.f, this primitive does not have collsion";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType    
    OutputPins[1].MakeNodePin("Out Point On Body", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetClosestPointOnCollision::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         FVector OutPointOnBody;
	OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetClosestPointOnCollision(GetConnectedPinValue(InputPins[1]).GetVectorArg(), OutPointOnBody, GetConnectedPinValue(InputPins[2]).GetNameArg()));
         
	OutputPins[1].Value.Array[0].SetVectorArg(OutPointOnBody);

    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_K2_IsCollisionEnabled::UComponents_K2_IsCollisionEnabled()
{
	NodeName = "Is Collision Enabled";
	NodeDescription = "Utility to see if there is any form of collision (query or physics) enabled on this component.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_K2_IsCollisionEnabled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->K2_IsCollisionEnabled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_K2_IsQueryCollisionEnabled::UComponents_K2_IsQueryCollisionEnabled()
{
	NodeName = "Is Query Collision Enabled";
	NodeDescription = "Utility to see if there is any query collision enabled on this component.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_K2_IsQueryCollisionEnabled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->K2_IsQueryCollisionEnabled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_K2_IsPhysicsCollisionEnabled::UComponents_K2_IsPhysicsCollisionEnabled()
{
	NodeName = "Is Physics Collision Enabled";
	NodeDescription = "Utility to see if there is any physics collision enabled on this component.";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_K2_IsPhysicsCollisionEnabled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->K2_IsPhysicsCollisionEnabled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetAllPhysicsAngularVelocityInDegrees::UComponents_SetAllPhysicsAngularVelocityInDegrees()
{
	NodeName = "Set All Physics Angular Velocity In Degrees";
	NodeDescription = "Set the angular velocity of all bodies in this component.@param NewAngVel		New angular velocity to apply to physics, in degrees per second.@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of all bodies.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Ang Vel", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetAllPhysicsAngularVelocityInDegrees::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetAllPhysicsAngularVelocityInDegrees(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetAllPhysicsAngularVelocityInRadians::UComponents_SetAllPhysicsAngularVelocityInRadians()
{
	NodeName = "Set All Physics Angular Velocity In Radians";
	NodeDescription = "Set the angular velocity of all bodies in this component.@param NewAngVel		New angular velocity to apply to physics, in radians per second.@param bAddToCurrent	If true, NewAngVel is added to the existing angular velocity of all bodies.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Ang Vel", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b Add To Current", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetAllPhysicsAngularVelocityInRadians::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetAllPhysicsAngularVelocityInRadians(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_WakeAllRigidBodies::UComponents_WakeAllRigidBodies()
{
	NodeName = "Wake All Rigid Bodies";
	NodeDescription = "Ensure simulation is running for all bodies in this component.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_WakeAllRigidBodies::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->WakeAllRigidBodies();
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetEnableGravity::UComponents_SetEnableGravity()
{
	NodeName = "Set Enable Gravity";
	NodeDescription = "Enablesdisables whether this component is affected by gravity. This applies only to components with bSimulatePhysics set to true.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("b Gravity Enabled", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetEnableGravity::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetEnableGravity(GetConnectedPinValue(InputPins[2]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_IsGravityEnabled::UComponents_IsGravityEnabled()
{
	NodeName = "Is Gravity Enabled";
	NodeDescription = "Returns whether this component is affected by gravity. Returns always false if the component is not simulated.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_IsGravityEnabled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->IsGravityEnabled());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetLinearDamping::UComponents_SetLinearDamping()
{
	NodeName = "Set Linear Damping";
	NodeDescription = "Sets the linear damping of this component.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("In Damping", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetLinearDamping::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetLinearDamping(GetConnectedPinValue(InputPins[2]).GetFloatArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetLinearDamping::UComponents_GetLinearDamping()
{
	NodeName = "Get Linear Damping";
	NodeDescription = "Returns the linear damping of this component.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UComponents_GetLinearDamping::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetLinearDamping());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetAngularDamping::UComponents_SetAngularDamping()
{
	NodeName = "Set Angular Damping";
	NodeDescription = "Sets the angular damping of this component.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("In Damping", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetAngularDamping::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetAngularDamping(GetConnectedPinValue(InputPins[2]).GetFloatArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetAngularDamping::UComponents_GetAngularDamping()
{
	NodeName = "Get Angular Damping";
	NodeDescription = "Returns the angular damping of this component.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UComponents_GetAngularDamping::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetAngularDamping());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetMassScale::UComponents_SetMassScale()
{
	NodeName = "Set Mass Scale";
	NodeDescription = "Change the mass scale used to calculate the mass of a single physics body";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[3].MakeNodePin("In Mass Scale", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetMassScale::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetMassScale(GetConnectedPinValue(InputPins[2]).GetNameArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetMassScale::UComponents_GetMassScale()
{
	NodeName = "Get Mass Scale";
	NodeDescription = "Returns the mass scale used to calculate the mass of a single physics body";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UComponents_GetMassScale::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetMassScale(GetConnectedPinValue(InputPins[1]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetAllMassScale::UComponents_SetAllMassScale()
{
	NodeName = "Set All Mass Scale";
	NodeDescription = "Change the mass scale used fo all bodies in this component";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("In Mass Scale", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetAllMassScale::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetAllMassScale(GetConnectedPinValue(InputPins[2]).GetFloatArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetMassOverrideInKg::UComponents_SetMassOverrideInKg()
{
	NodeName = "Set Mass Override In Kg";
	NodeDescription = "Override the mass (in Kg) of a single physics body.Note that in the case where multiple bodies are attached together, the override mass will be set for the entire group.Set the Override Mass to false if you want to reset the body's mass to the auto-calculated physx mass.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(NAME_None); // Default value

	InputPins[3].MakeNodePin("Mass In Kg", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(1.f); // Default value

	InputPins[4].MakeNodePin("b Override Mass", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(true); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetMassOverrideInKg::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetMassOverrideInKg(GetConnectedPinValue(InputPins[2]).GetNameArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetMass::UComponents_GetMass()
{
	NodeName = "Get Mass";
	NodeDescription = "Returns the mass of this component in kg.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UComponents_GetMass::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetMass());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_GetInertiaTensor::UComponents_GetInertiaTensor()
{
	NodeName = "Get Inertia Tensor";
	NodeDescription = "Returns the inertia tensor of this component in kg cm^2. The inertia tensor is in local component space.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_GetInertiaTensor::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->GetInertiaTensor(GetConnectedPinValue(InputPins[1]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_ScaleByMomentOfInertia::UComponents_ScaleByMomentOfInertia()
{
	NodeName = "Scale By Moment Of Inertia";
	NodeDescription = "Scales the given vector by the world space moment of inertia. Useful for computing the torque needed to rotate an object.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Input Vector", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Bone Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(NAME_None); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UComponents_ScaleByMomentOfInertia::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->ScaleByMomentOfInertia(GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetNameArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_IsAnyRigidBodyAwake::UComponents_IsAnyRigidBodyAwake()
{
	NodeName = "Is Any Rigid Body Awake";
	NodeDescription = "Returns if any body in this component is currently awake and simulating.";
	NodeCategory = "Components|Physics";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_IsAnyRigidBodyAwake::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->IsAnyRigidBodyAwake());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_SetCullDistance::UComponents_SetCullDistance()
{
	NodeName = "Set Max Draw Distance";
	NodeDescription = "Changes the value of CullDistance.@param NewCullDistance - The value to assign to CullDistance.";
	NodeCategory = "Components|LOD";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[2].MakeNodePin("New Cull Distance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UComponents_SetCullDistance::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg())
    {
         
		GetConnectedPinValue(InputPins[1]).GetPrimitiveComponentArg()->SetCullDistance(GetConnectedPinValue(InputPins[2]).GetFloatArg());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         	
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComponents_CanCharacterStepUp::UComponents_CanCharacterStepUp()
{
	NodeName = "Can Character Step Up";
	NodeDescription = "Return true if the given Pawn can step up onto this component.This controls whether they can try to step up on it when they bump in to it, not whether they can walk on it after landing on it.@param Pawn the Pawn that wants to step onto this component.@see CanCharacterStepUpOn";
	NodeCategory = "Components|Collision";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Primitive Component", EVariableTypes::PrimitiveComponent);// PinName + PinType
	InputPins[0].Value.Array[0].SetPrimitiveComponentArg(); // Default value

	InputPins[1].MakeNodePin("Pawn", EVariableTypes::Pawn);// PinName + PinType
	InputPins[1].Value.Array[0].SetPawnArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UComponents_CanCharacterStepUp::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetPrimitiveComponentArg()->CanCharacterStepUp(GetConnectedPinValue(InputPins[1]).GetPawnArg()));
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

