// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeMathLibrary.h"
#include "RuntimeBpConstructor.h"

URandomBool::URandomBool()
{
	NodeName = "Random Bool";
	NodeDescription = "Returns a uniformly distributed random bool";
	NodeCategory = "Math|Random";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void URandomBool::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::RandomBool());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomBoolWithWeight::URandomBoolWithWeight()
{
	NodeName = "Random Bool With Weight";
	NodeDescription = "Get a random chance with the specified weight. Range of weight is 0.0 - 1.0 E.g.,Weight = .6 return value = True 60% of the time";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Weight", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void URandomBoolWithWeight::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::RandomBoolWithWeight(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNot_PreBool::UNot_PreBool()
{
	NodeName = "NOT Boolean";
	NodeDescription = "Returns the logical complement of the Boolean value (NOT A)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNot_PreBool::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Not_PreBool(GetConnectedPinValue(InputPins[0]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_BoolBool::UEqualEqual_BoolBool()
{
	NodeName = "Equal Boolean";
	NodeDescription = "Returns true if the values are equal (A == B)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_BoolBool::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_BoolBool(GetConnectedPinValue(InputPins[0]).GetBoolArg(), GetConnectedPinValue(InputPins[1]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_BoolBool::UNotEqual_BoolBool()
{
	NodeName = "Not Equal Boolean";
	NodeDescription = "Returns true if the values are not equal (A != B)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_BoolBool::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_BoolBool(GetConnectedPinValue(InputPins[0]).GetBoolArg(), GetConnectedPinValue(InputPins[1]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBooleanAND::UBooleanAND()
{
	NodeName = "AND Boolean";
	NodeDescription = "Returns the logical AND of two values (A AND B)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UBooleanAND::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::BooleanAND(GetConnectedPinValue(InputPins[0]).GetBoolArg(), GetConnectedPinValue(InputPins[1]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBooleanNAND::UBooleanNAND()
{
	NodeName = "NAND Boolean";
	NodeDescription = "Returns the logical NAND of two values (A AND B)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UBooleanNAND::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::BooleanNAND(GetConnectedPinValue(InputPins[0]).GetBoolArg(), GetConnectedPinValue(InputPins[1]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBooleanOR::UBooleanOR()
{
	NodeName = "OR Boolean";
	NodeDescription = "Returns the logical OR of two values (A OR B)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UBooleanOR::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::BooleanOR(GetConnectedPinValue(InputPins[0]).GetBoolArg(), GetConnectedPinValue(InputPins[1]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBooleanXOR::UBooleanXOR()
{
	NodeName = "XOR Boolean";
	NodeDescription = "Returns the logical eXclusive OR of two values (A XOR B)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UBooleanXOR::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::BooleanXOR(GetConnectedPinValue(InputPins[0]).GetBoolArg(), GetConnectedPinValue(InputPins[1]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBooleanNOR::UBooleanNOR()
{
	NodeName = "NOR Boolean";
	NodeDescription = "Returns the logical Not OR of two values (A NOR B)";
	NodeCategory = "Math|Boolean";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Bool);// PinName + PinType
	InputPins[1].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UBooleanNOR::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::BooleanNOR(GetConnectedPinValue(InputPins[0]).GetBoolArg(), GetConnectedPinValue(InputPins[1]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_ByteByte::UMultiply_ByteByte()
{
	NodeName = "Byte * Byte";
	NodeDescription = "Multiplication (A  B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UMultiply_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::Multiply_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_ByteByte::UDivide_ByteByte()
{
	NodeName = "Byte / Byte";
	NodeDescription = "Division (A  B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UDivide_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::Divide_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPercent_ByteByte::UPercent_ByteByte()
{
	NodeName = "% (Byte";
	NodeDescription = "Modulo (A % B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UPercent_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::Percent_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_ByteByte::UAdd_ByteByte()
{
	NodeName = "Byte + Byte";
	NodeDescription = "Addition (A + B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UAdd_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::Add_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_ByteByte::USubtract_ByteByte()
{
	NodeName = "Byte - Byte";
	NodeDescription = "Subtraction (A - B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void USubtract_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::Subtract_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBMin::UBMin()
{
	NodeName = "Min (Byte";
	NodeDescription = "Returns the minimum value of A and B";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UBMin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::BMin(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBMax::UBMax()
{
	NodeName = "Max (Byte";
	NodeDescription = "Returns the maximum value of A and B";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UBMax::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::BMax(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULess_ByteByte::ULess_ByteByte()
{
	NodeName = "Byte < Byte";
	NodeDescription = "Returns true if A is less than B (A < B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void ULess_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Less_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGreater_ByteByte::UGreater_ByteByte()
{
	NodeName = "Byte > Byte";
	NodeDescription = "Returns true if A is greater than B (A > B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UGreater_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Greater_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULessEqual_ByteByte::ULessEqual_ByteByte()
{
	NodeName = "Byte <= Byte";
	NodeDescription = "Returns true if A is less than or equal to B (A <= B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void ULessEqual_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::LessEqual_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGreaterEqual_ByteByte::UGreaterEqual_ByteByte()
{
	NodeName = "Byte >= Byte";
	NodeDescription = "Returns true if A is greater than or equal to B (A >= B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UGreaterEqual_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::GreaterEqual_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_ByteByte::UEqualEqual_ByteByte()
{
	NodeName = "Equal (Byte";
	NodeDescription = "Returns true if A is equal to B (A == B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_ByteByte::UNotEqual_ByteByte()
{
	NodeName = "Not Equal (Byte";
	NodeDescription = "Returns true if A is not equal to B (A != B)";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_ByteByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_ByteByte(GetConnectedPinValue(InputPins[0]).GetByteArg(), GetConnectedPinValue(InputPins[1]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_IntInt::UMultiply_IntInt()
{
	NodeName = "integer * integer";
	NodeDescription = "Multiplication (A  B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UMultiply_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Multiply_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_IntInt::UDivide_IntInt()
{
	NodeName = "integer / integer";
	NodeDescription = "Division (A  B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UDivide_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Divide_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPercent_IntInt::UPercent_IntInt()
{
	NodeName = "% (integer";
	NodeDescription = "Modulo (A % B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UPercent_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Percent_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_IntInt::UAdd_IntInt()
{
	NodeName = "integer + integer";
	NodeDescription = "Addition (A + B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UAdd_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Add_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_IntInt::USubtract_IntInt()
{
	NodeName = "integer - integer";
	NodeDescription = "Subtraction (A - B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void USubtract_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Subtract_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULess_IntInt::ULess_IntInt()
{
	NodeName = "integer < integer";
	NodeDescription = "Returns true if A is less than B (A < B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void ULess_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Less_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGreater_IntInt::UGreater_IntInt()
{
	NodeName = "integer > integer";
	NodeDescription = "Returns true if A is greater than B (A > B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UGreater_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Greater_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULessEqual_IntInt::ULessEqual_IntInt()
{
	NodeName = "integer <= integer";
	NodeDescription = "Returns true if A is less than or equal to B (A <= B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void ULessEqual_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::LessEqual_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGreaterEqual_IntInt::UGreaterEqual_IntInt()
{
	NodeName = "integer >= integer";
	NodeDescription = "Returns true if A is greater than or equal to B (A >= B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UGreaterEqual_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::GreaterEqual_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_IntInt::UEqualEqual_IntInt()
{
	NodeName = "Equal (integer";
	NodeDescription = "Returns true if A is equal to B (A == B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_IntInt::UNotEqual_IntInt()
{
	NodeName = "Not Equal (integer";
	NodeDescription = "Returns true if A is not equal to B (A != B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UInRange_IntInt::UInRange_IntInt()
{
	NodeName = "In Range (integer";
	NodeDescription = "If InclusiveMin is true, value needs to be equal or larger than Min, else it needs to be largerIf InclusiveMax is true, value needs to be smaller or equal than Max, else it needs to be smaller";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("Min", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	InputPins[2].MakeNodePin("Max", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	InputPins[3].MakeNodePin("Inclusive Min", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(true); // Default value

	InputPins[4].MakeNodePin("Inclusive Max", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(true); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UInRange_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::InRange_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg(), GetConnectedPinValue(InputPins[2]).GetIntArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAnd_IntInt::UAnd_IntInt()
{
	NodeName = "Bitwise AND";
	NodeDescription = "Bitwise AND (A & B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UAnd_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::And_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UXor_IntInt::UXor_IntInt()
{
	NodeName = "Bitwise XOR";
	NodeDescription = "Bitwise XOR (A ^ B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UXor_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Xor_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UOr_IntInt::UOr_IntInt()
{
	NodeName = "Bitwise OR";
	NodeDescription = "Bitwise OR (A | B)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UOr_IntInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Or_IntInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNot_Int::UNot_Int()
{
	NodeName = "Bitwise NOT";
	NodeDescription = "Bitwise NOT (~A)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UNot_Int::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Not_Int(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USignOfInteger::USignOfInteger()
{
	NodeName = "Sign (integer";
	NodeDescription = "Sign (integer, returns -1 if A < 0, 0 if A is zero, and +1 if A > 0)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void USignOfInteger::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::SignOfInteger(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomInteger::URandomInteger()
{
	NodeName = "Random Integer";
	NodeDescription = "Returns a uniformly distributed random number between 0 and Max - 1";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Max", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void URandomInteger::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::RandomInteger(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomIntegerInRange::URandomIntegerInRange()
{
	NodeName = "Random Integer In Range";
	NodeDescription = "Return a random integer between Min and Max (>= Min and <= Max)";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Min", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("Max", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void URandomIntegerInRange::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::RandomIntegerInRange(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMin::UMin()
{
	NodeName = "Min (integer";
	NodeDescription = "Returns the minimum value of A and B";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UMin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Min(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMax::UMax()
{
	NodeName = "Max (integer";
	NodeDescription = "Returns the maximum value of A and B";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UMax::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Max(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UClamp::UClamp()
{
	NodeName = "Clamp (integer";
	NodeDescription = "Returns Value clamped to be between A and B (inclusive)";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("Min", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	InputPins[2].MakeNodePin("Max", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UClamp::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Clamp(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg(), GetConnectedPinValue(InputPins[2]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAbs_Int::UAbs_Int()
{
	NodeName = "Absolute (integer";
	NodeDescription = "Returns the absolute (positive) value of A";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UAbs_Int::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Abs_Int(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiplyMultiply_FloatFloat::UMultiplyMultiply_FloatFloat()
{
	NodeName = "Power";
	NodeDescription = "Power (Base to the Exp-th power)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Base", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Exp", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMultiplyMultiply_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::MultiplyMultiply_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_FloatFloat::UMultiply_FloatFloat()
{
	NodeName = "float * float";
	NodeDescription = "Multiplication (A  B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMultiply_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Multiply_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_IntFloat::UMultiply_IntFloat()
{
	NodeName = "int * float";
	NodeDescription = "Multiplication (A  B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMultiply_IntFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Multiply_IntFloat(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_FloatFloat::UDivide_FloatFloat()
{
	NodeName = "float / float";
	NodeDescription = "Division (A  B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDivide_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(GetConnectedPinValue(InputPins[0]).GetFloatArg() / GetConnectedPinValue(InputPins[1]).GetFloatArg());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPercent_FloatFloat::UPercent_FloatFloat()
{
	NodeName = "% (float";
	NodeDescription = "Modulo (A % B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UPercent_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Percent_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFraction::UFraction()
{
	NodeName = "Fraction";
	NodeDescription = "Returns the fractional part of a float.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFraction::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Fraction(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_FloatFloat::UAdd_FloatFloat()
{
	NodeName = "float + float";
	NodeDescription = "Addition (A + B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UAdd_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Add_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_FloatFloat::USubtract_FloatFloat()
{
	NodeName = "float - float";
	NodeDescription = "Subtraction (A - B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void USubtract_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Subtract_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULess_FloatFloat::ULess_FloatFloat()
{
	NodeName = "float < float";
	NodeDescription = "Returns true if A is Less than B (A < B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void ULess_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Less_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGreater_FloatFloat::UGreater_FloatFloat()
{
	NodeName = "float > float";
	NodeDescription = "Returns true if A is greater than B (A > B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UGreater_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Greater_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULessEqual_FloatFloat::ULessEqual_FloatFloat()
{
	NodeName = "float <= float";
	NodeDescription = "Returns true if A is Less than or equal to B (A <= B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void ULessEqual_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::LessEqual_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGreaterEqual_FloatFloat::UGreaterEqual_FloatFloat()
{
	NodeName = "float >= float";
	NodeDescription = "Returns true if A is greater than or equal to B (A >= B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UGreaterEqual_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::GreaterEqual_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_FloatFloat::UEqualEqual_FloatFloat()
{
	NodeName = "Equal (float";
	NodeDescription = "Returns true if A is exactly equal to B (A == B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNearlyEqual_FloatFloat::UNearlyEqual_FloatFloat()
{
	NodeName = "Nearly Equal (float";
	NodeDescription = "Returns true if A is nearly equal to B (|A - B| < ErrorTolerance)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-6f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNearlyEqual_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NearlyEqual_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_FloatFloat::UNotEqual_FloatFloat()
{
	NodeName = "Not Equal (float";
	NodeDescription = "Returns true if A does not equal B (A != B)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UInRange_FloatFloat::UInRange_FloatFloat()
{
	NodeName = "In Range (float";
	NodeDescription = "If InclusiveMin is true, value needs to be equal or larger than Min, else it needs to be largerIf InclusiveMax is true, value needs to be smaller or equal than Max, else it needs to be smaller";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Min", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Inclusive Min", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(true); // Default value

	InputPins[4].MakeNodePin("Inclusive Max", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(true); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UInRange_FloatFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::InRange_FloatFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg(), GetConnectedPinValue(InputPins[4]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UHypotenuse::UHypotenuse()
{
	NodeName = "Hypotenuse";
	NodeDescription = "Returns the hypotenuse of a right-angled triangle given the width and height.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Width", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Height", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UHypotenuse::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Hypotenuse(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGridSnap_Float::UGridSnap_Float()
{
	NodeName = "Snap to grid (float";
	NodeDescription = "Location = 5.1, GridSize = 10.0 : return value = 10.0If GridSize is 0 Location is returnedif GridSize is very small precision issues may occur.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Location", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Grid Size", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGridSnap_Float::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GridSnap_Float(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAbs::UAbs()
{
	NodeName = "Absolute (float";
	NodeDescription = "Returns the absolute (positive) value of A";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UAbs::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Abs(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USin::USin()
{
	NodeName = "Sin (Radians";
	NodeDescription = "Returns the sine of A (expects Radians)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void USin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Sin(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAsin::UAsin()
{
	NodeName = "Asin (Radians";
	NodeDescription = "Returns the inverse sine (arcsin) of A (result is in Radians)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UAsin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Asin(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCos::UCos()
{
	NodeName = "Cos (Radians";
	NodeDescription = "Returns the cosine of A (expects Radians)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UCos::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Cos(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAcos::UAcos()
{
	NodeName = "Acos (Radians";
	NodeDescription = "Returns the inverse cosine (arccos) of A (result is in Radians)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UAcos::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Acos(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTan::UTan()
{
	NodeName = "Tan (Radians";
	NodeDescription = "Returns the tan of A (expects Radians)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UTan::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Tan(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAtan::UAtan()
{
	NodeName = "Atan (Radians";
	NodeDescription = "Returns the inverse tan (atan) (result is in Radians)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UAtan::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Atan(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAtan2::UAtan2()
{
	NodeName = "Atan2 (Radians";
	NodeDescription = "Returns the inverse tan (atan2) of AB (result is in Radians)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UAtan2::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Atan2(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UExp::UExp()
{
	NodeName = "Exp";
	NodeDescription = "Returns exponential(e) to the power A (e^A)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UExp::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Exp(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULog::ULog()
{
	NodeName = "Log";
	NodeDescription = "Returns log of A base B (if B^R == A, returns R)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Base", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void ULog::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Log(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULoge::ULoge()
{
	NodeName = "Loge";
	NodeDescription = "Returns natural log of A (if e^R == A, returns R)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void ULoge::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Loge(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USqrt::USqrt()
{
	NodeName = "Sqrt";
	NodeDescription = "Returns square root of A";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void USqrt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Sqrt(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USquare::USquare()
{
	NodeName = "Square";
	NodeDescription = "Returns square of A (AA)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void USquare::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Square(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomFloat::URandomFloat()
{
	NodeName = "Random Float";
	NodeDescription = "Returns a random float between 0 and 1";
	NodeCategory = "Math|Random";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void URandomFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::RandomFloat());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomFloatInRange::URandomFloatInRange()
{
	NodeName = "Random Float In Range";
	NodeDescription = "Generate a random number between Min and Max";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Min", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Max", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void URandomFloatInRange::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::RandomFloatInRange(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetPI::UGetPI()
{
	NodeName = "Get PI";
	NodeDescription = "Returns the value of PI";
	NodeCategory = "Math|Trig";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetPI::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetPI());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetTAU::UGetTAU()
{
	NodeName = "Get TAU";
	NodeDescription = "Returns the value of TAU (= 2  PI)";
	NodeCategory = "Math|Trig";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetTAU::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetTAU());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegreesToRadians::UDegreesToRadians()
{
	NodeName = "Degrees To Radians";
	NodeDescription = "Returns radians value based on the input degrees";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegreesToRadians::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegreesToRadians(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URadiansToDegrees::URadiansToDegrees()
{
	NodeName = "Radians To Degrees";
	NodeDescription = "Returns degrees value based on the input radians";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void URadiansToDegrees::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::RadiansToDegrees(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegSin::UDegSin()
{
	NodeName = "Sin (Degrees";
	NodeDescription = "Returns the sin of A (expects Degrees)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegSin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegSin(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegAsin::UDegAsin()
{
	NodeName = "Asin (Degrees";
	NodeDescription = "Returns the inverse sin (arcsin) of A (result is in Degrees)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegAsin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegAsin(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegCos::UDegCos()
{
	NodeName = "Cos (Degrees";
	NodeDescription = "Returns the cos of A (expects Degrees)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegCos::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegCos(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegAcos::UDegAcos()
{
	NodeName = "Acos (Degrees";
	NodeDescription = "Returns the inverse cos (arccos) of A (result is in Degrees)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegAcos::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegAcos(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegTan::UDegTan()
{
	NodeName = "Tan (Degrees";
	NodeDescription = "Returns the tan of A (expects Degrees)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegTan::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegTan(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegAtan::UDegAtan()
{
	NodeName = "Atan (Degrees";
	NodeDescription = "Returns the inverse tan (atan) (result is in Degrees)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegAtan::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegAtan(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDegAtan2::UDegAtan2()
{
	NodeName = "Atan2 (Degrees";
	NodeDescription = "Returns the inverse tan (atan2) of AB (result is in Degrees)";
	NodeCategory = "Math|Trig";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDegAtan2::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DegAtan2(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UClampAngle::UClampAngle()
{
	NodeName = "Clamp Angle";
	NodeDescription = "Clamps an arbitrary angle to be between the given angles.  Will clamp to nearest boundary.@param MinAngleDegrees	'from' angle that defines the beginning of the range of valid angles (sweeping clockwise)@param MaxAngleDegrees	'to' angle that defines the end of the range of valid angles@return Returns clamped angle in the range -180..180.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Angle Degrees", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Min Angle Degrees", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max Angle Degrees", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UClampAngle::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::ClampAngle(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFMin::UFMin()
{
	NodeName = "Min (float";
	NodeDescription = "Returns the minimum value of A and B";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFMin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::FMin(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFMax::UFMax()
{
	NodeName = "Max (float";
	NodeDescription = "Returns the maximum value of A and B";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFMax::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::FMax(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFClamp::UFClamp()
{
	NodeName = "Clamp (float";
	NodeDescription = "Returns Value clamped between A and B (inclusive)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Min", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFClamp::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::FClamp(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMaxOfIntArray::UMaxOfIntArray()
{
	NodeName = "Max Of Int Array";
	NodeDescription = "Returns max of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty.";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Int Array", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.SetIntArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Index Of Max Value", EVariableTypes::Int);// PinName + PinType    
    OutputPins[2].MakeNodePin("Max Value", EVariableTypes::Int);// PinName + PinType
}


void UMaxOfIntArray::Execute(int Index, int FromLoopIndex)
{
    int IndexOfMaxValue;
	int MaxValue;
	UKismetMathLibrary::MaxOfIntArray(GetConnectedPinArray(InputPins[1]).GetIntArg(), IndexOfMaxValue, MaxValue);
    
	OutputPins[1].Value.Array[0].SetIntArg(IndexOfMaxValue);
	OutputPins[2].Value.Array[0].SetIntArg(MaxValue);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMinOfIntArray::UMinOfIntArray()
{
	NodeName = "Min Of Int Array";
	NodeDescription = "Returns min of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty.";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Int Array", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.SetIntArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Index Of Min Value", EVariableTypes::Int);// PinName + PinType    
    OutputPins[2].MakeNodePin("Min Value", EVariableTypes::Int);// PinName + PinType
}


void UMinOfIntArray::Execute(int Index, int FromLoopIndex)
{
    int IndexOfMinValue;
	int MinValue;
	UKismetMathLibrary::MinOfIntArray(GetConnectedPinArray(InputPins[1]).GetIntArg(), IndexOfMinValue, MinValue);
    
	OutputPins[1].Value.Array[0].SetIntArg(IndexOfMinValue);
	OutputPins[2].Value.Array[0].SetIntArg(MinValue);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMaxOfFloatArray::UMaxOfFloatArray()
{
	NodeName = "Max Of Float Array";
	NodeDescription = "Returns max of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Float Array", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.SetFloatArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Index Of Max Value", EVariableTypes::Int);// PinName + PinType    
    OutputPins[2].MakeNodePin("Max Value", EVariableTypes::Float);// PinName + PinType
}


void UMaxOfFloatArray::Execute(int Index, int FromLoopIndex)
{
    int IndexOfMaxValue;
	float MaxValue;
	UKismetMathLibrary::MaxOfFloatArray(GetConnectedPinArray(InputPins[1]).GetFloatArg(), IndexOfMaxValue, MaxValue);
    
	OutputPins[1].Value.Array[0].SetIntArg(IndexOfMaxValue);
	OutputPins[2].Value.Array[0].SetFloatArg(MaxValue);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMinOfFloatArray::UMinOfFloatArray()
{
	NodeName = "Min Of Float Array";
	NodeDescription = "Returns min of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Float Array", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.SetFloatArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Index Of Min Value", EVariableTypes::Int);// PinName + PinType    
    OutputPins[2].MakeNodePin("Min Value", EVariableTypes::Float);// PinName + PinType
}


void UMinOfFloatArray::Execute(int Index, int FromLoopIndex)
{
    int IndexOfMinValue;
	float MinValue;
	UKismetMathLibrary::MinOfFloatArray(GetConnectedPinArray(InputPins[1]).GetFloatArg(), IndexOfMinValue, MinValue);
    
	OutputPins[1].Value.Array[0].SetIntArg(IndexOfMinValue);
	OutputPins[2].Value.Array[0].SetFloatArg(MinValue);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMaxOfByteArray::UMaxOfByteArray()
{
	NodeName = "Max Of Byte Array";
	NodeDescription = "Returns max of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty.";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Byte Array", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.SetByteArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Index Of Max Value", EVariableTypes::Int);// PinName + PinType    
    OutputPins[2].MakeNodePin("Max Value", EVariableTypes::Byte);// PinName + PinType
}


void UMaxOfByteArray::Execute(int Index, int FromLoopIndex)
{
    int IndexOfMaxValue;
	uint8 MaxValue;
	UKismetMathLibrary::MaxOfByteArray(GetConnectedPinArray(InputPins[1]).GetByteArg(), IndexOfMaxValue, MaxValue);
    
	OutputPins[1].Value.Array[0].SetIntArg(IndexOfMaxValue);
	OutputPins[2].Value.Array[0].SetByteArg(MaxValue);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMinOfByteArray::UMinOfByteArray()
{
	NodeName = "Min Of Byte Array";
	NodeDescription = "Returns min of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty.";
	NodeCategory = "Math|Byte";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Byte Array", EVariableTypes::Byte);// PinName + PinType
	InputPins[1].Value.SetByteArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Index Of Min Value", EVariableTypes::Int);// PinName + PinType    
    OutputPins[2].MakeNodePin("Min Value", EVariableTypes::Byte);// PinName + PinType
}


void UMinOfByteArray::Execute(int Index, int FromLoopIndex)
{
    int IndexOfMinValue;
	uint8 MinValue;
	UKismetMathLibrary::MinOfByteArray(GetConnectedPinArray(InputPins[1]).GetByteArg(), IndexOfMinValue, MinValue);
    
	OutputPins[1].Value.Array[0].SetIntArg(IndexOfMinValue);
	OutputPins[2].Value.Array[0].SetByteArg(MinValue);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULerp::ULerp()
{
	NodeName = "Lerp";
	NodeDescription = "Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Alpha", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void ULerp::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Lerp(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URound::URound()
{
	NodeName = "Round";
	NodeDescription = "Rounds A to the nearest integer";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void URound::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Round(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFFloor::UFFloor()
{
	NodeName = "Floor";
	NodeDescription = "Rounds A to the largest previous integer";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UFFloor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::FFloor(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFTrunc::UFTrunc()
{
	NodeName = "Truncate";
	NodeDescription = "Rounds A to an integer with truncation towards zero.  (e.g. -1.7 truncated to -1, 2.8 truncated to 2)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UFTrunc::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::FTrunc(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFCeil::UFCeil()
{
	NodeName = "FCeil";
	NodeDescription = "Rounds A to the smallest following integer";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UFCeil::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::FCeil(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFMod::UFMod()
{
	NodeName = "Division (whole and remainder";
	NodeDescription = "Returns the number of times Divisor will go into Dividend (i.e., Dividend divided by Divisor), as well as the remainder";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Dividend", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Divisor", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType    
    OutputPins[1].MakeNodePin("Remainder", EVariableTypes::Float);// PinName + PinType
}


void UFMod::Execute(int Index, int FromLoopIndex)
{
    float Remainder;
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::FMod(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), Remainder));
    
	OutputPins[1].Value.Array[0].SetFloatArg(Remainder);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USignOfFloat::USignOfFloat()
{
	NodeName = "Sign (float";
	NodeDescription = "Sign (float, returns -1 if A < 0, 0 if A is zero, and +1 if A > 0)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void USignOfFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::SignOfFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNormalizeToRange::UNormalizeToRange()
{
	NodeName = "Normalize To Range";
	NodeDescription = "Returns Value normalized to the given range.  (e.g. 20 normalized to the range 10->50 would result in 0.25)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Range Min", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Range Max", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UNormalizeToRange::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::NormalizeToRange(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMapRangeUnclamped::UMapRangeUnclamped()
{
	NodeName = "Map Range Unclamped";
	NodeDescription = "Returns Value mapped from one range into another.  (e.g. 20 normalized from the range 10->50 to 20->40 would result in 25)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("In Range A", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("In Range B", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Out Range A", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	InputPins[4].MakeNodePin("Out Range B", EVariableTypes::Float);// PinName + PinType
	InputPins[4].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMapRangeUnclamped::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::MapRangeUnclamped(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg(), GetConnectedPinValue(InputPins[4]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMapRangeClamped::UMapRangeClamped()
{
	NodeName = "Map Range Clamped";
	NodeDescription = "Returns Value mapped from one range into another where the Value is clamped to the Input Range.  (e.g. 0.5 normalized from the range 0->1 to 0->50 would result in 25)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("In Range A", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("In Range B", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Out Range A", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	InputPins[4].MakeNodePin("Out Range B", EVariableTypes::Float);// PinName + PinType
	InputPins[4].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMapRangeClamped::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::MapRangeClamped(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg(), GetConnectedPinValue(InputPins[4]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiplyByPi::UMultiplyByPi()
{
	NodeName = "Multiply By Pi";
	NodeDescription = "Multiplies the input value by pi.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMultiplyByPi::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::MultiplyByPi(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFInterpEaseInOut::UFInterpEaseInOut()
{
	NodeName = "FInterp Ease In Out";
	NodeDescription = "Interpolate between A and B, applying an ease inout function.  Exp controls the degree of the curve.";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Alpha", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Exponent", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFInterpEaseInOut::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::FInterpEaseInOut(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakePulsatingValue::UMakePulsatingValue()
{
	NodeName = "Make Pulsating Value";
	NodeDescription = "Simple function to create a pulsating scalar value@param  InCurrentTime  Current absolute time@param  InPulsesPerSecond  How many full pulses per second?@param  InPhase  Optional phase amount, between 0.0 and 1.0 (to synchronize pulses)@return  Pulsating value (0.0-1.0)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("In Current Time", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("In Pulses Per Second", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.0f); // Default value

	InputPins[2].MakeNodePin("In Phase", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(0.0f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UMakePulsatingValue::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::MakePulsatingValue(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFixedTurn::UFixedTurn()
{
	NodeName = "Fixed Turn";
	NodeDescription = "Returns a new rotation component value@param InCurrent is the current rotation value@param InDesired is the desired rotation value@param  is the rotation amount to apply@return a new rotation component value clamped in the range (-360,360)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("In Current", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("In Desired", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("In Delta Rate", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFixedTurn::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::FixedTurn(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector2D_One::UVector2D_One()
{
	NodeName = "Vector2D One";
	NodeDescription = "2D one vector constant (1,1)";
	NodeCategory = "Math|Vector2D";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UVector2D_One::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Vector2D_One());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector2D_Unit45Deg::UVector2D_Unit45Deg()
{
	NodeName = "Vector2D Unit45Deg";
	NodeDescription = "2D unit vector constant along the 45 degree angle or symmetrical positive axes (sqrt(.5),sqrt(.5)) or (.707,.707). https:en.wikipedia.orgwikiUnit_vector";
	NodeCategory = "Math|Vector2D";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UVector2D_Unit45Deg::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Vector2D_Unit45Deg());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector2D_Zero::UVector2D_Zero()
{
	NodeName = "Vector2D Zero";
	NodeDescription = "2D zero vector constant (0,0)";
	NodeCategory = "Math|Vector2D";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UVector2D_Zero::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Vector2D_Zero());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeVector2D::UMakeVector2D()
{
	NodeName = "Make Vector2D";
	NodeDescription = "Makes a 2d vector {X, Y}";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("X", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Y", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UMakeVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::MakeVector2D(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBreakVector2D::UBreakVector2D()
{
	NodeName = "Break Vector2D";
	NodeDescription = "Breaks a 2D vector apart into X, Y.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Vec", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("X", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("Y", EVariableTypes::Float);// PinName + PinType
}


void UBreakVector2D::Execute(int Index, int FromLoopIndex)
{
    float X;
	float Y;
	UKismetMathLibrary::BreakVector2D(GetConnectedPinValue(InputPins[1]).GetVector2DArg(), X, Y);
    
	OutputPins[1].Value.Array[0].SetFloatArg(X);
	OutputPins[2].Value.Array[0].SetFloatArg(Y);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_Vector2DToVector::UConv_Vector2DToVector()
{
	NodeName = "To Vector (Vector2D";
	NodeDescription = "Convert a Vector2D to a Vector";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Vector2D", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("Z", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(0); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UConv_Vector2DToVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Conv_Vector2DToVector(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_Vector2DVector2D::UAdd_Vector2DVector2D()
{
	NodeName = "vector2d + vector2d";
	NodeDescription = "Returns addition of Vector A and Vector B (A + B)";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UAdd_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Add_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_Vector2DFloat::UAdd_Vector2DFloat()
{
	NodeName = "vector2d + float";
	NodeDescription = "Returns Vector A added by B";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UAdd_Vector2DFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Add_Vector2DFloat(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_Vector2DVector2D::USubtract_Vector2DVector2D()
{
	NodeName = "vector2d - vector2d";
	NodeDescription = "Returns subtraction of Vector B from Vector A (A - B)";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void USubtract_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Subtract_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_Vector2DFloat::USubtract_Vector2DFloat()
{
	NodeName = "vector2d - float";
	NodeDescription = "Returns Vector A subtracted by B";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void USubtract_Vector2DFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Subtract_Vector2DFloat(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_Vector2DVector2D::UMultiply_Vector2DVector2D()
{
	NodeName = "vector2d * vector2d";
	NodeDescription = "Element-wise Vector multiplication (Result = {A.xB.x, A.yB.y})";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UMultiply_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Multiply_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_Vector2DFloat::UMultiply_Vector2DFloat()
{
	NodeName = "vector2d * float";
	NodeDescription = "Returns Vector A scaled by B";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UMultiply_Vector2DFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Multiply_Vector2DFloat(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_Vector2DVector2D::UDivide_Vector2DVector2D()
{
	NodeName = "vector2d / vector2d";
	NodeDescription = "Element-wise Vector divide (Result = {A.xB.x, A.yB.y})";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UDivide_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Divide_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_Vector2DFloat::UDivide_Vector2DFloat()
{
	NodeName = "vector2d / float";
	NodeDescription = "Returns Vector A divided by B";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UDivide_Vector2DFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Divide_Vector2DFloat(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualExactly_Vector2DVector2D::UEqualExactly_Vector2DVector2D()
{
	NodeName = "Equal Exactly (Vector2D";
	NodeDescription = "Returns true if vector A is equal to vector B (A == B)";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualExactly_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualExactly_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_Vector2DVector2D::UEqualEqual_Vector2DVector2D()
{
	NodeName = "Equal (Vector2D";
	NodeDescription = "Returns true if vector2D A is equal to vector2D B (A == B) within a specified error tolerance";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqualExactly_Vector2DVector2D::UNotEqualExactly_Vector2DVector2D()
{
	NodeName = "Not Equal Exactly (Vector2D";
	NodeDescription = "Returns true if vector2D A is not equal to vector2D B (A != B) within a specified error tolerance";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqualExactly_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqualExactly_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_Vector2DVector2D::UNotEqual_Vector2DVector2D()
{
	NodeName = "Not Equal (Vector2D";
	NodeDescription = "Returns true if vector2D A is not equal to vector2D B (A != B) within a specified error tolerance";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_Vector2DVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_Vector2DVector2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNegated2D::UNegated2D()
{
	NodeName = "Negated2D";
	NodeDescription = "Gets a negated copy of the vector.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UNegated2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Negated2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UClampAxes2D::UClampAxes2D()
{
	NodeName = "Clamp Axes2D";
	NodeDescription = "Creates a copy of this vector with both axes clamped to the given range.@return New vector with clamped axes.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("Min Axis Val", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max Axis Val", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UClampAxes2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::ClampAxes2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCrossProduct2D::UCrossProduct2D()
{
	NodeName = "Cross Product (2D";
	NodeDescription = "Returns the cross product of two 2d vectors - see  http:mathworld.wolfram.comCrossProduct.html";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UCrossProduct2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::CrossProduct2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDistance2D::UDistance2D()
{
	NodeName = "Distance2D";
	NodeDescription = "Distance between two 2D points.@param V1 The first point.@param V2 The second point.@return The distance between two 2D points.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V1", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("V2", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDistance2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Distance2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDistanceSquared2D::UDistanceSquared2D()
{
	NodeName = "Distance Squared2D";
	NodeDescription = "Squared distance between two 2D points.@param V1 The first point.@param V2 The second point.@return The squared distance between two 2D points.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V1", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("V2", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDistanceSquared2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DistanceSquared2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDotProduct2D::UDotProduct2D()
{
	NodeName = "Dot Product (2D";
	NodeDescription = "Returns the dot product of two 2d vectors - see http:mathworld.wolfram.comDotProduct.html";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDotProduct2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::DotProduct2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetAbs2D::UGetAbs2D()
{
	NodeName = "Get Abs2D";
	NodeDescription = "Get a copy of this vector with absolute value of each component.@return A copy of this vector with absolute value of each component.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UGetAbs2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::GetAbs2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetAbsMax2D::UGetAbsMax2D()
{
	NodeName = "Get Abs Max2D";
	NodeDescription = "Get the maximum absolute value of the vector's components.@return The maximum absolute value of the vector's components.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetAbsMax2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetAbsMax2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetMax2D::UGetMax2D()
{
	NodeName = "Get Max2D";
	NodeDescription = "Get the maximum value of the vector's components.@return The maximum value of the vector's components.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetMax2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetMax2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetMin2D::UGetMin2D()
{
	NodeName = "Get Min2D";
	NodeDescription = "Get the minimum value of the vector's components.@return The minimum value of the vector's components.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetMin2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetMin2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetRotated2D::UGetRotated2D()
{
	NodeName = "Get Rotated2D";
	NodeDescription = "Rotates around axis (0,0,1)@param AngleDeg Angle to rotate (in degrees)@return Rotated Vector";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("Angle Deg", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UGetRotated2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::GetRotated2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsNearlyZero2D::UIsNearlyZero2D()
{
	NodeName = "Is Nearly Zero2D";
	NodeDescription = "Checks whether vector is near to zero within a specified tolerance.@param Tolerance Error tolerance.@return true if vector is in tolerance to zero, otherwise false.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsNearlyZero2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::IsNearlyZero2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsZero2D::UIsZero2D()
{
	NodeName = "Is Zero2D";
	NodeDescription = "Checks whether all components of the vector are exactly zero.@return true if vector is exactly zero, otherwise false.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsZero2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::IsZero2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector2DInterpTo::UVector2DInterpTo()
{
	NodeName = "Vector2DInterp To";
	NodeDescription = "Tries to reach Target based on distance from Current position, giving a nice smooth feeling when tracking a position.@param		Current			Actual position@param		Target			Target position@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UVector2DInterpTo::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Vector2DInterpTo(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector2DInterpTo_Constant::UVector2DInterpTo_Constant()
{
	NodeName = "Vector2DInterp To Constant";
	NodeDescription = "Tries to reach Target at a constant rate.@param		Current			Actual position@param		Target			Target position@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UVector2DInterpTo_Constant::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Vector2DInterpTo_Constant(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetVector2DArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNormalSafe2D::UNormalSafe2D()
{
	NodeName = "Normal Safe (Vector2D";
	NodeDescription = "Gets a normalized copy of the vector, checking it is safe to do so based on the length.Returns zero vector if vector length is too small to safely normalize.@param Tolerance Minimum squared length of vector for normalization.@return A normalized copy of the vector if safe, (0,0) otherwise.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-8f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UNormalSafe2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::NormalSafe2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNormal2D::UNormal2D()
{
	NodeName = "Normalize2D";
	NodeDescription = "Returns a unit normal version of the 2D vector";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UNormal2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Normal2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USpherical2DToUnitCartesian::USpherical2DToUnitCartesian()
{
	NodeName = "Spherical2D To Unit Cartesian";
	NodeDescription = "Converts spherical coordinates on the unit sphere into a Cartesian unit length vector.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void USpherical2DToUnitCartesian::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Spherical2DToUnitCartesian(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UToDirectionAndLength2D::UToDirectionAndLength2D()
{
	NodeName = "To Direction And Length";
	NodeDescription = "Util to convert this vector into a unit direction vector and its original length.@param OutDir Reference passed in to store unit direction vector.@param OutLength Reference passed in to store length of the vector.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Dir", EVariableTypes::Vector2D);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Length", EVariableTypes::Float);// PinName + PinType
}


void UToDirectionAndLength2D::Execute(int Index, int FromLoopIndex)
{
    FVector2D OutDir;
	float OutLength;
	UKismetMathLibrary::ToDirectionAndLength2D(GetConnectedPinValue(InputPins[1]).GetVector2DArg(), OutDir, OutLength);
    
	OutputPins[1].Value.Array[0].SetVector2DArg(OutDir);
	OutputPins[2].Value.Array[0].SetFloatArg(OutLength);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UToRounded2D::UToRounded2D()
{
	NodeName = "To Rounded (Vector2D";
	NodeDescription = "Get this vector as a vector where each component has been rounded to the nearest int.@return New FVector2D from this vector that is rounded.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UToRounded2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::ToRounded2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UToSign2D::UToSign2D()
{
	NodeName = "To sign (+1/-1";
	NodeDescription = "Get a copy of the vector as sign only.Each component is set to +1 or -1, with the sign of zero treated as +1.@return A copy of the vector with each component set to +1 or -1";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UToSign2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::ToSign2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVSize2D::UVSize2D()
{
	NodeName = "Vector2d Length";
	NodeDescription = "Returns the length of a 2D Vector.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVSize2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::VSize2D(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVSize2DSquared::UVSize2DSquared()
{
	NodeName = "Vector2d Length Squared";
	NodeDescription = "Returns the squared length of a 2D Vector.";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector2D);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector2DArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVSize2DSquared::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::VSize2DSquared(GetConnectedPinValue(InputPins[0]).GetVector2DArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Zero::UVector_Zero()
{
	NodeName = "Vector Zero";
	NodeDescription = "3D vector zero constant (0,0,0)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Zero::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Zero());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_One::UVector_One()
{
	NodeName = "Vector One";
	NodeDescription = "3D vector one constant (1,1,1)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_One::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_One());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Forward::UVector_Forward()
{
	NodeName = "Vector Forward";
	NodeDescription = "3D vector Unreal forward direction constant (1,0,0)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Forward::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Forward());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Backward::UVector_Backward()
{
	NodeName = "Vector Backward";
	NodeDescription = "3D vector Unreal backward direction constant (-1,0,0)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Backward::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Backward());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Up::UVector_Up()
{
	NodeName = "Vector Up";
	NodeDescription = "3D vector Unreal up direction constant (0,0,1)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Up::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Up());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Down::UVector_Down()
{
	NodeName = "Vector Down";
	NodeDescription = "3D vector Unreal down direction constant (0,0,-1)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Down::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Down());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Right::UVector_Right()
{
	NodeName = "Vector Right";
	NodeDescription = "3D vector Unreal right direction constant (0,1,0)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Right::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Right());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Left::UVector_Left()
{
	NodeName = "Vector Left";
	NodeDescription = "3D vector Unreal left direction constant (0,-1,0)";
	NodeCategory = "Math|Vector";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Left::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Left());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeVector::UMakeVector()
{
	NodeName = "Make Vector";
	NodeDescription = "Makes a vector {X, Y, Z}";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("X", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Y", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Z", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UMakeVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::MakeVector(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCreateVectorFromYawPitch::UCreateVectorFromYawPitch()
{
	NodeName = "Create Vector From Yaw Pitch";
	NodeDescription = "Creates a directional vector from rotation values {Pitch, Yaw} supplied in degrees with specified Length";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Yaw", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Pitch", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Length", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.0f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UCreateVectorFromYawPitch::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::CreateVectorFromYawPitch(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBreakVector::UBreakVector()
{
	NodeName = "Break Vector";
	NodeDescription = "Breaks a vector apart into X, Y, Z";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Vec", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("X", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("Y", EVariableTypes::Float);// PinName + PinType    
    OutputPins[3].MakeNodePin("Z", EVariableTypes::Float);// PinName + PinType
}


void UBreakVector::Execute(int Index, int FromLoopIndex)
{
    float X;
	float Y;
	float Z;
	UKismetMathLibrary::BreakVector(GetConnectedPinValue(InputPins[1]).GetVectorArg(), X, Y, Z);
    
	OutputPins[1].Value.Array[0].SetFloatArg(X);
	OutputPins[2].Value.Array[0].SetFloatArg(Y);
	OutputPins[3].Value.Array[0].SetFloatArg(Z);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_VectorToLinearColor::UConv_VectorToLinearColor()
{
	NodeName = "To Linear Color (Vector";
	NodeDescription = "Converts a vector to LinearColor";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vec", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UConv_VectorToLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::Conv_VectorToLinearColor(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_VectorToTransform::UConv_VectorToTransform()
{
	NodeName = "To Transform (Vector";
	NodeDescription = "Convert a vector to a transform. Uses vector as location";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UConv_VectorToTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::Conv_VectorToTransform(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_VectorToVector2D::UConv_VectorToVector2D()
{
	NodeName = "To Vector2D (Vector";
	NodeDescription = "Convert a Vector to a Vector2D";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vector", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UConv_VectorToVector2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Conv_VectorToVector2D(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_VectorToRotator::UConv_VectorToRotator()
{
	NodeName = "Rotation From XVector";
	NodeDescription = "Return the FRotator orientation corresponding to the direction in which the vector points.Sets Yaw and Pitch to the proper numbers, and sets Roll to zero because the roll can't be determined from a vector.@return FRotator from the Vector's direction, without any roll.";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vec", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UConv_VectorToRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::Conv_VectorToRotator(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URotatorFromAxisAndAngle::URotatorFromAxisAndAngle()
{
	NodeName = "Rotator From Axis And Angle";
	NodeDescription = "Create a rotation from an this axis and supplied angle (in degrees)";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Axis", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Angle", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void URotatorFromAxisAndAngle::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::RotatorFromAxisAndAngle(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_VectorVector::UAdd_VectorVector()
{
	NodeName = "vector + vector";
	NodeDescription = "Vector addition";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UAdd_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Add_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_VectorFloat::UAdd_VectorFloat()
{
	NodeName = "vector + float";
	NodeDescription = "Adds a float to each component of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UAdd_VectorFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Add_VectorFloat(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_VectorInt::UAdd_VectorInt()
{
	NodeName = "vector + int";
	NodeDescription = "Adds an integer to each component of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UAdd_VectorInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Add_VectorInt(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_VectorVector::USubtract_VectorVector()
{
	NodeName = "vector - vector";
	NodeDescription = "Vector subtraction";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void USubtract_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Subtract_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_VectorFloat::USubtract_VectorFloat()
{
	NodeName = "vector - float";
	NodeDescription = "Subtracts a float from each component of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void USubtract_VectorFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Subtract_VectorFloat(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_VectorInt::USubtract_VectorInt()
{
	NodeName = "vector - int";
	NodeDescription = "Subtracts an integer from each component of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void USubtract_VectorInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Subtract_VectorInt(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_VectorVector::UMultiply_VectorVector()
{
	NodeName = "vector * vector";
	NodeDescription = "Element-wise Vector multiplication (Result = {A.xB.x, A.yB.y, A.zB.z})";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UMultiply_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Multiply_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_VectorFloat::UMultiply_VectorFloat()
{
	NodeName = "vector * float";
	NodeDescription = "Scales Vector A by B";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UMultiply_VectorFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Multiply_VectorFloat(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_VectorInt::UMultiply_VectorInt()
{
	NodeName = "vector * int";
	NodeDescription = "Scales Vector A by B";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UMultiply_VectorInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Multiply_VectorInt(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_VectorVector::UDivide_VectorVector()
{
	NodeName = "vector / vector";
	NodeDescription = "Element-wise Vector division (Result = {A.xB.x, A.yB.y, A.zB.z})";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(FVector(1.f,1.f,1.f)); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UDivide_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Divide_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_VectorFloat::UDivide_VectorFloat()
{
	NodeName = "vector / float";
	NodeDescription = "Vector divide by a float";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UDivide_VectorFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Divide_VectorFloat(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_VectorInt::UDivide_VectorInt()
{
	NodeName = "vector / int";
	NodeDescription = "Vector divide by an integer";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UDivide_VectorInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Divide_VectorInt(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNegateVector::UNegateVector()
{
	NodeName = "Negate Vector";
	NodeDescription = "Negate a vector.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UNegateVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::NegateVector(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualExactly_VectorVector::UEqualExactly_VectorVector()
{
	NodeName = "Equal Exactly (Vector";
	NodeDescription = "Returns true if vector A is equal to vector B (A == B)";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualExactly_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualExactly_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_VectorVector::UEqualEqual_VectorVector()
{
	NodeName = "Equal (Vector";
	NodeDescription = "Returns true if vector A is equal to vector B (A == B) within a specified error tolerance";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqualExactly_VectorVector::UNotEqualExactly_VectorVector()
{
	NodeName = "Not Equal Exactly (Vector";
	NodeDescription = "Returns true if vector A is not equal to vector B (A != B)";
	NodeCategory = "Math|Vector2D";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqualExactly_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqualExactly_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_VectorVector::UNotEqual_VectorVector()
{
	NodeName = "Not Equal (Vector";
	NodeDescription = "Returns true if vector A is not equal to vector B (A != B) within a specified error tolerance";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDot_VectorVector::UDot_VectorVector()
{
	NodeName = "Dot Product";
	NodeDescription = "Returns the dot product of two 3d vectors - see http:mathworld.wolfram.comDotProduct.html";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UDot_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Dot_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCross_VectorVector::UCross_VectorVector()
{
	NodeName = "Cross Product";
	NodeDescription = "Returns the cross product of two 3d vectors - see http:mathworld.wolfram.comCrossProduct.html";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UCross_VectorVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Cross_VectorVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGreaterGreater_VectorRotator::UGreaterGreater_VectorRotator()
{
	NodeName = "Rotate Vector";
	NodeDescription = "Returns result of vector A rotated by Rotator B";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UGreaterGreater_VectorRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::GreaterGreater_VectorRotator(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URotateAngleAxis::URotateAngleAxis()
{
	NodeName = "Rotate Vector Around Axis";
	NodeDescription = "Returns result of vector A rotated by AngleDeg around Axis";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("In Vect", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Angle Deg", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Axis", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void URotateAngleAxis::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::RotateAngleAxis(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULessLess_VectorRotator::ULessLess_VectorRotator()
{
	NodeName = "Unrotate Vector";
	NodeDescription = "Returns result of vector A rotated by the inverse of Rotator B";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void ULessLess_VectorRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::LessLess_VectorRotator(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UClampVectorSize::UClampVectorSize()
{
	NodeName = "Clamp Vector Size";
	NodeDescription = "Create a copy of this vector, with its magnitudesizelength clamped between Min and Max.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Min", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UClampVectorSize::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::ClampVectorSize(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ClampSize2D::UVector_ClampSize2D()
{
	NodeName = "Vector Clamp Size2D";
	NodeDescription = "Create a copy of this vector, with the 2D magnitudesizelength clamped between Min and Max. Z is unchanged.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Min", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ClampSize2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ClampSize2D(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ClampSizeMax::UVector_ClampSizeMax()
{
	NodeName = "Vector Clamp Size Max";
	NodeDescription = "Create a copy of this vector, with its maximum magnitudesizelength clamped to MaxSize.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Max", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ClampSizeMax::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ClampSizeMax(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ClampSizeMax2D::UVector_ClampSizeMax2D()
{
	NodeName = "Vector Clamp Size Max2D";
	NodeDescription = "Create a copy of this vector, with the maximum 2D magnitudesizelength clamped to MaxSize. Z is unchanged.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Max", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ClampSizeMax2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ClampSizeMax2D(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetMinElement::UGetMinElement()
{
	NodeName = "Get Min Element";
	NodeDescription = "Find the minimum element (X, Y or Z) of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetMinElement::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetMinElement(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetMaxElement::UGetMaxElement()
{
	NodeName = "Get Max Element";
	NodeDescription = "Find the maximum element (X, Y or Z) of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetMaxElement::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetMaxElement(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_GetAbsMax::UVector_GetAbsMax()
{
	NodeName = "Vector Get Abs Max";
	NodeDescription = "Find the maximum absolute element (abs(X), abs(Y) or abs(Z)) of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_GetAbsMax::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_GetAbsMax(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_GetAbsMin::UVector_GetAbsMin()
{
	NodeName = "Vector Get Abs Min";
	NodeDescription = "Find the minimum absolute element (abs(X), abs(Y) or abs(Z)) of a vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_GetAbsMin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_GetAbsMin(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_GetAbs::UVector_GetAbs()
{
	NodeName = "Vector Get Abs";
	NodeDescription = "Get a copy of this vector with absolute value of each component.@return A copy of this vector with absolute value of each component.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_GetAbs::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_GetAbs(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ComponentMin::UVector_ComponentMin()
{
	NodeName = "Vector Component Min";
	NodeDescription = "Find the minimum elements (X, Y and Z) between the two vector's components";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ComponentMin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ComponentMin(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ComponentMax::UVector_ComponentMax()
{
	NodeName = "Vector Component Max";
	NodeDescription = "Find the maximum elements (X, Y and Z) between the two vector's components";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ComponentMax::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ComponentMax(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_GetSignVector::UVector_GetSignVector()
{
	NodeName = "Vector Get Sign Vector";
	NodeDescription = "Get a copy of the vector as sign only.Each component is set to +1 or -1, with the sign of zero treated as +1.@param A copy of the vector with each component set to +1 or -1";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_GetSignVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_GetSignVector(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_GetProjection::UVector_GetProjection()
{
	NodeName = "Vector Get Projection";
	NodeDescription = "Projects 2D components of vector based on Z.@return Projected version of vector based on Z.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_GetProjection::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_GetProjection(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_HeadingAngle::UVector_HeadingAngle()
{
	NodeName = "Vector Heading Angle";
	NodeDescription = "Convert a direction vector into a 'heading' angle.@return 'Heading' angle between +-PI radians. 0 is pointing down +X.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_HeadingAngle::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_HeadingAngle(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_CosineAngle2D::UVector_CosineAngle2D()
{
	NodeName = "Vector Cosine Angle2D";
	NodeDescription = "Returns the cosine of the angle between this vector and another projected onto the XY plane (no Z).@param B the other vector to find the 2D cosine of the angle with.@return The cosine.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_CosineAngle2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_CosineAngle2D(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ToRadians::UVector_ToRadians()
{
	NodeName = "Vector To Radians";
	NodeDescription = "Converts a vector containing degree values to a vector containing radian values.@return Vector containing radian values";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ToRadians::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ToRadians(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ToDegrees::UVector_ToDegrees()
{
	NodeName = "Vector To Degrees";
	NodeDescription = "Converts a vector containing radian values to a vector containing degree values.@return Vector  containing degree values";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ToDegrees::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ToDegrees(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_UnitCartesianToSpherical::UVector_UnitCartesianToSpherical()
{
	NodeName = "Vector Unit Cartesian To Spherical";
	NodeDescription = "Converts a Cartesian unit vector into spherical coordinates on the unit sphere.@return Output Theta will be in the range [0, PI], and output Phi will be in the range [-PI, PI].";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector2D);// PinName + PinType
}


void UVector_UnitCartesianToSpherical::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector2DArg(UKismetMathLibrary::Vector_UnitCartesianToSpherical(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetDirectionUnitVector::UGetDirectionUnitVector()
{
	NodeName = "Get Unit Direction (Vector";
	NodeDescription = "Find the unit direction vector from one position to another or (0,0,0) if positions are the same.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("From", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("To", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UGetDirectionUnitVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::GetDirectionUnitVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetYawPitchFromVector::UGetYawPitchFromVector()
{
	NodeName = "Get Yaw Pitch From Vector";
	NodeDescription = "Breaks a vector apart into Yaw, Pitch rotation values given in degrees. (non-clamped)";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Vec", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Yaw", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("Pitch", EVariableTypes::Float);// PinName + PinType
}


void UGetYawPitchFromVector::Execute(int Index, int FromLoopIndex)
{
    float Yaw;
	float Pitch;
	UKismetMathLibrary::GetYawPitchFromVector(GetConnectedPinValue(InputPins[1]).GetVectorArg(), Yaw, Pitch);
    
	OutputPins[1].Value.Array[0].SetFloatArg(Yaw);
	OutputPins[2].Value.Array[0].SetFloatArg(Pitch);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetAzimuthAndElevation::UGetAzimuthAndElevation()
{
	NodeName = "Get Azimuth And Elevation";
	NodeDescription = "";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Direction", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Reference Frame", EVariableTypes::Transform);// PinName + PinType
	InputPins[2].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Azimuth", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("Elevation", EVariableTypes::Float);// PinName + PinType
}


void UGetAzimuthAndElevation::Execute(int Index, int FromLoopIndex)
{
    float Azimuth;
	float Elevation;
	UKismetMathLibrary::GetAzimuthAndElevation(GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetTransformArg(), Azimuth, Elevation);
    
	OutputPins[1].Value.Array[0].SetFloatArg(Azimuth);
	OutputPins[2].Value.Array[0].SetFloatArg(Elevation);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetVectorArrayAverage::UGetVectorArrayAverage()
{
	NodeName = "Get Vector Array Average";
	NodeDescription = "Find the average of an array of vectors";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodeArray("Vectors", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UGetVectorArrayAverage::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::GetVectorArrayAverage(GetConnectedPinArray(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFTruncVector::UFTruncVector()
{
	NodeName = "Truncate (Vector";
	NodeDescription = "Rounds A to an integer with truncation towards zero for each element in a vector.  (e.g. -1.7 truncated to -1, 2.8 truncated to 2)";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vector", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::IntVector);// PinName + PinType
}


void UFTruncVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntVectorArg(UKismetMathLibrary::FTruncVector(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Distance::UVector_Distance()
{
	NodeName = "Distance (Vector";
	NodeDescription = "Distance between two points.@param V1 The first point.@param V2 The second point.@return The distance between two points.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V1", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("V2", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_Distance::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_Distance(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_DistanceSquared::UVector_DistanceSquared()
{
	NodeName = "Distance Squared (Vector";
	NodeDescription = "Squared distance between two points.@param V1 The first point.@param V2 The second point.@return The squared distance between two points.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V1", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("V2", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_DistanceSquared::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_DistanceSquared(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Distance2D::UVector_Distance2D()
{
	NodeName = "Distance2D (Vector";
	NodeDescription = "Euclidean distance between two points in the XY plane (ignoring Z).@param V1 The first point.@param V2 The second point.@return The distance between two points in the XY plane.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V1", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("V2", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_Distance2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_Distance2D(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Distance2DSquared::UVector_Distance2DSquared()
{
	NodeName = "Distance2D Squared (Vector";
	NodeDescription = "Squared euclidean distance between two points in the XY plane (ignoring Z).@param V1 The first point.@param V2 The second point.@return The distance between two points in the XY plane.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V1", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("V2", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector_Distance2DSquared::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector_Distance2DSquared(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVSize::UVSize()
{
	NodeName = "Vector Length";
	NodeDescription = "Returns the length of the vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVSize::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::VSize(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVSizeSquared::UVSizeSquared()
{
	NodeName = "Vector Length Squared";
	NodeDescription = "Returns the squared length of the vector";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVSizeSquared::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::VSizeSquared(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVSizeXY::UVSizeXY()
{
	NodeName = "Vector Length XY";
	NodeDescription = "Returns the length of the vector's XY components.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVSizeXY::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::VSizeXY(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVSizeXYSquared::UVSizeXYSquared()
{
	NodeName = "Vector Length XYSquared";
	NodeDescription = "Returns the squared length of the vector's XY components.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVSizeXYSquared::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::VSizeXYSquared(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_IsNearlyZero::UVector_IsNearlyZero()
{
	NodeName = "Vector Is Nearly Zero";
	NodeDescription = "Checks whether vector is near to zero within a specified tolerance.@param Tolerance Error tolerance.@return true if vector is in tolerance to zero, otherwise false.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector_IsNearlyZero::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector_IsNearlyZero(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_IsZero::UVector_IsZero()
{
	NodeName = "Vector Is Zero";
	NodeDescription = "Checks whether all components of the vector are exactly zero.@return true if vector is exactly zero, otherwise false.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector_IsZero::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector_IsZero(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_IsNAN::UVector_IsNAN()
{
	NodeName = "Vector Is NAN";
	NodeDescription = "Determines if any component is not a number (NAN)@return true if one or more components is NAN, otherwise false.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector_IsNAN::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector_IsNAN(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_IsUniform::UVector_IsUniform()
{
	NodeName = "Is Uniform (Vector";
	NodeDescription = "Checks whether all components of this vector are the same, within a tolerance.@param Tolerance Error tolerance.@return true if the vectors are equal within tolerance limits, false otherwise.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector_IsUniform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector_IsUniform(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_IsUnit::UVector_IsUnit()
{
	NodeName = "Is Unit (Vector";
	NodeDescription = "Determines if vector is normalized  unit (length 1) within specified squared tolerance.@return true if unit, false otherwise.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Squared Lenth Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector_IsUnit::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector_IsUnit(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_IsNormal::UVector_IsNormal()
{
	NodeName = "Is Normal (Vector";
	NodeDescription = "Determines if vector is normalized  unit (length 1).@return true if normalized, false otherwise.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector_IsNormal::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector_IsNormal(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNormal::UNormal()
{
	NodeName = "Normalize";
	NodeDescription = "Gets a normalized unit copy of the vector, ensuring it is safe to do so based on the length.Returns zero vector if vector length is too small to safely normalize.@param Tolerance Minimum squared vector length.@return A normalized copy if safe, (0,0,0) otherwise.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UNormal::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Normal(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Normal2D::UVector_Normal2D()
{
	NodeName = "Normalize 2D (Vector";
	NodeDescription = "Gets a normalized unit copy of the 2D components of the vector, ensuring it is safe to do so. Z is set to zero.Returns zero vector if vector length is too small to normalize.@param Tolerance Minimum squared vector length.@return Normalized copy if safe, (0,0,0) otherwise.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Normal2D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Normal2D(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_NormalUnsafe::UVector_NormalUnsafe()
{
	NodeName = "Normal unsafe (Vector";
	NodeDescription = "Calculates normalized unit version of vector without checking for zero length.@return Normalized version of vector.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_NormalUnsafe::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_NormalUnsafe(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVLerp::UVLerp()
{
	NodeName = "Lerp (Vector";
	NodeDescription = "Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1)";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Alpha", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVLerp::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::VLerp(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVInterpTo::UVInterpTo()
{
	NodeName = "VInterp To";
	NodeDescription = "Tries to reach Target based on distance from Current position, giving a nice smooth feeling when tracking a position.@param		Current			Actual position@param		Target			Target position@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVInterpTo::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::VInterpTo(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVInterpTo_Constant::UVInterpTo_Constant()
{
	NodeName = "VInterp To Constant";
	NodeDescription = "Tries to reach Target at a constant rate.@param		Current			Actual position@param		Target			Target position@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVInterpTo_Constant::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::VInterpTo_Constant(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_Reciprocal::UVector_Reciprocal()
{
	NodeName = "Reciprocal (Vector";
	NodeDescription = "Gets the reciprocal of this vector, avoiding division by zero.Zero components are set to BIG_NUMBER.@return Reciprocal of this vector.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_Reciprocal::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_Reciprocal(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetReflectionVector::UGetReflectionVector()
{
	NodeName = "Get Reflection Vector";
	NodeDescription = "Given a direction vector and a surface normal, returns the vector reflected across the surface normal.Produces a result like shining a laser at a mirror!@param Direction Direction vector the ray is coming from.@param SurfaceNormal A normal of the surface the ray should be reflected on.@returns Reflected vector.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Direction", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Surface Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UGetReflectionVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::GetReflectionVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMirrorVectorByNormal::UMirrorVectorByNormal()
{
	NodeName = "Mirror Vector By Normal";
	NodeDescription = "Given a direction vector and a surface normal, returns the vector reflected across the surface normal.Produces a result like shining a laser at a mirror!@param InVect Direction vector the ray is coming from.@param InNormal A normal of the surface the ray should be reflected on.@returns Reflected vector.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Vect", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("In Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UMirrorVectorByNormal::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::MirrorVectorByNormal(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_SnappedToGrid::UVector_SnappedToGrid()
{
	NodeName = "Vector Snapped To Grid";
	NodeDescription = "Gets a copy of this vector snapped to a grid.@param InGridSize Grid dimension  step.@return A copy of this vector snapped to a grid.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Vect", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("In Grid Size", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_SnappedToGrid::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_SnappedToGrid(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_BoundedToCube::UVector_BoundedToCube()
{
	NodeName = "Vector Bounded To Cube";
	NodeDescription = "Get a copy of this vector, clamped inside of an axis aligned cube centered at the origin.@param InRadius Half size of the cube (or radius of sphere circumscribed in the cube).@return A copy of this vector, bound by cube.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Vect", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("In Radius", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_BoundedToCube::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_BoundedToCube(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_BoundedToBox::UVector_BoundedToBox()
{
	NodeName = "Vector Bounded To Box";
	NodeDescription = "Get a copy of this vector, clamped inside of the specified axis aligned cube.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("In Vect", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("In Box Min", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("In Box Max", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_BoundedToBox::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_BoundedToBox(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector_ProjectOnToNormal::UVector_ProjectOnToNormal()
{
	NodeName = "Vector Project On To Normal";
	NodeDescription = "Gets a copy of this vector projected onto the input vector, which is assumed to be unit length.@param  InNormal Vector to project onto (assumed to be unit length).@return Projected vector.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("In Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UVector_ProjectOnToNormal::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Vector_ProjectOnToNormal(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UProjectVectorOnToVector::UProjectVectorOnToVector()
{
	NodeName = "Project Vector On To Vector";
	NodeDescription = "Projects one vector (V) onto another (Target) and returns the projected vector.If Target is nearly zero in length, returns the zero vector.@param  V Vector to project.@param  Target Vector on which we are projecting.@return V projected on to Target.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UProjectVectorOnToVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::ProjectVectorOnToVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UProjectPointOnToPlane::UProjectPointOnToPlane()
{
	NodeName = "Project Point On To Plane";
	NodeDescription = "Projectssnaps a point onto a plane defined by a point on the plane and a plane normal.@param  Point Point to project onto the plane.@param  PlaneBase A point on the plane.@param  PlaneNormal Normal of the plane.@return Point projected onto the plane.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Plane Base", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Plane Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UProjectPointOnToPlane::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::ProjectPointOnToPlane(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UProjectVectorOnToPlane::UProjectVectorOnToPlane()
{
	NodeName = "Project Vector On To Plane";
	NodeDescription = "Projects a vector onto a plane defined by a normalized vector (PlaneNormal).@param  V Vector to project onto the plane.@param  PlaneNormal Normal of the plane.@return Vector projected onto the plane.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("V", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Plane Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UProjectVectorOnToPlane::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::ProjectVectorOnToPlane(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFindNearestPointsOnLineSegments::UFindNearestPointsOnLineSegments()
{
	NodeName = "Find Nearest Points On Line Segments";
	NodeDescription = "Find closest points between 2 segments.@param	Segment1Start	Start of the 1st segment.@param	Segment1End		End of the 1st segment.@param	Segment2Start	Start of the 2nd segment.@param	Segment2End		End of the 2nd segment.@param	Segment1Point	Closest point on segment 1 to segment 2.@param	Segment2Point	Closest point on segment 2 to segment 1.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Segment1Start", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Segment1End", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Segment2Start", EVariableTypes::Vector);// PinName + PinType
	InputPins[3].Value.Array[0].SetVectorArg(); // Default value

	InputPins[4].MakeNodePin("Segment2End", EVariableTypes::Vector);// PinName + PinType
	InputPins[4].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Segment1Point", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Segment2Point", EVariableTypes::Vector);// PinName + PinType
}


void UFindNearestPointsOnLineSegments::Execute(int Index, int FromLoopIndex)
{
    FVector Segment1Point;
	FVector Segment2Point;
	UKismetMathLibrary::FindNearestPointsOnLineSegments(GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetVectorArg(), GetConnectedPinValue(InputPins[4]).GetVectorArg(), Segment1Point, Segment2Point);
    
	OutputPins[1].Value.Array[0].SetVectorArg(Segment1Point);
	OutputPins[2].Value.Array[0].SetVectorArg(Segment2Point);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFindClosestPointOnSegment::UFindClosestPointOnSegment()
{
	NodeName = "Find Closest Point On Segment";
	NodeDescription = "Find the closest point on a segment to a given point.@param Point			Point for which we find the closest point on the segment.@param SegmentStart	Start of the segment.@param SegmentEnd	End of the segment.@return The closest point on the segment to the given point.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Segment Start", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Segment End", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UFindClosestPointOnSegment::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::FindClosestPointOnSegment(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFindClosestPointOnLine::UFindClosestPointOnLine()
{
	NodeName = "Find Closest Point On Line";
	NodeDescription = "Find the closest point on an infinite line to a given point.@param Point			Point for which we find the closest point on the line.@param LineOrigin	Point of reference on the line.@param LineDirection Direction of the line. Not required to be normalized.@return The closest point on the line to the given point.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Line Origin", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Line Direction", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UFindClosestPointOnLine::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::FindClosestPointOnLine(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetPointDistanceToSegment::UGetPointDistanceToSegment()
{
	NodeName = "Get Point Distance To Segment";
	NodeDescription = "Find the distance from a point to the closest point on a segment.@param Point			Point for which we find the distance to the closest point on the segment.@param SegmentStart	Start of the segment.@param SegmentEnd		End of the segment.@return The distance from the given point to the closest point on the segment.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Segment Start", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Segment End", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetPointDistanceToSegment::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetPointDistanceToSegment(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetPointDistanceToLine::UGetPointDistanceToLine()
{
	NodeName = "Get Point Distance To Line";
	NodeDescription = "Find the distance from a point to the closest point on an infinite line.@param Point			Point for which we find the distance to the closest point on the line.@param LineOrigin		Point of reference on the line.@param LineDirection	Direction of the line. Not required to be normalized.@return The distance from the given point to the closest point on the line.";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Line Origin", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Line Direction", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UGetPointDistanceToLine::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::GetPointDistanceToLine(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomUnitVector::URandomUnitVector()
{
	NodeName = "Random Unit Vector";
	NodeDescription = "Returns a random vector with length of 1";
	NodeCategory = "Math|Random";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void URandomUnitVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::RandomUnitVector());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomPointInBoundingBox::URandomPointInBoundingBox()
{
	NodeName = "Random Point In Bounding Box";
	NodeDescription = "Returns a random point within the specified bounding box using the first vector as an origin and the second as the box extents.";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Origin", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Box Extent", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void URandomPointInBoundingBox::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::RandomPointInBoundingBox(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomUnitVectorInConeInRadians::URandomUnitVectorInConeInRadians()
{
	NodeName = "Random Unit Vector In Cone In Radians";
	NodeDescription = "Returns a random vector with length of 1, within the specified cone, with uniform random distribution.@param ConeDir					The base 'center' direction of the cone.@param ConeHalfAngleInRadians	The half-angle of the cone (from ConeDir to edge), in radians.";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Cone Dir", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Cone Half Angle In Radians", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void URandomUnitVectorInConeInRadians::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::RandomUnitVectorInConeInRadians(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomUnitVectorInConeInDegrees::URandomUnitVectorInConeInDegrees()
{
	NodeName = "Random Unit Vector In Cone In Degrees";
	NodeDescription = "Returns a random vector with length of 1, within the specified cone, with uniform random distribution.@param ConeDir					The base 'center' direction of the cone.@param ConeHalfAngleInDegrees	The half-angle of the cone (from ConeDir to edge), in degrees.";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Cone Dir", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Cone Half Angle In Degrees", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void URandomUnitVectorInConeInDegrees::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::RandomUnitVectorInConeInDegrees(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomUnitVectorInEllipticalConeInRadians::URandomUnitVectorInEllipticalConeInRadians()
{
	NodeName = "Random Unit Vector In Elliptical Cone In Radians";
	NodeDescription = "Returns a random vector with length of 1, within the specified cone, with uniform random distribution.The shape of the cone can be modified according to the yaw and pitch angles.@param MaxYawInRadians	The yaw angle of the cone (from ConeDir to horizontal edge), in radians.@param MaxPitchInRadians	The pitch angle of the cone (from ConeDir to vertical edge), in radians.";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Cone Dir", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Max Yaw In Radians", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max Pitch In Radians", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void URandomUnitVectorInEllipticalConeInRadians::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::RandomUnitVectorInEllipticalConeInRadians(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomUnitVectorInEllipticalConeInDegrees::URandomUnitVectorInEllipticalConeInDegrees()
{
	NodeName = "Random Unit Vector In Elliptical Cone In Degrees";
	NodeDescription = "Returns a random vector with length of 1, within the specified cone, with uniform random distribution.The shape of the cone can be modified according to the yaw and pitch angles.@param MaxYawInDegrees	The yaw angle of the cone (from ConeDir to horizontal edge), in degrees.@param MaxPitchInDegrees	The pitch angle of the cone (from ConeDir to vertical edge), in degrees.";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Cone Dir", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Max Yaw In Degrees", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Max Pitch In Degrees", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void URandomUnitVectorInEllipticalConeInDegrees::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::RandomUnitVectorInEllipticalConeInDegrees(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_Zero::UVector4_Zero()
{
	NodeName = "Vector4 Zero";
	NodeDescription = "4D vector zero constant (0,0,0)";
	NodeCategory = "Math|Vector4";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UVector4_Zero::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Vector4_Zero());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeVector4::UMakeVector4()
{
	NodeName = "Make Vector4";
	NodeDescription = "Makes a 4D vector {X, Y, Z, W}";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("X", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Y", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Z", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("W", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UMakeVector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::MakeVector4(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBreakVector4::UBreakVector4()
{
	NodeName = "Break Vector4";
	NodeDescription = "Breaks a 4D vector apart into X, Y, Z, W.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Vec", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(5);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("X", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("Y", EVariableTypes::Float);// PinName + PinType    
    OutputPins[3].MakeNodePin("Z", EVariableTypes::Float);// PinName + PinType    
    OutputPins[4].MakeNodePin("W", EVariableTypes::Float);// PinName + PinType
}


void UBreakVector4::Execute(int Index, int FromLoopIndex)
{
    float X;
	float Y;
	float Z;
	float W;
	UKismetMathLibrary::BreakVector4(GetConnectedPinValue(InputPins[1]).GetVector4Arg(), X, Y, Z, W);
    
	OutputPins[1].Value.Array[0].SetFloatArg(X);
	OutputPins[2].Value.Array[0].SetFloatArg(Y);
	OutputPins[3].Value.Array[0].SetFloatArg(Z);
	OutputPins[4].Value.Array[0].SetFloatArg(W);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_Vector4ToVector::UConv_Vector4ToVector()
{
	NodeName = "To Vector (Vector4";
	NodeDescription = "Convert a Vector4 to a Vector (dropping the W element)";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vector4", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UConv_Vector4ToVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Conv_Vector4ToVector(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_Vector4ToRotator::UConv_Vector4ToRotator()
{
	NodeName = "To Rotation (Vector4";
	NodeDescription = "Return the FRotator orientation corresponding to the direction in which the vector points.Sets Yaw and Pitch to the proper numbers, and sets Roll to zero because the roll can't be determined from a vector.@return FRotator from the Vector's direction, without any roll.";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Vec", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UConv_Vector4ToRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::Conv_Vector4ToRotator(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_Vector4Vector4::UAdd_Vector4Vector4()
{
	NodeName = "Vector4 + Vector4";
	NodeDescription = "Returns addition of Vector A and Vector B (A + B)";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UAdd_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Add_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_Vector4Vector4::USubtract_Vector4Vector4()
{
	NodeName = "Vector4 - Vector4";
	NodeDescription = "Returns subtraction of Vector B from Vector A (A - B)";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void USubtract_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Subtract_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_Vector4Vector4::UMultiply_Vector4Vector4()
{
	NodeName = "Vector4 * Vector4";
	NodeDescription = "Element-wise Vector multiplication (Result = {A.xB.x, A.yB.y, A.zB.z, A.wB.w})";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UMultiply_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Multiply_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_Vector4Vector4::UDivide_Vector4Vector4()
{
	NodeName = "Vector4 / Vector4";
	NodeDescription = "Element-wise Vector divide (Result = {A.xB.x, A.yB.y, A.zB.z, A.wB.w})";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UDivide_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Divide_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualExactly_Vector4Vector4::UEqualExactly_Vector4Vector4()
{
	NodeName = "Equal Exactly (Vector4";
	NodeDescription = "Returns true if vector A is equal to vector B (A == B)";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualExactly_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualExactly_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_Vector4Vector4::UEqualEqual_Vector4Vector4()
{
	NodeName = "Equal (Vector4";
	NodeDescription = "Returns true if vector A is equal to vector B (A == B) within a specified error tolerance";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqualExactly_Vector4Vector4::UNotEqualExactly_Vector4Vector4()
{
	NodeName = "Not Equal Exactly (Vector4";
	NodeDescription = "Returns true if vector A is not equal to vector B (A != B) within a specified error tolerance";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqualExactly_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqualExactly_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_Vector4Vector4::UNotEqual_Vector4Vector4()
{
	NodeName = "Not Equal (Vector4";
	NodeDescription = "Returns true if vector A is not equal to vector B (A != B) within a specified error tolerance";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_Vector4Vector4::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_Vector4Vector4(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_Negated::UVector4_Negated()
{
	NodeName = "Negated (Vector4";
	NodeDescription = "Gets a negated copy of the vector. Equivalent to -Vector for scripts.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UVector4_Negated::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Vector4_Negated(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_CrossProduct3::UVector4_CrossProduct3()
{
	NodeName = "Cross Product XYZ (Vector4";
	NodeDescription = "Returns the cross product of two vectors - see  http:mathworld.wolfram.comCrossProduct.html";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UVector4_CrossProduct3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Vector4_CrossProduct3(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_DotProduct::UVector4_DotProduct()
{
	NodeName = "Dot Product (Vector4";
	NodeDescription = "Returns the dot product of two vectors - see http:mathworld.wolfram.comDotProduct.html";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector4_DotProduct::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector4_DotProduct(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_DotProduct3::UVector4_DotProduct3()
{
	NodeName = "Dot Product XYZ (Vector4";
	NodeDescription = "Returns the dot product of two vectors - see http:mathworld.wolfram.comDotProduct.html The W element is ignored.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector4_DotProduct3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector4_DotProduct3(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_IsNAN::UVector4_IsNAN()
{
	NodeName = "Vector4 Is NAN";
	NodeDescription = "Determines if any component is not a number (NAN)@return true if one or more components is NAN, otherwise false.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector4_IsNAN::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector4_IsNAN(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_IsNearlyZero3::UVector4_IsNearlyZero3()
{
	NodeName = "Vector4 Is Nearly Zero3";
	NodeDescription = "Checks whether vector is near to zero within a specified tolerance. The W element is ignored.@param Tolerance Error tolerance.@return true if vector is in tolerance to zero, otherwise false.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector4_IsNearlyZero3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector4_IsNearlyZero3(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_IsZero::UVector4_IsZero()
{
	NodeName = "Vector4 Is Zero";
	NodeDescription = "Checks whether all components of the vector are exactly zero.@return true if vector is exactly zero, otherwise false.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector4_IsZero::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector4_IsZero(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_Size::UVector4_Size()
{
	NodeName = "Length (Vector4";
	NodeDescription = "Returns the length of the vector.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector4_Size::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector4_Size(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_SizeSquared::UVector4_SizeSquared()
{
	NodeName = "Length Squared (Vector4";
	NodeDescription = "Returns the squared length of the vector.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector4_SizeSquared::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector4_SizeSquared(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_Size3::UVector4_Size3()
{
	NodeName = "Length XYZ (Vector4";
	NodeDescription = "Returns the length of the vector. The W element is ignored.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector4_Size3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector4_Size3(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_SizeSquared3::UVector4_SizeSquared3()
{
	NodeName = "Length XYZ Squared (Vector4";
	NodeDescription = "Returns the squared length of the vector. The W element is ignored.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UVector4_SizeSquared3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Vector4_SizeSquared3(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_IsUnit3::UVector4_IsUnit3()
{
	NodeName = "Is Unit XYZ (Vector4";
	NodeDescription = "Determines if vector is normalized  unit (length 1) within specified squared tolerance. The W element is ignored.@return true if unit, false otherwise.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("Squared Lenth Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector4_IsUnit3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector4_IsUnit3(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_IsNormal3::UVector4_IsNormal3()
{
	NodeName = "Is Normal XYZ (Vector4";
	NodeDescription = "Determines if vector is normalized  unit (length 1). The W element is ignored.@return true if normalized, false otherwise.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UVector4_IsNormal3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Vector4_IsNormal3(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_Normal3::UVector4_Normal3()
{
	NodeName = "Normalize XYZ (Vector 4";
	NodeDescription = "Gets a normalized unit copy of the vector, ensuring it is safe to do so based on the length. The W element is ignored and the returned vector has W=0.Returns zero vector if vector length is too small to safely normalize.@param Tolerance Minimum squared vector length.@return A normalized copy if safe, (0,0,0) otherwise.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UVector4_Normal3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Vector4_Normal3(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_NormalUnsafe3::UVector4_NormalUnsafe3()
{
	NodeName = "Normal unsafe XYZ (Vector4";
	NodeDescription = "Calculates normalized unit version of vector without checking for zero length. The W element is ignored and the returned vector has W=0.@return Normalized version of vector.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UVector4_NormalUnsafe3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Vector4_NormalUnsafe3(GetConnectedPinValue(InputPins[0]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UVector4_MirrorByVector3::UVector4_MirrorByVector3()
{
	NodeName = "Vector4 Mirror By Vector3";
	NodeDescription = "Given a direction vector and a surface normal, returns the vector reflected across the surface normal.Produces a result like shining a laser at a mirror!The W element is ignored.@param Direction Direction vector the ray is coming from.@param SurfaceNormal A normal of the surface the ray should be reflected on.@returns Reflected vector.";
	NodeCategory = "Math|Vector4";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Direction", EVariableTypes::Vector4);// PinName + PinType
	InputPins[0].Value.Array[0].SetVector4Arg(); // Default value

	InputPins[1].MakeNodePin("Surface Normal", EVariableTypes::Vector4);// PinName + PinType
	InputPins[1].Value.Array[0].SetVector4Arg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector4);// PinName + PinType
}


void UVector4_MirrorByVector3::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVector4Arg(UKismetMathLibrary::Vector4_MirrorByVector3(GetConnectedPinValue(InputPins[0]).GetVector4Arg(), GetConnectedPinValue(InputPins[1]).GetVector4Arg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromX::UMakeRotFromX()
{
	NodeName = "Make Rot From X";
	NodeDescription = "Builds a rotator given only a XAxis. Y and Z are unspecified but will be orthonormal. XAxis need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("X", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromX::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromX(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromY::UMakeRotFromY()
{
	NodeName = "Make Rot From Y";
	NodeDescription = "Builds a rotation matrix given only a YAxis. X and Z are unspecified but will be orthonormal. YAxis need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Y", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromY::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromY(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromZ::UMakeRotFromZ()
{
	NodeName = "Make Rot From Z";
	NodeDescription = "Builds a rotation matrix given only a ZAxis. X and Y are unspecified but will be orthonormal. ZAxis need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Z", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromZ::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromZ(GetConnectedPinValue(InputPins[0]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromXY::UMakeRotFromXY()
{
	NodeName = "Make Rot From XY";
	NodeDescription = "Builds a matrix with given X and Y axes. X will remain fixed, Y may be changed minimally to enforce orthogonality. Z will be computed. Inputs need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("X", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Y", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromXY::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromXY(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromXZ::UMakeRotFromXZ()
{
	NodeName = "Make Rot From XZ";
	NodeDescription = "Builds a matrix with given X and Z axes. X will remain fixed, Z may be changed minimally to enforce orthogonality. Y will be computed. Inputs need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("X", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Z", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromXZ::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromXZ(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromYX::UMakeRotFromYX()
{
	NodeName = "Make Rot From YX";
	NodeDescription = "Builds a matrix with given Y and X axes. Y will remain fixed, X may be changed minimally to enforce orthogonality. Z will be computed. Inputs need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Y", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("X", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromYX::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromYX(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromYZ::UMakeRotFromYZ()
{
	NodeName = "Make Rot From YZ";
	NodeDescription = "Builds a matrix with given Y and Z axes. Y will remain fixed, Z may be changed minimally to enforce orthogonality. X will be computed. Inputs need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Y", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Z", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromYZ::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromYZ(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromZX::UMakeRotFromZX()
{
	NodeName = "Make Rot From ZX";
	NodeDescription = "Builds a matrix with given Z and X axes. Z will remain fixed, X may be changed minimally to enforce orthogonality. Y will be computed. Inputs need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Z", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("X", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromZX::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromZX(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotFromZY::UMakeRotFromZY()
{
	NodeName = "Make Rot From ZY";
	NodeDescription = "Builds a matrix with given Z and Y axes. Z will remain fixed, Y may be changed minimally to enforce orthogonality. X will be computed. Inputs need not be normalized.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Z", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Y", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotFromZY::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotFromZY(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotationFromAxes::UMakeRotationFromAxes()
{
	NodeName = "Make Rotation From Axes";
	NodeDescription = "Build a reference frame from three axes";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Forward", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Right", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Up", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotationFromAxes::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotationFromAxes(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFindLookAtRotation::UFindLookAtRotation()
{
	NodeName = "Find Look At Rotation";
	NodeDescription = "Find a rotation for an object at Start location to point at Target location.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Start", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UFindLookAtRotation::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::FindLookAtRotation(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBreakRotIntoAxes::UBreakRotIntoAxes()
{
	NodeName = "Break Rot Into Axes";
	NodeDescription = "Breaks apart a rotator into its component axes";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("X", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Y", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[3].MakeNodePin("Z", EVariableTypes::Vector);// PinName + PinType
}


void UBreakRotIntoAxes::Execute(int Index, int FromLoopIndex)
{
    FVector X;
	FVector Y;
	FVector Z;
	UKismetMathLibrary::BreakRotIntoAxes(GetConnectedPinValue(InputPins[1]).GetRotatorArg(), X, Y, Z);
    
	OutputPins[1].Value.Array[0].SetVectorArg(X);
	OutputPins[2].Value.Array[0].SetVectorArg(Y);
	OutputPins[3].Value.Array[0].SetVectorArg(Z);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_RotatorRotator::UEqualEqual_RotatorRotator()
{
	NodeName = "Equal (Rotator";
	NodeDescription = "Returns true if rotator A is equal to rotator B (A == B) within a specified error tolerance";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_RotatorRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_RotatorRotator(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_RotatorRotator::UNotEqual_RotatorRotator()
{
	NodeName = "Not Equal (Rotator";
	NodeDescription = "Returns true if rotator A is not equal to rotator B (A != B) within a specified error tolerance";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[2].MakeNodePin("Error Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_RotatorRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_RotatorRotator(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_RotatorFloat::UMultiply_RotatorFloat()
{
	NodeName = "Scale Rotator";
	NodeDescription = "Returns rotator representing rotator A scaled by B";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMultiply_RotatorFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::Multiply_RotatorFloat(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_RotatorInt::UMultiply_RotatorInt()
{
	NodeName = "Scale Rotator (integer";
	NodeDescription = "Returns rotator representing rotator A scaled by B";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMultiply_RotatorInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::Multiply_RotatorInt(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComposeRotators::UComposeRotators()
{
	NodeName = "Combine Rotators";
	NodeDescription = "Combine 2 rotations to give you the resulting rotation of first applying A, then B.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UComposeRotators::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::ComposeRotators(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNegateRotator::UNegateRotator()
{
	NodeName = "Invert Rotator";
	NodeDescription = "Negate a rotator";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UNegateRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::NegateRotator(GetConnectedPinValue(InputPins[0]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetForwardVector::UGetForwardVector()
{
	NodeName = "Get Forward Vector";
	NodeDescription = "Rotate the world forward vector by the given rotation";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UGetForwardVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::GetForwardVector(GetConnectedPinValue(InputPins[0]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetRightVector::UGetRightVector()
{
	NodeName = "Get Right Vector";
	NodeDescription = "Rotate the world right vector by the given rotation";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UGetRightVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::GetRightVector(GetConnectedPinValue(InputPins[0]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetUpVector::UGetUpVector()
{
	NodeName = "Get Up Vector";
	NodeDescription = "Rotate the world up vector by the given rotation";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UGetUpVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::GetUpVector(GetConnectedPinValue(InputPins[0]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_RotatorToVector::UConv_RotatorToVector()
{
	NodeName = "Get Rotation XVector";
	NodeDescription = "Get the X direction vector after this rotation";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UConv_RotatorToVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Conv_RotatorToVector(GetConnectedPinValue(InputPins[0]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_RotatorToTransform::UConv_RotatorToTransform()
{
	NodeName = "To Transform (Rotator";
	NodeDescription = "Convert Rotator to Transform";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Rotator", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UConv_RotatorToTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::Conv_RotatorToTransform(GetConnectedPinValue(InputPins[0]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetAxes::UGetAxes()
{
	NodeName = "Get Axes";
	NodeDescription = "Get the reference frame direction vectors (axes) described by this rotation";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("X", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Y", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[3].MakeNodePin("Z", EVariableTypes::Vector);// PinName + PinType
}


void UGetAxes::Execute(int Index, int FromLoopIndex)
{
    FVector X;
	FVector Y;
	FVector Z;
	UKismetMathLibrary::GetAxes(GetConnectedPinValue(InputPins[1]).GetRotatorArg(), X, Y, Z);
    
	OutputPins[1].Value.Array[0].SetVectorArg(X);
	OutputPins[2].Value.Array[0].SetVectorArg(Y);
	OutputPins[3].Value.Array[0].SetVectorArg(Z);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URandomRotator::URandomRotator()
{
	NodeName = "Random Rotator";
	NodeDescription = "Generates a random rotation, with optional random roll.";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("b Roll", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void URandomRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::RandomRotator(GetConnectedPinValue(InputPins[0]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URLerp::URLerp()
{
	NodeName = "Lerp (Rotator";
	NodeDescription = "Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1)";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[2].MakeNodePin("Alpha", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("b Shortest Path", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void URLerp::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::RLerp(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNormalizedDeltaRotator::UNormalizedDeltaRotator()
{
	NodeName = "Delta (Rotator";
	NodeDescription = "Normalized A-B";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UNormalizedDeltaRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::NormalizedDeltaRotator(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UClampAxis::UClampAxis()
{
	NodeName = "Clamp Axis";
	NodeDescription = "Clamps an angle to the range of [0, 360].@param Angle The angle to clamp.@return The clamped angle.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Angle", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UClampAxis::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::ClampAxis(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNormalizeAxis::UNormalizeAxis()
{
	NodeName = "Normalize Axis";
	NodeDescription = "Clamps an angle to the range of [-180, 180].@param Angle The Angle to clamp.@return The clamped angle.";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Angle", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UNormalizeAxis::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::NormalizeAxis(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_White::ULinearColor_White()
{
	NodeName = "Linear Color White";
	NodeDescription = "White linear color";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_White::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_White());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Gray::ULinearColor_Gray()
{
	NodeName = "Linear Color Gray";
	NodeDescription = "Grey linear color";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Gray::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Gray());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Black::ULinearColor_Black()
{
	NodeName = "Linear Color Black";
	NodeDescription = "Black linear color";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Black::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Black());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Red::ULinearColor_Red()
{
	NodeName = "Linear Color Red";
	NodeDescription = "Red linear color";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Red::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Red());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Green::ULinearColor_Green()
{
	NodeName = "Linear Color Green";
	NodeDescription = "Green linear color";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Green::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Green());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Blue::ULinearColor_Blue()
{
	NodeName = "Linear Color Blue";
	NodeDescription = "Blue linear color";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Blue::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Blue());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Yellow::ULinearColor_Yellow()
{
	NodeName = "Linear Color Yellow";
	NodeDescription = "Yellow linear color";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Yellow::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Yellow());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Transparent::ULinearColor_Transparent()
{
	NodeName = "Linear Color Transparent";
	NodeDescription = "Transparent linear color - black with 0 opacityalpha";
	NodeCategory = "Math|Color";
	
	 
	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Transparent::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Transparent());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeColor::UMakeColor()
{
	NodeName = "Make Color";
	NodeDescription = "Make a color from individual color components (RGB space)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("R", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("G", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(1.0f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UMakeColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::MakeColor(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBreakColor::UBreakColor()
{
	NodeName = "Break Color";
	NodeDescription = "Breaks apart a color into individual RGB components (as well as alpha)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(5);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("R", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("G", EVariableTypes::Float);// PinName + PinType    
    OutputPins[3].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType    
    OutputPins[4].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
}


void UBreakColor::Execute(int Index, int FromLoopIndex)
{
    float R;
	float G;
	float B;
	float A;
	UKismetMathLibrary::BreakColor(GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), R, G, B, A);
    
	OutputPins[1].Value.Array[0].SetFloatArg(R);
	OutputPins[2].Value.Array[0].SetFloatArg(G);
	OutputPins[3].Value.Array[0].SetFloatArg(B);
	OutputPins[4].Value.Array[0].SetFloatArg(A);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_FloatToLinearColor::UConv_FloatToLinearColor()
{
	NodeName = "To Linear Color (float";
	NodeDescription = "Convert a float into a LinearColor, where each element is that float";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Float", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UConv_FloatToLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::Conv_FloatToLinearColor(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UHSVToRGB::UHSVToRGB()
{
	NodeName = "HSV to RGB";
	NodeDescription = "Make a color from individual color components (HSV space; Hue is [0..360) while Saturation and Value are 0..1)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("H", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("S", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("V", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(1.0f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UHSVToRGB::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::HSVToRGB(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UHSVToRGB_Vector::UHSVToRGB_Vector()
{
	NodeName = "HSV to RGB (Vector";
	NodeDescription = "Converts a HSV linear color (where H is in R (0..360), S is in G (0..1), and V is in B (0..1)) to RGB";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("HSV", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("RGB", EVariableTypes::LinearColor);// PinName + PinType
}


void UHSVToRGB_Vector::Execute(int Index, int FromLoopIndex)
{
    FLinearColor RGB;
	UKismetMathLibrary::HSVToRGB_Vector(GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), RGB);
    
	OutputPins[1].Value.Array[0].SetLinearColorArg(RGB);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UHSVToRGBLinear::UHSVToRGBLinear()
{
	NodeName = "HSV to RGB linear color";
	NodeDescription = "Converts a HSV linear color (where H is in R, S is in G, and V is in B) to linear RGB";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("HSV", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UHSVToRGBLinear::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::HSVToRGBLinear(GetConnectedPinValue(InputPins[0]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URGBToHSV::URGBToHSV()
{
	NodeName = "RGB to HSV";
	NodeDescription = "Breaks apart a color into individual HSV components (as well as alpha) (Hue is [0..360) while Saturation and Value are 0..1)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(5);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("H", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("S", EVariableTypes::Float);// PinName + PinType    
    OutputPins[3].MakeNodePin("V", EVariableTypes::Float);// PinName + PinType    
    OutputPins[4].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
}


void URGBToHSV::Execute(int Index, int FromLoopIndex)
{
    float H;
	float S;
	float V;
	float A;
	UKismetMathLibrary::RGBToHSV(GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), H, S, V, A);
    
	OutputPins[1].Value.Array[0].SetFloatArg(H);
	OutputPins[2].Value.Array[0].SetFloatArg(S);
	OutputPins[3].Value.Array[0].SetFloatArg(V);
	OutputPins[4].Value.Array[0].SetFloatArg(A);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URGBToHSV_Vector::URGBToHSV_Vector()
{
	NodeName = "RGB to HSV (Vector";
	NodeDescription = "Converts a RGB linear color to HSV (where H is in R (0..360), S is in G (0..1), and V is in B (0..1))";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("RGB", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("HSV", EVariableTypes::LinearColor);// PinName + PinType
}


void URGBToHSV_Vector::Execute(int Index, int FromLoopIndex)
{
    FLinearColor HSV;
	UKismetMathLibrary::RGBToHSV_Vector(GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), HSV);
    
	OutputPins[1].Value.Array[0].SetLinearColorArg(HSV);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URGBLinearToHSV::URGBLinearToHSV()
{
	NodeName = "RGB to HSV linear color";
	NodeDescription = "Converts a RGB linear color to HSV (where H is in R, S is in G, and V is in B)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("RGB", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void URGBLinearToHSV::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::RGBLinearToHSV(GetConnectedPinValue(InputPins[0]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_LinearColorToVector::UConv_LinearColorToVector()
{
	NodeName = "To Vector (Linear Color";
	NodeDescription = "Converts a LinearColor to a vector";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Linear Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UConv_LinearColorToVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Conv_LinearColorToVector(GetConnectedPinValue(InputPins[0]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Desaturated::ULinearColor_Desaturated()
{
	NodeName = "Desaturate (Linear Color";
	NodeDescription = "Returns a desaturated color, with 0 meaning no desaturation and 1 == full desaturation@param	Desaturation	Desaturation factor in range [0..1]@return	Desaturated color";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("In Desaturation", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_Desaturated::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_Desaturated(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_Distance::ULinearColor_Distance()
{
	NodeName = "Distance (Linear Color";
	NodeDescription = "Euclidean distance between two color points.";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("C1", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("C2", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void ULinearColor_Distance::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::LinearColor_Distance(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_ToNewOpacity::ULinearColor_ToNewOpacity()
{
	NodeName = "New Opacity (Linear Color";
	NodeDescription = "Returns a copy of this color using the specified opacityalpha.";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("In Opacity", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColor_ToNewOpacity::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColor_ToNewOpacity(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_GetLuminance::ULinearColor_GetLuminance()
{
	NodeName = "Luminance (Linear Color";
	NodeDescription = "Returns the perceived brightness of a color on a display taking into account the impact on the human eye per color channel: green > red > blue.";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void ULinearColor_GetLuminance::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::LinearColor_GetLuminance(GetConnectedPinValue(InputPins[0]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_GetMax::ULinearColor_GetMax()
{
	NodeName = "Max (Linear Color";
	NodeDescription = "Returns the maximum color channel value in this color structure@return The maximum color channel value";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void ULinearColor_GetMax::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::LinearColor_GetMax(GetConnectedPinValue(InputPins[0]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_GetMin::ULinearColor_GetMin()
{
	NodeName = "Min (Linear Color";
	NodeDescription = "Returns the minimum color channel value in this color structure@return The minimum color channel value";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Color", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void ULinearColor_GetMin::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::LinearColor_GetMin(GetConnectedPinValue(InputPins[0]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UCInterpTo::UCInterpTo()
{
	NodeName = "Interpolate (Linear Color";
	NodeDescription = "Interpolate Linear Color from Current to Target. Scaled by distance to Target, so it has a strong start speed and ease out.@param		Current			Current Color@param		Target			Target Color@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated Color";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UCInterpTo::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::CInterpTo(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColorLerp::ULinearColorLerp()
{
	NodeName = "Lerp (Linear Color";
	NodeDescription = "Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[2].MakeNodePin("Alpha", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColorLerp::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColorLerp(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColorLerpUsingHSV::ULinearColorLerpUsingHSV()
{
	NodeName = "Lerp Using HSV (Linear Color";
	NodeDescription = "Linearly interpolates between two colors by the specified Alpha amount (100% of A when Alpha=0 and 100% of B when Alpha=1).  The interpolation is performed in HSV color space taking the shortest path to the new color's hue.  This can give better results than a normal lerp, but is much more expensive.  The incoming colors are in RGB space, and the output color will be RGB.  The alpha value will also be interpolated.@param	A		The color and alpha to interpolate from as linear RGBA@param	B		The color and alpha to interpolate to as linear RGBA@param	Alpha	Scalar interpolation amount (usually between 0.0 and 1.0 inclusive)@return	The interpolated color in linear RGB space along with the interpolated alpha value";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[2].MakeNodePin("Alpha", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void ULinearColorLerpUsingHSV::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::LinearColorLerpUsingHSV(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinearColor_IsNearEqual::ULinearColor_IsNearEqual()
{
	NodeName = "Near Equal (Linear Color";
	NodeDescription = "Returns true if linear color A is equal to linear color B (A == B) within a specified error tolerance";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[2].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void ULinearColor_IsNearEqual::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::LinearColor_IsNearEqual(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_LinearColorLinearColor::UEqualEqual_LinearColorLinearColor()
{
	NodeName = "Equal (Linear Color";
	NodeDescription = "Returns true if linear color A is equal to linear color B (A == B) within a specified error tolerance";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_LinearColorLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_LinearColorLinearColor(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_LinearColorLinearColor::UNotEqual_LinearColorLinearColor()
{
	NodeName = "Not Equal (Linear Color";
	NodeDescription = "Returns true if linear color A is not equal to linear color B (A != B) within a specified error tolerance";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_LinearColorLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_LinearColorLinearColor(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UAdd_LinearColorLinearColor::UAdd_LinearColorLinearColor()
{
	NodeName = "Linear Color + Linear Color";
	NodeDescription = "Element-wise addition of two linear colors (R+R, G+G, B+B, A+A)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UAdd_LinearColorLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::Add_LinearColorLinearColor(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USubtract_LinearColorLinearColor::USubtract_LinearColorLinearColor()
{
	NodeName = "Linear Color - Linear Color";
	NodeDescription = "Element-wise subtraction of two linear colors (R-R, G-G, B-B, A-A)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void USubtract_LinearColorLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::Subtract_LinearColorLinearColor(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_LinearColorLinearColor::UMultiply_LinearColorLinearColor()
{
	NodeName = "Linear Color * Linear Color";
	NodeDescription = "Element-wise multiplication of two linear colors (RR, GG, BB, AA)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UMultiply_LinearColorLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::Multiply_LinearColorLinearColor(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMultiply_LinearColorFloat::UMultiply_LinearColorFloat()
{
	NodeName = "Linear Color * Float";
	NodeDescription = "Element-wise multiplication of a linear color by a float (FR, FG, FB, FA)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UMultiply_LinearColorFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::Multiply_LinearColorFloat(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDivide_LinearColorLinearColor::UDivide_LinearColorLinearColor()
{
	NodeName = "Linear Color / Linear Color";
	NodeDescription = "Element-wise multiplication of two linear colors (RR, GG, BB, AA)";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void UDivide_LinearColorLinearColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::Divide_LinearColorLinearColor(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDaysInMonth::UDaysInMonth()
{
	NodeName = "Days In Month";
	NodeDescription = "Returns the number of days in the given year and month";
	NodeCategory = "Math|DateTime";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("Year", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("Month", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UDaysInMonth::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::DaysInMonth(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UDaysInYear::UDaysInYear()
{
	NodeName = "Days In Year";
	NodeDescription = "Returns the number of days in the given year";
	NodeCategory = "Math|DateTime";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Year", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UDaysInYear::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::DaysInYear(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsLeapYear::UIsLeapYear()
{
	NodeName = "Is Leap Year";
	NodeDescription = "Returns whether given year is a leap year";
	NodeCategory = "Math|DateTime";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Year", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsLeapYear::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::IsLeapYear(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_ByteToFloat::UConv_ByteToFloat()
{
	NodeName = "To Float (byte";
	NodeDescription = "Converts a byte to a float";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Byte", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UConv_ByteToFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Conv_ByteToFloat(GetConnectedPinValue(InputPins[0]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_IntToFloat::UConv_IntToFloat()
{
	NodeName = "To Float (integer";
	NodeDescription = "Converts an integer to a float";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Int", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UConv_IntToFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Conv_IntToFloat(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_IntToByte::UConv_IntToByte()
{
	NodeName = "To Byte (integer";
	NodeDescription = "Converts an integer to a byte (if the integer is too large, returns the low 8 bits)";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Int", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UConv_IntToByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::Conv_IntToByte(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_IntToIntVector::UConv_IntToIntVector()
{
	NodeName = "To Int Vector (integer";
	NodeDescription = "Converts an integer to an IntVector";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Int", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::IntVector);// PinName + PinType
}


void UConv_IntToIntVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntVectorArg(UKismetMathLibrary::Conv_IntToIntVector(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_IntToBool::UConv_IntToBool()
{
	NodeName = "To Bool (integer";
	NodeDescription = "Converts a int to a bool";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Int", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UConv_IntToBool::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::Conv_IntToBool(GetConnectedPinValue(InputPins[0]).GetIntArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_BoolToInt::UConv_BoolToInt()
{
	NodeName = "To Int (bool";
	NodeDescription = "Converts a bool to an int";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Bool", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UConv_BoolToInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Conv_BoolToInt(GetConnectedPinValue(InputPins[0]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_BoolToFloat::UConv_BoolToFloat()
{
	NodeName = "To Float (bool";
	NodeDescription = "Converts a bool to a float (0.0f or 1.0f)";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Bool", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UConv_BoolToFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Conv_BoolToFloat(GetConnectedPinValue(InputPins[0]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_BoolToByte::UConv_BoolToByte()
{
	NodeName = "To Byte (bool";
	NodeDescription = "Converts a bool to a byte";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Bool", EVariableTypes::Bool);// PinName + PinType
	InputPins[0].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Byte);// PinName + PinType
}


void UConv_BoolToByte::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetByteArg(UKismetMathLibrary::Conv_BoolToByte(GetConnectedPinValue(InputPins[0]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_ByteToInt::UConv_ByteToInt()
{
	NodeName = "To Int (byte";
	NodeDescription = "Converts a byte to an integer";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Byte", EVariableTypes::Byte);// PinName + PinType
	InputPins[0].Value.Array[0].SetByteArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UConv_ByteToInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::Conv_ByteToInt(GetConnectedPinValue(InputPins[0]).GetByteArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_IntVectorToVector::UConv_IntVectorToVector()
{
	NodeName = "To Vector (Int Vector";
	NodeDescription = "Convert an IntVector to a vector";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Int Vector", EVariableTypes::IntVector);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UConv_IntVectorToVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Conv_IntVectorToVector(GetConnectedPinValue(InputPins[0]).GetIntVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UConv_FloatToVector::UConv_FloatToVector()
{
	NodeName = "To Vector (float";
	NodeDescription = "Convert a float into a vector, where each element is that float";
	NodeCategory = "Math|Conversions";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("In Float", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UConv_FloatToVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::Conv_FloatToVector(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectString::USelectString()
{
	NodeName = "Select String";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Utilities|String";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::String);// PinName + PinType
	InputPins[0].Value.Array[0].SetStringArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::String);// PinName + PinType
	InputPins[1].Value.Array[0].SetStringArg(); // Default value

	InputPins[2].MakeNodePin("b Pick A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::String);// PinName + PinType
}


void USelectString::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetStringArg(UKismetMathLibrary::SelectString(GetConnectedPinValue(InputPins[0]).GetStringArg(), GetConnectedPinValue(InputPins[1]).GetStringArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectInt::USelectInt()
{
	NodeName = "Select Int";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Math|Integer";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Int);// PinName + PinType
	InputPins[0].Value.Array[0].SetIntArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	InputPins[2].MakeNodePin("b Pick A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void USelectInt::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(UKismetMathLibrary::SelectInt(GetConnectedPinValue(InputPins[0]).GetIntArg(), GetConnectedPinValue(InputPins[1]).GetIntArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectFloat::USelectFloat()
{
	NodeName = "Select Float";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Math|Float";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("b Pick A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void USelectFloat::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::SelectFloat(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectVector::USelectVector()
{
	NodeName = "Select Vector";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Math|Vector";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("b Pick A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void USelectVector::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::SelectVector(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectRotator::USelectRotator()
{
	NodeName = "Select Rotator";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Math|Rotator";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[2].MakeNodePin("b Pick A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void USelectRotator::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::SelectRotator(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectColor::USelectColor()
{
	NodeName = "Select Color";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Math|Color";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[0].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::LinearColor);// PinName + PinType
	InputPins[1].Value.Array[0].SetLinearColorArg(); // Default value

	InputPins[2].MakeNodePin("b Pick A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::LinearColor);// PinName + PinType
}


void USelectColor::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetLinearColorArg(UKismetMathLibrary::SelectColor(GetConnectedPinValue(InputPins[0]).GetLinearColorArg(), GetConnectedPinValue(InputPins[1]).GetLinearColorArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectTransform::USelectTransform()
{
	NodeName = "Select Transform";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	InputPins[2].MakeNodePin("b Pick A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void USelectTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::SelectTransform(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetTransformArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectObject::USelectObject()
{
	NodeName = "Select Object";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Object);// PinName + PinType
	InputPins[1].Value.Array[0].SetObjectArg(); // Default value

	InputPins[2].MakeNodePin("b Select A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Object);// PinName + PinType
}


void USelectObject::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetObjectArg(UKismetMathLibrary::SelectObject(GetConnectedPinValue(InputPins[0]).GetObjectArg(), GetConnectedPinValue(InputPins[1]).GetObjectArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


USelectClass::USelectClass()
{
	NodeName = "Select Class";
	NodeDescription = "If bPickA is true, A is returned, otherwise B is";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Class);// PinName + PinType
	InputPins[0].Value.Array[0].SetClassArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Class);// PinName + PinType
	InputPins[1].Value.Array[0].SetClassArg(); // Default value

	InputPins[2].MakeNodePin("b Select A", EVariableTypes::Bool);// PinName + PinType
	InputPins[2].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Class);// PinName + PinType
}


void USelectClass::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetClassArg(UKismetMathLibrary::SelectClass(GetConnectedPinValue(InputPins[0]).GetClassArg(), GetConnectedPinValue(InputPins[1]).GetClassArg(), GetConnectedPinValue(InputPins[2]).GetBoolArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_ObjectObject::UEqualEqual_ObjectObject()
{
	NodeName = "Equal (Object";
	NodeDescription = "Returns true if A and B are equal (A == B)";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Object);// PinName + PinType
	InputPins[1].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_ObjectObject::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_ObjectObject(GetConnectedPinValue(InputPins[0]).GetObjectArg(), GetConnectedPinValue(InputPins[1]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_ObjectObject::UNotEqual_ObjectObject()
{
	NodeName = "Not Equal (Object";
	NodeDescription = "Returns true if A and B are not equal (A != B)";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Object);// PinName + PinType
	InputPins[0].Value.Array[0].SetObjectArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Object);// PinName + PinType
	InputPins[1].Value.Array[0].SetObjectArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_ObjectObject::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_ObjectObject(GetConnectedPinValue(InputPins[0]).GetObjectArg(), GetConnectedPinValue(InputPins[1]).GetObjectArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_ClassClass::UEqualEqual_ClassClass()
{
	NodeName = "Equal (Class";
	NodeDescription = "Returns true if A and B are equal (A == B)";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Class);// PinName + PinType
	InputPins[0].Value.Array[0].SetClassArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Class);// PinName + PinType
	InputPins[1].Value.Array[0].SetClassArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_ClassClass::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_ClassClass(GetConnectedPinValue(InputPins[0]).GetClassArg(), GetConnectedPinValue(InputPins[1]).GetClassArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_ClassClass::UNotEqual_ClassClass()
{
	NodeName = "Not Equal (Class";
	NodeDescription = "Returns true if A and B are not equal (A != B)";
	NodeCategory = "Utilities";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Class);// PinName + PinType
	InputPins[0].Value.Array[0].SetClassArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Class);// PinName + PinType
	InputPins[1].Value.Array[0].SetClassArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_ClassClass::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_ClassClass(GetConnectedPinValue(InputPins[0]).GetClassArg(), GetConnectedPinValue(InputPins[1]).GetClassArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_NameName::UEqualEqual_NameName()
{
	NodeName = "Equal (Name";
	NodeDescription = "Returns true if A and B are equal (A == B)";
	NodeCategory = "Utilities|Name";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Name);// PinName + PinType
	InputPins[0].Value.Array[0].SetNameArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_NameName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_NameName(GetConnectedPinValue(InputPins[0]).GetNameArg(), GetConnectedPinValue(InputPins[1]).GetNameArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNotEqual_NameName::UNotEqual_NameName()
{
	NodeName = "Not Equal (Name";
	NodeDescription = "Returns true if A and B are not equal (A != B)";
	NodeCategory = "Utilities|Name";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Name);// PinName + PinType
	InputPins[0].Value.Array[0].SetNameArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Name);// PinName + PinType
	InputPins[1].Value.Array[0].SetNameArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNotEqual_NameName::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NotEqual_NameName(GetConnectedPinValue(InputPins[0]).GetNameArg(), GetConnectedPinValue(InputPins[1]).GetNameArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeTransform::UMakeTransform()
{
	NodeName = "Make Transform";
	NodeDescription = "Make a transform from location, rotation and scale";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Rotation", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[2].MakeNodePin("Scale", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(FVector::OneVector); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UMakeTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::MakeTransform(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UBreakTransform::UBreakTransform()
{
	NodeName = "Break Transform";
	NodeDescription = "Breaks apart a transform into location, rotation and scale";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In Transform", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Location", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Rotation", EVariableTypes::Rotator);// PinName + PinType    
    OutputPins[3].MakeNodePin("Scale", EVariableTypes::Vector);// PinName + PinType
}


void UBreakTransform::Execute(int Index, int FromLoopIndex)
{
    FVector Location;
	FRotator Rotation;
	FVector Scale;
	UKismetMathLibrary::BreakTransform(GetConnectedPinValue(InputPins[1]).GetTransformArg(), Location, Rotation, Scale);
    
	OutputPins[1].Value.Array[0].SetVectorArg(Location);
	OutputPins[2].Value.Array[0].SetRotatorArg(Rotation);
	OutputPins[3].Value.Array[0].SetVectorArg(Scale);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UEqualEqual_TransformTransform::UEqualEqual_TransformTransform()
{
	NodeName = "Equal Transform";
	NodeDescription = "Returns true if transform A is equal to transform B";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UEqualEqual_TransformTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::EqualEqual_TransformTransform(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetTransformArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UNearlyEqual_TransformTransform::UNearlyEqual_TransformTransform()
{
	NodeName = "Nearly Equal (Transform";
	NodeDescription = "Returns true if transform A is nearly equal to B@param LocationTolerance	How close position of transforms need to be to be considered equal@param RotationTolerance	How close rotations of transforms need to be to be considered equal@param Scale3DTolerance		How close scale of transforms need to be to be considered equal";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	InputPins[2].MakeNodePin("Location Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	InputPins[3].MakeNodePin("Rotation Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	InputPins[4].MakeNodePin("Scale3DTolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[4].Value.Array[0].SetFloatArg(1.e-4f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UNearlyEqual_TransformTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::NearlyEqual_TransformTransform(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetTransformArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg(), GetConnectedPinValue(InputPins[4]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UComposeTransforms::UComposeTransforms()
{
	NodeName = "Compose Transforms";
	NodeDescription = "Compose two transforms in order: A  B.Order matters when composing transforms:A  B will yield a transform that logically first applies A then B to any subsequent transformation.Example: LocalToWorld = ComposeTransforms(DeltaRotation, LocalToWorld) will change rotation in local space by DeltaRotation.Example: LocalToWorld = ComposeTransforms(LocalToWorld, DeltaRotation) will change rotation in world space by DeltaRotation.@return New transform: A  B";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("B", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UComposeTransforms::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::ComposeTransforms(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetTransformArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTransformLocation::UTransformLocation()
{
	NodeName = "Transform Location";
	NodeDescription = "Transform a position by the supplied transform.For example, if T was an object's transform, this would transform a position from local space to world space.";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("T", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UTransformLocation::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::TransformLocation(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTransformDirection::UTransformDirection()
{
	NodeName = "Transform Direction";
	NodeDescription = "Transform a direction vector by the supplied transform - will not change its length.For example, if T was an object's transform, this would transform a direction from local space to world space.";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("T", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Direction", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UTransformDirection::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::TransformDirection(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTransformRotation::UTransformRotation()
{
	NodeName = "Transform Rotation";
	NodeDescription = "Transform a rotator by the supplied transform.For example, if T was an object's transform, this would transform a rotation from local space to world space.";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("T", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Rotation", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UTransformRotation::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::TransformRotation(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UInverseTransformLocation::UInverseTransformLocation()
{
	NodeName = "Inverse Transform Location";
	NodeDescription = "Transform a position by the inverse of the supplied transform.For example, if T was an object's transform, this would transform a position from world space to local space.";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("T", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Location", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UInverseTransformLocation::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::InverseTransformLocation(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UInverseTransformDirection::UInverseTransformDirection()
{
	NodeName = "Inverse Transform Direction";
	NodeDescription = "Transform a direction vector by the inverse of the supplied transform - will not change its length.For example, if T was an object's transform, this would transform a direction from world space to local space.";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("T", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Direction", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Vector);// PinName + PinType
}


void UInverseTransformDirection::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetVectorArg(UKismetMathLibrary::InverseTransformDirection(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UInverseTransformRotation::UInverseTransformRotation()
{
	NodeName = "Inverse Transform Rotation";
	NodeDescription = "Transform a rotator by the inverse of the supplied transform.For example, if T was an object's transform, this would transform a rotation from world space to local space.";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("T", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Rotation", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UInverseTransformRotation::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::InverseTransformRotation(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRelativeTransform::UMakeRelativeTransform()
{
	NodeName = "Make Relative Transform";
	NodeDescription = "Computes a relative transform of one transform compared to another.Example: ChildOffset = MakeRelativeTransform(Child.GetActorTransform(), Parent.GetActorTransform())This computes the relative transform of the Child from the Parent.@param		A				The object's transform@param		RelativeTo		The transform the result is relative to (in the same space as A)@return		The new relative transform";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin("A", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Relative To", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UMakeRelativeTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::MakeRelativeTransform(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetTransformArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UInvertTransform::UInvertTransform()
{
	NodeName = "Invert Transform";
	NodeDescription = "Returns the inverse of the given transform T.Example: Given a LocalToWorld transform, WorldToLocal will be returned.@param	T	The transform you wish to invert@return	The inverse of T.";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("T", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UInvertTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::InvertTransform(GetConnectedPinValue(InputPins[0]).GetTransformArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTInterpTo::UTInterpTo()
{
	NodeName = "TInterp To";
	NodeDescription = "Tries to reach a target transform.";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Transform);// PinName + PinType
}


void UTInterpTo::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetTransformArg(UKismetMathLibrary::TInterpTo(GetConnectedPinValue(InputPins[0]).GetTransformArg(), GetConnectedPinValue(InputPins[1]).GetTransformArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UTransform_Determinant::UTransform_Determinant()
{
	NodeName = "Determinant";
	NodeDescription = "Calculates the determinant of the transform (converts to FMatrix internally)";
	NodeCategory = "Math|Transform";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Transform", EVariableTypes::Transform);// PinName + PinType
	InputPins[0].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UTransform_Determinant::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::Transform_Determinant(GetConnectedPinValue(InputPins[0]).GetTransformArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFInterpTo::UFInterpTo()
{
	NodeName = "FInterp To";
	NodeDescription = "Tries to reach Target based on distance from Current position, giving a nice smooth feeling when tracking a position.@param		Current			Actual position@param		Target			Target position@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFInterpTo::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::FInterpTo(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UFInterpTo_Constant::UFInterpTo_Constant()
{
	NodeName = "FInterp To Constant";
	NodeDescription = "Tries to reach Target at a constant rate.@param		Current			Actual position@param		Target			Target position@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UFInterpTo_Constant::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::FInterpTo_Constant(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URInterpTo::URInterpTo()
{
	NodeName = "RInterp To";
	NodeDescription = "Tries to reach Target rotation based on Current rotation, giving a nice smooth feeling when rotating to Target rotation.@param		Current			Actual rotation@param		Target			Target rotation@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void URInterpTo::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::RInterpTo(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


URInterpTo_Constant::URInterpTo_Constant()
{
	NodeName = "RInterp To Constant";
	NodeDescription = "Tries to reach Target rotation at a constant rate.@param		Current			Actual rotation@param		Target			Target rotation@param		DeltaTime		Time since last tick@param		InterpSpeed		Interpolation speed@return		New interpolated position";
	NodeCategory = "Math|Interpolation";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Current", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[1].MakeNodePin("Target", EVariableTypes::Rotator);// PinName + PinType
	InputPins[1].Value.Array[0].SetRotatorArg(); // Default value

	InputPins[2].MakeNodePin("Delta Time", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	InputPins[3].MakeNodePin("Interp Speed", EVariableTypes::Float);// PinName + PinType
	InputPins[3].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void URInterpTo_Constant::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::RInterpTo_Constant(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), GetConnectedPinValue(InputPins[1]).GetRotatorArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg(), GetConnectedPinValue(InputPins[3]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPerlinNoise1D::UPerlinNoise1D()
{
	NodeName = "Perlin Noise1D";
	NodeDescription = "Generates a 1D Perlin noise from the given value.  Returns a continuous random value between -1.0 and 1.0.@param	Value	The input value that Perlin noise will be generated from.  This is usually a steadily incrementing time value.@return	Perlin noise in the range of -1.0 to 1.0";
	NodeCategory = "Math|Random";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodePin("Value", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Float);// PinName + PinType
}


void UPerlinNoise1D::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetFloatArg(UKismetMathLibrary::PerlinNoise1D(GetConnectedPinValue(InputPins[0]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMinimumAreaRectangle::UMinimumAreaRectangle()
{
	NodeName = "Minimum Area Rectangle";
	NodeDescription = "Finds the minimum area rectangle that encloses all of the points in InVertsUses algorithm found in http:www.geometrictools.comDocumentationMinimumAreaRectangle.pdf@param		InVerts	- Points to enclose in the rectangle@outparam	OutRectCenter - Center of the enclosing rectangle@outparam	OutRectSideA - Vector oriented and sized to represent one edge of the enclosing rectangle, orthogonal to OutRectSideB@outparam	OutRectSideB - Vector oriented and sized to represent one edge of the enclosing rectangle, orthogonal to OutRectSideA";
	NodeCategory = "Math|Geometry";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("In Verts", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Sample Surface Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("b Debug Draw", EVariableTypes::Bool);// PinName + PinType
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(5);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Rect Center", EVariableTypes::Vector);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Rect Rotation", EVariableTypes::Rotator);// PinName + PinType    
    OutputPins[3].MakeNodePin("Out Side Length X", EVariableTypes::Float);// PinName + PinType    
    OutputPins[4].MakeNodePin("Out Side Length Y", EVariableTypes::Float);// PinName + PinType
}


void UMinimumAreaRectangle::Execute(int Index, int FromLoopIndex)
{
    FVector OutRectCenter;
	FRotator OutRectRotation;
	float OutSideLengthX;
	float OutSideLengthY;
	UKismetMathLibrary::MinimumAreaRectangle(this, GetConnectedPinArray(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg(), OutRectCenter, OutRectRotation, OutSideLengthX, OutSideLengthY, GetConnectedPinValue(InputPins[3]).GetBoolArg());
    
	OutputPins[1].Value.Array[0].SetVectorArg(OutRectCenter);
	OutputPins[2].Value.Array[0].SetRotatorArg(OutRectRotation);
	OutputPins[3].Value.Array[0].SetFloatArg(OutSideLengthX);
	OutputPins[4].Value.Array[0].SetFloatArg(OutSideLengthY);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UPointsAreCoplanar::UPointsAreCoplanar()
{
	NodeName = "Points Are Coplanar";
	NodeDescription = "Determines whether a given set of points are coplanar, with a tolerance. Any three points or less are always coplanar.@param Points - The set of points to determine coplanarity for.@param Tolerance - Larger numbers means more variance is allowed.@return Whether the points are relatively coplanar, based on the tolerance";
	NodeCategory = "Math|Geometry";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodeArray("Points", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Tolerance", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(0.1f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UPointsAreCoplanar::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::PointsAreCoplanar(GetConnectedPinArray(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsPointInBox::UIsPointInBox()
{
	NodeName = "Is Point In Box";
	NodeDescription = "Determines whether the given point is in a box. Includes points on the box.@param Point			Point to test@param BoxOrigin		Origin of the box@param BoxExtent		Extents of the box (distance in each axis from origin)@return Whether the point is in the box.";
	NodeCategory = "Math|Geometry";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Box Origin", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Box Extent", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsPointInBox::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::IsPointInBox(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UIsPointInBoxWithTransform::UIsPointInBoxWithTransform()
{
	NodeName = "Is Point In Box With Transform";
	NodeDescription = "Determines whether a given point is in a box with a given transform. Includes points on the box.@param Point				Point to test@param BoxWorldTransform	Component-to-World transform of the box.@param BoxExtent			Extents of the box (distance in each axis from origin), in component space.@return Whether the point is in the box.";
	NodeCategory = "Math|Geometry";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin("Point", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Box World Transform", EVariableTypes::Transform);// PinName + PinType
	InputPins[1].Value.Array[0].SetTransformArg(); // Default value

	InputPins[2].MakeNodePin("Box Extent", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UIsPointInBoxWithTransform::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::IsPointInBoxWithTransform(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetTransformArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg()));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UGetSlopeDegreeAngles::UGetSlopeDegreeAngles()
{
	NodeName = "Get Slope Degree Angles";
	NodeDescription = "Returns Slope Pitch and Roll angles in degrees based on the following information:@param	MyRightYAxis				Right (Y) direction unit vector of Actor standing on Slope.@param	FloorNormal					Floor Normal (unit) vector.@param	UpVector					UpVector of reference frame.@outparam OutSlopePitchDegreeAngle	Slope Pitch angle (degrees)@outparam OutSlopeRollDegreeAngle		Slope Roll angle (degrees)";
	NodeCategory = "Math|Geometry";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("My Right YAxis", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Floor Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Up Vector", EVariableTypes::Vector);// PinName + PinType
	InputPins[3].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Out Slope Pitch Degree Angle", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("Out Slope Roll Degree Angle", EVariableTypes::Float);// PinName + PinType
}


void UGetSlopeDegreeAngles::Execute(int Index, int FromLoopIndex)
{
    float OutSlopePitchDegreeAngle;
	float OutSlopeRollDegreeAngle;
	UKismetMathLibrary::GetSlopeDegreeAngles(GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetVectorArg(), OutSlopePitchDegreeAngle, OutSlopeRollDegreeAngle);
    
	OutputPins[1].Value.Array[0].SetFloatArg(OutSlopePitchDegreeAngle);
	OutputPins[2].Value.Array[0].SetFloatArg(OutSlopeRollDegreeAngle);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


ULinePlaneIntersection_OriginNormal::ULinePlaneIntersection_OriginNormal()
{
	NodeName = "Line Plane Intersection (Origin & Normal";
	NodeDescription = "Computes the intersection point between a line and a plane.@param		T - The t of the intersection between the line and the plane@param		Intersection - The point of intersection between the line and the plane@return		True if the intersection test was successful.";
	NodeCategory = "Math|Intersection";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin("Line Start", EVariableTypes::Vector);// PinName + PinType
	InputPins[0].Value.Array[0].SetVectorArg(); // Default value

	InputPins[1].MakeNodePin("Line End", EVariableTypes::Vector);// PinName + PinType
	InputPins[1].Value.Array[0].SetVectorArg(); // Default value

	InputPins[2].MakeNodePin("Plane Origin", EVariableTypes::Vector);// PinName + PinType
	InputPins[2].Value.Array[0].SetVectorArg(); // Default value

	InputPins[3].MakeNodePin("Plane Normal", EVariableTypes::Vector);// PinName + PinType
	InputPins[3].Value.Array[0].SetVectorArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType    
    OutputPins[1].MakeNodePin("T", EVariableTypes::Float);// PinName + PinType    
    OutputPins[2].MakeNodePin("Intersection", EVariableTypes::Vector);// PinName + PinType
}


void ULinePlaneIntersection_OriginNormal::Execute(int Index, int FromLoopIndex)
{
    float T;
	FVector Intersection;
	OutputPins[0].Value.Array[0].SetBoolArg(UKismetMathLibrary::LinePlaneIntersection_OriginNormal(GetConnectedPinValue(InputPins[0]).GetVectorArg(), GetConnectedPinValue(InputPins[1]).GetVectorArg(), GetConnectedPinValue(InputPins[2]).GetVectorArg(), GetConnectedPinValue(InputPins[3]).GetVectorArg(), T, Intersection));
    
	OutputPins[1].Value.Array[0].SetFloatArg(T);
	OutputPins[2].Value.Array[0].SetVectorArg(Intersection);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UBreakRotator::UBreakRotator()
{
	NodeName = "Break Rotator";
	NodeDescription = "Breaks a rotator apart into Roll, Pitch, Yaw";
	NodeCategory = "Math|Rotator";

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin("In Rot", EVariableTypes::Rotator);// PinName + PinType
	InputPins[0].Value.Array[0].SetRotatorArg(); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Roll", EVariableTypes::Float);// PinName + PinType    
	OutputPins[1].MakeNodePin("Pitch", EVariableTypes::Float);// PinName + PinType    
	OutputPins[2].MakeNodePin("Yaw", EVariableTypes::Float);// PinName + PinType
}


void UBreakRotator::Execute(int Index, int FromLoopIndex)
{
	float Roll;
	float Pitch;
	float Yaw;
	UKismetMathLibrary::BreakRotator(GetConnectedPinValue(InputPins[0]).GetRotatorArg(), Roll, Pitch, Yaw);

	OutputPins[0].Value.Array[0].SetFloatArg(Roll);
	OutputPins[1].Value.Array[0].SetFloatArg(Pitch);
	OutputPins[2].Value.Array[0].SetFloatArg(Yaw);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UMakeRotator::UMakeRotator()
{
	NodeName = "Make Rotator";
	NodeDescription = "Makes a rotator {Roll, Pitch, Yaw}";
	NodeCategory = "Math|Rotator";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin("Roll", EVariableTypes::Float);// PinName + PinType
	InputPins[0].Value.Array[0].SetFloatArg(); // Default value

	InputPins[1].MakeNodePin("Pitch", EVariableTypes::Float);// PinName + PinType
	InputPins[1].Value.Array[0].SetFloatArg(); // Default value

	InputPins[2].MakeNodePin("Yaw", EVariableTypes::Float);// PinName + PinType
	InputPins[2].Value.Array[0].SetFloatArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Rotator);// PinName + PinType
}


void UMakeRotator::Execute(int Index, int FromLoopIndex)
{

	OutputPins[0].Value.Array[0].SetRotatorArg(UKismetMathLibrary::MakeRotator(GetConnectedPinValue(InputPins[0]).GetFloatArg(), GetConnectedPinValue(InputPins[1]).GetFloatArg(), GetConnectedPinValue(InputPins[2]).GetFloatArg()));

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}