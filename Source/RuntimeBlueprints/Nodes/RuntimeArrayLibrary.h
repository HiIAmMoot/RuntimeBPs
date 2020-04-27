// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Nodes/ExampleNodes.h"
#include "RuntimeArrayLibrary.generated.h"


/**
*Add item to array
*
*@param	TargetArray		The array to add item to
*@param	NewItem			The item to add to the array
*@return	The index of the newly added item
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Add : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Add();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*Add item to array (unique)
*
*@param		TargetArray		The array to add item to
*@param		NewItem			The item to add to the array
*@return	The index of the newly added item, or INDEX_NONE if the item is already present in the array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_AddUnique : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_AddUnique();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Shuffle (randomize) the elements of an array
*
*@param	TargetArray		The array to shuffle
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Shuffle : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Shuffle();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks if two arrays are memberwise identical
*
* @param	ArrayA		One of the arrays to compare
* @param	ArrayB		The other array to compare
* @return Whether the two arrays are identical
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Identical : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Identical();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*Append an array to another array
*
*@param	TargetArray		The array to add the source array to
*@param	SourceArray		The array to add to the target array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Append : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Append();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Insert item at the given index into the array.
*
*@param	TargetArray		The array to insert into
*@param	NewItem			The item to insert into the array
*@param	Index			The index at which to insert the item into the array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Insert : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Insert();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Remove item at the given index from the array.
*
*@param	TargetArray		The array to remove from
*@param	IndexToRemove	The index into the array to remove from
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Remove : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Remove();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Remove all instances of item from array.
*
*@param	TargetArray		The array to remove from
*@param	Item			The item to remove from the array
*@return	True if one or more items were removed
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_RemoveItem : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_RemoveItem();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Clear an array, removes all content
*
*@param	TargetArray		The array to clear
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Clear : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Clear();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Resize Array to specified size.
*
*@param	TargetArray		The array to resize
*@param	Size			The new size of the array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Resize : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Resize();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Get the number of items in an array
*
*@param	TargetArray		The array to get the length of
*@return	The length of the array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Length : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Length();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Get the last valid index into an array
*
*@param	TargetArray		The array to perform the operation on
*@return	The last valid index of the array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_LastIndex : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_LastIndex();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Given an array and an index, returns a copy of the item found at that index
*
*@param	TargetArray		The array to get an item from
*@param	Index			The index in the array to get an item from
*@return	A copy of the item stored at the index
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Get : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Get();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Given an array and an index, assigns the item to that array element
*
*@param	TargetArray		The array to perform the operation on
*@param	Index			The index to assign the item to
*@param	Item			The item to assign to the index of the array
*@param	bSizeToFit		If true, the array will expand if Index is greater than the current size of the array
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Set : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Set();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Swaps the elements at the specified positions in the specified array
*If the specified positions are equal, invoking this method leaves the array unchanged
*
*@param	TargetArray		The array to perform the operation on
*@param    FirstIndex      The index of one element to be swapped
*@param    SecondIndex     The index of the other element to be swapped
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Swap : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Swap();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Finds the index of the first instance of the item within the array
*
*@param	TargetArray		The array to search for the item
*@param	ItemToFind		The item to look for
*@return	The index the item was found at, or -1 if not found
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_Find : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_Find();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
*Tests if IndexToTest is valid, i.e. greater than or equal to zero, and less than the number of elements in TargetArray.
*
*@param	TargetArray		Array to use for the IsValidIndex test
*@param	IndexToTest		The Index, that we want to test for being valid
*@return	True if the Index is Valid, i.e. greater than or equal to zero, and less than the number of elements in TargetArray.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UArray_IsValidIndex : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UArray_IsValidIndex();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

UCLASS()
class RUNTIMEBLUEPRINTS_API UForEachLoop : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UForEachLoop();

	TArray<FNodeVarArgs> Array;

	int CurrentLoopIndex;

	int LastIndex;

	int ReceivedFromLoopIndex;

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

	virtual void Next() override;

};