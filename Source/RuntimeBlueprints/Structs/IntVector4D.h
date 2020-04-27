// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreTypes.h"
#include "Misc/Crc.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/UnrealString.h"
#include "Serialization/StructuredArchive.h"
#include "IntVector4D.generated.h"

/**
 * Structure for integer vectors in 4-d space.
 */
USTRUCT(BlueprintType)
struct FIntVector4D
{
	GENERATED_BODY()

	/**  Holds the vectors's x-component. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	/**  Holds the vectors's y-component. */
	int Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	/**  Holds the vectors's z-component. */
	int Z;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	/**  Holds the vectors's w-component. */
	int W;

public:

	/**
	 * Default constructor (no initialization).
	 */
	FIntVector4D();

	/**
	 * Creates and initializes a new instance with the specified coordinates.
	 *
	 * @param InX The x-component.
	 * @param InY The y-component.
	 * @param InZ The z-component.
	 * @param InW The w-component.
	 */
	FIntVector4D(int32 InX, int32 InY, int32 InZ, int32 InW);

	/**
	 * Constructor
	 *
	 * @param InValue replicated to all components
	 */
	explicit FIntVector4D(int32 InValue);

	/**
	 * Constructor
	 *
	 * @param InVector4 float vector converted to int
	 */
	explicit FIntVector4D(FVector4 InVector);

	/**
	 * Constructor
	 *
	 * @param EForceInit Force init enum
	 */
	explicit FORCEINLINE FIntVector4D(EForceInit);

public:

	/**
	 * Gets specific component of a point.
	 *
	 * @param ComponentIndex Index of point component.
	 * @return const reference to component.
	 */
	const int32& operator()(int32 ComponentIndex) const;

	/**
	 * Gets specific component of a point.
	 *
	 * @param ComponentIndex Index of point component.
	 * @return reference to component.
	 */
	int32& operator()(int32 ComponentIndex);

	/**
	 * Gets specific component of a point.
	 *
	 * @param ComponentIndex Index of point component.
	 * @return const reference to component.
	 */
	const int32& operator[](int32 ComponentIndex) const;

	/**
	 * Gets specific component of a point.
	 *
	 * @param ComponentIndex Index of point component.
	 * @return reference to component.
	 */
	int32& operator[](int32 ComponentIndex);

	/**
	 * Compares points for equality.
	 *
	 * @param Other The other int point being compared.
	 * @return true if the points are equal, false otherwise..
	 */
	bool operator==(const FIntVector4D& Other) const;

	/**
	 * Compares points for inequality.
	 *
	 * @param Other The other int point being compared.
	 * @return true if the points are not equal, false otherwise..
	 */
	bool operator!=(const FIntVector4D& Other) const;

	/**
	 * Scales this point.
	 *
	 * @param Scale What to multiply the point by.
	 * @return Reference to this point after multiplication.
	 */
	FIntVector4D& operator*=(int32 Scale);

	/**
	 * Divides this point.
	 *
	 * @param Divisor What to divide the point by.
	 * @return Reference to this point after division.
	 */
	FIntVector4D& operator/=(int32 Divisor);

	/**
	 * Adds to this point.
	 *
	 * @param Other The point to add to this point.
	 * @return Reference to this point after addition.
	 */
	FIntVector4D& operator+=(const FIntVector4D& Other);

	/**
	 * Subtracts from this point.
	 *
	 * @param Other The point to subtract from this point.
	 * @return Reference to this point after subtraction.
	 */
	FIntVector4D& operator-=(const FIntVector4D& Other);

	/**
	 * Assigns another point to this one.
	 *
	 * @param Other The point to assign this point from.
	 * @return Reference to this point after assignment.
	 */
	FIntVector4D& operator=(const FIntVector4D& Other);

	/**
	 * Gets the result of scaling on this point.
	 *
	 * @param Scale What to multiply the point by.
	 * @return A new scaled int point.
	 */
	FIntVector4D operator*(int32 Scale) const;

	/**
	 * Gets the result of division on this point.
	 *
	 * @param Divisor What to divide the point by.
	 * @return A new divided int point.
	 */
	FIntVector4D operator/(int32 Divisor) const;

	/**
	 * Gets the result of addition on this point.
	 *
	 * @param Other The other point to add to this.
	 * @return A new combined int point.
	 */
	FIntVector4D operator+(const FIntVector4D& Other) const;

	/**
	 * Gets the result of subtraction from this point.
	 *
	 * @param Other The other point to subtract from this.
	 * @return A new subtracted int point.
	 */
	FIntVector4D operator-(const FIntVector4D& Other) const;

public:

	/**
	 * Gets the maximum value in the point.
	 *
	 * @return The maximum value in the point.
	 */
	float GetMax() const;

	/**
	 * Gets the minimum value in the point.
	 *
	 * @return The minimum value in the point.
	 */
	float GetMin() const;

	/**
	 * Gets the distance of this point from (0,0,0,0).
	 *
	 * @return The distance of this point from (0,0,0,0).
	 */
	int32 Size() const;

	/**
	 * Get a textual representation of this vector.
	 *
	 * @return A string describing the vector.
	 */
	FString ToString() const;

public:

	/**
	 * Divide an int point and round up the result.
	 *
	 * @param lhs The int point being divided.
	 * @param Divisor What to divide the int point by.
	 * @return A new divided int point.
	 */
	static FIntVector4D DivideAndRoundUp(FIntVector4D lhs, int32 Divisor);

	/**
	 * Gets the number of components a point has.
	 *
	 * @return Number of components point has.
	 */
	static int32 Num();

public:

	/**
	 * Serializes the Rectangle.
	 *
	 * @param Ar The archive to serialize into.
	 * @param Vector The vector to serialize.
	 * @return Reference to the Archive after serialization.
	 */
	friend FArchive& operator<<(FArchive& Ar, FIntVector4D& Vector)
	{
		return Ar << Vector.X << Vector.Y << Vector.Z << Vector.W;
	}

	friend void operator<<(FStructuredArchive::FSlot Slot, FIntVector4D& Vector)
	{
		FStructuredArchive::FRecord Record = Slot.EnterRecord();
		Record << NAMED_ITEM("X", Vector.X);
		Record << NAMED_ITEM("Y", Vector.Y);
		Record << NAMED_ITEM("Z", Vector.Z);
		Record << NAMED_ITEM("W", Vector.W);
	}

	bool Serialize(FArchive& Ar)
	{
		Ar << *this;
		return true;
	}
};

/* FIntVector4D inline functions
 *****************************************************************************/

FORCEINLINE FIntVector4D::FIntVector4D()
{ }


FORCEINLINE FIntVector4D::FIntVector4D(int32 InX, int32 InY, int32 InZ, int32 InW)
	: X(InX)
	, Y(InY)
	, Z(InZ)
	, W(InW)
{ }


FORCEINLINE FIntVector4D::FIntVector4D(int32 InValue)
	: X(InValue)
	, Y(InValue)
	, Z(InValue)
	, W(InValue)
{ }


FORCEINLINE FIntVector4D::FIntVector4D(EForceInit)
	: X(0)
	, Y(0)
	, Z(0)
	, W(0)
{ }


FORCEINLINE const int32& FIntVector4D::operator()(int32 ComponentIndex) const
{
	return (&X)[ComponentIndex];
}


FORCEINLINE int32& FIntVector4D::operator()(int32 ComponentIndex)
{
	return (&X)[ComponentIndex];
}


FORCEINLINE const int32& FIntVector4D::operator[](int32 ComponentIndex) const
{
	return (&X)[ComponentIndex];
}


FORCEINLINE int32& FIntVector4D::operator[](int32 ComponentIndex)
{
	return (&X)[ComponentIndex];
}

FORCEINLINE bool FIntVector4D::operator==(const FIntVector4D& Other) const
{
	return X == Other.X && Y == Other.Y && Z == Other.Z && W == Other.W;
}


FORCEINLINE bool FIntVector4D::operator!=(const FIntVector4D& Other) const
{
	return X != Other.X || Y != Other.Y || Z != Other.Z || W != Other.W;
}


FORCEINLINE FIntVector4D& FIntVector4D::operator*=(int32 Scale)
{
	X *= Scale;
	Y *= Scale;
	Z *= Scale;
	W *= Scale;

	return *this;
}


FORCEINLINE FIntVector4D& FIntVector4D::operator/=(int32 Divisor)
{
	X /= Divisor;
	Y /= Divisor;
	Z /= Divisor;
	W /= Divisor;

	return *this;
}


FORCEINLINE FIntVector4D& FIntVector4D::operator+=(const FIntVector4D& Other)
{
	X += Other.X;
	Y += Other.Y;
	Z += Other.Z;
	W += Other.W;

	return *this;
}


FORCEINLINE FIntVector4D& FIntVector4D::operator-=(const FIntVector4D& Other)
{
	X -= Other.X;
	Y -= Other.Y;
	Z -= Other.Z;
	W -= Other.W;

	return *this;
}


FORCEINLINE FIntVector4D& FIntVector4D::operator=(const FIntVector4D& Other)
{
	X = Other.X;
	Y = Other.Y;
	Z = Other.Z;
	W = Other.W;

	return *this;
}


FORCEINLINE FIntVector4D FIntVector4D::operator*(int32 Scale) const
{
	return FIntVector4D(*this) *= Scale;
}


FORCEINLINE FIntVector4D FIntVector4D::operator/(int32 Divisor) const
{
	return FIntVector4D(*this) /= Divisor;
}


FORCEINLINE FIntVector4D FIntVector4D::operator+(const FIntVector4D& Other) const
{
	return FIntVector4D(*this) += Other;
}

FORCEINLINE FIntVector4D FIntVector4D::operator-(const FIntVector4D& Other) const
{
	return FIntVector4D(*this) -= Other;
}


FORCEINLINE FIntVector4D FIntVector4D::DivideAndRoundUp(FIntVector4D lhs, int32 Divisor)
{
	return FIntVector4D(FMath::DivideAndRoundUp(lhs.X, Divisor), FMath::DivideAndRoundUp(lhs.Y, Divisor), FMath::DivideAndRoundUp(lhs.Z, Divisor), FMath::DivideAndRoundUp(lhs.W, Divisor));
}


FORCEINLINE float FIntVector4D::GetMax() const
{
	return FMath::Max(FMath::Max(X, Y), FMath::Max(Z, W));
}


FORCEINLINE float FIntVector4D::GetMin() const
{
	return FMath::Min(FMath::Min(X, Y), FMath::Min(Z, W));
}


FORCEINLINE int32 FIntVector4D::Num()
{
	return 4;
}


FORCEINLINE int32 FIntVector4D::Size() const
{
	int64 X64 = (int64)X;
	int64 Y64 = (int64)Y;
	int64 Z64 = (int64)Z;
	int64 W64 = (int64)W;
	return int32(FMath::Sqrt(float(X64 * X64 + Y64 * Y64 + Z64 * Z64 + W64 * W64)));
}

FORCEINLINE FString FIntVector4D::ToString() const
{
	return FString::Printf(TEXT("X=%d Y=%d Z=%d W=%d"), X, Y, Z, W);
}

FORCEINLINE uint32 GetTypeHash(const FIntVector4D& Vector)
{
	return FCrc::MemCrc_DEPRECATED(&Vector, sizeof(FIntVector4D));
}