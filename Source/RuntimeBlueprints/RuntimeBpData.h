// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectConverter.h"
#include "LongUnion.h"
#include "Structs/IntVector4D.h"
#include "RuntimeBpMacros.h"
#include "UObject/ConstructorHelpers.h"

#include "GameFramework/Character.h"
#include "Components/LightComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "RuntimeBpExample/RuntimeBpGrenade.h"

#include "RuntimeBpData.generated.h"

// Runtime BP log
RUNTIMEBLUEPRINTS_API DECLARE_LOG_CATEGORY_EXTERN(LogRuntimeBps, Log, All);

class URuntimeBpObject;

// The ways a pin can connect
UENUM(BlueprintType)
enum class ENodeType : uint8
{
	Node 					UMETA(DisplayName = "Node"),
	VariableGetter 			UMETA(DisplayName = "VariableGetter"),
	VariableSetter 			UMETA(DisplayName = "VariableSetter"),
	LocalVariableGetter 	UMETA(DisplayName = "LocalVariableGetter"),
	LocalVariableSetter 	UMETA(DisplayName = "LocalVariableSetter"),
	CustomFunction 			UMETA(DisplayName = "CustomFunction"),
	ExternalFunction 		UMETA(DisplayName = "ExternalFunction"),
	FunctionStart			UMETA(DisplayName = "FunctionStart"),
	FunctionEnd				UMETA(DisplayName = "FunctionEnd"),
	Graph					UMETA(DisplayName = "Graph")
};

// The kind of variables a pin can be
UENUM(BlueprintType)
enum class EVariableTypes : uint8
{
	// Variables
	Bool 					UMETA(DisplayName = "Bool"),
	Byte 					UMETA(DisplayName = "Byte"),
	Int						UMETA(DisplayName = "Integer"),
	Float 					UMETA(DisplayName = "Float"),
	Name 					UMETA(DisplayName = "Name"),
	String	 				UMETA(DisplayName = "String"),
	Text 					UMETA(DisplayName = "Text"),
	Vector	 				UMETA(DisplayName = "Vector"),
	Rotator 				UMETA(DisplayName = "Rotator"),
	Transform 				UMETA(DisplayName = "Transform"),
	Vector2D 				UMETA(DisplayName = "Vector2D"),
	Vector4					UMETA(DisplayName = "Vector4"),
	LinearColor 			UMETA(DisplayName = "LinearColor"),
	IntVector 				UMETA(DisplayName = "IntVector"),
	IntVector4				UMETA(DisplayName = "IntVector4"),
	HitResult				UMETA(DisplayName = "HitResult"),
	// Objects
	Object					UMETA(DisplayName = "Object"),
	Actor	 				UMETA(DisplayName = "Actor"),
	PlayerController		UMETA(DisplayName = "PlayerController"),
	Pawn					UMETA(DisplayName = "Pawn"),
	Character 				UMETA(DisplayName = "Character"),
	SceneComponent			UMETA(DisplayName = "SceneComponent"),
	PrimitiveComponent		UMETA(DisplayName = "PrimitiveComponent"),
	StaticMeshComponent		UMETA(DisplayName = "StaticMeshComponent"),
	LightComponent			UMETA(DisplayName = "LightComponent"),
	ParticleSystemComponent	UMETA(DisplayName = "ParticleSystemComponent"),
	DamageType				UMETA(DisplayName = "DamageType"),
	// Assets
	Class 					UMETA(DisplayName = "Class"),
	StaticMesh				UMETA(DisplayName = "StaticMesh"),
	MaterialInterface		UMETA(DisplayName = "MaterialInterface"),
	ParticleSystem			UMETA(DisplayName = "ParticleSystem"),
	// Custom classes
	Grenade 				UMETA(DisplayName = "Grenade"),
	// Misc
	Exec 					UMETA(DisplayName = "Exec"),
	WildCard 				UMETA(DisplayName = "WildCard")
};

// This stuct is used to have a dynamic variable depending on the Enum above this
USTRUCT(BlueprintType)
struct FNodeVarArgs
{
	GENERATED_BODY()

	NODE_VAR_ARG_UNION VariableData;
	
	// Strings are messed up with TUnions so this variable is here to store string data, this also allows to use this string as a meta for other values
	FString StringData = "";

	int GetSubtypeIndex() const
	{
		return VariableData.CurrentSubtypeIndex;
	}

	void Reset()
	{
		VariableData.Reset();
		StringData = "";
	}

	FNodeVarArgs()
	{}


	// Constructor with a variable type as input
	FNodeVarArgs(EVariableTypes VariableType)
	{
		switch (VariableType)
		{
			case EVariableTypes::Bool: SetBoolArg(); break;
			case EVariableTypes::Byte: SetByteArg(); break;
			case EVariableTypes::Int: SetIntArg(); break;
			case EVariableTypes::Float: SetFloatArg(); break;
			case EVariableTypes::Name: SetNameArg(); break;
			case EVariableTypes::String: SetStringArg(); break;
			case EVariableTypes::Text: SetTextArg(); break;
			case EVariableTypes::Vector: SetVectorArg(); break;
			case EVariableTypes::Rotator: SetRotatorArg(); break;
			case EVariableTypes::Transform: SetTransformArg(); break;
			case EVariableTypes::Vector2D: SetVector2DArg(); break;
			case EVariableTypes::Vector4: SetVector4Arg(); break;
			case EVariableTypes::LinearColor: SetLinearColorArg(); break;
			case EVariableTypes::IntVector: SetIntVectorArg(); break;
			case EVariableTypes::IntVector4: SetIntVector4Arg(); break;
			case EVariableTypes::Object: SetObjectArg(); break;
			case EVariableTypes::Actor: SetActorArg(); break;
			case EVariableTypes::PlayerController: SetPlayerControllerArg(); break;
			case EVariableTypes::Pawn: SetPawnArg(); break;
			case EVariableTypes::Character: SetCharacterArg(); break;
			case EVariableTypes::SceneComponent: SetSceneComponentArg(); break;
			case EVariableTypes::PrimitiveComponent: SetPrimitiveComponentArg(); break;
			case EVariableTypes::StaticMeshComponent: SetStaticMeshComponentArg(); break;
			case EVariableTypes::LightComponent: SetLightComponentArg(); break;
			case EVariableTypes::ParticleSystemComponent: SetParticleSystemComponentArg(); break;
			case EVariableTypes::DamageType: SetDamageTypeArg(); break;
			case EVariableTypes::Class: SetClassArg(); break;
			case EVariableTypes::StaticMesh: SetStaticMeshArg(); break;
			case EVariableTypes::MaterialInterface: SetMaterialInterfaceArg(); break;
			case EVariableTypes::ParticleSystem: SetParticleSystemArg(); break;
			case EVariableTypes::Grenade: SetGrenadeArg(); break;
			case EVariableTypes::HitResult: SetHitResultArg(); break;
			default: break;
		}
	}

	NODE_VAR_ARG_FUNCTIONS(bool, Bool, false) // 0
	NODE_VAR_ARG_FUNCTIONS(uint8, Byte, 0) // 1
	NODE_VAR_ARG_FUNCTIONS(int, Int, 0) // 2
	NODE_VAR_ARG_FUNCTIONS(float, Float, 0.f) // 3
	NODE_VAR_ARG_FUNCTIONS(FVector, Vector, FVector::ZeroVector) // 4
	NODE_VAR_ARG_FUNCTIONS(FRotator, Rotator, FRotator::ZeroRotator) // 5
	NODE_VAR_ARG_FUNCTIONS(FTransform, Transform, FTransform()) // 6
	NODE_VAR_ARG_FUNCTIONS(FVector2D, Vector2D, FVector2D::ZeroVector) // 7
	NODE_VAR_ARG_FUNCTIONS(FVector4, Vector4, FVector4()) // 8
	NODE_VAR_ARG_FUNCTIONS(FLinearColor, LinearColor, FLinearColor(0.f, 0.f, 0.f, 1.f)) // 9
	NODE_VAR_ARG_FUNCTIONS(FIntVector, IntVector, FIntVector::ZeroValue) // 10
	NODE_VAR_ARG_FUNCTIONS(FIntVector4D, IntVector4, FIntVector4D(0, 0, 0, 1)) // 11

	NODE_VAR_ARG_FUNCTIONS(ARuntimeBpGrenade*, Grenade, nullptr) // 26
	NODE_VAR_ARG_FUNCTIONS(UDamageType*, DamageType, nullptr) // 27

	NODE_VAR_ARG_FUNCTIONS(FHitResult, HitResult, FHitResult()) // 28

	FNodeVarArgs(const FString& Value) { StringData = Value; }
	FNodeVarArgs(FName Value) { StringData = Value.ToString(); }
	FNodeVarArgs(FText Value) { StringData = Value.ToString(); }

	NODE_VAR_ARG_CONSTRUCTOR(UObject*)
	NODE_VAR_ARG_CONSTRUCTOR(UClass*)
	NODE_VAR_ARG_CONSTRUCTOR(AActor*)
	NODE_VAR_ARG_CONSTRUCTOR(USceneComponent*)
	NODE_VAR_ARG_CONSTRUCTOR(UPrimitiveComponent*)
	NODE_VAR_ARG_CONSTRUCTOR(APlayerController*)
	NODE_VAR_ARG_CONSTRUCTOR(APawn*)
	NODE_VAR_ARG_CONSTRUCTOR(ACharacter*)
	NODE_VAR_ARG_CONSTRUCTOR(UStaticMeshComponent*)
	NODE_VAR_ARG_CONSTRUCTOR(ULightComponent*)
	NODE_VAR_ARG_CONSTRUCTOR(UParticleSystemComponent*)
	NODE_VAR_ARG_CONSTRUCTOR(UStaticMesh*)
	NODE_VAR_ARG_CONSTRUCTOR(UMaterialInterface*)
	NODE_VAR_ARG_CONSTRUCTOR(UParticleSystem*)

	// Gets the variable in the form of a name
	FName GetNameArg() const
	{
		return FName(*StringData);
	}

	// Sets the variable in the form of a name
	void SetNameArg(FName Value = "")
	{
		StringData = Value.ToString();
	}

	// Gets the variable in the form of a string
	FString GetStringArg() const
	{
		return StringData;
	}

	// Sets the variable in the form of a string
	void SetStringArg(const FString& Value = "")
	{
		StringData = Value;
	}

	// Gets the variable in the form of a text
	FText GetTextArg() const
	{
		return FText::FromString(StringData);
	}

	// Sets the variable in the form of a text
	void SetTextArg(FText Value = FText::GetEmpty())
	{
		StringData = Value.ToString();
		// VariableData.SetSubtype<FText>(Value);
	}
	/*
	UObject* GetObjectArg() const
	{
		return getSubTypeForEach<UObject*,
			AActor*,
			USceneComponent*>(VariableData);
	}*/

	/*UObject* GetObjectArg() const
	{
		return getSubTypeForEach<UObject*, 
			AActor*,
			USceneComponent*,
			UPrimitiveComponent*,
			APlayerController*,
			ACharacter*,
			APawn*,
			UStaticMeshComponent*,
			ULightComponent*,
			UParticleSystemComponent*>(VariableData);
	}*/
	/*
	NODE_VAR_ARG_GETTER_OBJECT(UObject*, Object, VariableData, (UObject*,
																AActor*,
																USceneComponent*, 
																UPrimitiveComponent*, 
																APlayerController*, 
																ACharacter*,
																APawn*,
																UStaticMeshComponent*,
																ULightComponent*,
																UParticleSystemComponent*))*/
	
	// Gets the variable in the form of an UObject
	class UObject* GetObjectArg() const
	{
		if (VariableData.HasSubtype<AActor*>())
		{
			return VariableData.GetSubtype<AActor*>();
		}

		if (VariableData.HasSubtype<USceneComponent*>())
		{
			return VariableData.GetSubtype<USceneComponent*>();
		}

		if (VariableData.HasSubtype<UPrimitiveComponent*>())
		{
			return VariableData.GetSubtype<UPrimitiveComponent*>();
		}

		if (VariableData.HasSubtype<APlayerController*>())
		{
			return VariableData.GetSubtype<APlayerController*>();
		}

		if (VariableData.HasSubtype<ACharacter*>())
		{
			return VariableData.GetSubtype<ACharacter*>();
		}

		if (VariableData.HasSubtype<APawn*>())
		{
			return VariableData.GetSubtype<APawn*>();
		}

		if (VariableData.HasSubtype<UStaticMeshComponent*>())
		{
			return VariableData.GetSubtype<UStaticMeshComponent*>();
		}

		if (VariableData.HasSubtype<ULightComponent*>())
		{
			return VariableData.GetSubtype<ULightComponent*>();
		}

		if (VariableData.HasSubtype<UParticleSystemComponent*>())
		{
			return VariableData.GetSubtype<UParticleSystemComponent*>();
		}

		if (VariableData.HasSubtype<ARuntimeBpGrenade*>())
		{
			return VariableData.GetSubtype<ARuntimeBpGrenade*>();
		}

		if (VariableData.HasSubtype<UDamageType*>())
		{
			return VariableData.GetSubtype<UDamageType*>();
		}

		return VariableData.GetSubtype<UObject*>();
	}
	
	// Sets the variable in the form of an UObject
	void SetObjectArg(UObject* Value = nullptr)
	{
		VariableData.SetSubtype<UObject*>(Value);
	}

	// Gets the variable in the form of an UClass
	class UClass* GetClassArg() const
	{
		return VariableData.GetSubtype<UClass*>();
	}

	// Sets the variable in the form of an UClass
	void SetClassArg(UClass* Value = nullptr)
	{
		VariableData.SetSubtype<UClass*>(Value);
	}

	// Gets the variable in the form of an AActor
	AActor* GetActorArg() const
	{
		if (VariableData.HasSubtype<APawn*>())
		{
			return VariableData.GetSubtype<APawn*>();
		}

		if (VariableData.HasSubtype<ACharacter*>())
		{
			return VariableData.GetSubtype<ACharacter*>();
		}

		if (VariableData.HasSubtype<ARuntimeBpGrenade*>())
		{
			return VariableData.GetSubtype<ARuntimeBpGrenade*>();
		}

		return VariableData.GetSubtype<AActor*>();
	}

	// Sets the variable in the form of an AActor
	void SetActorArg(AActor* Value = nullptr)
	{
		VariableData.SetSubtype<AActor*>(Value);
	}

	// Gets the variable in the form of an USceneComponent
	USceneComponent* GetSceneComponentArg() const
	{
		if (VariableData.HasSubtype<UStaticMeshComponent*>())
		{
			return VariableData.GetSubtype<UStaticMeshComponent*>();
		}

		if (VariableData.HasSubtype<UPrimitiveComponent*>())
		{
			return VariableData.GetSubtype<UPrimitiveComponent*>();
		}

		if (VariableData.HasSubtype<ULightComponent*>())
		{
			return VariableData.GetSubtype<ULightComponent*>();
		}

		if (VariableData.HasSubtype<UParticleSystemComponent*>())
		{
			return VariableData.GetSubtype<UParticleSystemComponent*>();
		}

		return VariableData.GetSubtype<USceneComponent*>();
	}

	// Sets the variable in the form of an USceneComponent
	void SetSceneComponentArg(USceneComponent* Value = nullptr)
	{
		VariableData.SetSubtype<USceneComponent*>(Value);
	}

	// Gets the variable in the form of an USceneComponent
	UPrimitiveComponent* GetPrimitiveComponentArg() const
	{
		if (VariableData.HasSubtype<UStaticMeshComponent*>())
		{
			return VariableData.GetSubtype<UStaticMeshComponent*>();
		}

		if (VariableData.HasSubtype<UParticleSystemComponent*>())
		{
			return VariableData.GetSubtype<UParticleSystemComponent*>();
		}

		return VariableData.GetSubtype<UPrimitiveComponent*>();
	}

	// Sets the variable in the form of an USceneComponent
	void SetPrimitiveComponentArg(UPrimitiveComponent* Value = nullptr)
	{
		VariableData.SetSubtype<UPrimitiveComponent*>(Value);
	}

	// Gets the variable in the form of an APlayerController
	APlayerController* GetPlayerControllerArg() const
	{
		return VariableData.GetSubtype<APlayerController*>();
	}

	// Sets the variable in the form of an APlayerController
	void SetPlayerControllerArg(APlayerController* Value = nullptr)
	{
		VariableData.SetSubtype<APlayerController*>(Value);
	}

	// Gets the variable in the form of an ACharacter
	ACharacter* GetCharacterArg() const
	{
		return VariableData.GetSubtype<ACharacter*>();
	}

	// Sets the variable in the form of an ACharacter
	void SetCharacterArg(ACharacter* Value = nullptr)
	{
		VariableData.SetSubtype<ACharacter*>(Value);
	}

	// Gets the variable in the form of an ACharacter
	APawn* GetPawnArg() const
	{
		if (VariableData.HasSubtype<ACharacter*>())
		{
			return VariableData.GetSubtype<ACharacter*>();
		}

		return VariableData.GetSubtype<APawn*>();
	}

	// Sets the variable in the form of an ACharacter
	void SetPawnArg(APawn* Value = nullptr)
	{
		VariableData.SetSubtype<APawn*>(Value);
	}

	// Gets the variable in the form of an UStaticMeshComponent
	UStaticMeshComponent* GetStaticMeshComponentArg() const
	{
		return VariableData.GetSubtype<UStaticMeshComponent*>();
	}

	// Sets the variable in the form of an UStaticMeshComponent
	void SetStaticMeshComponentArg(UStaticMeshComponent* Value = nullptr)
	{
		VariableData.SetSubtype<UStaticMeshComponent*>(Value);
	}

	// Gets the variable in the form of an ULightComponent
	ULightComponent* GetLightComponentArg() const
	{
		return VariableData.GetSubtype<ULightComponent*>();
	}

	// Sets the variable in the form of an ULightComponent
	void SetLightComponentArg(ULightComponent* Value = nullptr)
	{
		VariableData.SetSubtype<ULightComponent*>(Value);
	}

	// Gets the variable in the form of an UParticleSystemComponent
	UParticleSystemComponent* GetParticleSystemComponentArg() const
	{
		return VariableData.GetSubtype<UParticleSystemComponent*>();
	}

	// Sets the variable in the form of an UParticleSystemComponent
	void SetParticleSystemComponentArg(UParticleSystemComponent* Value = nullptr)
	{
		VariableData.SetSubtype<UParticleSystemComponent*>(Value);
	}

	// Gets the variable in the form of an UStaticMesh
	UStaticMesh* GetStaticMeshArg() const
	{
		return VariableData.GetSubtype<UStaticMesh*>();
	}

	// Sets the variable in the form of an UStaticMesh
	void SetStaticMeshArg(UStaticMesh* Value = nullptr)
	{
		VariableData.SetSubtype<UStaticMesh*>(Value);
	}

	// Gets the variable in the form of an UMaterialInterface
	UMaterialInterface* GetMaterialInterfaceArg() const
	{
		return VariableData.GetSubtype<UMaterialInterface*>();
	}

	// Sets the variable in the form of an UMaterialInterface
	void SetMaterialInterfaceArg(UMaterialInterface* Value = nullptr)
	{
		VariableData.SetSubtype<UMaterialInterface*>(Value);
	}

	// Gets the variable in the form of an UParticleSystemComponent
	UParticleSystem* GetParticleSystemArg() const
	{
		return VariableData.GetSubtype<UParticleSystem*>();
	}

	// Sets the variable in the form of an UParticleSystemComponent
	void SetParticleSystemArg(UParticleSystem* Value = nullptr)
	{
		VariableData.SetSubtype<UParticleSystem*>(Value);
	}

	/** Equality comparison. This relies on the order of the TLongUnion, if you add more types then this must be updated aswell or the equality will always fail.
	 *	Only add new types to the end of the union so this order doesn't get messed up. */
	FORCEINLINE bool operator==(const FNodeVarArgs& Other) const
	{
		switch(GetSubtypeIndex())
		{
			case 0: return GetBoolArg() == Other.GetBoolArg();
			case 1: return GetByteArg() == Other.GetByteArg();
			case 2: return GetIntArg() == Other.GetIntArg();
			case 3: return GetFloatArg() == Other.GetFloatArg();
			case 4: return GetVectorArg() == Other.GetVectorArg();
			case 5: return GetRotatorArg() == Other.GetRotatorArg();
			// Main reason why we do this comparison, Transforms don't have a == operator so you can't use the default union == operator.
			case 6: return GetTransformArg().Equals(Other.GetTransformArg());
			case 7: return GetVector2DArg() == Other.GetVector2DArg();
			case 8: return GetVector4Arg() == Other.GetVector4Arg();
			case 9: return GetLinearColorArg() == Other.GetLinearColorArg();
			case 10: return GetIntVectorArg() == Other.GetIntVectorArg();
			case 11: return GetIntVector4Arg() == Other.GetIntVector4Arg();
			case 12: return GetObjectArg() == Other.GetObjectArg();
			case 13: return GetClassArg() == Other.GetClassArg();
			case 14: return GetActorArg() == Other.GetActorArg();
			case 15: return GetSceneComponentArg() == Other.GetSceneComponentArg();
			case 16: return GetPlayerControllerArg() == Other.GetPlayerControllerArg();
			case 17: return GetCharacterArg() == Other.GetCharacterArg();
			case 18: return GetStaticMeshComponentArg() == Other.GetStaticMeshComponentArg();
			case 19: return GetLightComponentArg() == Other.GetLightComponentArg();
			case 20: return GetParticleSystemComponentArg() == Other.GetParticleSystemComponentArg();
			case 21: return GetStaticMeshArg() == Other.GetStaticMeshArg();
			case 22: return GetMaterialInterfaceArg() == Other.GetMaterialInterfaceArg();
			case 23: return GetParticleSystemArg() == Other.GetParticleSystemArg();
			case 24: return GetPrimitiveComponentArg() == Other.GetPrimitiveComponentArg();
			case 25: return GetPawnArg() == Other.GetPawnArg();
			case 26: return GetGrenadeArg() == Other.GetGrenadeArg(); 
			case 27: return GetDamageTypeArg() == Other.GetDamageTypeArg();
			case 28: return false; // HitResult has no equality comparison, we could make one ourselves but in most cases it's false anyway.
			// If the subtype index is invalid then we assume it is a string type
			default: return GetStringArg() == Other.GetStringArg();
		}
		return false;
	}

	~FNodeVarArgs()
	{
		Reset();
	}

};

// Array of FNodeVarArgs nested in a struct, this is used to store array variables
USTRUCT(BlueprintType)
struct FNodeVarArgsArray
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNodeVarArgs> Array;

	FNodeVarArgsArray()
	{
		Array.Empty();
	}

	~FNodeVarArgsArray()
	{
		Array.Empty();
	}

	FNodeVarArgsArray(const TArray<FNodeVarArgs>& Values)
	{
		Array = Values;
	}

	NODE_VAR_ARRAY_FUNCTIONS(bool, Bool)
	NODE_VAR_ARRAY_FUNCTIONS(uint8, Byte)
	NODE_VAR_ARRAY_FUNCTIONS(int, Int)
	NODE_VAR_ARRAY_FUNCTIONS(float, Float)
	NODE_VAR_ARRAY_FUNCTIONS(FVector, Vector)
	NODE_VAR_ARRAY_FUNCTIONS(FRotator, Rotator)
	NODE_VAR_ARRAY_FUNCTIONS(FTransform, Transform)
	NODE_VAR_ARRAY_FUNCTIONS(FVector2D, Vector2D)
	NODE_VAR_ARRAY_FUNCTIONS(FVector4, Vector4)
	NODE_VAR_ARRAY_FUNCTIONS(FLinearColor, LinearColor)
	NODE_VAR_ARRAY_FUNCTIONS(FIntVector, IntVector)
	NODE_VAR_ARRAY_FUNCTIONS(FIntVector4D, IntVector4)
	NODE_VAR_ARRAY_FUNCTIONS(UObject*, Object)
	NODE_VAR_ARRAY_FUNCTIONS(UClass*, Class)
	NODE_VAR_ARRAY_FUNCTIONS(AActor*, Actor)
	NODE_VAR_ARRAY_FUNCTIONS(USceneComponent*, SceneComponent)
	NODE_VAR_ARRAY_FUNCTIONS(UPrimitiveComponent*, PrimitiveComponent)
	NODE_VAR_ARRAY_FUNCTIONS(APlayerController*, PlayerController)
	NODE_VAR_ARRAY_FUNCTIONS(ACharacter*, Character)
	NODE_VAR_ARRAY_FUNCTIONS(APawn*, Pawn)
	NODE_VAR_ARRAY_FUNCTIONS(UStaticMeshComponent*, StaticMeshComponent)
	NODE_VAR_ARRAY_FUNCTIONS(ULightComponent*, LightComponent)
	NODE_VAR_ARRAY_FUNCTIONS(UParticleSystemComponent*, ParticleSystemComponent)
	NODE_VAR_ARRAY_FUNCTIONS(UStaticMesh*, StaticMesh)
	NODE_VAR_ARRAY_FUNCTIONS(UMaterialInterface*, MaterialInterface)
	NODE_VAR_ARRAY_FUNCTIONS(UParticleSystem*, ParticleSystem)
	NODE_VAR_ARRAY_FUNCTIONS(FString, String)
	NODE_VAR_ARRAY_FUNCTIONS(FName, Name)
	NODE_VAR_ARRAY_FUNCTIONS(FText, Text)
	NODE_VAR_ARRAY_FUNCTIONS(ARuntimeBpGrenade*, Grenade)
	NODE_VAR_ARRAY_FUNCTIONS(UDamageType*, DamageType)
	NODE_VAR_ARRAY_FUNCTIONS(FHitResult, HitResult)
};


// This struct contains all info needed for a pin to connect to another pin
USTRUCT(BlueprintType)
struct FPinStruct
{
	GENERATED_BODY()

	// Name of the pin that will show up in the node
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PinName;

	// The value of the pin, this is an array in case it is needed. If not then just index 0 will be used.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNodeVarArgsArray Value;

	// The type of pin this pin is connected to
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ENodeType ConnectPinType;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// TArray<int> ValueIndices;

	// Is true if the array length of Value >1. This bool is used so it doesn't have to constantly check for the array length to determine wether to use a Loop.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Array = false;

	// The kind of variable this pin is
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVariableTypes VariableType;

	// Whether this pin is an input or output pin
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Input;

	// Which node this pin is connected to, if -1 it means not connected to any node
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConnectedNodeIndex = -1;

	// Which pin this pin is connected to
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConnectedPinIndex = -1;

	// Pin metadata
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Meta;

	void MakeNodePin(FString Name = "Execute", EVariableTypes Type = EVariableTypes::Exec)
	{
		PinName = Name; // Input name
		VariableType = Type; // Variable type
		FPinStruct();
	}

	void MakeNodeArray(FString Name = "Execute", EVariableTypes Type = EVariableTypes::Exec, int ArrayLength = 0)
	{
		PinName = Name; // Input name
		VariableType = Type; // Variable type
		Array = true;
		Value.Array.Empty();
	}

	FPinStruct() :
		Value(FNodeVarArgsArray({FNodeVarArgs(VariableType)}))
	{}
};

// This struct contains all info needed for a node to be saved
USTRUCT(BlueprintType)
struct FNodeStruct
{
	GENERATED_BODY()

	// The coordinates of the nodes when in editing mode
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D NodeCoords;

	// The array of output pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPinStruct> InputPins;

	// The array of output pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPinStruct> OutputPins;

	// The name of the node
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	// The node description
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;

	// The index of the node in the array of all nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NodeIndex;

	// The class of this node
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<URuntimeBpObject> NodeClass;

	// The wildcard type of this node
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVariableTypes WildCardType = EVariableTypes::WildCard;
};


// These structs are used to make the nodes saveable
// Saveable Variable Arrays
USTRUCT(BlueprintType)
struct FSaveableProperty
{
	GENERATED_BODY()

	virtual	TArray<FNodeVarArgs> GetNodeVarArgs(EVariableTypes VariableType)
	{
		TArray<FNodeVarArgs> NodeVars;
		return NodeVars;
	}

	virtual void SetValue(TArray<FNodeVarArgs> NodeVarArgs, EVariableTypes VariableType)
	{}

	virtual FString ToJson(int Indent = 0, bool PrettyPrint = false)
	{
		return FString();
	}

	virtual TArray<TSharedPtr<FJsonValue>> ToJsonValue()
	{
		return TArray<TSharedPtr<FJsonValue>>();
	}

	virtual bool FromJsonValue(TArray<TSharedPtr<FJsonValue>> JsonObject)
	{
		return false;
	}

	virtual ~FSaveableProperty()
	{}

};

//Saveable formats of each variable type
USTRUCT(BlueprintType)
struct FSaveableBoolArray : public FSaveableProperty 
{ 
	GENERATED_BODY() 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<bool> Array; 
	SAVEABLE_PROPERTY_ARRAY(bool, Bool, FSaveableBoolArray) 
};

USTRUCT(BlueprintType)
struct FSaveableByteArray : public FSaveableProperty 
{
	GENERATED_BODY() 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<uint8> Array;
	SAVEABLE_PROPERTY_ARRAY(uint8, Byte, FSaveableByteArray)
};

USTRUCT(BlueprintType)
struct FSaveableIntArray : public FSaveableProperty 
{
	GENERATED_BODY() 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Array;
	SAVEABLE_PROPERTY_ARRAY(int, Int, FSaveableIntArray)
};

USTRUCT(BlueprintType)
struct FSaveableFloatArray : public FSaveableProperty 
{
	GENERATED_BODY() 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> Array;
	SAVEABLE_PROPERTY_ARRAY(float, Float, FSaveableFloatArray)
};

USTRUCT(BlueprintType)
struct FSaveableVectorArray : public FSaveableProperty
{ 
	GENERATED_BODY() 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Array;
	SAVEABLE_PROPERTY_ARRAY(FVector, Vector, FSaveableVectorArray)
};

USTRUCT(BlueprintType)
struct FSaveableRotatorArray : public FSaveableProperty 
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRotator> Array;
	SAVEABLE_PROPERTY_ARRAY(FRotator, Rotator, FSaveableRotatorArray)
};

USTRUCT(BlueprintType)
struct FSaveableTransformArray : public FSaveableProperty
{
	GENERATED_BODY() 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTransform> Array;
	SAVEABLE_PROPERTY_ARRAY(FTransform, Transform, FSaveableTransformArray) 
};

USTRUCT(BlueprintType)
struct FSaveableVector2DArray : public FSaveableProperty 
{
	GENERATED_BODY() 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> Array;
	SAVEABLE_PROPERTY_ARRAY(FVector2D, Vector2D, FSaveableVector2DArray) 
};

USTRUCT(BlueprintType)
struct FSaveableVector4Array : public FSaveableProperty
{
	GENERATED_BODY() 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector4> Array;
	SAVEABLE_PROPERTY_ARRAY(FVector4, Vector4, FSaveableVector4Array) };

USTRUCT(BlueprintType)
struct FSaveableLinearColorArray : public FSaveableProperty
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLinearColor> Array;
	SAVEABLE_PROPERTY_ARRAY(FLinearColor, LinearColor, FSaveableLinearColorArray) };

USTRUCT(BlueprintType)
struct FSaveableIntVectorArray : public FSaveableProperty 
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FIntVector> Array;
	SAVEABLE_PROPERTY_ARRAY(FIntVector, IntVector, FSaveableIntVectorArray)
};

USTRUCT(BlueprintType)
struct FSaveableIntVector4Array : public FSaveableProperty 
{
	GENERATED_BODY() 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FIntVector4D> Array;
	SAVEABLE_PROPERTY_ARRAY(FIntVector4D, IntVector4, FSaveableIntVector4Array)
};

USTRUCT(BlueprintType)
struct FSaveableClassArray : public FSaveableProperty 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UClass*> Array;
	SAVEABLE_PROPERTY_ARRAY(UClass*, Class, FSaveableClassArray)
};

USTRUCT(BlueprintType)
struct FSaveableStaticMeshArray : public FSaveableProperty 
{
	GENERATED_BODY() 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> Array;
	SAVEABLE_PROPERTY_ARRAY(UStaticMesh*, StaticMesh, FSaveableStaticMeshArray)
};

USTRUCT(BlueprintType)
struct FSaveableMaterialInterfaceArray : public FSaveableProperty 
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface*> Array;
	SAVEABLE_PROPERTY_ARRAY(UMaterialInterface*, MaterialInterface, FSaveableMaterialInterfaceArray) 
};

USTRUCT(BlueprintType)
struct FSaveableParticleSystemArray : public FSaveableProperty 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UParticleSystem*> Array;
	SAVEABLE_PROPERTY_ARRAY(UParticleSystem*, ParticleSystem, FSaveableParticleSystemArray)
};

USTRUCT(BlueprintType)
struct FSaveableHitResultArray : public FSaveableProperty
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FHitResult> Array;
	SAVEABLE_PROPERTY_ARRAY(FHitResult, HitResult, FSaveableHitResultArray)
};

USTRUCT(BlueprintType)
struct FSaveableStringArray : public FSaveableProperty
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Array;

	virtual TArray<FNodeVarArgs> GetNodeVarArgs(EVariableTypes VariableType) override
	{
		TArray<FNodeVarArgs> NodeVars;
		NodeVars.Reserve(Array.Num());

		for (FString Element : Array)
		{
			NodeVars.Add(FNodeVarArgs(Element));
		}

		return NodeVars;
	}

	virtual void SetValue(TArray<FNodeVarArgs> NodeVarArgs, EVariableTypes VariableType) override
	{
		// Unlike the other structs, we don't need to check for the variabletype because the string is not using the Union and is used by multiple asset types aswell.
		Array.Empty();
		Array.Reserve(NodeVarArgs.Num());

		switch (VariableType)
		{
			case EVariableTypes::Name:
			{
				for (FNodeVarArgs NodeVarArg : NodeVarArgs)
				{
					Array.Add(NodeVarArg.GetStringArg());
				}
				break;
			}
			case EVariableTypes::String:
			{
				for (FNodeVarArgs NodeVarArg : NodeVarArgs)
				{
					Array.Add(NodeVarArg.GetStringArg());
				}
				break;
			}
			case EVariableTypes::Text:
			{
				for (FNodeVarArgs NodeVarArg : NodeVarArgs)
				{
					Array.Add(NodeVarArg.GetStringArg());
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}

	virtual FString ToJson(int Indent = 0, bool PrettyPrint = false) override
	{
		FString JsonString;
		FJsonObjectConverter::UStructToJsonObjectString<FSaveableStringArray>(*this, JsonString, 0, 0, Indent, nullptr, PrettyPrint);
		return JsonString;
	}

	virtual TArray<TSharedPtr<FJsonValue>> ToJsonValue() override
	{
		TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject<FSaveableStringArray>(*this, 0, 0, nullptr);
		// OutArray = JsonObject->GetField<EJson::Array>("array")->AsArray();
		return JsonObject->GetArrayField("array");
	}

	virtual bool FromJsonValue(TArray<TSharedPtr<FJsonValue>> JsonValue) override
	{
		TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
		JsonObject->SetArrayField("array", JsonValue);
		return FJsonObjectConverter::JsonObjectToUStruct<FSaveableStringArray>(JsonObject, this, 0, 0);
	}
};

// Single letter variables to lower the filesize
USTRUCT(BlueprintType)
struct FSaveableOutputPin
{
	GENERATED_BODY()

	// Output pins don't have a default value so we don't have to save one, only reason this struct exists is for EXEC pins as they rely on the output to connect.
	// Connected node index
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int n;

	// Connected pin index
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int p;

	FSaveableOutputPin()
	{}

	FSaveableOutputPin(const FPinStruct& Pin)
	{
		FromScript(Pin);
	}
	virtual void FromScript(const FPinStruct& Pin)
	{
		n = Pin.ConnectedNodeIndex;
		p = Pin.ConnectedPinIndex;
	}

	virtual void ToScript(FPinStruct& Pin)
	{
		Pin.ConnectedNodeIndex = n;
		Pin.ConnectedPinIndex = p;
	}

	virtual ~FSaveableOutputPin()
	{}

};

USTRUCT(BlueprintType)
struct FSaveableInputPin : public FSaveableOutputPin
{
	GENERATED_BODY()

	// Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNodeVarArgs> v;

	FSaveableInputPin()
	{}

	FSaveableInputPin(const FPinStruct& Pin)
	{
		FromScript(Pin);
	}

	virtual void FromScript(const FPinStruct& Pin) override
	{
		v = Pin.Value.Array;
		n = Pin.ConnectedNodeIndex;
		p = Pin.ConnectedPinIndex;
	}

	// We set the Pin by ref instead of having it be a return value due to the pin potentially having other data initialized
	virtual void ToScript(FPinStruct& Pin) override
	{
		Pin.ConnectedNodeIndex = n;
		Pin.ConnectedPinIndex = p;
		Pin.Value = v;
	}
};

USTRUCT(BlueprintType)
struct FSaveableCustomInputPin : public FSaveableInputPin
{
	GENERATED_BODY()

	// Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString f;

	// Array
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool a;

	// Variable type
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVariableTypes t;

	FSaveableCustomInputPin()
	{}

	FSaveableCustomInputPin(const FPinStruct& Pin)
	{
		FromScript(Pin);
	}

	virtual void FromScript(const FPinStruct& Pin) override
	{
		v = Pin.Value.Array;
		f = Pin.PinName;
		a = Pin.Array;
		t = Pin.VariableType;
		n = Pin.ConnectedNodeIndex;
		p = Pin.ConnectedPinIndex;
	}

	// We set the Pin by ref instead of having it be a return value due to the pin potentially having other data initialized
	virtual void ToScript(FPinStruct& Pin) override
	{
		Pin.ConnectedNodeIndex = n;
		Pin.ConnectedPinIndex = p;
		Pin.Value = v;
		Pin.PinName = f;
		Pin.Array = a;
		Pin.VariableType = t;
	}

	// Do the same as above but leave the connected node and pin indices untouched
	void ToScriptTypeOnly(FPinStruct& Pin)
	{
		Pin.Value = v;
		Pin.PinName = f;
		Pin.Array = a;
		Pin.VariableType = t;
	}
};

USTRUCT(BlueprintType)
struct FSaveableCustomOutputPin : public FSaveableOutputPin
{
	GENERATED_BODY()

	// Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString f;

	// Array
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool a;

	// Variable type
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVariableTypes t;

	FSaveableCustomOutputPin()
	{}

	FSaveableCustomOutputPin(const FPinStruct& Pin)
	{
		FromScript(Pin);
	}

	virtual void FromScript(const FPinStruct& Pin) override
	{
		f = Pin.PinName;
		a = Pin.Array;
		t = Pin.VariableType;
		n = Pin.ConnectedNodeIndex;
		p = Pin.ConnectedPinIndex;
	}

	// We set the Pin by ref instead of having it be a return value due to the pin potentially having other data initialized
	virtual void ToScript(FPinStruct& Pin) override
	{
		Pin.ConnectedNodeIndex = n;
		Pin.ConnectedPinIndex = p;
		Pin.PinName = f;
		Pin.Array = a;
		Pin.VariableType = t;
	}

	// Do the same as above but leave the connected node and pin indices untouched
	void ToScriptTypeOnly(FPinStruct& Pin)
	{
		Pin.PinName = f;
		Pin.Array = a;
		Pin.VariableType = t;
	}
};

USTRUCT(BlueprintType)
struct FSaveableNode
{
	GENERATED_BODY()

	// Coordinates
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Coordinates"))
	FVector2D c;

	// Input pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Input Pins"))
	TArray<FSaveableInputPin> i;

	// Output pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Output Pins"))
	TArray<FSaveableOutputPin> o;

	// Node index
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Node Index"))
	int ix;

	// Node class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Node Class"))
	class TSubclassOf<URuntimeBpObject> n;

	// Wildcard Meta
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Meta"))
	EVariableTypes w = EVariableTypes::WildCard;

	FSaveableNode()
	{}

	FSaveableNode(const FNodeStruct& Node)
	{
		FromScript(Node);
	}

	void FromScript(const FNodeStruct& Node)
	{

		i.Reserve(Node.InputPins.Num());
		for (FPinStruct Input : Node.InputPins)
		{
			i.Add(FSaveableInputPin(Input));
		}

		o.Reserve(Node.OutputPins.Num());
		for (FPinStruct Output : Node.OutputPins)
		{
			o.Add(FSaveableOutputPin(Output));
		}

		c = Node.NodeCoords;
		ix = Node.NodeIndex;
		n = Node.NodeClass;
		w = Node.WildCardType;
	}

	void ToScript(FNodeStruct& Node)
	{
		// Set the values that are not from the class default
		Node.NodeCoords = c;
		Node.NodeIndex = ix;
		Node.NodeClass = n;
		Node.WildCardType = w;

		// Loop and update the pins with the data that was saved
		int Index = 0;
		Node.InputPins.SetNum(i.Num());
		for (FSaveableInputPin& Input : i)
		{
			Input.ToScript(Node.InputPins[Index]);
			Index++;
		}

		Index = 0;
		Node.OutputPins.SetNum(o.Num());
		for (FSaveableOutputPin& Output : o)
		{
			Output.ToScript(Node.OutputPins[Index]);
			Index++;
		}
	}
};

USTRUCT(BlueprintType)
struct FSaveableLocalVariable
{
	GENERATED_BODY()

	// Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Values"))
	TArray<FNodeVarArgs> v;

	// Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Name"))
	FString n;

	// Description
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Description"))
	FString d;

	// Category
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Category"))
	FString c;

	// Array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Array"))
	bool a;

	// Type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Variable Type"))
	EVariableTypes t;
};

USTRUCT(BlueprintType)
struct FSaveableVariable : public FSaveableLocalVariable
{
	GENERATED_BODY()

	// Editable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Editable"))
	bool e;

	void ToLocal(FSaveableLocalVariable& LocalVariable)
	{
		LocalVariable.v = v;
		LocalVariable.n = n;
		LocalVariable.d = d;
		LocalVariable.c = c;
		LocalVariable.a = a;
		LocalVariable.t = t;
	}

	void FromLocal(FSaveableLocalVariable& LocalVariable)
	{
		v = LocalVariable.v;
		n = LocalVariable.n;
		d = LocalVariable.d;
		c = LocalVariable.c;
		a = LocalVariable.a;
		t = LocalVariable.t;
	}
};

// This struct contains all the info needed to create a custom function
USTRUCT(BlueprintType)
struct FRuntimeFunction
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNodeStruct> Nodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSaveableVariable> LocalVariables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPinStruct> InputPins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPinStruct> OutputPins;

	FRuntimeFunction()
	{
		// Add the exec and then function inputs so this function can be connected to.
		FPinStruct Input;
		Input.MakeNodePin();
		InputPins.SetNum(1);
		InputPins[0] = Input;

		FPinStruct Output;
		Output.MakeNodePin("Then");
		OutputPins.SetNum(1);
		OutputPins[0] = Input;

		FNodeStruct FunctionStart;
		FunctionStart.NodeIndex = 0;
		UClass* FunctionStartClass = FindObject<UClass>(ANY_PACKAGE, TEXT("FunctionStart"));
		// ConstructorHelpers::FClassFinder<class UFunctionStart> FunctionStartClass(TEXT("/Script/RuntimeBlueprints.CallFunction"));
		FunctionStart.NodeClass = FunctionStartClass;
		Nodes.SetNum(1);
		Nodes[0] = FunctionStart;
	}
};

// This struct contains all the info needed to create a custom function
USTRUCT(BlueprintType)
struct FSaveableFunction
{
	GENERATED_BODY()

	// Function Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Function Name"))
	FString f;

	// Description
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Description"))
	FString d;

	// Nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Nodes"))
	TArray<FSaveableNode> n;

	// Local variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Local Variables"))
	TArray<FSaveableLocalVariable> v;

	// Input pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Input Pins"))
	TArray<FSaveableCustomInputPin> i;

	// Output Pins
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Output Pins"))
	TArray<FSaveableCustomOutputPin> o;

	FSaveableFunction()
	{}

	FSaveableFunction(const FRuntimeFunction& Function)
	{
		FromScript(Function);
	}

	// Convert a runtime function to a saveable function
	void FromScript(const FRuntimeFunction& Function)
	{
		// Name and description
		f = Function.FunctionName;
		d = Function.Description;

		// Nodes
		n.Reserve(Function.Nodes.Num());
		for (FNodeStruct Node : Function.Nodes)
		{
			n.Add(FSaveableNode(Node));
		}
		
		// Local variables
		int Index = 0;
		v.SetNum(Function.LocalVariables.Num());
		for (FSaveableVariable LocalVariable : Function.LocalVariables)
		{
			LocalVariable.ToLocal(v[Index]);
			Index++;
		}

		// Input pins
		i.Reserve(Function.InputPins.Num());
		for (FPinStruct Input : Function.InputPins)
		{
			i.Add(FSaveableCustomInputPin(Input));
		}


		// Output pins
		o.Reserve(Function.OutputPins.Num());
		for (FPinStruct Output : Function.OutputPins)
		{
			o.Add(FSaveableCustomOutputPin(Output));
		}

	}

	// Convert this saveable function to a runtime function
	void ToScript(FRuntimeFunction& Function)
	{
		// Name and description
		Function.FunctionName = f;
		Function.Description = d;

		// Nodes
		int Index = 0;
		Function.Nodes.SetNum(n.Num());
		for (FSaveableNode& Node : n)
		{
			Node.ToScript(Function.Nodes[Index]);
			Index++;
		}

		// Local variables
		Index = 0;
		Function.LocalVariables.SetNum(v.Num());
		for (FSaveableVariable& LocalVariable : Function.LocalVariables)
		{
			LocalVariable.FromLocal(v[Index]);
			Index++;
		}

		// Input pins
		Index = 0;
		Function.InputPins.SetNum(i.Num());
		for (FSaveableCustomInputPin& Input : i)
		{
			Input.ToScript(Function.InputPins[Index]);
			Index++;
		}

		// Output pins
		Index = 0;
		Function.OutputPins.SetNum(o.Num());
		for (FSaveableCustomOutputPin& Output : o)
		{
			Output.ToScript(Function.OutputPins[Index]);
			Index++;
		}
	}
};

USTRUCT(BlueprintType)
struct FRuntimeBpJsonFormat
{
	GENERATED_BODY()

	// All Nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNodeStruct> Nodes;

	// All Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSaveableVariable> Variables;

	// All Functions
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRuntimeFunction> Functions;

	// All Script References
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> References;

	// Set of nodes that are erroring, if this isn't empty the script won't execute. X = FunctionIndex, Y = NodeIndex, Z = PinIndex, W = 0 if output, 1 if input
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSet<FIntVector4D> ErroringNodes;

	FRuntimeBpJsonFormat()
	{}

};

USTRUCT(BlueprintType)
struct FSaveableBPJsonFormat
{
	GENERATED_BODY()

	// All Nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSaveableNode> Nodes;

	// All Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSaveableVariable> Variables;

	// All Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSaveableFunction> Functions;

	// All Script References
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> References;

	FSaveableBPJsonFormat()
	{}

	FSaveableBPJsonFormat(const FRuntimeBpJsonFormat& Script)
	{
		FromScript(Script);
	}

	void FromScript(const FRuntimeBpJsonFormat& Script)
	{
		// Init nodes
		Nodes.Empty();
		Nodes.Reserve(Script.Nodes.Num());
		for (FNodeStruct Node : Script.Nodes)
		{
			Nodes.Add(FSaveableNode(Node));
		}

		// Init variables
		Variables = Script.Variables;
		
		// Init custom functions
		Functions.Empty();
		Functions.Reserve(Script.Functions.Num());
		for (FRuntimeFunction Function : Script.Functions)
		{
			Functions.Add(FSaveableFunction(Function));
		}

		References = Script.References;
	}

	void ToScript(FRuntimeBpJsonFormat& Script)
	{
		// Init nodes
		Script.Nodes.SetNum(Nodes.Num());
		int Index = 0;
		for (FSaveableNode Node : Nodes)
		{
			Node.ToScript(Script.Nodes[Index]);
			Index++;
		}

		// Init variables
		Script.Variables = Variables;

		// Init custom functions
		Script.Functions.SetNum(Functions.Num());
		Index = 0;
		for (FSaveableFunction Function : Functions)
		{
			Function.ToScript(Script.Functions[Index]);
			Index++;
		}

		Script.References = References;
	}
};