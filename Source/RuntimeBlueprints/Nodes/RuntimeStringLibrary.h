// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Kismet/KismetStringLibrary.h"
#include "RuntimeStringLibrary.generated.h"


/** Converts a float value to a string */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_FloatToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_FloatToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts an integer value to a string */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_IntToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_IntToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a byte value to a string */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_ByteToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_ByteToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a boolean value to a string, either 'true' or 'false' */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_BoolToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_BoolToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a vector value to a string, in the form 'X= Y= Z=' */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_VectorToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_VectorToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts an IntVector value to a string, in the form 'X= Y= Z=' */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_IntVectorToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_IntVectorToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a vector2d value to a string, in the form 'X= Y=' */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_Vector2dToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_Vector2dToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a rotator value to a string, in the form 'P= Y= R=' */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_RotatorToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_RotatorToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a transform value to a string, in the form 'Translation: X= Y= Z= Rotation: P= Y= R= Scale: X= Y= Z=' */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_TransformToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_TransformToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a UObject value to a string by calling the object's GetName method */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_ObjectToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_ObjectToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a linear color value to a string, in the form '(R=,G=,B=,A=)' */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_ColorToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_ColorToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a name value to a string */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_NameToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_NameToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a string to a name value */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_StringToName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_StringToName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a string to a int value */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_StringToInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_StringToInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a string to a float value */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_StringToFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_StringToFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert String Back To Vector. IsValid indicates whether or not the string could be successfully converted. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_StringToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_StringToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert String Back To Vector2D. IsValid indicates whether or not the string could be successfully converted. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_StringToVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_StringToVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert String Back To Rotator. IsValid indicates whether or not the string could be successfully converted. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_StringToRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_StringToRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert String Back To Color. IsValid indicates whether or not the string could be successfully converted. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_StringToColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_StringToColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a float->string, create a new string in the form AppendTo+Prefix+InFloat+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InFloat - The float value to convert
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Float : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Float();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a int->string, creating a new string in the form AppendTo+Prefix+InInt+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InInt - The int value to convert
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Int : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Int();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a boolean->string, creating a new string in the form AppendTo+Prefix+InBool+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InBool - The bool value to convert. Will add "true" or "false" to the conversion string
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Bool : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Bool();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a vector->string, creating a new string in the form AppendTo+Prefix+InVector+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InVector - The vector value to convert. Uses the standard FVector::ToString conversion
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Vector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Vector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts an IntVector->string, creating a new string in the form AppendTo+Prefix+InIntVector+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InIntVector - The intVector value to convert. Uses the standard FVector::ToString conversion
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_IntVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_IntVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a vector2d->string, creating a new string in the form AppendTo+Prefix+InVector2d+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InVector2d - The vector2d value to convert. Uses the standard FVector2D::ToString conversion
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Vector2d : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Vector2d();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a rotator->string, creating a new string in the form AppendTo+Prefix+InRot+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InRot	- The rotator value to convert. Uses the standard ToString conversion
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Rotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Rotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a object->string, creating a new string in the form AppendTo+Prefix+object name+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InObj - The object to convert. Will insert the name of the object into the conversion string
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Object : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Object();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a color->string, creating a new string in the form AppendTo+Prefix+InColor+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InColor - The linear color value to convert. Uses the standard ToString conversion
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Color : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Color();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a color->string, creating a new string in the form AppendTo+Prefix+InName+Suffix
* @param AppendTo - An existing string to use as the start of the conversion string
* @param Prefix - A string to use as a prefix, after the AppendTo string
* @param InName - The name value to convert
* @param Suffix - A suffix to append to the end of the conversion string
* @return A new string built from the passed parameters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UBuildString_Name : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBuildString_Name();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Concatenates two strings together to make a new string
* @param A - The original string
* @param B - The string to append to A
* @returns A new string which is the concatenation of A+B
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UConcat_StrStr : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConcat_StrStr();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Test if the input strings are equal (A == B)
* @param A - The string to compare against
* @param B - The string to compare
* @returns True if the strings are equal, false otherwise
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_StrStr : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_StrStr();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Test if the input strings are equal (A == B), ignoring case
* @param A - The string to compare against
* @param B - The string to compare
* @returns True if the strings are equal, false otherwise
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_StriStri : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_StriStri();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Test if the input string are not equal (A != B)
* @param A - The string to compare against
* @param B - The string to compare
* @return Returns true if the input strings are not equal, false if they are equal
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_StrStr : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_StrStr();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Test if the input string are not equal (A != B), ignoring case differences
* @param A - The string to compare against
* @param B - The string to compare
* @return Returns true if the input strings are not equal, false if they are equal
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_StriStri : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_StriStri();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the number of characters in the string
* @param SourceString - The string to measure
* @return The number of chars in the string
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULen : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULen();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a substring from the string starting at the specified position
* @param SourceString - The string to get the substring from
* @param StartIndex - The location in SourceString to use as the start of the substring
* @param Length The length of the requested substring
*
* @return The requested substring
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetSubstring : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetSubstring();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Finds the starting index of a substring in the a specified string
* @param SearchIn The string to search within
* @param Substring The string to look for in the SearchIn string
* @param bUseCase Whether or not to be case-sensitive
* @param bSearchFromEnd Whether or not to start the search from the end of the string instead of the beginning
* @param StartPosition The position to start the search from
* @return The index (starting from 0 if bSearchFromEnd is false) of the first occurence of the substring
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFindSubstring : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFindSubstring();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns whether this string contains the specified substring.
*
* @param SubStr			Find to search for
* @param SearchCase		Indicates whether the search is case sensitive or not ( defaults to ESearchCase::IgnoreCase )
* @param SearchDir			Indicates whether the search starts at the begining or at the end ( defaults to ESearchDir::FromStart )
* @return					Returns whether the string contains the substring
**/
UCLASS()
class RUNTIMEBLUEPRINTS_API UContains : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UContains();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets a single character from the string (as an integer)
* @param SourceString - The string to convert
* @param Index - Location of the character whose value is required
* @return The integer value of the character or 0 if index is out of range
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetCharacterAsNumber : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetCharacterAsNumber();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets an array of strings from a source string divided up by a separator and empty strings can optionally be culled.
* @param SourceString - The string to chop up
* @param Delimiter - The string to delimit on
* @param CullEmptyStrings = true - Cull (true) empty strings or add them to the array (false)
* @return The array of string that have been separated
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UParseIntoArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UParseIntoArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Concatenates an array of strings into a single string.
* @param SourceArray - The array of strings to concatenate.
* @param Separator - The string used to separate each element.
* @return The final, joined, separated string.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UJoinStringArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UJoinStringArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns an array that contains one entry for each character in SourceString
* @param	SourceString	The string to break apart into characters
* @return	An array containing one entry for each character in SourceString
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetCharacterArrayFromString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetCharacterArrayFromString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a string converted to Upper case
* @param	SourceString	The string to convert
* @return	The string in upper case
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UToUpper : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UToUpper();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a string converted to Lower case
* @param	SourceString	The string to convert
* @return	The string in lower case
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UToLower : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UToLower();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
* Pad the left of this string for a specified number of characters
* @param	SourceString	The string to pad
* @param	ChCount			Amount of padding required
* @return	The padded string
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULeftPad : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULeftPad();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
* Pad the right of this string for a specified number of characters
* @param	SourceString	The string to pad
* @param	ChCount			Amount of padding required
* @return	The padded string
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URightPad : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URightPad();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/*
* Checks if a string contains only numeric characters
* @param	SourceString	The string to check
* @return true if the string only contains numeric characters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsNumeric : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsNumeric();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Removes whitespace characters from the front of this string.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UTrim : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTrim();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Removes trailing whitespace characters
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UTrimTrailing : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTrimTrailing();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Takes an array of strings and removes any zero length entries.
*
* @param	InArray	The array to cull
*
* @return	The number of elements left in InArray
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCullArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCullArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a copy of this string, with the characters in reverse order
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UReverse : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UReverse();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the left most given number of characters */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULeft : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULeft();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the left most characters from the string chopping the given number of characters from the end */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULeftChop : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULeftChop();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the string to the right of the specified location, counting back from the right (end of the word). */
UCLASS()
class RUNTIMEBLUEPRINTS_API URight : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URight();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the string to the right of the specified location, counting forward from the left (from the beginning of the word). */
UCLASS()
class RUNTIMEBLUEPRINTS_API URightChop : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URightChop();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the substring from Start position for Count characters. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMid : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMid();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Convert a number of seconds into minutes:seconds.milliseconds format string (including leading zeroes)
*
* @return A new string built from the seconds parameter
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UTimeSecondsToString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTimeSecondsToString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};