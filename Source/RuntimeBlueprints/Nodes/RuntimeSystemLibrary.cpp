// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeSystemLibrary.h"
#include "RuntimeBpConstructor.h"

UIsValid::UIsValid()
{
	NodeName = "Is Valid";
	NodeDescription = "Return true if the object is usable : non-null and not pending kill";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Object", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsValid::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetSystemLibrary::IsValid(GetConnectedPinValue(InputPins[0]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsValidClass::UIsValidClass()
{
	NodeName = "Is Valid Class";
	NodeDescription = "Return true if the class is usable : non-null and not pending kill";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Class", EVariableTypes::Class);// PinName + PinType
	InputPins[0].Value.Array[0].SetClassArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsValidClass::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetSystemLibrary::IsValidClass(GetConnectedPinValue(InputPins[0]).GetClassArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetObjectName::UGetObjectName()
{
	NodeName = "Get Object Name";
	NodeDescription = "Returns the actual object name.";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Object", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UGetObjectName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetSystemLibrary::GetObjectName(GetConnectedPinValue(InputPins[0]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetPathName::UGetPathName()
{
	NodeName = "Get Path Name";
	NodeDescription = "Returns the full path to the specified object.";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Object", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UGetPathName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetSystemLibrary::GetPathName(GetConnectedPinValue(InputPins[0]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetDisplayName::UGetDisplayName()
{
	NodeName = "Get Display Name";
	NodeDescription = "Note: In editor builds, this is the actor label.  In non-editor builds, this is the actual object name.  This function should not be used to uniquely identify actors!";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Object", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UGetDisplayName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetSystemLibrary::GetDisplayName(GetConnectedPinValue(InputPins[0]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetClassDisplayName::UGetClassDisplayName()
{
	NodeName = "Get Class Display Name";
	NodeDescription = "Returns the display name of a class";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Class", EVariableTypes::Class);// PinName + PinType
	InputPins[0].Value.Array[0].SetClassArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UGetClassDisplayName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetSystemLibrary::GetClassDisplayName(GetConnectedPinValue(InputPins[0]).GetClassArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetOuterObject::UGetOuterObject()
{
	NodeName = "Get Outer Object";
	NodeDescription = "Returns the outer object of an object.";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Object", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Object);// PinName + PinType
}


void UGetOuterObject::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetObjectArg(UKismetSystemLibrary::GetOuterObject(GetConnectedPinValue(InputPins[0]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetGameTimeInSeconds::UGetGameTimeInSeconds()
{
	NodeName = "Get Game Time In Seconds";
	NodeDescription = "Get the current game time, in seconds. This stops when the game is paused and is affected by slomo.@param WorldContextObject	World context";
	NodeCategory = "Utilities|Time";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetGameTimeInSeconds::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetSystemLibrary::GetGameTimeInSeconds(this));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsServer::UIsServer()
{
	NodeName = "Is Server";
	NodeDescription = "Returns whether the world this object is in is the host or not";
	NodeCategory = "Networking";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsServer::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetSystemLibrary::IsServer(this));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsDedicatedServer::UIsDedicatedServer()
{
	NodeName = "Is Dedicated Server";
	NodeDescription = "Returns whether this is running on a dedicated server";
	NodeCategory = "Networking";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsDedicatedServer::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetSystemLibrary::IsDedicatedServer(this));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsStandalone::UIsStandalone()
{
	NodeName = "Is Standalone";
	NodeDescription = "Returns whether this game instance is stand alone (no networking).";
	NodeCategory = "Networking";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsStandalone::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetSystemLibrary::IsStandalone(this));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeLiteralInt::UMakeLiteralInt()
{
	NodeName = "Make Literal Int";
	NodeDescription = "Creates a literal integer@param	Value	value to set the integer to@return	The literal integer";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UMakeLiteralInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetSystemLibrary::MakeLiteralInt(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeLiteralFloat::UMakeLiteralFloat()
{
	NodeName = "Make Literal Float";
	NodeDescription = "Creates a literal float@param	Value	value to set the float to@return	The literal float";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMakeLiteralFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetSystemLibrary::MakeLiteralFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeLiteralBool::UMakeLiteralBool()
{
	NodeName = "Make Literal Bool";
	NodeDescription = "Creates a literal bool@param	Value	value to set the bool to@return	The literal bool";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UMakeLiteralBool::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetSystemLibrary::MakeLiteralBool(GetConnectedPinValue(InputPins[0]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeLiteralName::UMakeLiteralName()
{
	NodeName = "Make Literal Name";
	NodeDescription = "Creates a literal name@param	Value	value to set the name to@return	The literal name";
	NodeCategory = "Utilities|Name";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Name);// PinName + PinType
	InputPins[0].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Name);// PinName + PinType
}


void UMakeLiteralName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetNameArg(UKismetSystemLibrary::MakeLiteralName(GetConnectedPinValue(InputPins[0]).GetNameArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeLiteralByte::UMakeLiteralByte()
{
	NodeName = "Make Literal Byte";
	NodeDescription = "Creates a literal byte@param	Value	value to set the byte to@return	The literal byte";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UMakeLiteralByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetSystemLibrary::MakeLiteralByte(GetConnectedPinValue(InputPins[0]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeLiteralString::UMakeLiteralString()
{
	NodeName = "Make Literal String";
	NodeDescription = "Creates a literal string@param	Value	value to set the string to@return	The literal string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UMakeLiteralString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetSystemLibrary::MakeLiteralString(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeLiteralText::UMakeLiteralText()
{
	NodeName = "Make Literal Text";
	NodeDescription = "Creates a literal FText@param	Value	value to set the FText to@return	The literal FText";
	NodeCategory = "Utilities|Text";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Text);// PinName + PinType
	InputPins[0].Value.Array[0].SetTextArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Text);// PinName + PinType
}


void UMakeLiteralText::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTextArg(UKismetSystemLibrary::MakeLiteralText(GetConnectedPinValue(InputPins[0]).GetTextArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USetWindowTitle::USetWindowTitle()
{
	NodeName = "Set Window Title";
	NodeDescription = "Sets the game window title";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Title", EVariableTypes::Text);// PinName + PinType
	InputPins[1].Value.Array[0].SetTextArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void USetWindowTitle::Execute(int Index, int FromLoopIndex)
{
    
		UKismetSystemLibrary::SetWindowTitle(GetConnectedPinValue(InputPins[1]).GetTextArg());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetComponentBounds::UGetComponentBounds()
{
	NodeName = "Get Component Bounds";
	NodeDescription = "Get bounds";
	NodeCategory = "Collision";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Component", EVariableTypes::SceneComponent);// PinName + PinType
	InputPins[1].Value.Array[0].SetSceneComponentArg(); // Default value

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Origin", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Box Extent", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[3].MakeNodePin("Sphere Radius", EVariableTypes::Float);// PinName + PinType
}


void UGetComponentBounds::Execute(int Index, int FromLoopIndex)
{
    FVector Origin;
	FVector BoxExtent;
	float SphereRadius;
	UKismetSystemLibrary::GetComponentBounds(GetConnectedPinValue(InputPins[1]).GetSceneComponentArg(), Origin, BoxExtent, SphereRadius);
    
	OutputPins[1].Value.Array[0].SetVectorArg(Origin);
	OutputPins[2].Value.Array[0].SetVectorArg(BoxExtent);
	OutputPins[3].Value.Array[0].SetFloatArg(SphereRadius);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetActorBounds::UGetActorBounds()
{
	NodeName = "Get Actor Bounds";
	NodeDescription = "";
	NodeCategory = "Collision";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Actor", EVariableTypes::Actor);// PinName + PinType
	InputPins[1].Value.Array[0].SetActorArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Origin", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Box Extent", EVariableTypes::Vector);// PinName + PinType
}


void UGetActorBounds::Execute(int Index, int FromLoopIndex)
{
    FVector Origin;
	FVector BoxExtent;
	UKismetSystemLibrary::GetActorBounds(GetConnectedPinValue(InputPins[1]).GetActorArg(), Origin, BoxExtent);
    
	OutputPins[1].Value.Array[0].SetVectorArg(Origin);
	OutputPins[2].Value.Array[0].SetVectorArg(BoxExtent);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USetSuppressViewportTransitionMessage::USetSuppressViewportTransitionMessage()
{
	NodeName = "Set Suppress Viewport Transition Message";
	NodeDescription = "Sets the state of the transition message rendered by the viewport. (The blue text displayed when the game is paused and so forth.)@param WorldContextObject	World context@param State					set true to suppress transition message";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("b State", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void USetSuppressViewportTransitionMessage::Execute(int Index, int FromLoopIndex)
{
    
		UKismetSystemLibrary::SetSuppressViewportTransitionMessage(this, GetConnectedPinValue(InputPins[1]).GetBoolArg());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

