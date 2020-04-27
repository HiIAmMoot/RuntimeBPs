// Copyright notice here..

#include "RandomBPLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "RuntimeBlueprints.h"


//Based on a Fibonacci Sphere as shown here https:// Stackoverflow.com/questions/9600801/evenly-distributing-n-points-on-a-sphere
TArray<FVector> URandomBPLibrary::DistributePointsAroundSphere(float SphereRadius, FVector SphereCenterLocation, int AmountOfPoints = 16, bool Randomize = false)
{
	int RandomInt = 1;
	if (Randomize)
	{
		RandomInt = FMath::RandHelper(AmountOfPoints);
	}

	TArray<FVector> Points;
	Points.Reserve(AmountOfPoints);
	
	float Offset = 2.f / AmountOfPoints;
	float Increment = PI * (3.f - FMath::Sqrt(5.f));

	for (int i = 0; i < AmountOfPoints; i++)
	{
		float Y = ((i * Offset) - 1.f) + (Offset * 0.5);
		float R = FMath::Sqrt(1.f - FMath::Pow(Y, 2));

		float Phi = ((i + RandomInt) % AmountOfPoints) * Increment;

		float X = FMath::Cos(Phi) * R;
		float Z = FMath::Sin(Phi) * R;

		Points.Add(FVector(X * SphereRadius, Y * SphereRadius, Z * SphereRadius) + SphereCenterLocation);
	}

	return Points;
}