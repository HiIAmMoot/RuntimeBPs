// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Kismet/KismetMathLibrary.h"
#include "RuntimeMathLibrary.generated.h"


/** Returns a uniformly distributed random bool*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomBool : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomBool();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get a random chance with the specified weight. Range of weight is 0.0 - 1.0 E.g.,
*		Weight = .6 return value = True 60% of the time
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomBoolWithWeight : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomBoolWithWeight();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the logical complement of the Boolean value (NOT A) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNot_PreBool : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNot_PreBool();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if the values are equal (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_BoolBool : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_BoolBool();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if the values are not equal (A != B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_BoolBool : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_BoolBool();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the logical AND of two values (A AND B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBooleanAND : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBooleanAND();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the logical NAND of two values (A AND B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBooleanNAND : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBooleanNAND();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the logical OR of two values (A OR B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBooleanOR : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBooleanOR();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the logical eXclusive OR of two values (A XOR B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBooleanXOR : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBooleanXOR();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the logical Not OR of two values (A NOR B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBooleanNOR : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBooleanNOR();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Multiplication (A * B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Division (A / B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Modulo (A % B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPercent_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPercent_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Addition (A + B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Subtraction (A - B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the minimum value of A and B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBMin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBMin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the maximum value of A and B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBMax : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBMax();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is less than B (A < B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULess_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULess_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is greater than B (A > B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGreater_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGreater_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is less than or equal to B (A <= B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULessEqual_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULessEqual_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is greater than or equal to B (A >= B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGreaterEqual_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGreaterEqual_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is equal to B (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is not equal to B (A != B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_ByteByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_ByteByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Multiplication (A * B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Division (A / B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Modulo (A % B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPercent_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPercent_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Addition (A + B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Subtraction (A - B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is less than B (A < B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULess_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULess_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is greater than B (A > B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGreater_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGreater_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is less than or equal to B (A <= B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULessEqual_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULessEqual_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is greater than or equal to B (A >= B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGreaterEqual_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGreaterEqual_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is equal to B (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is not equal to B (A != B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if value is between Min and Max (V >= Min && V <= Max)
* If InclusiveMin is true, value needs to be equal or larger than Min, else it needs to be larger
* If InclusiveMax is true, value needs to be smaller or equal than Max, else it needs to be smaller
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UInRange_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UInRange_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Bitwise AND (A & B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAnd_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAnd_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Bitwise XOR (A ^ B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UXor_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UXor_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Bitwise OR (A | B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UOr_IntInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UOr_IntInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Bitwise NOT (~A) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNot_Int : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNot_Int();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Sign (integer, returns -1 if A < 0, 0 if A is zero, and +1 if A > 0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USignOfInteger : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USignOfInteger();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns a uniformly distributed random number between 0 and Max - 1 */
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomInteger : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomInteger();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Return a random integer between Min and Max (>= Min and <= Max) */
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomIntegerInRange : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomIntegerInRange();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the minimum value of A and B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the maximum value of A and B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMax : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMax();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Value clamped to be between A and B (inclusive) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UClamp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UClamp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the absolute (positive) value of A */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAbs_Int : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAbs_Int();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Power (Base to the Exp-th power) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiplyMultiply_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiplyMultiply_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Multiplication (A * B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Multiplication (A * B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_IntFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_IntFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Division (A / B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Modulo (A % B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UPercent_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPercent_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the fractional part of a float. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFraction : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFraction();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Addition (A + B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Subtraction (A - B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is Less than B (A < B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULess_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULess_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is greater than B (A > B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGreater_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGreater_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is Less than or equal to B (A <= B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULessEqual_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULessEqual_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is greater than or equal to B (A >= B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGreaterEqual_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGreaterEqual_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is exactly equal to B (A == B)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A is nearly equal to B (|A - B| < ErrorTolerance) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNearlyEqual_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNearlyEqual_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A does not equal B (A != B)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if value is between Min and Max (V >= Min && V <= Max)
* If InclusiveMin is true, value needs to be equal or larger than Min, else it needs to be larger
* If InclusiveMax is true, value needs to be smaller or equal than Max, else it needs to be smaller
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UInRange_FloatFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UInRange_FloatFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the hypotenuse of a right-angled triangle given the width and height. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UHypotenuse : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UHypotenuse();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Snaps a value to the nearest grid multiple. E.g.,
*		Location = 5.1, GridSize = 10.0 : return value = 10.0
* If GridSize is 0 Location is returned
* if GridSize is very small precision issues may occur.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGridSnap_Float : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGridSnap_Float();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the absolute (positive) value of A */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAbs : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAbs();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the sine of A (expects Radians)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API USin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse sine (arcsin) of A (result is in Radians) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAsin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAsin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the cosine of A (expects Radians)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCos : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCos();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse cosine (arccos) of A (result is in Radians) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAcos : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAcos();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the tan of A (expects Radians)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UTan : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTan();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse tan (atan) (result is in Radians)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UAtan : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAtan();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse tan (atan2) of A/B (result is in Radians)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UAtan2 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAtan2();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns exponential(e) to the power A (e^A)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UExp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UExp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns log of A base B (if B^R == A, returns R)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULog : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULog();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns natural log of A (if e^R == A, returns R)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULoge : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULoge();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns square root of A*/
UCLASS()
class RUNTIMEBLUEPRINTS_API USqrt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USqrt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns square of A (A*A)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API USquare : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USquare();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns a random float between 0 and 1 */
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Generate a random number between Min and Max */
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomFloatInRange : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomFloatInRange();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the value of PI */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetPI : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetPI();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the value of TAU (= 2 * PI) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetTAU : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetTAU();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns radians value based on the input degrees */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegreesToRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegreesToRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns degrees value based on the input radians */
UCLASS()
class RUNTIMEBLUEPRINTS_API URadiansToDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URadiansToDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the sin of A (expects Degrees)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegSin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegSin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse sin (arcsin) of A (result is in Degrees) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegAsin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegAsin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the cos of A (expects Degrees)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegCos : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegCos();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse cos (arccos) of A (result is in Degrees) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegAcos : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegAcos();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the tan of A (expects Degrees)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegTan : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegTan();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse tan (atan) (result is in Degrees)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegAtan : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegAtan();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the inverse tan (atan2) of A/B (result is in Degrees)*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDegAtan2 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDegAtan2();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Clamps an arbitrary angle to be between the given angles.  Will clamp to nearest boundary.
*
* @param MinAngleDegrees	"from" angle that defines the beginning of the range of valid angles (sweeping clockwise)
* @param MaxAngleDegrees	"to" angle that defines the end of the range of valid angles
* @return Returns clamped angle in the range -180..180.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UClampAngle : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UClampAngle();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the minimum value of A and B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFMin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFMin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the maximum value of A and B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFMax : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFMax();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Value clamped between A and B (inclusive) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFClamp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFClamp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns max of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMaxOfIntArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMaxOfIntArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns min of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMinOfIntArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMinOfIntArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns max of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMaxOfFloatArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMaxOfFloatArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns min of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMinOfFloatArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMinOfFloatArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns max of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMaxOfByteArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMaxOfByteArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns min of all array entries and the index at which it was found. Returns value of 0 and index of -1 if the supplied array is empty. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMinOfByteArray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMinOfByteArray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULerp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULerp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rounds A to the nearest integer */
UCLASS()
class RUNTIMEBLUEPRINTS_API URound : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URound();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rounds A to the largest previous integer */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFFloor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFFloor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rounds A to an integer with truncation towards zero.  (e.g. -1.7 truncated to -1, 2.8 truncated to 2) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFTrunc : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFTrunc();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rounds A to the smallest following integer */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFCeil : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFCeil();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the number of times Divisor will go into Dividend (i.e., Dividend divided by Divisor), as well as the remainder */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFMod : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFMod();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Sign (float, returns -1 if A < 0, 0 if A is zero, and +1 if A > 0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USignOfFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USignOfFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Value normalized to the given range.  (e.g. 20 normalized to the range 10->50 would result in 0.25) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNormalizeToRange : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNormalizeToRange();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Value mapped from one range into another.  (e.g. 20 normalized from the range 10->50 to 20->40 would result in 25) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMapRangeUnclamped : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMapRangeUnclamped();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Value mapped from one range into another where the Value is clamped to the Input Range.  (e.g. 0.5 normalized from the range 0->1 to 0->50 would result in 25) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMapRangeClamped : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMapRangeClamped();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Multiplies the input value by pi. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiplyByPi : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiplyByPi();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Interpolate between A and B, applying an ease in/out function.  Exp controls the degree of the curve. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFInterpEaseInOut : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFInterpEaseInOut();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Simple function to create a pulsating scalar value
*
* @param  InCurrentTime  Current absolute time
* @param  InPulsesPerSecond  How many full pulses per second?
* @param  InPhase  Optional phase amount, between 0.0 and 1.0 (to synchronize pulses)
*
* @return  Pulsating value (0.0-1.0)
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakePulsatingValue : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakePulsatingValue();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a new rotation component value
*
* @param InCurrent is the current rotation value
* @param InDesired is the desired rotation value
* @param  is the rotation amount to apply
*
* @return a new rotation component value clamped in the range (-360,360)
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFixedTurn : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFixedTurn();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 2D one vector constant (1,1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector2D_One : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector2D_One();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 2D unit vector constant along the 45 degree angle or symmetrical positive axes (sqrt(.5),sqrt(.5)) or (.707,.707). https:// En.wikipedia.org/wiki/Unit_vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector2D_Unit45Deg : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector2D_Unit45Deg();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 2D zero vector constant (0,0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector2D_Zero : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector2D_Zero();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Makes a 2d vector {X, Y} */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks a 2D vector apart into X, Y. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBreakVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBreakVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert a Vector2D to a Vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_Vector2DToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_Vector2DToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns addition of Vector A and Vector B (A + B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Vector A added by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_Vector2DFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_Vector2DFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns subtraction of Vector B from Vector A (A - B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Vector A subtracted by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_Vector2DFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_Vector2DFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise Vector multiplication (Result = {A.x*B.x, A.y*B.y}) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Vector A scaled by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_Vector2DFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_Vector2DFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise Vector divide (Result = {A.x/B.x, A.y/B.y}) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns Vector A divided by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_Vector2DFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_Vector2DFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is equal to vector B (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualExactly_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualExactly_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector2D A is equal to vector2D B (A == B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector2D A is not equal to vector2D B (A != B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqualExactly_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqualExactly_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector2D A is not equal to vector2D B (A != B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_Vector2DVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_Vector2DVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Gets a negated copy of the vector. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNegated2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNegated2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Creates a copy of this vector with both axes clamped to the given range.
* @return New vector with clamped axes.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UClampAxes2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UClampAxes2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the cross product of two 2d vectors - see  http:// Mathworld.wolfram.com/CrossProduct.html */
UCLASS()
class RUNTIMEBLUEPRINTS_API UCrossProduct2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCrossProduct2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Distance between two 2D points.
*
* @param V1 The first point.
* @param V2 The second point.
* @return The distance between two 2D points.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDistance2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDistance2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Squared distance between two 2D points.
*
* @param V1 The first point.
* @param V2 The second point.
* @return The squared distance between two 2D points.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UDistanceSquared2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDistanceSquared2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the dot product of two 2d vectors - see http:// Mathworld.wolfram.com/DotProduct.html */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDotProduct2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDotProduct2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get a copy of this vector with absolute value of each component.
*
* @return A copy of this vector with absolute value of each component.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetAbs2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetAbs2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get the maximum absolute value of the vector's components.
*
* @return The maximum absolute value of the vector's components.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetAbsMax2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetAbsMax2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get the maximum value of the vector's components.
*
* @return The maximum value of the vector's components.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetMax2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetMax2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get the minimum value of the vector's components.
*
* @return The minimum value of the vector's components.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetMin2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetMin2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Rotates around axis (0,0,1)
*
* @param AngleDeg Angle to rotate (in degrees)
* @return Rotated Vector
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetRotated2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetRotated2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks whether vector is near to zero within a specified tolerance.
*
* @param Tolerance Error tolerance.
* @return true if vector is in tolerance to zero, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsNearlyZero2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsNearlyZero2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks whether all components of the vector are exactly zero.
*
* @return true if vector is exactly zero, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsZero2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsZero2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target based on distance from Current position, giving a nice smooth feeling when tracking a position.
*
* @param		Current			Actual position
* @param		Target			Target position
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector2DInterpTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector2DInterpTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target at a constant rate.
*
* @param		Current			Actual position
* @param		Target			Target position
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector2DInterpTo_Constant : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector2DInterpTo_Constant();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets a normalized copy of the vector, checking it is safe to do so based on the length.
* Returns zero vector if vector length is too small to safely normalize.
*
* @param Tolerance Minimum squared length of vector for normalization.
* @return A normalized copy of the vector if safe, (0,0) otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNormalSafe2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNormalSafe2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns a unit normal version of the 2D vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNormal2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNormal2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts spherical coordinates on the unit sphere into a Cartesian unit length vector. */
UCLASS()
class RUNTIMEBLUEPRINTS_API USpherical2DToUnitCartesian : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USpherical2DToUnitCartesian();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Util to convert this vector into a unit direction vector and its original length.
*
* @param OutDir Reference passed in to store unit direction vector.
* @param OutLength Reference passed in to store length of the vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UToDirectionAndLength2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UToDirectionAndLength2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get this vector as a vector where each component has been rounded to the nearest int.
*
* @return New FVector2D from this vector that is rounded.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UToRounded2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UToRounded2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get a copy of the vector as sign only.
* Each component is set to +1 or -1, with the sign of zero treated as +1.
*
* @return A copy of the vector with each component set to +1 or -1
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UToSign2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UToSign2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the length of a 2D Vector. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVSize2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVSize2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the squared length of a 2D Vector. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVSize2DSquared : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVSize2DSquared();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector zero constant (0,0,0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Zero : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Zero();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector one constant (1,1,1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_One : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_One();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector Unreal forward direction constant (1,0,0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Forward : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Forward();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector Unreal backward direction constant (-1,0,0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Backward : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Backward();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector Unreal up direction constant (0,0,1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Up : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Up();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector Unreal down direction constant (0,0,-1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Down : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Down();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector Unreal right direction constant (0,1,0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Right : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Right();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 3D vector Unreal left direction constant (0,-1,0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Left : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Left();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Makes a vector {X, Y, Z} */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Creates a directional vector from rotation values {Pitch, Yaw} supplied in degrees with specified Length*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCreateVectorFromYawPitch : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCreateVectorFromYawPitch();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks a vector apart into X, Y, Z */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBreakVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBreakVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a vector to LinearColor */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_VectorToLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_VectorToLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert a vector to a transform. Uses vector as location */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_VectorToTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_VectorToTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert a Vector to a Vector2D */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_VectorToVector2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_VectorToVector2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Return the FRotator orientation corresponding to the direction in which the vector points.
* Sets Yaw and Pitch to the proper numbers, and sets Roll to zero because the roll can't be determined from a vector.
*
* @return FRotator from the Vector's direction, without any roll.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_VectorToRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_VectorToRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Create a rotation from an this axis and supplied angle (in degrees) */
UCLASS()
class RUNTIMEBLUEPRINTS_API URotatorFromAxisAndAngle : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URotatorFromAxisAndAngle();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Vector addition */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Adds a float to each component of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_VectorFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_VectorFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Adds an integer to each component of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_VectorInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_VectorInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Vector subtraction */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Subtracts a float from each component of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_VectorFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_VectorFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Subtracts an integer from each component of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_VectorInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_VectorInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise Vector multiplication (Result = {A.x*B.x, A.y*B.y, A.z*B.z}) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Scales Vector A by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_VectorFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_VectorFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Scales Vector A by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_VectorInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_VectorInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise Vector division (Result = {A.x/B.x, A.y/B.y, A.z/B.z}) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Vector divide by a float */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_VectorFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_VectorFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Vector divide by an integer */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_VectorInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_VectorInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Negate a vector. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNegateVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNegateVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is equal to vector B (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualExactly_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualExactly_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is equal to vector B (A == B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is not equal to vector B (A != B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqualExactly_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqualExactly_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is not equal to vector B (A != B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the dot product of two 3d vectors - see http:// Mathworld.wolfram.com/DotProduct.html */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDot_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDot_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the cross product of two 3d vectors - see http:// Mathworld.wolfram.com/CrossProduct.html */
UCLASS()
class RUNTIMEBLUEPRINTS_API UCross_VectorVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCross_VectorVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns result of vector A rotated by Rotator B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGreaterGreater_VectorRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGreaterGreater_VectorRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns result of vector A rotated by AngleDeg around Axis */
UCLASS()
class RUNTIMEBLUEPRINTS_API URotateAngleAxis : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URotateAngleAxis();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns result of vector A rotated by the inverse of Rotator B */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULessLess_VectorRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULessLess_VectorRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Create a copy of this vector, with its magnitude/size/length clamped between Min and Max. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UClampVectorSize : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UClampVectorSize();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Create a copy of this vector, with the 2D magnitude/size/length clamped between Min and Max. Z is unchanged. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ClampSize2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ClampSize2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Create a copy of this vector, with its maximum magnitude/size/length clamped to MaxSize. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ClampSizeMax : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ClampSizeMax();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Create a copy of this vector, with the maximum 2D magnitude/size/length clamped to MaxSize. Z is unchanged. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ClampSizeMax2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ClampSizeMax2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the minimum element (X, Y or Z) of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetMinElement : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetMinElement();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the maximum element (X, Y or Z) of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetMaxElement : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetMaxElement();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the maximum absolute element (abs(X), abs(Y) or abs(Z)) of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_GetAbsMax : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_GetAbsMax();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the minimum absolute element (abs(X), abs(Y) or abs(Z)) of a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_GetAbsMin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_GetAbsMin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get a copy of this vector with absolute value of each component.
*
* @return A copy of this vector with absolute value of each component.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_GetAbs : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_GetAbs();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the minimum elements (X, Y and Z) between the two vector's components */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ComponentMin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ComponentMin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the maximum elements (X, Y and Z) between the two vector's components */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ComponentMax : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ComponentMax();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get a copy of the vector as sign only.
* Each component is set to +1 or -1, with the sign of zero treated as +1.
*
* @param A copy of the vector with each component set to +1 or -1
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_GetSignVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_GetSignVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Projects 2D components of vector based on Z.
*
* @return Projected version of vector based on Z.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_GetProjection : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_GetProjection();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Convert a direction vector into a 'heading' angle.
*
* @return 'Heading' angle between +/-PI radians. 0 is pointing down +X.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_HeadingAngle : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_HeadingAngle();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the cosine of the angle between this vector and another projected onto the XY plane (no Z).
*
* @param B the other vector to find the 2D cosine of the angle with.
* @return The cosine.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_CosineAngle2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_CosineAngle2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a vector containing degree values to a vector containing radian values.
*
* @return Vector containing radian values
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ToRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ToRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a vector containing radian values to a vector containing degree values.
*
* @return Vector  containing degree values
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ToDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ToDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Converts a Cartesian unit vector into spherical coordinates on the unit sphere.
* @return Output Theta will be in the range [0, PI], and output Phi will be in the range [-PI, PI].
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_UnitCartesianToSpherical : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_UnitCartesianToSpherical();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the unit direction vector from one position to another or (0,0,0) if positions are the same. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetDirectionUnitVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetDirectionUnitVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks a vector apart into Yaw, Pitch rotation values given in degrees. (non-clamped) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetYawPitchFromVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetYawPitchFromVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};


UCLASS()
class RUNTIMEBLUEPRINTS_API UGetAzimuthAndElevation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetAzimuthAndElevation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find the average of an array of vectors */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetVectorArrayAverage : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetVectorArrayAverage();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rounds A to an integer with truncation towards zero for each element in a vector.  (e.g. -1.7 truncated to -1, 2.8 truncated to 2) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFTruncVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFTruncVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Distance between two points.
*
* @param V1 The first point.
* @param V2 The second point.
* @return The distance between two points.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Distance : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Distance();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Squared distance between two points.
*
* @param V1 The first point.
* @param V2 The second point.
* @return The squared distance between two points.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_DistanceSquared : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_DistanceSquared();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Euclidean distance between two points in the XY plane (ignoring Z).
*
* @param V1 The first point.
* @param V2 The second point.
* @return The distance between two points in the XY plane.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Distance2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Distance2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Squared euclidean distance between two points in the XY plane (ignoring Z).
*
* @param V1 The first point.
* @param V2 The second point.
* @return The distance between two points in the XY plane.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Distance2DSquared : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Distance2DSquared();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the length of the vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVSize : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVSize();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the squared length of the vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVSizeSquared : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVSizeSquared();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the length of the vector's XY components. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVSizeXY : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVSizeXY();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the squared length of the vector's XY components. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVSizeXYSquared : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVSizeXYSquared();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks whether vector is near to zero within a specified tolerance.
*
* @param Tolerance Error tolerance.
* @return true if vector is in tolerance to zero, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_IsNearlyZero : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_IsNearlyZero();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks whether all components of the vector are exactly zero.
*
* @return true if vector is exactly zero, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_IsZero : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_IsZero();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines if any component is not a number (NAN)
*
* @return true if one or more components is NAN, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_IsNAN : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_IsNAN();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks whether all components of this vector are the same, within a tolerance.
*
* @param Tolerance Error tolerance.
* @return true if the vectors are equal within tolerance limits, false otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_IsUniform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_IsUniform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines if vector is normalized / unit (length 1) within specified squared tolerance.
*
* @return true if unit, false otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_IsUnit : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_IsUnit();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines if vector is normalized / unit (length 1).
*
* @return true if normalized, false otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_IsNormal : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_IsNormal();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets a normalized unit copy of the vector, ensuring it is safe to do so based on the length.
* Returns zero vector if vector length is too small to safely normalize.
*
* @param Tolerance Minimum squared vector length.
* @return A normalized copy if safe, (0,0,0) otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNormal : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNormal();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets a normalized unit copy of the 2D components of the vector, ensuring it is safe to do so. Z is set to zero.
* Returns zero vector if vector length is too small to normalize.
*
* @param Tolerance Minimum squared vector length.
* @return Normalized copy if safe, (0,0,0) otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Normal2D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Normal2D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Calculates normalized unit version of vector without checking for zero length.
*
* @return Normalized version of vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_NormalUnsafe : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_NormalUnsafe();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVLerp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVLerp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target based on distance from Current position, giving a nice smooth feeling when tracking a position.
*
* @param		Current			Actual position
* @param		Target			Target position
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVInterpTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVInterpTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target at a constant rate.
*
* @param		Current			Actual position
* @param		Target			Target position
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVInterpTo_Constant : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVInterpTo_Constant();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets the reciprocal of this vector, avoiding division by zero.
* Zero components are set to BIG_NUMBER.
*
* @return Reciprocal of this vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_Reciprocal : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_Reciprocal();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Given a direction vector and a surface normal, returns the vector reflected across the surface normal.
* Produces a result like shining a laser at a mirror!
*
* @param Direction Direction vector the ray is coming from.
* @param SurfaceNormal A normal of the surface the ray should be reflected on.
*
* @returns Reflected vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetReflectionVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetReflectionVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Given a direction vector and a surface normal, returns the vector reflected across the surface normal.
* Produces a result like shining a laser at a mirror!
*
* @param InVect Direction vector the ray is coming from.
* @param InNormal A normal of the surface the ray should be reflected on.
*
* @returns Reflected vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMirrorVectorByNormal : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMirrorVectorByNormal();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets a copy of this vector snapped to a grid.
*
* @param InGridSize Grid dimension / step.
* @return A copy of this vector snapped to a grid.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_SnappedToGrid : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_SnappedToGrid();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Get a copy of this vector, clamped inside of an axis aligned cube centered at the origin.
*
* @param InRadius Half size of the cube (or radius of sphere circumscribed in the cube).
* @return A copy of this vector, bound by cube.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_BoundedToCube : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_BoundedToCube();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get a copy of this vector, clamped inside of the specified axis aligned cube. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_BoundedToBox : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_BoundedToBox();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets a copy of this vector projected onto the input vector, which is assumed to be unit length.
*
* @param  InNormal Vector to project onto (assumed to be unit length).
* @return Projected vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector_ProjectOnToNormal : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector_ProjectOnToNormal();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Projects one vector (V) onto another (Target) and returns the projected vector.
* If Target is nearly zero in length, returns the zero vector.
*
* @param  V Vector to project.
* @param  Target Vector on which we are projecting.
* @return V projected on to Target.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UProjectVectorOnToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UProjectVectorOnToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Projects/snaps a point onto a plane defined by a point on the plane and a plane normal.
*
* @param  Point Point to project onto the plane.
* @param  PlaneBase A point on the plane.
* @param  PlaneNormal Normal of the plane.
* @return Point projected onto the plane.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UProjectPointOnToPlane : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UProjectPointOnToPlane();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Projects a vector onto a plane defined by a normalized vector (PlaneNormal).
*
* @param  V Vector to project onto the plane.
* @param  PlaneNormal Normal of the plane.
* @return Vector projected onto the plane.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UProjectVectorOnToPlane : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UProjectVectorOnToPlane();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Find closest points between 2 segments.
*
* @param	Segment1Start	Start of the 1st segment.
* @param	Segment1End		End of the 1st segment.
* @param	Segment2Start	Start of the 2nd segment.
* @param	Segment2End		End of the 2nd segment.
* @param	Segment1Point	Closest point on segment 1 to segment 2.
* @param	Segment2Point	Closest point on segment 2 to segment 1.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFindNearestPointsOnLineSegments : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFindNearestPointsOnLineSegments();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Find the closest point on a segment to a given point.
*
* @param Point			Point for which we find the closest point on the segment.
* @param SegmentStart	Start of the segment.
* @param SegmentEnd	End of the segment.
* @return The closest point on the segment to the given point.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFindClosestPointOnSegment : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFindClosestPointOnSegment();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Find the closest point on an infinite line to a given point.
*
* @param Point			Point for which we find the closest point on the line.
* @param LineOrigin	Point of reference on the line.
* @param LineDirection Direction of the line. Not required to be normalized.
* @return The closest point on the line to the given point.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFindClosestPointOnLine : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFindClosestPointOnLine();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Find the distance from a point to the closest point on a segment.
*
* @param Point			Point for which we find the distance to the closest point on the segment.
* @param SegmentStart	Start of the segment.
* @param SegmentEnd		End of the segment.
* @return The distance from the given point to the closest point on the segment.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetPointDistanceToSegment : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetPointDistanceToSegment();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Find the distance from a point to the closest point on an infinite line.
*
* @param Point			Point for which we find the distance to the closest point on the line.
* @param LineOrigin		Point of reference on the line.
* @param LineDirection	Direction of the line. Not required to be normalized.
* @return The distance from the given point to the closest point on the line.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetPointDistanceToLine : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetPointDistanceToLine();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns a random vector with length of 1 */
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomUnitVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomUnitVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns a random point within the specified bounding box using the first vector as an origin and the second as the box extents. */
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomPointInBoundingBox : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomPointInBoundingBox();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a random vector with length of 1, within the specified cone, with uniform random distribution.
* @param ConeDir					The base "center" direction of the cone.
* @param ConeHalfAngleInRadians	The half-angle of the cone (from ConeDir to edge), in radians.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomUnitVectorInConeInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomUnitVectorInConeInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a random vector with length of 1, within the specified cone, with uniform random distribution.
* @param ConeDir					The base "center" direction of the cone.
* @param ConeHalfAngleInDegrees	The half-angle of the cone (from ConeDir to edge), in degrees.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomUnitVectorInConeInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomUnitVectorInConeInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a random vector with length of 1, within the specified cone, with uniform random distribution.
* The shape of the cone can be modified according to the yaw and pitch angles.
*
* @param MaxYawInRadians	The yaw angle of the cone (from ConeDir to horizontal edge), in radians.
* @param MaxPitchInRadians	The pitch angle of the cone (from ConeDir to vertical edge), in radians.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomUnitVectorInEllipticalConeInRadians : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomUnitVectorInEllipticalConeInRadians();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a random vector with length of 1, within the specified cone, with uniform random distribution.
* The shape of the cone can be modified according to the yaw and pitch angles.
*
* @param MaxYawInDegrees	The yaw angle of the cone (from ConeDir to horizontal edge), in degrees.
* @param MaxPitchInDegrees	The pitch angle of the cone (from ConeDir to vertical edge), in degrees.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomUnitVectorInEllipticalConeInDegrees : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomUnitVectorInEllipticalConeInDegrees();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** 4D vector zero constant (0,0,0) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_Zero : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_Zero();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Makes a 4D vector {X, Y, Z, W} */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeVector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeVector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks a 4D vector apart into X, Y, Z, W. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBreakVector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBreakVector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert a Vector4 to a Vector (dropping the W element) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_Vector4ToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_Vector4ToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Return the FRotator orientation corresponding to the direction in which the vector points.
* Sets Yaw and Pitch to the proper numbers, and sets Roll to zero because the roll can't be determined from a vector.
*
* @return FRotator from the Vector's direction, without any roll.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_Vector4ToRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_Vector4ToRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns addition of Vector A and Vector B (A + B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns subtraction of Vector B from Vector A (A - B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise Vector multiplication (Result = {A.x*B.x, A.y*B.y, A.z*B.z, A.w*B.w}) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise Vector divide (Result = {A.x/B.x, A.y/B.y, A.z/B.z, A.w/B.w}) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is equal to vector B (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualExactly_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualExactly_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is equal to vector B (A == B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is not equal to vector B (A != B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqualExactly_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqualExactly_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if vector A is not equal to vector B (A != B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_Vector4Vector4 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_Vector4Vector4();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Gets a negated copy of the vector. Equivalent to -Vector for scripts. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_Negated : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_Negated();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the cross product of two vectors - see  http:// Mathworld.wolfram.com/CrossProduct.html */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_CrossProduct3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_CrossProduct3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the dot product of two vectors - see http:// Mathworld.wolfram.com/DotProduct.html */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_DotProduct : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_DotProduct();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the dot product of two vectors - see http:// Mathworld.wolfram.com/DotProduct.html The W element is ignored.*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_DotProduct3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_DotProduct3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines if any component is not a number (NAN)
*
* @return true if one or more components is NAN, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_IsNAN : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_IsNAN();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks whether vector is near to zero within a specified tolerance. The W element is ignored.
*
* @param Tolerance Error tolerance.
* @return true if vector is in tolerance to zero, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_IsNearlyZero3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_IsNearlyZero3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Checks whether all components of the vector are exactly zero.
*
* @return true if vector is exactly zero, otherwise false.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_IsZero : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_IsZero();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the length of the vector. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_Size : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_Size();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the squared length of the vector. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_SizeSquared : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_SizeSquared();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the length of the vector. The W element is ignored. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_Size3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_Size3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the squared length of the vector. The W element is ignored. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_SizeSquared3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_SizeSquared3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines if vector is normalized / unit (length 1) within specified squared tolerance. The W element is ignored.
*
* @return true if unit, false otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_IsUnit3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_IsUnit3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines if vector is normalized / unit (length 1). The W element is ignored.
*
* @return true if normalized, false otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_IsNormal3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_IsNormal3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Gets a normalized unit copy of the vector, ensuring it is safe to do so based on the length. The W element is ignored and the returned vector has W=0.
* Returns zero vector if vector length is too small to safely normalize.
*
* @param Tolerance Minimum squared vector length.
* @return A normalized copy if safe, (0,0,0) otherwise.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_Normal3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_Normal3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Calculates normalized unit version of vector without checking for zero length. The W element is ignored and the returned vector has W=0.
*
* @return Normalized version of vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_NormalUnsafe3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_NormalUnsafe3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Given a direction vector and a surface normal, returns the vector reflected across the surface normal.
* Produces a result like shining a laser at a mirror!
* The W element is ignored.
*
* @param Direction Direction vector the ray is coming from.
* @param SurfaceNormal A normal of the surface the ray should be reflected on.
*
* @returns Reflected vector.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UVector4_MirrorByVector3 : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UVector4_MirrorByVector3();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a rotator given only a XAxis. Y and Z are unspecified but will be orthonormal. XAxis need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromX : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromX();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a rotation matrix given only a YAxis. X and Z are unspecified but will be orthonormal. YAxis need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromY : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromY();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a rotation matrix given only a ZAxis. X and Y are unspecified but will be orthonormal. ZAxis need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromZ : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromZ();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a matrix with given X and Y axes. X will remain fixed, Y may be changed minimally to enforce orthogonality. Z will be computed. Inputs need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromXY : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromXY();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a matrix with given X and Z axes. X will remain fixed, Z may be changed minimally to enforce orthogonality. Y will be computed. Inputs need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromXZ : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromXZ();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a matrix with given Y and X axes. Y will remain fixed, X may be changed minimally to enforce orthogonality. Z will be computed. Inputs need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromYX : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromYX();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a matrix with given Y and Z axes. Y will remain fixed, Z may be changed minimally to enforce orthogonality. X will be computed. Inputs need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromYZ : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromYZ();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a matrix with given Z and X axes. Z will remain fixed, X may be changed minimally to enforce orthogonality. Y will be computed. Inputs need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromZX : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromZX();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Builds a matrix with given Z and Y axes. Z will remain fixed, Y may be changed minimally to enforce orthogonality. X will be computed. Inputs need not be normalized. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotFromZY : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotFromZY();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

// Build a reference frame from three axes
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotationFromAxes : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotationFromAxes();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Find a rotation for an object at Start location to point at Target location. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UFindLookAtRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFindLookAtRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks apart a rotator into its component axes */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBreakRotIntoAxes : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBreakRotIntoAxes();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if rotator A is equal to rotator B (A == B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_RotatorRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_RotatorRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if rotator A is not equal to rotator B (A != B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_RotatorRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_RotatorRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns rotator representing rotator A scaled by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_RotatorFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_RotatorFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns rotator representing rotator A scaled by B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_RotatorInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_RotatorInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Combine 2 rotations to give you the resulting rotation of first applying A, then B. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UComposeRotators : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComposeRotators();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Negate a rotator*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNegateRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNegateRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rotate the world forward vector by the given rotation */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetForwardVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetForwardVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rotate the world right vector by the given rotation */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetRightVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetRightVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Rotate the world up vector by the given rotation */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetUpVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetUpVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the X direction vector after this rotation */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_RotatorToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_RotatorToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert Rotator to Transform */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_RotatorToTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_RotatorToTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Get the reference frame direction vectors (axes) described by this rotation */
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetAxes : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetAxes();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Generates a random rotation, with optional random roll. */
UCLASS()
class RUNTIMEBLUEPRINTS_API URandomRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URandomRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API URLerp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URLerp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Normalized A-B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNormalizedDeltaRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNormalizedDeltaRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Clamps an angle to the range of [0, 360].
*
* @param Angle The angle to clamp.
* @return The clamped angle.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UClampAxis : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UClampAxis();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Clamps an angle to the range of [-180, 180].
*
* @param Angle The Angle to clamp.
* @return The clamped angle.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNormalizeAxis : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNormalizeAxis();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** White linear color */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_White : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_White();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Grey linear color */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Gray : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Gray();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Black linear color */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Black : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Black();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Red linear color */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Red : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Red();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Green linear color */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Green : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Green();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Blue linear color */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Blue : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Blue();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Yellow linear color */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Yellow : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Yellow();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Transparent linear color - black with 0 opacity/alpha */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Transparent : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Transparent();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Make a color from individual color components (RGB space) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks apart a color into individual RGB components (as well as alpha) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBreakColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBreakColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert a float into a LinearColor, where each element is that float */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_FloatToLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_FloatToLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Make a color from individual color components (HSV space; Hue is [0..360) while Saturation and Value are 0..1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UHSVToRGB : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UHSVToRGB();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a HSV linear color (where H is in R (0..360), S is in G (0..1), and V is in B (0..1)) to RGB */
UCLASS()
class RUNTIMEBLUEPRINTS_API UHSVToRGB_Vector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UHSVToRGB_Vector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a HSV linear color (where H is in R, S is in G, and V is in B) to linear RGB */
UCLASS()
class RUNTIMEBLUEPRINTS_API UHSVToRGBLinear : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UHSVToRGBLinear();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks apart a color into individual HSV components (as well as alpha) (Hue is [0..360) while Saturation and Value are 0..1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API URGBToHSV : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URGBToHSV();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a RGB linear color to HSV (where H is in R (0..360), S is in G (0..1), and V is in B (0..1)) */
UCLASS()
class RUNTIMEBLUEPRINTS_API URGBToHSV_Vector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URGBToHSV_Vector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a RGB linear color to HSV (where H is in R, S is in G, and V is in B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API URGBLinearToHSV : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URGBLinearToHSV();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a LinearColor to a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_LinearColorToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_LinearColorToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns a desaturated color, with 0 meaning no desaturation and 1 == full desaturation
*
* @param	Desaturation	Desaturation factor in range [0..1]
* @return	Desaturated color
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Desaturated : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Desaturated();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Euclidean distance between two color points. */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_Distance : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_Distance();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns a copy of this color using the specified opacity/alpha.	 */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_ToNewOpacity : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_ToNewOpacity();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**	Returns the perceived brightness of a color on a display taking into account the impact on the human eye per color channel: green > red > blue. */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_GetLuminance : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_GetLuminance();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the maximum color channel value in this color structure
*
* @return The maximum color channel value
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_GetMax : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_GetMax();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the minimum color channel value in this color structure
*
* @return The minimum color channel value
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_GetMin : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_GetMin();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Interpolate Linear Color from Current to Target. Scaled by distance to Target, so it has a strong start speed and ease out.
*
* @param		Current			Current Color
* @param		Target			Target Color
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated Color
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UCInterpTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UCInterpTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Linearly interpolates between A and B based on Alpha (100% of A when Alpha=0 and 100% of B when Alpha=1) */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColorLerp : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColorLerp();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Linearly interpolates between two colors by the specified Alpha amount (100% of A when Alpha=0 and 100% of B when Alpha=1).  The interpolation is performed in HSV color space taking the shortest path to the new color's hue.  This can give better results than a normal lerp, but is much more expensive.  The incoming colors are in RGB space, and the output color will be RGB.  The alpha value will also be interpolated.
*
* @param	A		The color and alpha to interpolate from as linear RGBA
* @param	B		The color and alpha to interpolate to as linear RGBA
* @param	Alpha	Scalar interpolation amount (usually between 0.0 and 1.0 inclusive)
*
* @return	The interpolated color in linear RGB space along with the interpolated alpha value
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColorLerpUsingHSV : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColorLerpUsingHSV();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if linear color A is equal to linear color B (A == B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinearColor_IsNearEqual : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinearColor_IsNearEqual();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if linear color A is equal to linear color B (A == B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_LinearColorLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_LinearColorLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if linear color A is not equal to linear color B (A != B) within a specified error tolerance */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_LinearColorLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_LinearColorLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise addition of two linear colors (R+R, G+G, B+B, A+A) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UAdd_LinearColorLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UAdd_LinearColorLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise subtraction of two linear colors (R-R, G-G, B-B, A-A) */
UCLASS()
class RUNTIMEBLUEPRINTS_API USubtract_LinearColorLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USubtract_LinearColorLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise multiplication of two linear colors (R*R, G*G, B*B, A*A) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_LinearColorLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_LinearColorLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise multiplication of a linear color by a float (F*R, F*G, F*B, F*A) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMultiply_LinearColorFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMultiply_LinearColorFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Element-wise multiplication of two linear colors (R/R, G/G, B/B, A/A) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDivide_LinearColorLinearColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDivide_LinearColorLinearColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the number of days in the given year and month */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDaysInMonth : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDaysInMonth();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns the number of days in the given year */
UCLASS()
class RUNTIMEBLUEPRINTS_API UDaysInYear : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UDaysInYear();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns whether given year is a leap year */
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsLeapYear : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsLeapYear();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a byte to a float */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_ByteToFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_ByteToFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts an integer to a float */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_IntToFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_IntToFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts an integer to a byte (if the integer is too large, returns the low 8 bits) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_IntToByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_IntToByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts an integer to an IntVector*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_IntToIntVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_IntToIntVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a int to a bool*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_IntToBool : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_IntToBool();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a bool to an int */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_BoolToInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_BoolToInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a bool to a float (0.0f or 1.0f) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_BoolToFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_BoolToFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a bool to a byte */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_BoolToByte : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_BoolToByte();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Converts a byte to an integer */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_ByteToInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_ByteToInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert an IntVector to a vector */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_IntVectorToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_IntVectorToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Convert a float into a vector, where each element is that float */
UCLASS()
class RUNTIMEBLUEPRINTS_API UConv_FloatToVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UConv_FloatToVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectString : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectString();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectInt : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectInt();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectFloat : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectFloat();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectVector : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectVector();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectColor : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectColor();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectObject : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectObject();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** If bPickA is true, A is returned, otherwise B is */
UCLASS()
class RUNTIMEBLUEPRINTS_API USelectClass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	USelectClass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A and B are equal (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_ObjectObject : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_ObjectObject();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A and B are not equal (A != B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_ObjectObject : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_ObjectObject();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A and B are equal (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_ClassClass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_ClassClass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A and B are not equal (A != B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_ClassClass : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_ClassClass();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A and B are equal (A == B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_NameName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_NameName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if A and B are not equal (A != B) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UNotEqual_NameName : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNotEqual_NameName();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Make a transform from location, rotation and scale */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks apart a transform into location, rotation and scale */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBreakTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBreakTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Returns true if transform A is equal to transform B */
UCLASS()
class RUNTIMEBLUEPRINTS_API UEqualEqual_TransformTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UEqualEqual_TransformTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Returns true if transform A is nearly equal to B
*	@param LocationTolerance	How close position of transforms need to be to be considered equal
*	@param RotationTolerance	How close rotations of transforms need to be to be considered equal
*	@param Scale3DTolerance		How close scale of transforms need to be to be considered equal
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UNearlyEqual_TransformTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UNearlyEqual_TransformTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Compose two transforms in order: A * B.
*
* Order matters when composing transforms:
* A * B will yield a transform that logically first applies A then B to any subsequent transformation.
*
* Example: LocalToWorld = ComposeTransforms(DeltaRotation, LocalToWorld) will change rotation in local space by DeltaRotation.
* Example: LocalToWorld = ComposeTransforms(LocalToWorld, DeltaRotation) will change rotation in world space by DeltaRotation.
*
* @return New transform: A * B
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UComposeTransforms : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UComposeTransforms();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Transform a position by the supplied transform.
*	For example, if T was an object's transform, this would transform a position from local space to world space.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UTransformLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTransformLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Transform a direction vector by the supplied transform - will not change its length.
*	For example, if T was an object's transform, this would transform a direction from local space to world space.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UTransformDirection : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTransformDirection();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Transform a rotator by the supplied transform.
*	For example, if T was an object's transform, this would transform a rotation from local space to world space.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UTransformRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTransformRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Transform a position by the inverse of the supplied transform.
*	For example, if T was an object's transform, this would transform a position from world space to local space.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UInverseTransformLocation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UInverseTransformLocation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Transform a direction vector by the inverse of the supplied transform - will not change its length.
*	For example, if T was an object's transform, this would transform a direction from world space to local space.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UInverseTransformDirection : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UInverseTransformDirection();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
*	Transform a rotator by the inverse of the supplied transform.
*	For example, if T was an object's transform, this would transform a rotation from world space to local space.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UInverseTransformRotation : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UInverseTransformRotation();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Computes a relative transform of one transform compared to another.
*
* Example: ChildOffset = MakeRelativeTransform(Child.GetActorTransform(), Parent.GetActorTransform())
* This computes the relative transform of the Child from the Parent.
*
* @param		A				The object's transform
* @param		RelativeTo		The transform the result is relative to (in the same space as A)
* @return		The new relative transform
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRelativeTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRelativeTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns the inverse of the given transform T.
*
* Example: Given a LocalToWorld transform, WorldToLocal will be returned.
*
* @param	T	The transform you wish to invert
* @return	The inverse of T.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UInvertTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UInvertTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Tries to reach a target transform. */
UCLASS()
class RUNTIMEBLUEPRINTS_API UTInterpTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTInterpTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Calculates the determinant of the transform (converts to FMatrix internally) */
UCLASS()
class RUNTIMEBLUEPRINTS_API UTransform_Determinant : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UTransform_Determinant();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target based on distance from Current position, giving a nice smooth feeling when tracking a position.
*
* @param		Current			Actual position
* @param		Target			Target position
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFInterpTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFInterpTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target at a constant rate.
*
* @param		Current			Actual position
* @param		Target			Target position
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UFInterpTo_Constant : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UFInterpTo_Constant();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target rotation based on Current rotation, giving a nice smooth feeling when rotating to Target rotation.
*
* @param		Current			Actual rotation
* @param		Target			Target rotation
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URInterpTo : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URInterpTo();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Tries to reach Target rotation at a constant rate.
*
* @param		Current			Actual rotation
* @param		Target			Target rotation
* @param		DeltaTime		Time since last tick
* @param		InterpSpeed		Interpolation speed
* @return		New interpolated position
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API URInterpTo_Constant : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	URInterpTo_Constant();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Generates a 1D Perlin noise from the given value.  Returns a continuous random value between -1.0 and 1.0.
*
* @param	Value	The input value that Perlin noise will be generated from.  This is usually a steadily incrementing time value.
*
* @return	Perlin noise in the range of -1.0 to 1.0
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UPerlinNoise1D : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPerlinNoise1D();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Finds the minimum area rectangle that encloses all of the points in InVerts
* Uses algorithm found in http:// Www.geometrictools.com/Documentation/MinimumAreaRectangle.pdf
*
* @param		InVerts	- Points to enclose in the rectangle
* @outparam	OutRectCenter - Center of the enclosing rectangle
* @outparam	OutRectSideA - Vector oriented and sized to represent one edge of the enclosing rectangle, orthogonal to OutRectSideB
* @outparam	OutRectSideB - Vector oriented and sized to represent one edge of the enclosing rectangle, orthogonal to OutRectSideA
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UMinimumAreaRectangle : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMinimumAreaRectangle();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines whether a given set of points are coplanar, with a tolerance. Any three points or less are always coplanar.
*
* @param Points - The set of points to determine coplanarity for.
* @param Tolerance - Larger numbers means more variance is allowed.
*
* @return Whether the points are relatively coplanar, based on the tolerance
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UPointsAreCoplanar : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UPointsAreCoplanar();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines whether the given point is in a box. Includes points on the box.
*
* @param Point			Point to test
* @param BoxOrigin		Origin of the box
* @param BoxExtent		Extents of the box (distance in each axis from origin)
* @return Whether the point is in the box.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsPointInBox : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsPointInBox();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Determines whether a given point is in a box with a given transform. Includes points on the box.
*
* @param Point				Point to test
* @param BoxWorldTransform	Component-to-World transform of the box.
* @param BoxExtent			Extents of the box (distance in each axis from origin), in component space.
* @return Whether the point is in the box.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UIsPointInBoxWithTransform : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UIsPointInBoxWithTransform();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Returns Slope Pitch and Roll angles in degrees based on the following information:
*
* @param	MyRightYAxis				Right (Y) direction unit vector of Actor standing on Slope.
* @param	FloorNormal					Floor Normal (unit) vector.
* @param	UpVector					UpVector of reference frame.
* @outparam OutSlopePitchDegreeAngle	Slope Pitch angle (degrees)
* @outparam OutSlopeRollDegreeAngle		Slope Roll angle (degrees)
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API UGetSlopeDegreeAngles : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UGetSlopeDegreeAngles();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/**
* Computes the intersection point between a line and a plane.
* @param		T - The t of the intersection between the line and the plane
* @param		Intersection - The point of intersection between the line and the plane
* @return		True if the intersection test was successful.
*/
UCLASS()
class RUNTIMEBLUEPRINTS_API ULinePlaneIntersection_OriginNormal : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	ULinePlaneIntersection_OriginNormal();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Breaks a rotator apart into Roll, Pitch, Yaw */
UCLASS()
class RUNTIMEBLUEPRINTS_API UBreakRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UBreakRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};

/** Makes a rotator {Roll, Pitch, Yaw} */
UCLASS()
class RUNTIMEBLUEPRINTS_API UMakeRotator : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	UMakeRotator();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};