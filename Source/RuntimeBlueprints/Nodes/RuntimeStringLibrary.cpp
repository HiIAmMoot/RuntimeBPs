// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeStringLibrary.h"
#include "RuntimeBpConstructor.h"

UConv_FloatToString::UConv_FloatToString()
{
	NodeName = "Conv Float To String";
	NodeDescription = "Converts a float value to a string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Float", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_FloatToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_FloatToString(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_IntToString::UConv_IntToString()
{
	NodeName = "Conv Int To String";
	NodeDescription = "Converts an integer value to a string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Int", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_IntToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_IntToString(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_ByteToString::UConv_ByteToString()
{
	NodeName = "Conv Byte To String";
	NodeDescription = "Converts a byte value to a string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Byte", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_ByteToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_ByteToString(GetConnectedPinValue(InputPins[0]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_BoolToString::UConv_BoolToString()
{
	NodeName = "Conv Bool To String";
	NodeDescription = "Converts a boolean value to a string, either 'true' or 'false'";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Bool", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_BoolToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_BoolToString(GetConnectedPinValue(InputPins[0]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_VectorToString::UConv_VectorToString()
{
	NodeName = "Conv Vector To String";
	NodeDescription = "Converts a vector value to a string, in the form 'X= Y= Z='";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vec", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_VectorToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_VectorToString(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_IntVectorToString::UConv_IntVectorToString()
{
	NodeName = "Conv Int Vector To String";
	NodeDescription = "Converts an IntVector value to a string, in the form 'X= Y= Z='";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Int Vec", EVariableTypes::IntVector);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_IntVectorToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_IntVectorToString(GetConnectedPinValue(InputPins[0]).GetIntVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_Vector2dToString::UConv_Vector2dToString()
{
	NodeName = "Conv Vector2d To String";
	NodeDescription = "Converts a vector2d value to a string, in the form 'X= Y='";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vec", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_Vector2dToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_Vector2dToString(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_RotatorToString::UConv_RotatorToString()
{
	NodeName = "Conv Rotator To String";
	NodeDescription = "Converts a rotator value to a string, in the form 'P= Y= R='";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_RotatorToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_RotatorToString(GetConnectedPinValue(InputPins[0]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_TransformToString::UConv_TransformToString()
{
	NodeName = "Conv Transform To String";
	NodeDescription = "Converts a transform value to a string, in the form 'Translation: X= Y= Z= Rotation: P= Y= R= Scale: X= Y= Z='";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Trans", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_TransformToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_TransformToString(GetConnectedPinValue(InputPins[0]).GetTransformArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_ObjectToString::UConv_ObjectToString()
{
	NodeName = "Conv Object To String";
	NodeDescription = "Converts a UObject value to a string by calling the object's GetName method";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Obj", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_ObjectToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_ObjectToString(GetConnectedPinValue(InputPins[0]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_ColorToString::UConv_ColorToString()
{
	NodeName = "Conv Color To String";
	NodeDescription = "Converts a linear color value to a string, in the form '(R=,G=,B=,A=)'";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_ColorToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_ColorToString(GetConnectedPinValue(InputPins[0]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_NameToString::UConv_NameToString()
{
	NodeName = "Conv Name To String";
	NodeDescription = "Converts a name value to a string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Name", EVariableTypes::Name);// PinName + PinType
	InputPins[0].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConv_NameToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Conv_NameToString(GetConnectedPinValue(InputPins[0]).GetNameArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_StringToName::UConv_StringToName()
{
	NodeName = "Conv String To Name";
	NodeDescription = "Converts a string to a name value";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Name);// PinName + PinType
}


void UConv_StringToName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetNameArg(UKismetStringLibrary::Conv_StringToName(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_StringToInt::UConv_StringToInt()
{
	NodeName = "Conv String To Int";
	NodeDescription = "Converts a string to a int value";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UConv_StringToInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetStringLibrary::Conv_StringToInt(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_StringToFloat::UConv_StringToFloat()
{
	NodeName = "Conv String To Float";
	NodeDescription = "Converts a string to a float value";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UConv_StringToFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetStringLibrary::Conv_StringToFloat(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_StringToVector::UConv_StringToVector()
{
	NodeName = "Conv String To Vector";
	NodeDescription = "Convert String Back To Vector. IsValid indicates whether or not the string could be successfully converted.";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In String", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Converted Vector", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Is Valid", EVariableTypes::Bool);// PinName + PinType
}


void UConv_StringToVector::Execute(int Index, int FromLoopIndex)
{
    FVector OutConvertedVector;
	bool OutIsValid;
	UKismetStringLibrary::Conv_StringToVector(GetConnectedPinValue(InputPins[1]).GetStringArg(), OutConvertedVector, OutIsValid);
    
	OutputPins[1].Value.Array[0].SetVectorArg(OutConvertedVector);
	OutputPins[2].Value.Array[0].SetBoolArg(OutIsValid);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_StringToVector2D::UConv_StringToVector2D()
{
	NodeName = "Conv String To Vector2D";
	NodeDescription = "Convert String Back To Vector2D. IsValid indicates whether or not the string could be successfully converted.";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In String", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Converted Vector2D", EVariableTypes::Vector2D);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Is Valid", EVariableTypes::Bool);// PinName + PinType
}


void UConv_StringToVector2D::Execute(int Index, int FromLoopIndex)
{
    FVector2D OutConvertedVector2D;
	bool OutIsValid;
	UKismetStringLibrary::Conv_StringToVector2D(GetConnectedPinValue(InputPins[1]).GetStringArg(), OutConvertedVector2D, OutIsValid);
    
	OutputPins[1].Value.Array[0].SetVector2DArg(OutConvertedVector2D);
	OutputPins[2].Value.Array[0].SetBoolArg(OutIsValid);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_StringToRotator::UConv_StringToRotator()
{
	NodeName = "Conv String To Rotator";
	NodeDescription = "Convert String Back To Rotator. IsValid indicates whether or not the string could be successfully converted.";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In String", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Converted Rotator", EVariableTypes::Rotator);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Is Valid", EVariableTypes::Bool);// PinName + PinType
}


void UConv_StringToRotator::Execute(int Index, int FromLoopIndex)
{
    FRotator OutConvertedRotator;
	bool OutIsValid;
	UKismetStringLibrary::Conv_StringToRotator(GetConnectedPinValue(InputPins[1]).GetStringArg(), OutConvertedRotator, OutIsValid);
    
	OutputPins[1].Value.Array[0].SetRotatorArg(OutConvertedRotator);
	OutputPins[2].Value.Array[0].SetBoolArg(OutIsValid);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_StringToColor::UConv_StringToColor()
{
	NodeName = "Conv String To Color";
	NodeDescription = "Convert String Back To Color. IsValid indicates whether or not the string could be successfully converted.";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In String", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Converted Color", EVariableTypes::LinearColor);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Is Valid", EVariableTypes::Bool);// PinName + PinType
}


void UConv_StringToColor::Execute(int Index, int FromLoopIndex)
{
    FLinearColor OutConvertedColor;
	bool OutIsValid;
	UKismetStringLibrary::Conv_StringToColor(GetConnectedPinValue(InputPins[1]).GetStringArg(), OutConvertedColor, OutIsValid);
    
	OutputPins[1].Value.Array[0].SetLinearColorArg(OutConvertedColor);
	OutputPins[2].Value.Array[0].SetBoolArg(OutIsValid);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Float::UBuildString_Float()
{
	NodeName = "Build String Float";
	NodeDescription = "Converts a float->string, create a new string in the form AppendTo+Prefix+InFloat+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InFloat - The float value to convert@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Float", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Float::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Float(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Int::UBuildString_Int()
{
	NodeName = "Build String Int";
	NodeDescription = "Converts a int->string, creating a new string in the form AppendTo+Prefix+InInt+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InInt - The int value to convert@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Int", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Int::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Int(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetIntArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Bool::UBuildString_Bool()
{
	NodeName = "Build String Bool";
	NodeDescription = "Converts a boolean->string, creating a new string in the form AppendTo+Prefix+InBool+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InBool - The bool value to convert. Will add 'true' or 'false' to the conversion string@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Bool", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Bool::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Bool(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Vector::UBuildString_Vector()
{
	NodeName = "Build String Vector";
	NodeDescription = "Converts a vector->string, creating a new string in the form AppendTo+Prefix+InVector+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InVector - The vector value to convert. Uses the standard FVector::ToString conversion@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Vector", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Vector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Vector(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_IntVector::UBuildString_IntVector()
{
	NodeName = "Build String Int Vector";
	NodeDescription = "Converts an IntVector->string, creating a new string in the form AppendTo+Prefix+InIntVector+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InIntVector - The intVector value to convert. Uses the standard FVector::ToString conversion@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Int Vector", EVariableTypes::IntVector);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntVectorArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_IntVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_IntVector(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetIntVectorArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Vector2d::UBuildString_Vector2d()
{
	NodeName = "Build String Vector2d";
	NodeDescription = "Converts a vector2d->string, creating a new string in the form AppendTo+Prefix+InVector2d+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InVector2d - The vector2d value to convert. Uses the standard FVector2D::ToString conversion@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Vector2d", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[2].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Vector2d::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Vector2d(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetVector2DArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Rotator::UBuildString_Rotator()
{
	NodeName = "Build String Rotator";
	NodeDescription = "Converts a rotator->string, creating a new string in the form AppendTo+Prefix+InRot+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InRot	- The rotator value to convert. Uses the standard ToString conversion@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[2].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Rotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Rotator(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetRotatorArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Object::UBuildString_Object()
{
	NodeName = "Build String Object";
	NodeDescription = "Converts a object->string, creating a new string in the form AppendTo+Prefix+object name+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InObj - The object to convert. Will insert the name of the object into the conversion string@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Obj", EVariableTypes::Object);// PinName + PinType
	InputPins[2].Value.Array[0].SetObjectArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Object::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Object(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetObjectArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Color::UBuildString_Color()
{
	NodeName = "Build String Color";
	NodeDescription = "Converts a color->string, creating a new string in the form AppendTo+Prefix+InColor+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InColor - The linear color value to convert. Uses the standard ToString conversion@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[2].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Color::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Color(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetLinearColorArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBuildString_Name::UBuildString_Name()
{
	NodeName = "Build String Name";
	NodeDescription = "Converts a color->string, creating a new string in the form AppendTo+Prefix+InName+Suffix@param AppendTo - An existing string to use as the start of the conversion string@param Prefix - A string to use as a prefix, after the AppendTo string@param InName - The name value to convert@param Suffix - A suffix to append to the end of the conversion string@return A new string built from the passed parameters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Append To", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Prefix", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("In Name", EVariableTypes::Name);// PinName + PinType
	InputPins[2].Value.Array[0].SetNameArg(); // Default value

	InputPins[3].MakeNodePin("Suffix", EVariableTypes::String);// PinName + PinType
	InputPins[3].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UBuildString_Name::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::BuildString_Name(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetNameArg(), GetConnectedPinValue(InputPins[3]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConcat_StrStr::UConcat_StrStr()
{
	NodeName = "Concat Str Str";
	NodeDescription = "Concatenates two strings together to make a new string@param A - The original string@param B - The string to append to A@returns A new string which is the concatenation of A+B";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UConcat_StrStr::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Concat_StrStr(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_StrStr::UEqualEqual_StrStr()
{
	NodeName = "Equal Equal Str Str";
	NodeDescription = "Test if the input strings are equal (A == B)@param A - The string to compare against@param B - The string to compare@returns True if the strings are equal, false otherwise";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_StrStr::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetStringLibrary::EqualEqual_StrStr(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_StriStri::UEqualEqual_StriStri()
{
	NodeName = "Equal Equal Stri Stri";
	NodeDescription = "Test if the input strings are equal (A == B), ignoring case@param A - The string to compare against@param B - The string to compare@returns True if the strings are equal, false otherwise";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_StriStri::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetStringLibrary::EqualEqual_StriStri(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_StrStr::UNotEqual_StrStr()
{
	NodeName = "Not Equal Str Str";
	NodeDescription = "Test if the input string are not equal (A != B)@param A - The string to compare against@param B - The string to compare@return Returns true if the input strings are not equal, false if they are equal";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_StrStr::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetStringLibrary::NotEqual_StrStr(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_StriStri::UNotEqual_StriStri()
{
	NodeName = "Not Equal Stri Stri";
	NodeDescription = "@param A - The string to compare against@param B - The string to compare@return Returns true if the input strings are not equal, false if they are equal";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_StriStri::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetStringLibrary::NotEqual_StriStri(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULen::ULen()
{
	NodeName = "Len";
	NodeDescription = "Returns the number of characters in the string@param SourceString - The string to measure@return The number of chars in the string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("S", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void ULen::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetStringLibrary::Len(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetSubstring::UGetSubstring()
{
	NodeName = "Get Substring";
	NodeDescription = "Returns a substring from the string starting at the specified position@param SourceString - The string to get the substring from@param StartIndex - The location in SourceString to use as the start of the substring@param Length The length of the requested substring@return The requested substring";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Start Index", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(0); // Default value

	InputPins[2].MakeNodePin("Length", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UGetSubstring::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::GetSubstring(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg(), GetConnectedPinValue(InputPins[2]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFindSubstring::UFindSubstring()
{
	NodeName = "Find Substring";
	NodeDescription = "Finds the starting index of a substring in the a specified string@param SearchIn The string to search within@param Substring The string to look for in the SearchIn string@param bUseCase Whether or not to be case-sensitive@param bSearchFromEnd Whether or not to start the search from the end of the string instead of the beginning@param StartPosition The position to start the search from@return The index (starting from 0 if bSearchFromEnd is false) of the first occurence of the substring";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin("Search In", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Substring", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("b Use Case", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[3].MakeNodePin("b Search From End", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[4].MakeNodePin("Start Position", EVariableTypes::Int);// PinName + PinType
	InputPins[4].Value.Array[0].SetIntArg(-1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UFindSubstring::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetStringLibrary::FindSubstring(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UContains::UContains()
{
	NodeName = "Contains";
	NodeDescription = "Returns whether this string contains the specified substring.@param SubStr			Find to search for@param SearchCase		Indicates whether the search is case sensitive or not ( defaults to ESearchCase::IgnoreCase )@param SearchDir			Indicates whether the search starts at the begining or at the end ( defaults to ESearchDir::FromStart )@return					Returns whether the string contains the substring";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Search In", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Substring", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("b Use Case", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(false); // Default value

	InputPins[3].MakeNodePin("b Search From End", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UContains::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetStringLibrary::Contains(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetCharacterAsNumber::UGetCharacterAsNumber()
{
	NodeName = "Get Character As Number";
	NodeDescription = "Gets a single character from the string (as an integer)@param SourceString - The string to convert@param Index - Location of the character whose value is required@return The integer value of the character or 0 if index is out of range";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Index", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(0); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UGetCharacterAsNumber::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetStringLibrary::GetCharacterAsNumber(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UParseIntoArray::UParseIntoArray()
{
	NodeName = "Parse Into Array";
	NodeDescription = "Gets an array of strings from a source string divided up by a separator and empty strings can optionally be culled.@param SourceString - The string to chop up@param Delimiter - The string to delimit on@param CullEmptyStrings = true - Cull (true) empty strings or add them to the array (false)@return The array of string that have been separated";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Delimiter", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(FString(TEXT(" "))); // Default value

	InputPins[2].MakeNodePin("Cull Empty Strings", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(true); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodeArray("Return", EVariableTypes::String);// PinName + PinType
}


void UParseIntoArray::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.SetStringArg(UKismetStringLibrary::ParseIntoArray(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UJoinStringArray::UJoinStringArray()
{
	NodeName = "Join String Array";
	NodeDescription = "Concatenates an array of strings into a single string.@param SourceArray - The array of strings to concatenate.@param Separator - The string used to separate each element.@return The final, joined, separated string.";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodeArray("Source Array", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Separator", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(FString(TEXT(" "))); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UJoinStringArray::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::JoinStringArray(GetConnectedPinArray(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetCharacterArrayFromString::UGetCharacterArrayFromString()
{
	NodeName = "Get Character Array From String";
	NodeDescription = "Returns an array that contains one entry for each character in SourceString@param	SourceString	The string to break apart into characters@return	An array containing one entry for each character in SourceString";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodeArray("Return", EVariableTypes::String);// PinName + PinType
}


void UGetCharacterArrayFromString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.SetStringArg(UKismetStringLibrary::GetCharacterArrayFromString(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UToUpper::UToUpper()
{
	NodeName = "To Upper";
	NodeDescription = "Returns a string converted to Upper case@param	SourceString	The string to convert@return	The string in upper case";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UToUpper::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::ToUpper(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UToLower::UToLower()
{
	NodeName = "To Lower";
	NodeDescription = "Returns a string converted to Lower case@param	SourceString	The string to convert@return	The string in lower case";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UToLower::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::ToLower(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULeftPad::ULeftPad()
{
	NodeName = "Left Pad";
	NodeDescription = "Pad the left of this string for a specified number of characters@param	SourceString	The string to pad@param	ChCount			Amount of padding required@return	The padded string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Ch Count", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void ULeftPad::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::LeftPad(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URightPad::URightPad()
{
	NodeName = "Right Pad";
	NodeDescription = "Pad the right of this string for a specified number of characters@param	SourceString	The string to pad@param	ChCount			Amount of padding required@return	The padded string";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Ch Count", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void URightPad::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::RightPad(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsNumeric::UIsNumeric()
{
	NodeName = "Is Numeric";
	NodeDescription = "Checks if a string contains only numeric characters@param	SourceString	The string to check@return true if the string only contains numeric characters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsNumeric::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetStringLibrary::IsNumeric(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTrim::UTrim()
{
	NodeName = "Trim";
	NodeDescription = "Removes whitespace characters from the front of this string.";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UTrim::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Trim(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTrimTrailing::UTrimTrailing()
{
	NodeName = "Trim Trailing";
	NodeDescription = "Removes trailing whitespace characters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UTrimTrailing::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::TrimTrailing(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCullArray::UCullArray()
{
	NodeName = "Cull Array";
	NodeDescription = "Takes an array of strings and removes any zero length entries.@param	InArray	The array to cull@return	The number of elements left in InArray";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType    
    OutputPins[1].MakeNodeArray("In Array", EVariableTypes::String);// PinName + PinType
}


void UCullArray::Execute(int Index, int FromLoopIndex)
{
    TArray<FString> InArray;
	OutputPins[0].Value.Array[0].SetIntArg(UKismetStringLibrary::CullArray(GetConnectedPinValue(InputPins[0]).GetStringArg(), InArray));
    
	OutputPins[1].Value.SetStringArg(InArray);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UReverse::UReverse()
{
	NodeName = "Reverse";
	NodeDescription = "Returns a copy of this string, with the characters in reverse order";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UReverse::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Reverse(GetConnectedPinValue(InputPins[0]).GetStringArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULeft::ULeft()
{
	NodeName = "Left";
	NodeDescription = "Returns the left most given number of characters";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Count", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void ULeft::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Left(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULeftChop::ULeftChop()
{
	NodeName = "Left Chop";
	NodeDescription = "Returns the left most characters from the string chopping the given number of characters from the end";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Count", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void ULeftChop::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::LeftChop(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URight::URight()
{
	NodeName = "Right";
	NodeDescription = "Returns the string to the right of the specified location, counting back from the right (end of the word).";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Count", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void URight::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Right(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URightChop::URightChop()
{
	NodeName = "Right Chop";
	NodeDescription = "Returns the string to the right of the specified location, counting forward from the left (from the beginning of the word).";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Count", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void URightChop::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::RightChop(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMid::UMid()
{
	NodeName = "Mid";
	NodeDescription = "Returns the substring from Start position for Count characters.";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Source String", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("Start", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	InputPins[2].MakeNodePin("Count", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UMid::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::Mid(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetIntArg(), GetConnectedPinValue(InputPins[2]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTimeSecondsToString::UTimeSecondsToString()
{
	NodeName = "Time Seconds To String";
	NodeDescription = "Convert a number of seconds into minutes:seconds.milliseconds format string (including leading zeroes)@return A new string built from the seconds parameter";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Seconds", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void UTimeSecondsToString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetStringLibrary::TimeSecondsToString(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

