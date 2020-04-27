// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RuntimeSystemLibrary.generated.h"


// Return true if the object is usable : non-null and not pending kill
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsValid : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsValid();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

// Return true if the class is usable : non-null and not pending kill
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsValidClass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsValidClass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

// Returns the actual object name.
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetObjectName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetObjectName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

// Returns the full path to the specified object.
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetPathName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetPathName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

// Returns the display name (or actor label), for displaying as a debugging aid.
// Note: In editor builds, this is the actor label.  In non-editor builds, this is the actual object name.  This function should not be used to uniquely identify actors!
// It is not localized and should not be used for display to an end user of a game.
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetDisplayName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetDisplayName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

// Returns the display name of a class
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetClassDisplayName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetClassDisplayName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

// Returns the outer object of an object.
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetOuterObject : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetOuterObject();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get the current game time, in seconds. This stops when the game is paused and is affected by slomo.
*
* @param WorldContextObject	World context
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetGameTimeInSeconds : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetGameTimeInSeconds();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns whether the world this object is in is the host or not */
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsServer : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsServer();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns whether this is running on a dedicated server */
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsDedicatedServer : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsDedicatedServer();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns whether this game instance is stand alone (no networking). */
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsStandalone : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsStandalone();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a literal integer
* @param	Value	value to set the integer to
* @return	The literal integer
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeLiteralInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeLiteralInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a literal float
* @param	Value	value to set the float to
* @return	The literal float
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeLiteralFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeLiteralFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a literal bool
* @param	Value	value to set the bool to
* @return	The literal bool
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeLiteralBool : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeLiteralBool();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a literal name
* @param	Value	value to set the name to
* @return	The literal name
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeLiteralName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeLiteralName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a literal byte
* @param	Value	value to set the byte to
* @return	The literal byte
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeLiteralByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeLiteralByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a literal string
* @param	Value	value to set the string to
* @return	The literal string
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeLiteralString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeLiteralString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a literal FText
* @param	Value	value to set the FText to
* @return	The literal FText
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeLiteralText : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeLiteralText();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Sets the game window title */
UCLASS()
class RUNTIMEBLUEPRINTS_API USetWindowTitle : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USetWindowTitle();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get bounds */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetComponentBounds : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetComponentBounds();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UGetActorBounds : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetActorBounds();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Sets the state of the transition message rendered by the viewport. (The blue text displayed when the game is paused and so forth.)
*
* @param WorldContextObject	World context
* @param State					set true to suppress transition message
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API USetSuppressViewportTransitionMessage : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USetSuppressViewportTransitionMessage();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};