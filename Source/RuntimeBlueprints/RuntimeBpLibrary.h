// Copyright notice here..

#pragma once

#include "Engine.h"
#include "RuntimeBpData.h"
#include "RuntimeBpConstructor.h"
#include "RuntimeBpObject.h"
#include "AssetRegistryModule.h"
#include "IAssetRegistry.h"
#include "AssetData.h"
#include "ARFilter.h"
#include "JsonObjectConverter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextWidgetTypes.h"
#include "RuntimeBpLibrary.generated.h"


UCLASS()
class RUNTIMEBLUEPRINTS_API URuntimeBpLibrary : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:

	/**
	* Performs a cubic interpolation between 2 float values
	*/
	UFUNCTION(BlueprintPure, Category = "Math|Float")
	static float FCubicInterp(float StartPoint, float StartTangent, float EndPoint, float EndTangent, float Alpha);

	UFUNCTION(BlueprintCallable, Category = "Painting")
	static int GetContextMaxLayer(UPARAM(ref) FPaintContext& Context);

	/**
	 * Draws a spline.
	 *
	 * @param Layer			States which Z-order layer this spline is rendered in
	 * @param Start			Starting position of the spline in local space.
	 * @param StartDir		Starting direction of the spline.
	 * @param End			Ending position of the spline in local space.
	 * @param EndDir		Ending direction of the spline.
	 * @param Thickness		How many pixels thick this spline should be.
	 * @param Tint			Color to render the spline.
	 */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "8"), Category = "Painting")
	static void DrawSpline(UPARAM(ref) FPaintContext& Context, int InLayer, const FVector2D& InStart, const FVector2D& InStartDir, const FVector2D& InEnd, const FVector2D& InEndDir, float InThickness, const FLinearColor& InTint);

	/**
	 * Draws a polyline.
	 *
	 * @param Layer			States which Z-order layer this polyline is rendered in
	 * @param Start			Starting position of the polyline in local space.
	 * @param End			Ending position of the polyline in local space.
	 * @param Thickness		How many pixels thick this polyline should be.
	 * @param Tint			Color to render the polyline.
	 */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "6"), Category = "Painting")
	static void DrawPolyLine(UPARAM(ref) FPaintContext& Context, int InLayer, const FVector2D& InStart, const FVector2D& InEnd, float InThickness, const FLinearColor& InTint);


	// returns a list of all save games in /Saved/SaveGames folder, without the extension (filename only)
	UFUNCTION(BlueprintPure, Category = Game)
	static TArray<FString> GetAllSaveGameSlotNames(const FString& LocalPath, const FString& FileExtension = FString(TEXT("sav")));
	
	// returns an array of all child classes of a specified class
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Child Classes of Class", Keywords = "Get Child Classes"), Category = Class)
	static TArray<UClass*> GetChildClassesOfClass(UClass* ParentClass, TArray<TAssetSubclassOf<UObject>>& BPResults, const FString& Path);

	// Sets the wrap length of a text widget
	UFUNCTION(BlueprintCallable, Category = "Appearance")
	static void SetWrapTextAt(UTextLayoutWidget* TextWidget, float WrapTextAt);

	UFUNCTION(BlueprintCallable, Category = "Utilities|Enum", meta = (Keywords = "Get Enum Entries From Name"))
	static bool GetEnumEntriesFromName(const FString& EnumName, TArray<FString>& EnumEntries);

	/**
	* TArray<FNodeVarArgs> functions exposed for BP usage
	*/

	// Sets the default value based on the VariableType
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Default"))
	static void SetDefaultArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, EVariableTypes VariableType);

	// Sets the variable in the form of a bool
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints", Keywords = "Clear Node Var Args"))
	static void ClearNodeVarArgs(UPARAM(ref) TArray<FNodeVarArgs>& Values, EVariableTypes VariableType, bool Array = false);

	// Gets the variable in the form of a bool
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Bool"))
	static TArray<bool> GetBoolArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a bool
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Bool"))
	static void SetBoolArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<bool> Value);

	// Gets the variable in the form of an int8 (or byte)
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Byte"))
	static TArray<uint8> GetByteArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an int8 (or byte)
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Byte"))
	static void SetByteArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<uint8> Value);

	// Gets the variable in the form of an integer
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Int"))
	static TArray<int> GetIntArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Gets the variable in the form of an integer
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Int"))
	static void SetIntArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<int> Value);

	// Gets the variable in the form of a float
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Float"))
	static TArray<float> GetFloatArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a float
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Float"))
	static void SetFloatArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<float> Value);

	// Gets the variable in the form of a name
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Name"))
	static TArray<FName> GetNameArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a name
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Name"))
	static void SetNameArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FName> Value);

	// Gets the variable in the form of a string
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args String"))
	static TArray<FString> GetStringArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a string
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args String"))
	static void SetStringArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, const TArray<FString>& Value);

	// Gets the variable in the form of a text
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Text"))
	static TArray<FText> GetTextArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a text
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Text"))
	static void SetTextArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FText> Value);

	// Gets the variable in the form of a vector
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Vector"))
	static TArray<FVector> GetVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a vector
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Vector"))
	static void SetVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FVector> Value);

	// Gets the variable in the form of a rotator
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Rotator"))
	static TArray<FRotator> GetRotatorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a rotator
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Rotator"))
	static void SetRotatorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FRotator> Value);

	// Gets the variable in the form of a transform
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Transform"))
	static TArray<FTransform> GetTransformArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a transform
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Transform"))
	static void SetTransformArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FTransform> Value);

	// Gets the variable in the form of a Vector2D
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Vector 2D"))
	static TArray<FVector2D> GetVector2DArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a Vector2D
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Vector 2D"))
	static void SetVector2DArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FVector2D> Value);

	// Sets the variable in the form of a Vector4
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Vector 4"))
	static TArray<FVector4> GetVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Gets the variable in the form of a Vector4
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Vector 4"))
	static void SetVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FVector4> Value);

	// Gets the variable in the form of a color
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Color"))
	static TArray<FLinearColor> GetLinearColorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a color
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Color"))
	static void SetLinearColorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FLinearColor> Value);

	// Gets the variable in the form of a HitResult
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Int Vector"))
	static TArray<FIntVector> GetIntVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a HitResult
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Int Vector"))
	static void SetIntVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FIntVector> Value);

	// Gets the variable in the form of an IntVector4
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Int Vector 4"))
	static TArray<FIntVector4D> GetIntVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an IntVector4
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Int Vector 4"))
	static void SetIntVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FIntVector4D> Value);

	// Gets the variable in the form of an UObject
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Object UObject"))
	static TArray<UObject*> GetObjectArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UObject
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Object UObject"))
	static void SetObjectArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UObject*> Value);

	// Gets the variable in the form of an UClass
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Class UClass"))
	static TArray<UClass*> GetClassArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UClass
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Class UClass")) 
	static void SetClassArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UClass*> Value);
	
	//~~PYTHON SCRIPT IDENTIFIER~~

	// Gets the variable in the form of an AActor
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Actor"))
	static TArray<AActor*> GetActorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an AActor
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Actor"))
	static void SetActorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<AActor*> Value);

	// Gets the variable in the form of an USceneComponent
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Scene Component"))
	static TArray<USceneComponent*> GetSceneComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an USceneComponent
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Scene Component"))
	static void SetSceneComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<USceneComponent*> Value);

	// Gets the variable in the form of an UPrimitiveComponent
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Primitive Component"))
	static TArray<UPrimitiveComponent*> GetPrimitiveComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UPrimitiveComponent
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Primitive Component"))
	static void SetPrimitiveComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UPrimitiveComponent*> Value);

	// Gets the variable in the form of an APlayerController
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Player Controller"))
	static TArray<APlayerController*> GetPlayerControllerArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an APlayerController
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Player Controller"))
	static void SetPlayerControllerArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<APlayerController*> Value);

	// Gets the variable in the form of an ACharacter
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Character"))
	static TArray<ACharacter*> GetCharacterArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an ACharacter
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Character"))
	static void SetCharacterArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ACharacter*> Value);

	// Gets the variable in the form of an APawn
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Pawn"))
	static TArray<APawn*> GetPawnArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an APawn
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Pawn"))
	static void SetPawnArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<APawn*> Value);

	// Gets the variable in the form of an UStaticMeshComponent
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Static Mesh Component"))
	static TArray<UStaticMeshComponent*> GetStaticMeshComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UStaticMeshComponent
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Static Mesh Component"))
	static void SetStaticMeshComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UStaticMeshComponent*> Value);

	// Gets the variable in the form of an ULightComponent
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Light Component"))
	static TArray<ULightComponent*> GetLightComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an ULightComponent
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Light Component"))
	static void SetLightComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ULightComponent*> Value);

	// Gets the variable in the form of an UParticleSystemComponent
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Particle System Component"))
	static TArray<UParticleSystemComponent*> GetParticleSystemComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UParticleSystemComponent
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Particle System Component"))
	static void SetParticleSystemComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UParticleSystemComponent*> Value);

	// Gets the variable in the form of an UStaticMesh
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Static Mesh"))
	static TArray<UStaticMesh*> GetStaticMeshArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UStaticMesh
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Static Mesh"))
	static void SetStaticMeshArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UStaticMesh*> Value);

	// Gets the variable in the form of an UMaterialInterface
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Material Interface"))
	static TArray<UMaterialInterface*> GetMaterialInterfaceArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UMaterialInterface
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Material Interface"))
	static void SetMaterialInterfaceArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UMaterialInterface*> Value);
	
	// Gets the variable in the form of an UParticleSystem
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Particle System"))
	static TArray<UParticleSystem*> GetParticleSystemArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UParticleSystem
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Particle System"))
	static void SetParticleSystemArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UParticleSystem*> Value);

	// Gets the variable in the form of an ARuntimeBpGrenade
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args Grenade"))
	static TArray<ARuntimeBpGrenade*> GetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an ARuntimeBpGrenade
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args Grenade"))
	static void SetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ARuntimeBpGrenade*> Value);

	// Gets the variable in the form of an UDamageType
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args DamageType Damage Type"))
	static TArray<UDamageType*> GetDamageTypeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of an UDamageType
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args DamageType Damage Type"))
	static void SetDamageTypeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UDamageType*> Value);

	// Gets the variable in the form of a FHitResult
	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints|Get", Keywords = "Get Node Var Args HitResult Hit Result"))
	static TArray<FHitResult> GetHitResultArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array = false);

	// Sets the variable in the form of a FHitResult
	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Set", Keywords = "Set Node Var Args HitResult Hit Result"))
	static void SetHitResultArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, const TArray<FHitResult>& Value);

	/*
	** End of variable arg functions
	*/

	UFUNCTION(BlueprintPure, meta = (Category = "Runtime Blueprints", Keywords = "Get Connected Pin Value", DisplayName = "Get Value From Connected Pin"))
	static FPinStruct GetConnectedPinValue(FPinStruct Pin, class URuntimeBpConstructor* BPConstructor);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints", Keywords = "Pin value index"))
	static int GetValueSubtypeIndex(UPARAM(ref) TArray<FNodeVarArgs>& Values);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints", Keywords = "Variable value index"))
	static int GetVariableSubtypeIndex(UPARAM(ref)FSaveableVariable& Variable);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints", Keywords = "Pin Value to Variable"))
	static bool PinValueToVariableValue(UPARAM(ref) FSaveableVariable& Variable, UPARAM(ref) FPinStruct& Pin);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints", Keywords = "Variable Value to Pin"))
	static bool VariableValueToPinValue(UPARAM(ref) FSaveableVariable& Variable, UPARAM(ref) FPinStruct& Pin);

	UFUNCTION(BlueprintCallable, meta = (Category = "Runtime Blueprints|Saving", Keywords = "Convert Saveable Value to Json"))
	static FString SaveableValueToJson(FSaveableProperty SaveableValue, EVariableTypes VariableType, int Indent, bool PrettyPrint);

	static bool GenericArray_SortCompare(const FProperty* LeftProperty, void* LeftValuePtr, const FProperty* RightProperty, void* RightValuePtr);

	/**
	 *	Sort the elements of an array by FString, FName, FText, float, int or boolean.
	 *	Supports struct and object based arrays.
	 *
	 *	@param	TargetArray		The array to sort.
	 *	@param	bAscendingOrder	If true, sort by ascending order.
	 *	@param	VariableName	If a struct or object based array, the name of the variable to sort by.
	 */
	UFUNCTION(BlueprintCallable, CustomThunk, Meta = (Category = "Utilities|Array", DisplayName = "Sort", ArrayParm = "TargetArray", AdvancedDisplay = "bAscendingOrder,VariableName"))
	static void Array_Sort(const TArray<int32>& TargetArray, bool bAscendingOrder = true, FName VariableName = NAME_None);

	static void GenericArray_Sort(void* TargetArray, const FArrayProperty* ArrayProp, bool bAscendingOrder = true, FName VariableName = NAME_None);

	DECLARE_FUNCTION(execArray_Sort)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<FArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		P_GET_UBOOL(bAscendingOrder);

		P_GET_PROPERTY(FNameProperty, VariableName);

		P_FINISH;
		P_NATIVE_BEGIN;
		GenericArray_Sort(ArrayAddr, ArrayProperty, bAscendingOrder, VariableName);
		P_NATIVE_END;
	}
};

