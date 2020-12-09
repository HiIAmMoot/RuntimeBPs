// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeArrayLibrary.h"
#include "RuntimeBpConstructor.h"

UArray_Add::UArray_Add()
{
	NodeName = "Add";
	NodeDescription = "Add item to array@param	TargetArray		The array to add item to@param	NewItem			The item to add to the array@return	The index of the newly added item";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodePin("New Item", EVariableTypes::WildCard);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
	OutputPins[1].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UArray_Add::Execute(int Index, int FromLoopIndex)
{
	// We get the actual variable if the input pin is connected to a variable
	OutputPins[1].Value.Array[0].SetIntArg(GetConnectedVariableRef(InputPins[1]).v.Add(GetConnectedPinValue(InputPins[2])));

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UArray_AddUnique::UArray_AddUnique()
{
	NodeName = "Add Unique";
	NodeDescription = "Add item to array (unique)@param		TargetArray		The array to add item to@param		NewItem			The item to add to the array@return	The index of the newly added item, or -1 if the item is already present in the array";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodePin("New Item", EVariableTypes::WildCard);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
	OutputPins[1].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UArray_AddUnique::Execute(int Index, int FromLoopIndex)
{
	// We get the actual variable if the input pin is connected to a variable
	OutputPins[1].Value.Array[0].SetIntArg(GetConnectedVariableRef(InputPins[1]).v.AddUnique(GetConnectedPinValue(InputPins[2])));

	Super::Execute(0, FromLoopIndex);// Index here is the array index


}

UArray_Shuffle::UArray_Shuffle()
{
	NodeName = "Shuffle";
	NodeDescription = "Shuffle (randomize) the elements of an array@param	TargetArray		The array to shuffle";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(2);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Shuffle::Execute(int Index, int FromLoopIndex)
{
	int Length = GetConnectedVariableRef(InputPins[1]).v.Num();
	if (Length > 1)
	{
		int32 LastIndex = Length - 1;
		for (int32 i = 0; i <= LastIndex; ++i)
		{
			int32 ArrayIndex = FMath::RandRange(i, LastIndex);
			if (i != ArrayIndex)
			{
				GetConnectedVariableRef(InputPins[1]).v.SwapMemory(i, ArrayIndex);
			}
		}
	}

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UArray_Identical::UArray_Identical()
{
	NodeName = "Identical";
	NodeDescription = "Checks if two arrays are memberwise identical@param	ArrayA		One of the arrays to compare@param	ArrayB		The other array to compare@return Whether the two arrays are identical";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(2);
	InputPins[0].MakeNodeArray("Array A", EVariableTypes::WildCard);// PinName + PinType
	InputPins[0].Value.SetIntArg(); // Default value

	InputPins[1].MakeNodeArray("Array B", EVariableTypes::WildCard);// PinName + PinType
	InputPins[1].Value.SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UArray_Identical::Execute(int Index, int FromLoopIndex)
{
	FNodeVarArgsArray ArrayA = GetConnectedPinArray(InputPins[0]);
	FNodeVarArgsArray ArrayB = GetConnectedPinArray(InputPins[1]);

	if (ArrayA.Array.Num() == ArrayB.Array.Num() && InputPins[0].VariableType == InputPins[1].VariableType)
	{
		if (ArrayA.Array.Num() > 0)
		{
			int ArrayANum = ArrayA.Array.Num();
			// We set the bool to true here, the loop will set it to false if the array doesn't match
			OutputPins[0].Value.Array[0].SetBoolArg(true);
			for (int i = 0; i < ArrayANum; ++i)
			{
				if (!(ArrayA.Array[i] == ArrayB.Array[i]))
				{
					OutputPins[0].Value.Array[0].SetBoolArg(false);
					break;
				}
			}
		}
		else
		{
		OutputPins[0].Value.Array[0].SetBoolArg(true);
		}

	}
	else
	{
		OutputPins[0].Value.Array[0].SetBoolArg(false);
	}
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UArray_Append::UArray_Append()
{
	NodeName = "Append Array";
	NodeDescription = "Append an array to another array@param	TargetArray		The array that will be added to@param	SourceArray		This array will be added to the target array";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodeArray("Source Array", EVariableTypes::WildCard);// PinName + PinType

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Append::Execute(int Index, int FromLoopIndex)
{
	TArray<FNodeVarArgs> SourceArray = GetConnectedPinArray(InputPins[2]).Array;
	int ArrayNum = SourceArray.Num();

	GetConnectedVariableRef(InputPins[1]).v.Append(SourceArray);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UArray_Insert::UArray_Insert()
{
	NodeName = "Insert";
	NodeDescription = "Insert item at the given index into the array.@param	TargetArray		The array to insert into@param	NewItem			The item to insert into the array@param	Index			The index at which to insert the item into the array";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(4);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodePin("New Item", EVariableTypes::WildCard);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	InputPins[3].MakeNodePin("Index", EVariableTypes::Int);// PinName + PinType
	InputPins[3].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Insert::Execute(int Index, int FromLoopIndex)
{
	int InsertedIndex = GetConnectedPinValue(InputPins[2]).GetIntArg();

	if (InsertedIndex > 0)
	{
		GetConnectedVariableRef(InputPins[1]).v.Insert(GetConnectedPinValue(InputPins[2]), InsertedIndex);
	}

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Remove::UArray_Remove()
{
	NodeName = "Remove Index";
	NodeDescription = "Remove item at the given index from the array.@param	TargetArray		The array to remove from@param	IndexToRemove	The index into the array to remove from";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType
	InputPins[1].Value.SetIntArg(); // Default value

	InputPins[2].MakeNodePin("Index To Remove", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Remove::Execute(int Index, int FromLoopIndex)
{
	int IndexToRemove = GetConnectedPinValue(InputPins[2]).GetIntArg();

	if (GetConnectedVariableRef(InputPins[1]).v.Num() > IndexToRemove && IndexToRemove >= 0)
	{
		GetConnectedVariableRef(InputPins[1]).v.RemoveSingle(GetConnectedVariableRef(InputPins[1]).v[IndexToRemove]);
	}
	
	// UKismetArrayLibrary::Array_Remove(GetConnectedPinArray(InputPins[1]).GetIntArg(), GetConnectedPinValue(InputPins[2]).GetIntArg());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_RemoveItem::UArray_RemoveItem()
{
	NodeName = "Remove Item";
	NodeDescription = "Remove all instances of item from array.@param	TargetArray		The array to remove from@param	Item			The item to remove from the array@return	True if one or more items were removed";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodePin("Item", EVariableTypes::WildCard);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");// Output exec pin    
    OutputPins[1].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UArray_RemoveItem::Execute(int Index, int FromLoopIndex)
{
	int RemovedItems = GetConnectedVariableRef(InputPins[1]).v.RemoveSingle(GetConnectedPinValue(InputPins[2]));

	if (RemovedItems > 0)
	{
		OutputPins[1].Value.Array[0].SetBoolArg(true);
	}
	else
	{
		OutputPins[1].Value.Array[0].SetBoolArg(false);
	}
	        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Clear::UArray_Clear()
{
	NodeName = "Clear";
	NodeDescription = "Clear an array, removes all content@param	TargetArray		The array to clear";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Clear::Execute(int Index, int FromLoopIndex)
{
	GetConnectedVariableRef(InputPins[1]).v.Empty();
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Resize::UArray_Resize()
{
	NodeName = "Resize";
	NodeDescription = "Resize Array to specified size.@param	TargetArray		The array to resize@param	Size			The new size of the array";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(3); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodePin("Size", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Resize::Execute(int Index, int FromLoopIndex)
{
	int NewSize = GetConnectedPinValue(InputPins[2]).GetIntArg();
	if (NewSize >= 0)
	{
		GetConnectedVariableRef(InputPins[1]).v.SetNum(GetConnectedPinValue(InputPins[2]).GetIntArg());
	}
	
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Length::UArray_Length()
{
	NodeName = "Length";
	NodeDescription = "Get the number of items in an array@param	TargetArray		The array to get the length of@return	The length of the array";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UArray_Length::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(GetConnectedVariableRef(InputPins[0]).v.Num());
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_LastIndex::UArray_LastIndex()
{
	NodeName = "Last Index";
	NodeDescription = "Get the last valid index into an array@param	TargetArray		The array to perform the operation on@return	The last valid index of the array";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(1); 
	InputPins[0].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UArray_LastIndex::Execute(int Index, int FromLoopIndex)
{
    
	OutputPins[0].Value.Array[0].SetIntArg(GetConnectedVariableRef(InputPins[0]).v.Num() - 1);

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Get::UArray_Get()
{
	NodeName = "Get Element";
	NodeDescription = "Given an array and an index, returns a copy of the item found at that index@param	TargetArray		The array to get an item from@param	Index			The index in the array to get an item from@return	A copy of the item stored at the index";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[1].MakeNodePin("Index", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);  
    OutputPins[0].MakeNodePin("Item", EVariableTypes::WildCard);// PinName + PinType
}


void UArray_Get::Execute(int Index, int FromLoopIndex)
{
    FNodeVarArgs Item;
	int ArrayIndex = GetConnectedPinValue(InputPins[1]).GetIntArg();

	if (GetConnectedPinArray(InputPins[0]).Array.Num() > ArrayIndex && ArrayIndex >= 0)
	{
		Item = GetConnectedPinArray(InputPins[0]).Array[ArrayIndex];
	}
	else
	{
		Item = FNodeVarArgs(OutputPins[0].VariableType);
	}
	OutputPins[0].Value.Array[0] = Item;

	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Set::UArray_Set()
{
	NodeName = "Set Element";
	NodeDescription = "Given an array and an index, assigns the item to that array element@param	TargetArray		The array to perform the operation on@param	Index			The index to assign the item to@param	Item			The item to assign to the index of the array@param	bSizeToFit		If true, the array will expand if Index is greater than the current size of the array";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(5); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodePin("Index", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	InputPins[3].MakeNodePin("Item", EVariableTypes::WildCard);// PinName + PinType
	InputPins[3].Value.Array[0].SetIntArg(); // Default value

	InputPins[4].MakeNodePin("Size To Fit", EVariableTypes::Bool);// PinName + PinType
	InputPins[4].Value.Array[0].SetBoolArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Set::Execute(int Index, int FromLoopIndex)
{
	int ArrayIndex = GetConnectedPinValue(InputPins[2]).GetIntArg();

	if (ArrayIndex >= 0)
	{
		FNodeVarArgs Item = GetConnectedPinValue(InputPins[3]);
		if (GetConnectedVariableRef(InputPins[1]).v.Num() > ArrayIndex)
		{
			GetConnectedVariableRef(InputPins[1]).v[ArrayIndex] = Item;
		}
		else if (GetConnectedPinValue(InputPins[4]).GetBoolArg())
		{
			GetConnectedVariableRef(InputPins[1]).v.SetNum(ArrayIndex + 1);
			GetConnectedVariableRef(InputPins[1]).v[ArrayIndex] = Item;
		}
	}
    
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Swap::UArray_Swap()
{
	NodeName = "Swap Array Elements";
	NodeDescription = "Swaps the elements at the specified positions in the specified arrayIf the specified positions are equal, invoking this method leaves the array unchanged@param	TargetArray		The array to perform the operation on@param    FirstIndex      The index of one element to be swapped@param    SecondIndex     The index of the other element to be swapped";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(4); 
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[2].MakeNodePin("First Index", EVariableTypes::Int);// PinName + PinType
	InputPins[2].Value.Array[0].SetIntArg(); // Default value

	InputPins[3].MakeNodePin("Second Index", EVariableTypes::Int);// PinName + PinType
	InputPins[3].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");// Output exec pin
}


void UArray_Swap::Execute(int Index, int FromLoopIndex)
{
	int FirstIndex = GetConnectedPinValue(InputPins[2]).GetIntArg();
	int SecondIndex = GetConnectedPinValue(InputPins[3]).GetIntArg();

	if (FirstIndex >= 0 && SecondIndex >= 0 && GetConnectedVariableRef(InputPins[1]).v.Num() > (FMath::Max<int>({ FirstIndex, SecondIndex })))
	{
		GetConnectedVariableRef(InputPins[1]).v.Swap(FirstIndex, SecondIndex);
	}
   
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_Find::UArray_Find()
{
	NodeName = "Find Item";
	NodeDescription = "Finds the index of the first instance of the item within the array@param	TargetArray		The array to search for the item@param	ItemToFind		The item to look for@return	The index the item was found at, or -1 if not found";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[1].MakeNodePin("Item To Find", EVariableTypes::WildCard);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Int);// PinName + PinType
}


void UArray_Find::Execute(int Index, int FromLoopIndex)
{
	OutputPins[0].Value.Array[0].SetIntArg(GetConnectedPinArray(InputPins[1]).Array.Find(GetConnectedPinValue(InputPins[1])));
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}


UArray_IsValidIndex::UArray_IsValidIndex()
{
	NodeName = "Is Valid Index";
	NodeDescription = "Tests if IndexToTest is valid, i.e. greater than or equal to zero, and less than the number of elements in TargetArray.@param	TargetArray		Array to use for the IsValidIndex test@param	IndexToTest		The Index, that we want to test for being valid@return	True if the Index is Valid, i.e. greater than or equal to zero, and less than the number of elements in TargetArray.";
	NodeCategory = "Utilities|Array";
	
	InputPins.SetNum(2); 
	InputPins[0].MakeNodeArray("Target Array", EVariableTypes::WildCard);// PinName + PinType

	InputPins[1].MakeNodePin("Index To Test", EVariableTypes::Int);// PinName + PinType
	InputPins[1].Value.Array[0].SetIntArg(); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Return", EVariableTypes::Bool);// PinName + PinType
}


void UArray_IsValidIndex::Execute(int Index, int FromLoopIndex)
{
	int IndexToTest = GetConnectedPinValue(InputPins[1]).GetIntArg();

	if (IndexToTest >= 0 && GetConnectedPinArray(InputPins[0]).Array.Num() > IndexToTest)
	{
		OutputPins[0].Value.Array[0].SetBoolArg(true);
	}
	else
	{
		OutputPins[0].Value.Array[0].SetBoolArg(false);
	}
        
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}

UForEachLoop::UForEachLoop()
{
	NodeName = "For Each Loop";

	InputPins.SetNum(2);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Array", EVariableTypes::WildCard);

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Loop Body");
	OutputPins[1].MakeNodePin("Array Element", EVariableTypes::WildCard);
	OutputPins[2].MakeNodePin("Array Index", EVariableTypes::Int);
	OutputPins[3].MakeNodePin("Completed");
}

void UForEachLoop::Execute(int Index, int FromLoopIndex)
{
	CurrentLoopIndex = 0;
	// Copy the array so we don't have to go down the chain to get the array for each iteration
	Array = GetConnectedPinArray(InputPins[1]).Array;
	LastIndex = Array.Num() - 1;
	ReceivedFromLoopIndex = FromLoopIndex;
	if (LastIndex >= 0 && CurrentLoopIndex >= 0)
	{
		Next();
	}
	else
	{
		Super::Execute(3, FromLoopIndex);// On Completed
	}
}

// This function is automatically called again by the last function in the execution chain by checking FromLoopIndex
void UForEachLoop::Next()
{
	if (CurrentLoopIndex <= LastIndex)
	{
		// Array element, we don't need to know what kind of array it is to pass the value
		OutputPins[1].Value.Array[0] = Array[CurrentLoopIndex];
		// Array index
		OutputPins[2].Value.Array[0].SetIntArg(CurrentLoopIndex);

		// Doing a sleep every 1024 iterations to not overload the thread
		if (BPConstructor->GetMultiThread() && !(CurrentLoopIndex & 1023))
		{
			FPlatformProcess::Sleep(0.01);
			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				CurrentLoopIndex++;
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, NodeIndex, FunctionIndex);
				//Super::Execute(0, NodeIndex);// Loop Body

			});
		}
		else
		{
			CurrentLoopIndex++;
			Super::Execute(0, NodeIndex);// Loop Body
		}
	}
	else
	{
		if (BPConstructor->GetMultiThread())
		{
			FPlatformProcess::Sleep(0.01);
			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 3, ReceivedFromLoopIndex, FunctionIndex);
				//Super::Execute(2, ReceivedFromLoopIndex);// On Completed
			});
		}
		else
		{
			Super::Execute(3, ReceivedFromLoopIndex);// On Completed
		}
	}
}

UForEachLoopWithBreak::UForEachLoopWithBreak()
{
	NodeName = "For Each Loop";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodeArray("Array", EVariableTypes::WildCard);
	InputPins[2].MakeNodePin("Break");// No args means execute

	OutputPins.SetNum(4);
	OutputPins[0].MakeNodePin("Loop Body");
	OutputPins[1].MakeNodePin("Array Element", EVariableTypes::WildCard);
	OutputPins[2].MakeNodePin("Array Index", EVariableTypes::Int);
	OutputPins[3].MakeNodePin("Completed");
}

void UForEachLoopWithBreak::Execute(int Index, int FromLoopIndex)
{
	if (Index == 2)
	{
		Break = true;
		return;
	}

	Break = false;
	CurrentLoopIndex = 0;

	// Copy the array so we don't have to go down the chain to get the array for each iteration
	Array = GetConnectedPinArray(InputPins[1]).Array;
	LastIndex = Array.Num() - 1;
	ReceivedFromLoopIndex = FromLoopIndex;
	if (LastIndex >= 0 && CurrentLoopIndex >= 0)
	{
		Next();
	}
	else
	{
		Super::Execute(3, FromLoopIndex);// On Completed
	}
}

// This function is automatically called again by the last function in the execution chain by checking FromLoopIndex
void UForEachLoopWithBreak::Next()
{
	if (Break)
	{
		Super::Execute(3, ReceivedFromLoopIndex);// On Completed
		return;
	}

	if (CurrentLoopIndex <= LastIndex)
	{
		// Array element, we don't need to know what kind of array it is to pass the value
		OutputPins[1].Value.Array[0] = Array[CurrentLoopIndex];
		// Array index
		OutputPins[2].Value.Array[0].SetIntArg(CurrentLoopIndex);

		// Doing a sleep every 1024 iterations to not overload the thread
		if (BPConstructor->GetMultiThread() && !(CurrentLoopIndex & 1023))
		{
			FPlatformProcess::Sleep(0.01);
			AsyncTask(ENamedThreads::GameThread, [this]()
				{
					CurrentLoopIndex++;
					URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, NodeIndex, FunctionIndex);
					//Super::Execute(0, NodeIndex);// Loop Body

				});
		}
		else
		{
			CurrentLoopIndex++;
			Super::Execute(0, NodeIndex);// Loop Body
		}
	}
	else
	{
		if (BPConstructor->GetMultiThread())
		{
			FPlatformProcess::Sleep(0.01);
			AsyncTask(ENamedThreads::GameThread, [this]()
				{
					URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 3, ReceivedFromLoopIndex, FunctionIndex);
					//Super::Execute(2, ReceivedFromLoopIndex);// On Completed
				});
		}
		else
		{
			Super::Execute(3, ReceivedFromLoopIndex);// On Completed
		}
	}
}