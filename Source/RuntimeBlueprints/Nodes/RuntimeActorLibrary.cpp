// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeActorLibrary.h"
#include "RuntimeBpConstructor.h"

UActor_GetTransform::UActor_GetTransform()
{
	NodeName = "Get Actor Transform";
	NodeDescription = "Get the actor-to-world transform.@return The transform that transforms from actor space to world space.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UActor_GetTransform::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
         
		OutputPins[0].Value.Array[0].SetTransformArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetTransform());
             
    }
    else
    {
        // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
        OutputPins[0].Value.Array[0].SetTransformArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_K2_GetActorLocation::UActor_K2_GetActorLocation()
{
	NodeName = "Get Actor Location";
	NodeDescription = "Returns the location of the RootComponent of this Actor";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_K2_GetActorLocation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->K2_GetActorLocation());
             
    }
    else
    {
        // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
        OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_K2_GetActorRotation::UActor_K2_GetActorRotation()
{
	NodeName = "Get Actor Rotation";
	NodeDescription = "Returns the rotation of the RootComponent of this Actor.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UActor_K2_GetActorRotation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
         
		OutputPins[0].Value.Array[0].SetRotatorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->K2_GetActorRotation());
             
    }
    else
    {
        // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
        OutputPins[0].Value.Array[0].SetRotatorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetActorForwardVector::UActor_GetActorForwardVector()
{
	NodeName = "Get Actor Forward Vector";
	NodeDescription = "Get the forward (X) vector (length 1.0) from this Actor, in world space.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_GetActorForwardVector::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
         
		OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorForwardVector());
             
    }
    else
    {
        // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
        OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetActorUpVector::UActor_GetActorUpVector()
{
	NodeName = "Get Actor Up Vector";
	NodeDescription = "Get the up (Z) vector (length 1.0) from this Actor, in world space.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_GetActorUpVector::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
         
		OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorUpVector());
             
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetActorRightVector::UActor_GetActorRightVector()
{
	NodeName = "Get Actor Right Vector";
	NodeDescription = "Get the right (Y) vector (length 1.0) from this Actor, in world space.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_GetActorRightVector::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorRightVector());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetActorBounds::UActor_GetActorBounds()
{
	NodeName = "Get Actor Bounds";
	NodeDescription = "Returns the bounding box of all components that make up this Actor (excluding ChildActorComponents).@param	bOnlyCollidingComponents	If true, will only return the bounding box for components with collision enabled.@param	Origin						Set to the center of the actor in world space@param	BoxExtent					Set to half the actor's size in 3d space";
	NodeCategory = "Actor|Collision";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("Only Colliding Components", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Origin", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Box Extent", EVariableTypes::Vector);// PinName + PinType
}


void UActor_GetActorBounds::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetActorArg())
    {
        FVector Origin;
		FVector BoxExtent;
		GetConnectedPinValue(InputPins[1]).GetActorArg()->GetActorBounds(GetConnectedPinValue(InputPins[2]).GetBoolArg(), Origin, BoxExtent);
         
		OutputPins[1].Value.Array[0].SetVectorArg(Origin);
		OutputPins[2].Value.Array[0].SetVectorArg(BoxExtent);
    }
    else
    {
		Super::Execute(0, FromLoopIndex);// Index here is the array index
    }

}


UActor_K2_GetRootComponent::UActor_K2_GetRootComponent()
{
	NodeName = "Get Root Component";
	NodeDescription = "Returns the RootComponent of this Actor";
	NodeCategory = "Actor";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::SceneComponent);// PinName + PinType
}


void UActor_K2_GetRootComponent::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetSceneComponentArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->K2_GetRootComponent()); 
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetSceneComponentArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetVelocity::UActor_GetVelocity()
{
	NodeName = "Get Velocity";
	NodeDescription = "Returns velocity (in cms (Unreal Unitssecond) of the rootcomponent if it is either using physics or has an associated MovementComponent";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_GetVelocity::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetVelocity());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_K2_SetActorRotation::UActor_K2_SetActorRotation()
{
	NodeName = "Set Actor Rotation";
	NodeDescription = "Set the Actor's rotation instantly to the specified rotation.@param	NewRotation	The new rotation for the Actor.@param	bTeleportPhysics Whether we teleport the physics state (if physics collision is enabled for this object).If true, physics velocity for this object is unchanged (so ragdoll parts are not affected by change in location).If false, physics velocity is updated based on the change in position (affecting ragdoll parts).@return	Whether the rotation was successfully set.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Rotation", EVariableTypes::Rotator);// PinName + PinType
	InputPins[2].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[3].MakeNodePin("Teleport Physics", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UActor_K2_SetActorRotation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetActorArg())
    {
		if (BPConstructor->GetMultiThread())
		{
			FRotator NewRotation = GetConnectedPinValue(InputPins[2]).GetRotatorArg();
			bool TeleportPhysics = GetConnectedPinValue(InputPins[3]).GetBoolArg();

			AsyncTask(ENamedThreads::GameThread, [this, NewRotation, TeleportPhysics, FromLoopIndex]()
			{
				OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_SetActorRotation(NewRotation, GetConnectedPinValue(InputPins[3]).GetBoolArg()));
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_SetActorRotation(GetConnectedPinValue(InputPins[2]).GetRotatorArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg()));
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[1].Value.Array[0].SetBoolArg();
		 Super::Execute(0, FromLoopIndex);// Index here is the array index
    }
}


UActor_SetActorScale3D::UActor_SetActorScale3D()
{
	NodeName = "Set Actor Scale3D";
	NodeDescription = "Set the Actor's world-space scale.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Scale3D", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UActor_SetActorScale3D::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetActorArg())
    {
		if (BPConstructor->GetMultiThread())
		{
			FVector NewScale3D = GetConnectedPinValue(InputPins[2]).GetVectorArg();
			AsyncTask(ENamedThreads::GameThread, [this, NewScale3D, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorScale3D(NewScale3D);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorScale3D(GetConnectedPinValue(InputPins[2]).GetVectorArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
    }
}


UActor_GetActorScale3D::UActor_GetActorScale3D()
{
	NodeName = "Get Actor Scale3D";
	NodeDescription = "Returns the Actor's world-space scale.";
	NodeCategory = "Actor|Utilities|Orientation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_GetActorScale3D::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorScale3D());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetDistanceTo::UActor_GetDistanceTo()
{
	NodeName = "Get Distance To";
	NodeDescription = "Returns the distance from this Actor to OtherActor.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Other Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UActor_GetDistanceTo::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetDistanceTo(GetConnectedPinValue(InputPins[1]).GetActorArg()));
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetSquaredDistanceTo::UActor_GetSquaredDistanceTo()
{
	NodeName = "Get Squared Distance To";
	NodeDescription = "Returns the squared distance from this Actor to OtherActor.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Other Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UActor_GetSquaredDistanceTo::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetSquaredDistanceTo(GetConnectedPinValue(InputPins[1]).GetActorArg()));
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetHorizontalDistanceTo::UActor_GetHorizontalDistanceTo()
{
	NodeName = "Get Horizontal Distance To";
	NodeDescription = "Returns the distance from this Actor to OtherActor, ignoring Z.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Other Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UActor_GetHorizontalDistanceTo::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetHorizontalDistanceTo(GetConnectedPinValue(InputPins[1]).GetActorArg()));
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetVerticalDistanceTo::UActor_GetVerticalDistanceTo()
{
	NodeName = "Get Vertical Distance To";
	NodeDescription = "Returns the distance from this Actor to OtherActor, ignoring XY.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Other Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UActor_GetVerticalDistanceTo::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetVerticalDistanceTo(GetConnectedPinValue(InputPins[1]).GetActorArg()));  
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetDotProductTo::UActor_GetDotProductTo()
{
	NodeName = "Get Dot Product To";
	NodeDescription = "Returns the dot product from this Actor to OtherActor. Returns -2.0 on failure. Returns 0.0 for coincidental actors.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Other Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UActor_GetDotProductTo::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetDotProductTo(GetConnectedPinValue(InputPins[1]).GetActorArg()));
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetHorizontalDotProductTo::UActor_GetHorizontalDotProductTo()
{
	NodeName = "Get Horizontal Dot Product To";
	NodeDescription = "Returns the dot product from this Actor to OtherActor, ignoring Z. Returns -2.0 on failure. Returns 0.0 for coincidental actors.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Other Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UActor_GetHorizontalDotProductTo::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetHorizontalDotProductTo(GetConnectedPinValue(InputPins[1]).GetActorArg()));
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_SetActorRelativeScale3D::UActor_SetActorRelativeScale3D()
{
	NodeName = "Set Actor Relative Scale3D";
	NodeDescription = "Set the actor's RootComponent to the specified relative scale 3d@param NewRelativeScale	New scale to set the actor's RootComponent to";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Relative Scale", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UActor_SetActorRelativeScale3D::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			FVector NewRelativeScale = GetConnectedPinValue(InputPins[2]).GetVectorArg();

			AsyncTask(ENamedThreads::GameThread, [this, NewRelativeScale, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorRelativeScale3D(NewRelativeScale);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorRelativeScale3D(GetConnectedPinValue(InputPins[2]).GetVectorArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}


UActor_GetActorRelativeScale3D::UActor_GetActorRelativeScale3D()
{
	NodeName = "Get Actor Relative Scale3D";
	NodeDescription = "Return the actor's relative scale 3d";
	NodeCategory = "Actor|Utilities|Orientation";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_GetActorRelativeScale3D::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetVectorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorRelativeScale3D());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetVectorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_SetActorEnableCollision::UActor_SetActorEnableCollision()
{
	NodeName = "Set Actor Enable Collision";
	NodeDescription = "Allows enablingdisabling collision for the whole actor";
	NodeCategory = "Actor|Collision";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Actor Enable Collision", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UActor_SetActorEnableCollision::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		

		if (BPConstructor->GetMultiThread())
		{
			bool NewActorEnableCollision = GetConnectedPinValue(InputPins[2]).GetBoolArg();

			AsyncTask(ENamedThreads::GameThread, [this, NewActorEnableCollision, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorEnableCollision(NewActorEnableCollision);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorEnableCollision(GetConnectedPinValue(InputPins[2]).GetBoolArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}


UActor_GetActorEnableCollision::UActor_GetActorEnableCollision()
{
	NodeName = "Get Actor Enable Collision";
	NodeDescription = "Get current state of collision for the whole actor";
	NodeCategory = "Actor|Collision";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UActor_GetActorEnableCollision::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
         
	OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorEnableCollision());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_K2_DestroyActor::UActor_K2_DestroyActor()
{
	NodeName = "Destroy Actor";
	NodeDescription = "Destroy the actor";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UActor_K2_DestroyActor::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			AsyncTask(ENamedThreads::GameThread, [this, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_DestroyActor();
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_DestroyActor();
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}


UActor_ActorHasTag::UActor_ActorHasTag()
{
	NodeName = "Actor Has Tag";
	NodeDescription = "See if this actor's Tags array contains the supplied name tag";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Tag", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UActor_ActorHasTag::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    { 
		OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->ActorHasTag(GetConnectedPinValue(InputPins[1]).GetNameArg()));
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetActorTimeDilation::UActor_GetActorTimeDilation()
{
	NodeName = "Get Actor Time Dilation";
	NodeDescription = "Get ActorTimeDilation - this can be used for input control or speed control for slomo.We don't want to scale input globally because input can be used for UI, which do not care for TimeDilation.";
	NodeCategory = "Actor|Utilities|Time";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UActor_GetActorTimeDilation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
         
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorTimeDilation());
             
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_GetTickableWhenPaused::UActor_GetTickableWhenPaused()
{
	NodeName = "Get Tickable When Paused";
	NodeDescription = "Gets whether this actor can tick when paused.";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UActor_GetTickableWhenPaused::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetActorArg())
    {
		OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetActorArg()->GetTickableWhenPaused()); 
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[1].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_SetTickableWhenPaused::UActor_SetTickableWhenPaused()
{
	NodeName = "Set Tickable When Paused";
	NodeDescription = "Sets whether this actor can tick when paused.";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("Tickable When Paused", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UActor_SetTickableWhenPaused::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			bool TickableWhenPaused = GetConnectedPinValue(InputPins[2]).GetBoolArg();
			AsyncTask(ENamedThreads::GameThread, [this, TickableWhenPaused, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetTickableWhenPaused(TickableWhenPaused);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetTickableWhenPaused(GetConnectedPinValue(InputPins[2]).GetBoolArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}

UActor_GetGameTimeSinceCreation::UActor_GetGameTimeSinceCreation()
{
	NodeName = "Get Game Time Since Creation";
	NodeDescription = "The number of seconds (in game time) since this Actor was created, relative to Get Game Time In Seconds.";
	NodeCategory = "Actor";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}

void UActor_GetGameTimeSinceCreation::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetGameTimeSinceCreation());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_SetLifeSpan::UActor_SetLifeSpan()
{
	NodeName = "Set Life Span";
	NodeDescription = "Set the lifespan of this actor. When it expires the object will be destroyed. If requested lifespan is 0, the timer is cleared and the actor will not be destroyed.";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("In Lifespan", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}

void UActor_SetLifeSpan::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			float InLifeSpan = GetConnectedPinValue(InputPins[2]).GetFloatArg();
			AsyncTask(ENamedThreads::GameThread, [this, InLifeSpan, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetLifeSpan(InLifeSpan);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetLifeSpan(GetConnectedPinValue(InputPins[2]).GetFloatArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}

UActor_GetLifeSpan::UActor_GetLifeSpan()
{
	NodeName = "Get Life Span";
	NodeDescription = "Get the remaining lifespan of this actor. If zero is returned the actor lives forever.";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}

void UActor_GetLifeSpan::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetLifeSpan());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_SetActorTickEnabled::UActor_SetActorTickEnabled()
{
	NodeName = "Set Actor Tick Enabled";
	NodeDescription = "Set this actor's tick functions to be enabled or disabled. Only has an effect if the function is registeredThis only modifies the tick function on actor itself@param	bEnabled	Whether it should be enabled or not";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("Enabled", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}

void UActor_SetActorTickEnabled::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			bool Enabled = GetConnectedPinValue(InputPins[2]).GetBoolArg();
			AsyncTask(ENamedThreads::GameThread, [this, Enabled, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorTickEnabled(Enabled);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorTickEnabled(GetConnectedPinValue(InputPins[2]).GetBoolArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}

UActor_IsActorTickEnabled::UActor_IsActorTickEnabled()
{
	NodeName = "Is Actor Tick Enabled";
	NodeDescription = "Returns whether this actor has tick enabled or not";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}

void UActor_IsActorTickEnabled::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->IsActorTickEnabled());       
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_SetActorTickInterval::UActor_SetActorTickInterval()
{
	NodeName = "Set Actor Tick Interval";
	NodeDescription = "Sets the tick interval of this actor's primary tick function. Will not enable a disabled tick function. Takes effect on next tick.@param TickInterval	The rate at which this actor should be ticking";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("Tick Interval", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}

void UActor_SetActorTickInterval::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			float TickInterval = GetConnectedPinValue(InputPins[2]).GetFloatArg();
			AsyncTask(ENamedThreads::GameThread, [this, TickInterval, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorTickInterval(TickInterval);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetActorTickInterval(GetConnectedPinValue(InputPins[2]).GetFloatArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}

UActor_GetActorTickInterval::UActor_GetActorTickInterval()
{
	NodeName = "Get Actor Tick Interval";
	NodeDescription = "Returns the tick interval of this actor's primary tick function";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}

void UActor_GetActorTickInterval::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
         
	OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetActorTickInterval());
             
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         OutputPins[0].Value.Array[0].SetFloatArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_SetOwner::UActor_SetOwner()
{
	NodeName = "Set Owner";
	NodeDescription = "Set the owner of this Actor, used primarily for network replication.@param NewOwner	The Actor whom takes over ownership of this Actor";
	NodeCategory = "Actor";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Owner", EVariableTypes::Actor);// PinName + PinType
	InputPins[2].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}

void UActor_SetOwner::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			AActor* NewOwner = GetConnectedPinValue(InputPins[2]).GetActorArg();
			AsyncTask(ENamedThreads::GameThread, [this, NewOwner, FromLoopIndex]()
			{
				GetConnectedPinValue(InputPins[1]).GetActorArg()->SetOwner(NewOwner);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			GetConnectedPinValue(InputPins[1]).GetActorArg()->SetOwner(GetConnectedPinValue(InputPins[2]).GetActorArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}

UActor_GetOwner::UActor_GetOwner()
{
	NodeName = "Get Owner";
	NodeDescription = "Get the owner of this Actor, used primarily for network replication.";
	NodeCategory = "Actor";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Actor);// PinName + PinType
}

void UActor_GetOwner::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetActorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetOwner());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetActorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_IsOverlappingActor::UActor_IsOverlappingActor()
{
	NodeName = "Is Overlapping Actor";
	NodeDescription = "Check whether any component of this Actor is overlapping any component of another Actor.@param Other The other Actor to test against@return Whether any component of this Actor is overlapping any component of another Actor.";
	NodeCategory = "Actor|Collision";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	InputPins[1].MakeNodePin("Other", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}

void UActor_IsOverlappingActor::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->IsOverlappingActor(GetConnectedPinValue(InputPins[1]).GetActorArg()));
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_IsChildActor::UActor_IsChildActor()
{
	NodeName = "Is Child Actor";
	NodeDescription = "Returns whether this Actor was spawned by a child actor component";
	NodeCategory = "Actor";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}

void UActor_IsChildActor::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->IsChildActor());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetBoolArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_GetAllChildActors::UActor_GetAllChildActors()
{
	NodeName = "Get All Child Actors";
	NodeDescription = "Returns a list of all actors spawned by our Child Actor Components, including children of children.This does not return the contents of the Children array";
	NodeCategory = "Actor";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("Include Descendants", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(true); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodeArray("Child Actors", EVariableTypes::Actor);// PinName + PinType
}

void UActor_GetAllChildActors::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetActorArg())
    {
		TArray<AActor*> ChildActors;
		GetConnectedPinValue(InputPins[1]).GetActorArg()->GetAllChildActors(ChildActors, GetConnectedPinValue(InputPins[2]).GetBoolArg());
         
		OutputPins[1].Value.SetActorArg(ChildActors);
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_GetParentActor::UActor_GetParentActor()
{
	NodeName = "Get Parent Actor";
	NodeDescription = "If this Actor was created by a Child Actor Component returns the Actor that owns that Child Actor Component";
	NodeCategory = "Actor";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Actor);// PinName + PinType
}

void UActor_GetParentActor::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetActorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetParentActor());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetActorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_K2_TeleportTo::UActor_K2_TeleportTo()
{
	NodeName = "Teleport";
	NodeDescription = "Teleport this actor to a new location. If the actor doesn't fit exactly at the location specified, tries to slightly move it out of walls and such.@param DestLocation The target destination point@param DestRotation The target rotation at the destination@return true if the actor has been successfully moved, or false if it couldn't fit.";
	NodeCategory = "Actor|Utilities|Transformation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("Dest Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Dest Rotation", EVariableTypes::Rotator);// PinName + PinType
	InputPins[3].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}

void UActor_K2_TeleportTo::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		if (BPConstructor->GetMultiThread())
		{
			FVector DestLocation = GetConnectedPinValue(InputPins[2]).GetVectorArg();
			FRotator DestRotation = GetConnectedPinValue(InputPins[3]).GetRotatorArg();
			AsyncTask(ENamedThreads::GameThread, [this, DestLocation, DestRotation, FromLoopIndex]()
			{
				OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_TeleportTo(DestLocation, DestRotation));
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_TeleportTo(GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetRotatorArg()));
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}

UActor_GetAttachParentActor::UActor_GetAttachParentActor()
{
	NodeName = "Get Attach Parent Actor";
	NodeDescription = "Walk up the attachment chain from RootComponent until we encounter a different actor, and return it. If we are not attached to a component in a different actor, returns nullptr";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Actor);// PinName + PinType
}

void UActor_GetAttachParentActor::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetActorArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetAttachParentActor());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetActorArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_GetAttachParentSocketName::UActor_GetAttachParentSocketName()
{
	NodeName = "Get Attach Parent Socket Name";
	NodeDescription = "Walk up the attachment chain from RootComponent until we encounter a different actor, and return the socket name in the component. If we are not attached to a component in a different actor, returns NAME_None";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Name);// PinName + PinType
}

void UActor_GetAttachParentSocketName::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[0]).GetActorArg())
    {
		OutputPins[0].Value.Array[0].SetNameArg(GetConnectedPinValue(InputPins[0]).GetActorArg()->GetAttachParentSocketName());
    }
    else
    {
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetNameArg();
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_GetAttachedActors::UActor_GetAttachedActors()
{
	NodeName = "Get Attached Actors";
	NodeDescription = "Find all Actors which are attached directly to a component in this actor";
	NodeCategory = "Actor|Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodeArray("Out Actors", EVariableTypes::Actor);// PinName + PinType
}

void UActor_GetAttachedActors::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetActorArg())
    {
		TArray<AActor*> OutActors;
		GetConnectedPinValue(InputPins[1]).GetActorArg()->GetAttachedActors(OutActors);  
		OutputPins[1].Value.SetActorArg(OutActors);
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_GetActorEyesViewPoint::UActor_GetActorEyesViewPoint()
{
	NodeName = "Get Actor Eyes View Point";
	NodeDescription = "Returns the point of view of the actor.Note that this doesn't mean the camera, but the 'eyes' of the actor.For example, for a Pawn, this would define the eye height location,and view rotation (which is different from the pawn rotation which has a zeroed pitch component).A camera first person view will typically use this view point. Most traces (weapon, AI) will be done from this view point.@param	OutLocation - location of view point@param	OutRotation - view rotation of actor.";
	NodeCategory = "Actor";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Location", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Rotation", EVariableTypes::Rotator);// PinName + PinType
}

void UActor_GetActorEyesViewPoint::Execute(int Index, int FromLoopIndex)
{
    if (GetConnectedPinValue(InputPins[1]).GetActorArg())
    {
		FVector OutLocation;
		FRotator OutRotation;
		GetConnectedPinValue(InputPins[1]).GetActorArg()->GetActorEyesViewPoint(OutLocation, OutRotation);
		OutputPins[1].Value.Array[0].SetVectorArg(OutLocation);
		OutputPins[2].Value.Array[0].SetRotatorArg(OutRotation);
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UActor_K2_SetActorLocation::UActor_K2_SetActorLocation()
{
	NodeName = "Set Actor Location";
	NodeDescription = "Move the Actor to the specified location.@param NewLocation	The new location to move the Actor to.@param bSweep		Whether we sweep to the destination location, triggering overlaps along the way and stopping short of the target if blocked by something. Only the root component is swept and checked for blocking collision, child components move without sweeping. If collision is off, this has no effect. @param bTeleport		Whether we teleport the physics state (if physics collision is enabled for this object). If true, physics velocity for this object is unchanged (so ragdoll parts are not affected by change in location). If false, physics velocity is updated based on the change in position (affecting ragdoll parts).@param SweepHitResult	The hit result from the move if swept.@return	Whether the location was successfully set (if not swept), or whether movement occurred at all (if swept).";
	NodeCategory = "Actor|Utilities|Transformation";

	InputPins.SetNum(5);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Sweep", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	InputPins[4].MakeNodePin("Teleport", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
	OutputPins[1].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType    

}

void UActor_K2_SetActorLocation::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		FVector NewLocation = GetConnectedPinValue(InputPins[2]).GetVectorArg();
		bool Sweep = GetConnectedPinValue(InputPins[3]).GetBoolArg();
		bool Teleport = GetConnectedPinValue(InputPins[4]).GetBoolArg();

		if (BPConstructor->GetMultiThread())
		{

			AsyncTask(ENamedThreads::GameThread, [this, NewLocation, Sweep, Teleport, FromLoopIndex]()
			{
				FHitResult HitResult;
				OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_SetActorLocation(NewLocation, Sweep, HitResult, Teleport));
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			FHitResult HitResult;
			OutputPins[1].Value.Array[0].SetBoolArg(GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_SetActorLocation(NewLocation, Sweep, HitResult, Teleport));
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[1].Value.Array[0].SetBoolArg();
		Super::Execute(0, FromLoopIndex);// Index here is the array index	
	}
}

UActor_K2_SetActorRelativeLocation::UActor_K2_SetActorRelativeLocation()
{
	NodeName = "Set Actor Relative Location";
	NodeDescription = "Set the actor's RootComponent to the specified relative location.@param NewRelativeLocation	New relative location of the actor's root component@param bSweep					Whether we sweep to the destination location, triggering overlaps along the way and stopping short of the target if blocked by something. @param bTeleport				Whether we teleport the physics state (if physics collision is enabled for this object). If true, physics velocity for this object is unchanged (so ragdoll parts are not affected by change in location). If false, physics velocity is updated based on the change in position (affecting ragdoll parts).";
	NodeCategory = "Actor|Utilities|Transformation";

	InputPins.SetNum(5);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Relative Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Sweep", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	InputPins[4].MakeNodePin("Teleport", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}

void UActor_K2_SetActorRelativeLocation::Execute(int Index, int FromLoopIndex)
{
	AActor* Actor = GetConnectedPinValue(InputPins[1]).GetActorArg();
	if (Actor)
	{
		FVector NewLocation = GetConnectedPinValue(InputPins[2]).GetVectorArg();
		bool Sweep = GetConnectedPinValue(InputPins[3]).GetBoolArg();
		bool Teleport = GetConnectedPinValue(InputPins[4]).GetBoolArg();

		if (BPConstructor->GetMultiThread())
		{

			AsyncTask(ENamedThreads::GameThread, [this, Actor, NewLocation, Sweep, Teleport, FromLoopIndex]()
			{
				FHitResult HitResult;
				Actor->K2_SetActorRelativeLocation(NewLocation, Sweep, HitResult, Teleport);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			FHitResult HitResult;
			Actor->K2_SetActorRelativeLocation(NewLocation, Sweep, HitResult, Teleport);
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
}

UActor_K2_GetActorRelativeLocation::UActor_K2_GetActorRelativeLocation()
{
	NodeName = "Get Actor Relative Location";
	NodeDescription = "Returns the relative location of the RootComponent of this Actor";
	NodeCategory = "Actor|Utilities|Transformation";

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UActor_K2_GetActorRelativeLocation::Execute(int Index, int FromLoopIndex)
{
	AActor* Actor = GetConnectedPinValue(InputPins[0]).GetActorArg();

	if (Actor && Actor->GetRootComponent())
	{
		OutputPins[0].Value.Array[0].SetVectorArg(Actor->GetRootComponent()->GetRelativeLocation());

	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetVectorArg();
	}
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UActor_K2_SetActorRelativeRotation::UActor_K2_SetActorRelativeRotation()
{
	NodeName = "Set Actor Relative Rotation";
	NodeDescription = "Set the actor's RootComponent to the specified relative rotation.@param NewRelativeRotation	New relative rotation of the actor's root component.@param bSweep					Whether we sweep to the destination location, triggering overlaps along the way and stopping short of the target if blocked by something. Only the root component is swept and checked for blocking collision, child components move without sweeping. If collision is off, this has no effect.@param bTeleport				Whether we teleport the physics state (if physics collision is enabled for this object). If true, physics velocity for this object is unchanged (so ragdoll parts are not affected by change in location). If false, physics velocity is updated based on the change in position (affecting ragdoll parts).";
	NodeCategory = "Actor|Utilities|Transformation";

	InputPins.SetNum(4);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("New Relative Rotation", EVariableTypes::Rotator);// PinName + PinType
	InputPins[2].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[3].MakeNodePin("Teleport Physics", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
}

void UActor_K2_SetActorRelativeRotation::Execute(int Index, int FromLoopIndex)
{
	AActor* Actor = GetConnectedPinValue(InputPins[1]).GetActorArg();

	if (Actor)
	{
		if (BPConstructor->GetMultiThread())
		{
			FRotator NewRelativeRotation = GetConnectedPinValue(InputPins[2]).GetRotatorArg();
			bool TeleportPhysics = GetConnectedPinValue(InputPins[3]).GetBoolArg();

			AsyncTask(ENamedThreads::GameThread, [this, Actor, NewRelativeRotation, TeleportPhysics, FromLoopIndex]()
			{
				FHitResult HitResult;
				Actor->K2_SetActorRelativeRotation(NewRelativeRotation, false, HitResult, GetConnectedPinValue(InputPins[3]).GetBoolArg());
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			FHitResult HitResult;
			Actor->K2_SetActorRelativeRotation(GetConnectedPinValue(InputPins[2]).GetRotatorArg(), false, HitResult, GetConnectedPinValue(InputPins[3]).GetBoolArg());
			Super::Execute(0, FromLoopIndex);// Index here is the array index
		}
	}
}

UActor_K2_GetActorRelativeRotation::UActor_K2_GetActorRelativeRotation()
{
	NodeName = "Get Actor Relative Rotation";
	NodeDescription = "Returns the relative rotation of the RootComponent of this Actor.";
	NodeCategory = "Actor|Utilities|Transformation";

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[0].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UActor_K2_GetActorRelativeRotation::Execute(int Index, int FromLoopIndex)
{
	AActor* Actor = GetConnectedPinValue(InputPins[0]).GetActorArg();

	if (Actor && Actor->GetRootComponent())
	{

		OutputPins[0].Value.Array[0].SetRotatorArg(Actor->GetRootComponent()->GetRelativeRotation());

	}
	else
	{
		// We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
		OutputPins[0].Value.Array[0].SetRotatorArg();
	}
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UAttachActorToActor::UAttachActorToActor()
{
	NodeName = "Attach Actor to Actor";
	NodeDescription = "Attaches the RootComponent of this Actor to the RootComponent of the supplied actor, optionally at a named socket.@param ParentActor				Actor to attach this actor's RootComponent to.@param SocketName				Socket name to attach to, if any.@param LocationRule				How to handle translation when attaching.@param RotationRule				How to handle rotation when attaching.@param ScaleRule					How to handle scale when attaching.@param bWeldSimulatedBodies		Whether to weld together simulated physics bodies.";
	NodeCategory = "Actor|Utilities|Transformation";

	InputPins.SetNum(8);
	InputPins[0].MakeNodePin();// No args means execute

	InputPins[1].MakeNodePin("In Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	InputPins[2].MakeNodePin("Parent Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[2].Value.Array[0].SetActorArg(); // Default value

	InputPins[3].MakeNodePin("Socket Name", EVariableTypes::Name);// PinName + PinType
	InputPins[3].Value.Array[0].SetNameArg(); // Default value

	InputPins[4].MakeNodePin("Location Rule", EVariableTypes::Byte);// PinName + PinType
	InputPins[4].Value.Array[0].SetByteArg(); // Default value
	InputPins[4].Meta = "EAttachmentRule"; // Enum data

	InputPins[5].MakeNodePin("Rotation Rule", EVariableTypes::Byte);// PinName + PinType
	InputPins[5].Value.Array[0].SetByteArg(); // Default value
	InputPins[5].Meta = "EAttachmentRule"; // Enum data

	InputPins[6].MakeNodePin("Scale Rule", EVariableTypes::Byte);// PinName + PinType
	InputPins[6].Value.Array[0].SetByteArg(); // Default value
	InputPins[6].Meta = "EAttachmentRule"; // Enum data

	InputPins[7].MakeNodePin("Weld simulated Bodies", EVariableTypes::Bool);// PinName + PinType
	InputPins[7].Value.Array[0].SetBoolArg(true); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");
}

void UAttachActorToActor::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetActorArg())
	{
		GetConnectedPinValue(InputPins[1]).GetActorArg()->K2_AttachToActor(
			GetConnectedPinValue(InputPins[2]).GetActorArg(),
			GetConnectedPinValue(InputPins[3]).GetNameArg(),
			static_cast<EAttachmentRule>(GetConnectedPinValue(InputPins[4]).GetByteArg()),
			static_cast<EAttachmentRule>(GetConnectedPinValue(InputPins[5]).GetByteArg()),
			static_cast<EAttachmentRule>(GetConnectedPinValue(InputPins[6]).GetByteArg()),
			GetConnectedPinValue(InputPins[7]).GetBoolArg());
	}

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}