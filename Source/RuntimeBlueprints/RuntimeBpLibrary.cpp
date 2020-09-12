// Copyright notice here..

#include "RuntimeBpLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "Paths.h"
#include "AssetDataTagMap.h"
#include "PlatformFile.h"
#include "PlatformFilemanager.h"
#include "RuntimeBlueprints.h"

float URuntimeBpLibrary::FCubicInterp(float StartPoint, float StartTangent, float EndPoint, float EndTangent, float Alpha)
{
	return FMath::CubicInterp<float>(StartPoint, StartTangent, EndPoint, EndTangent, Alpha);
}

int URuntimeBpLibrary::GetContextMaxLayer(UPARAM(ref) FPaintContext& Context)
{
	return Context.MaxLayer;
}

void URuntimeBpLibrary::DrawSpline(UPARAM(ref) FPaintContext& Context, int InLayer, const FVector2D& InStart, const FVector2D& InStartDir, const FVector2D& InEnd, const FVector2D& InEndDir, float InThickness, const FLinearColor& InTint)
{
	FSlateDrawElement::MakeSpline(Context.OutDrawElements, InLayer, Context.AllottedGeometry.ToPaintGeometry(), InStart, InStartDir, InEnd, InEndDir, InThickness, ESlateDrawEffect::None, InTint);
}

void URuntimeBpLibrary::DrawPolyLine(UPARAM(ref)FPaintContext& Context, int InLayer, const FVector2D& InStart, const FVector2D& InEnd, float InThickness, const FLinearColor& InTint)
{
	TArray<FVector2D> Points;
	Points.Add(InStart);
	float AverageX = (InStart.X + InEnd.X) * 0.5;
	Points.Add(FVector2D(AverageX, InStart.Y));
	Points.Add(FVector2D(AverageX, InEnd.Y));
	Points.Add(InEnd);

	FSlateDrawElement::MakeLines(Context.OutDrawElements, InLayer, Context.AllottedGeometry.ToPaintGeometry(), Points, ESlateDrawEffect::None, InTint, false, InThickness);
}

TArray<FString> URuntimeBpLibrary::GetAllSaveGameSlotNames(const FString& LocalPath, const FString& FileExtension)
{
	class FFindSavesVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		FFindSavesVisitor() {}

		FString Extension = "sav";

		virtual bool Visit(const TCHAR* (FilenameOrDirectory), bool bIsDirectory)
		{
			if (!bIsDirectory)
			{
				FString FullFilePath(FilenameOrDirectory);
				if (FPaths::GetExtension(FullFilePath) == Extension)
				{
					FString ExtensionWithDot = "." + Extension;
					FString CleanFilename = FPaths::GetBaseFilename(FullFilePath);
					CleanFilename = CleanFilename.Replace(*ExtensionWithDot, TEXT(""));
					SavesFound.Add(CleanFilename);
				}
			}
			return true;
		}
		TArray<FString> SavesFound;
};

	TArray<FString> Saves;
	const FString SavesFolder = FPaths::ProjectSavedDir() + TEXT("SaveGames") + LocalPath;

	if (!SavesFolder.IsEmpty())
	{
		FFindSavesVisitor Visitor;
		Visitor.Extension = FileExtension;
		FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*SavesFolder, Visitor);
		Saves = Visitor.SavesFound;
	}

	return Saves;
}

TArray<UClass*> URuntimeBpLibrary::GetChildClassesOfClass(UClass* ParentClass, TArray<TAssetSubclassOf<UObject>>& BPResults, const FString& Path = "")
{
	// Get C++ classes
	TArray<UClass*> Results;

	// get our parent class
	const FString ParentClassName = ParentClass->GetName();
	UObject* ClassPackage = ANY_PACKAGE;
	UClass* ParentBPClass = FindObject<UClass>(ClassPackage, *ParentClassName);

	// iterate over UClass, this might be heavy on performance, so keep in mind..
	// better suggestions for a check are welcome
	for (TObjectIterator<UClass> It; It; ++It)
	{

		if (It->IsChildOf(ParentBPClass))// &&  !It->IsNative() && (It->HasAnyClassFlags(CLASS_Deprecated | CLASS_NewerVersionExists)))
		{
			// It is a child of the Parent Class
			// make sure we don't include our parent class in the array (weak name check, suggestions welcome)
			if (It->GetName() != ParentClassName)
			{
				Results.Add(*It);
			}
		}
	}

	//BP classes

	// Load the asset registry module
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked< FAssetRegistryModule >(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	// The asset registry is populated asynchronously at startup, so there's no guarantee it has finished.
	// This simple approach just runs a synchronous scan on the entire content directory.
	// Better solutions would be to specify only the path to where the relevant blueprints are,
	// or to register a callback with the asset registry to be notified of when it's finished populating.
	TArray< FString > ContentPaths;
	ContentPaths.Add(TEXT("/Game"));
	AssetRegistry.ScanPathsSynchronous(ContentPaths);

	FName BaseClassName = ParentClass->GetFName();

	// Use the asset registry to get the set of all class names deriving from Base
	TSet< FName > DerivedNames;
	{
		TArray< FName > BaseNames;
		BaseNames.Add(BaseClassName);

		TSet< FName > Excluded;
		AssetRegistry.GetDerivedClassNames(BaseNames, Excluded, DerivedNames);
	}

	// Having got a reference to the asset registry, we first ask it for a list of class names deriving from our base class.
	FARFilter Filter;
	Filter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
	Filter.bRecursiveClasses = true;

	if (!Path.IsEmpty())
	{
		Filter.PackagePaths.Add(*Path);
	}

	Filter.bRecursivePaths = true;

	TArray< FAssetData > AssetList;
	AssetRegistry.GetAssets(Filter, AssetList);

	// Iterate over retrieved blueprint assets
	for (auto const& Asset : AssetList)
	{
		// Get the the class this blueprint generates (this is stored as a full path)
		auto GeneratedClassPath = Asset.TagsAndValues.FindTag(FName("GeneratedClass"));
		if (GeneratedClassPath.IsSet())
		{
			// Convert path to just the name part
			const FString ClassObjectPath = FPackageName::ExportTextPathToObjectPath(GeneratedClassPath.GetValue());
			const FString ClassName = FPackageName::ObjectPathToObjectName(ClassObjectPath);

			// Check if this class is in the derived set
			if (!DerivedNames.Contains(*ClassName))
			{
				continue;
			}

			// Store using the path to the generated class
			BPResults.Add(TAssetSubclassOf< UObject >(FStringAssetReference(ClassObjectPath)));
		}
	}

	return Results;
}

void URuntimeBpLibrary::SetWrapTextAt(UTextLayoutWidget* TextWidget, float WrapTextAt)
{
	// Doing a hacky way to set this because the source code has this variable protected.
	if (TextWidget)
	{
		const FProperty* Property = (UTextLayoutWidget::StaticClass())->FindPropertyByName(FName(TEXT("WrapTextAt")));
		((FFloatProperty*)Property)->SetPropertyValue_InContainer(TextWidget, WrapTextAt);
		//	return ((FBoolProperty*)Property)->GetPropertyValue_InContainer(InTileLayer);
	}
}


bool URuntimeBpLibrary::GetEnumEntriesFromName(const FString& EnumName, TArray<FString>& EnumEntries)
{
	UEnum* MyEnum = FindObject<UEnum>(ANY_PACKAGE, *EnumName, true);
	if (MyEnum)
	{
		EnumEntries.Reserve(MyEnum->GetMaxEnumValue());
		for (int i = 0; i < MyEnum->GetMaxEnumValue(); i++)
		{
			EnumEntries.Add(MyEnum->GetNameStringByIndex(i));
		}
		return true;
	}
	else
	{
		EnumEntries = TArray<FString>();
		return false;
	}
}

/**
* FValues functions exposed for BP usage
*/

void URuntimeBpLibrary::ClearNodeVarArgs(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	Values.Empty();
}

TArray<bool> URuntimeBpLibrary::GetBoolArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(bool, Bool)
}

void URuntimeBpLibrary::SetBoolArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<bool> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(bool, Bool)
}

TArray<uint8> URuntimeBpLibrary::GetByteArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(uint8, Byte)
}

void URuntimeBpLibrary::SetByteArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<uint8> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(uint8, Byte)
}

TArray<int> URuntimeBpLibrary::GetIntArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(int, Int)
}

void URuntimeBpLibrary::SetIntArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<int> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(int, Int)
}

TArray<float> URuntimeBpLibrary::GetFloatArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(float, Float)
}

void URuntimeBpLibrary::SetFloatArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<float> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(float, Float)
}

TArray<FName> URuntimeBpLibrary::GetNameArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_STRING_GETTER_SAFE(FName, Name)
}

void URuntimeBpLibrary::SetNameArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FName> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FName, Name)
}

TArray<FString> URuntimeBpLibrary::GetStringArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_STRING_GETTER_SAFE(FString, String)
}

void URuntimeBpLibrary::SetStringArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, const TArray<FString>& Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FString, String)
}

TArray<FText> URuntimeBpLibrary::GetTextArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_STRING_GETTER_SAFE(FText, Text)
}

void URuntimeBpLibrary::SetTextArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FText> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FText, Text)
}

TArray<FVector> URuntimeBpLibrary::GetVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FVector, Vector)
}

void URuntimeBpLibrary::SetVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FVector> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FVector, Vector)
}

TArray<FRotator> URuntimeBpLibrary::GetRotatorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FRotator, Rotator)
}

void URuntimeBpLibrary::SetRotatorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FRotator> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FRotator, Rotator)
}

TArray<FTransform> URuntimeBpLibrary::GetTransformArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FTransform, Transform)
}

void URuntimeBpLibrary::SetTransformArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FTransform> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FTransform, Transform)
}

TArray<FVector2D> URuntimeBpLibrary::GetVector2DArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FVector2D, Vector2D)
}

void URuntimeBpLibrary::SetVector2DArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FVector2D> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FVector2D, Vector2D)
}

TArray<FVector4> URuntimeBpLibrary::GetVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FVector4, Vector4)
}

void URuntimeBpLibrary::SetVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FVector4> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FVector4, Vector4)
}

TArray<FLinearColor> URuntimeBpLibrary::GetLinearColorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FLinearColor, LinearColor)
}

void URuntimeBpLibrary::SetLinearColorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FLinearColor> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FLinearColor, LinearColor)
}

TArray<FIntVector> URuntimeBpLibrary::GetIntVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FIntVector, IntVector)
}

void URuntimeBpLibrary::SetIntVectorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FIntVector> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FIntVector, IntVector)
}


TArray<FIntVector4D> URuntimeBpLibrary::GetIntVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FIntVector4D, IntVector4)
}

void URuntimeBpLibrary::SetIntVector4Arg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<FIntVector4D> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FIntVector4D, IntVector4)
}

TArray<UObject*> URuntimeBpLibrary::GetObjectArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UObject*, Object)
}

void URuntimeBpLibrary::SetObjectArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<class UObject*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UObject*, Object)
}

TArray<UClass*> URuntimeBpLibrary::GetClassArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UClass*, Class)
}

void URuntimeBpLibrary::SetClassArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<class UClass*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UClass*, Class)
}

//~~PYTHON SCRIPT IDENTIFIER~~

TArray<AActor*> URuntimeBpLibrary::GetActorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(AActor*, Actor)
}

void URuntimeBpLibrary::SetActorArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<AActor*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(AActor*, Actor)
}

TArray<USceneComponent*> URuntimeBpLibrary::GetSceneComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(USceneComponent*, SceneComponent)
}

void URuntimeBpLibrary::SetSceneComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<USceneComponent*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(USceneComponent*, SceneComponent)
}

TArray<UPrimitiveComponent*> URuntimeBpLibrary::GetPrimitiveComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UPrimitiveComponent*, PrimitiveComponent)
}

void URuntimeBpLibrary::SetPrimitiveComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UPrimitiveComponent*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UPrimitiveComponent*, PrimitiveComponent)
}

TArray<APlayerController*> URuntimeBpLibrary::GetPlayerControllerArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(APlayerController*, PlayerController)
}

void URuntimeBpLibrary::SetPlayerControllerArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<APlayerController*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(APlayerController*, PlayerController)
}

TArray<ACharacter*> URuntimeBpLibrary::GetCharacterArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(ACharacter*, Character)
}

void URuntimeBpLibrary::SetCharacterArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ACharacter*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(ACharacter*, Character)
}

TArray<APawn*> URuntimeBpLibrary::GetPawnArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(APawn*, Pawn)
}

void URuntimeBpLibrary::SetPawnArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<APawn*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(APawn*, Pawn)
}

TArray<UStaticMeshComponent*> URuntimeBpLibrary::GetStaticMeshComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UStaticMeshComponent*, StaticMeshComponent)
}

void URuntimeBpLibrary::SetStaticMeshComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UStaticMeshComponent*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UStaticMeshComponent*, StaticMeshComponent)
}

TArray<ULightComponent*> URuntimeBpLibrary::GetLightComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(ULightComponent*, LightComponent)
}

void URuntimeBpLibrary::SetLightComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ULightComponent*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(ULightComponent*, LightComponent)
}

TArray<UParticleSystemComponent*> URuntimeBpLibrary::GetParticleSystemComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UParticleSystemComponent*, ParticleSystemComponent)
}

void URuntimeBpLibrary::SetParticleSystemComponentArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UParticleSystemComponent*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UParticleSystemComponent*, ParticleSystemComponent)
}

TArray<UStaticMesh*> URuntimeBpLibrary::GetStaticMeshArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UStaticMesh*, StaticMesh)
}

void URuntimeBpLibrary::SetStaticMeshArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UStaticMesh*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UStaticMesh*, StaticMesh)
}

TArray<UMaterialInterface*> URuntimeBpLibrary::GetMaterialInterfaceArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UMaterialInterface*, MaterialInterface)
}

void URuntimeBpLibrary::SetMaterialInterfaceArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UMaterialInterface*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UMaterialInterface*, MaterialInterface)
}

TArray<UParticleSystem*> URuntimeBpLibrary::GetParticleSystemArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UParticleSystem*, ParticleSystem)
}

void URuntimeBpLibrary::SetParticleSystemArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UParticleSystem*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UParticleSystem*, ParticleSystem)
}

TArray<ARuntimeBpGrenade*> URuntimeBpLibrary::GetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(ARuntimeBpGrenade*, Grenade)
}

void URuntimeBpLibrary::SetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ARuntimeBpGrenade*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(ARuntimeBpGrenade*, Grenade)
}

TArray<UDamageType*> URuntimeBpLibrary::GetDamageTypeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(UDamageType*, DamageType)
}

void URuntimeBpLibrary::SetDamageTypeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<UDamageType*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(UDamageType*, DamageType)
}

TArray<FHitResult> URuntimeBpLibrary::GetHitResultArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(FHitResult, HitResult)
}

void URuntimeBpLibrary::SetHitResultArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, const TArray<FHitResult>& Value)
{
	NODE_VAR_ARG_SETTER_SAFE(FHitResult, HitResult)
}

/*
** End of variable arg functions
*/

FPinStruct URuntimeBpLibrary::GetConnectedPinValue(FPinStruct Pin, class URuntimeBpConstructor* BPConstructor)
{
	if (Pin.ConnectedNodeIndex > -1 && BPConstructor != nullptr)
	{
		URuntimeBpObject* ConnectedNode = BPConstructor->BPNodes[Pin.ConnectedNodeIndex];
		FPinStruct ConnectedPin = ConnectedNode->OutputPins[Pin.ConnectedPinIndex];
		Pin.Value.Array[0] = ConnectedNode->GetConnectedPinValue(ConnectedPin);
		return Pin;
	}

	// If constructor is invalid or node index is -1(which means it's not connected to anything), use the default value of this pin.
	return Pin;
}

int URuntimeBpLibrary::GetValueSubtypeIndex(UPARAM(ref) TArray<FNodeVarArgs>& Values)
{
	if (Values.Num() > 0)
	{
		return Values[0].GetSubtypeIndex();
	}

	return -1;
}
int URuntimeBpLibrary::GetVariableSubtypeIndex(UPARAM(ref) FSaveableVariable & Variable)
{
	if (Variable.v.Num() > 0)
	{
		return Variable.v[0].VariableData.CurrentSubtypeIndex;
	}

	return -1;
}
bool URuntimeBpLibrary::PinValueToVariableValue(UPARAM(ref) FSaveableVariable& Variable, UPARAM(ref) FPinStruct& Pin)
{
	if (Variable.t == Pin.VariableType && (Variable.v.Num() > 0 || Variable.a))
	{
		Variable.v = Pin.Value.Array;
		return true;
	}
	return false;
}
bool URuntimeBpLibrary::VariableValueToPinValue(UPARAM(ref) FSaveableVariable & Variable, UPARAM(ref) FPinStruct & Pin)
{
	if (Variable.t == Pin.VariableType && (Variable.v.Num() > 0 || Variable.a))
	{
		Pin.Value.Array = Variable.v;
		return true;
	}
	return false;
}

FString URuntimeBpLibrary::SaveableValueToJson(FSaveableProperty SaveableValue, EVariableTypes VariableType, int Indent, bool PrettyPrint)
{
	// We make sure that live object references are excluded
	switch (VariableType)
	{
		case EVariableTypes::Object: return FString();
		case EVariableTypes::Actor: return FString();
		case EVariableTypes::PlayerController: return FString();
		case EVariableTypes::Character: return FString();
		case EVariableTypes::Pawn: return FString();
		case EVariableTypes::SceneComponent: return FString();
		case EVariableTypes::PrimitiveComponent: return FString();
		case EVariableTypes::StaticMeshComponent: return FString();
		case EVariableTypes::LightComponent: return FString();
		case EVariableTypes::ParticleSystemComponent: return FString();
		case EVariableTypes::Grenade: return FString();
		case EVariableTypes::DamageType: return FString();
		default: return SaveableValue.ToJson(Indent, PrettyPrint);
	}
}

bool URuntimeBpLibrary::GenericArray_SortCompare(const FProperty* LeftProperty, void* LeftValuePtr, const FProperty* RightProperty, void* RightValuePtr)
{
	bool bResult = false;

	if (const FNumericProperty *LeftNumericProperty = CastField<const FNumericProperty>(LeftProperty))
	{
		if (LeftNumericProperty->IsFloatingPoint())
		{
			bResult = (LeftNumericProperty->GetFloatingPointPropertyValue(LeftValuePtr) < CastField<const FNumericProperty>(RightProperty)->GetFloatingPointPropertyValue(RightValuePtr));
		}
		else if (LeftNumericProperty->IsInteger())
		{
			bResult = (LeftNumericProperty->GetSignedIntPropertyValue(LeftValuePtr) < CastField<const FNumericProperty>(RightProperty)->GetSignedIntPropertyValue(RightValuePtr));
		}
	}
	else if (const FBoolProperty* LeftBoolProperty = CastField<const FBoolProperty>(LeftProperty))
	{
		bResult = (!LeftBoolProperty->GetPropertyValue(LeftValuePtr) && CastField<const FBoolProperty>(RightProperty)->GetPropertyValue(RightValuePtr));
	}
	else if (const FNameProperty* LeftNameProperty = CastField<const FNameProperty>(LeftProperty))
	{
		bResult = (LeftNameProperty->GetPropertyValue(LeftValuePtr).ToString() < CastField<const FNameProperty>(RightProperty)->GetPropertyValue(RightValuePtr).ToString());
	}
	else if (const FStrProperty* LeftStringProperty = CastField<const FStrProperty>(LeftProperty))
	{
		bResult = (LeftStringProperty->GetPropertyValue(LeftValuePtr) < CastField<const FStrProperty>(RightProperty)->GetPropertyValue(RightValuePtr));
	}
	else if (const FTextProperty* LeftTextProperty = CastField<const FTextProperty>(LeftProperty))
	{
		bResult = (LeftTextProperty->GetPropertyValue(LeftValuePtr).ToString() < CastField<const FTextProperty>(RightProperty)->GetPropertyValue(RightValuePtr).ToString());
	}
	return bResult;
}

void URuntimeBpLibrary::GenericArray_Sort(void* TargetArray, const FArrayProperty* ArrayProp, bool bAscendingOrder /* = true */, FName VariableName /* = NAME_None */)
{
	if (TargetArray)
	{
		FScriptArrayHelper ArrayHelper(ArrayProp, TargetArray);
		const int32 LastIndex = ArrayHelper.Num();

		if (const FObjectProperty* ObjectProperty = CastField<const FObjectProperty>(ArrayProp->Inner))
		{
			for (int32 i = 0; i < LastIndex; ++i)
			{
				for (int32 j = 0; j < LastIndex - 1 - i; ++j)
				{
					UObject* LeftObject = ObjectProperty->GetObjectPropertyValue(ArrayHelper.GetRawPtr(j));
					UObject* RightObject = ObjectProperty->GetObjectPropertyValue(ArrayHelper.GetRawPtr(j + 1));

					FProperty* LeftProperty = FindFProperty<FProperty>(LeftObject->GetClass(), VariableName);
					FProperty* RightProperty = FindFProperty<FProperty>(RightObject->GetClass(), VariableName);

					if (LeftProperty && RightProperty)
					{
						void* LeftValuePtr = LeftProperty->ContainerPtrToValuePtr<void>(LeftObject);
						void* RightValuePtr = RightProperty->ContainerPtrToValuePtr<void>(RightObject);

						if (GenericArray_SortCompare(LeftProperty, LeftValuePtr, RightProperty, RightValuePtr) != bAscendingOrder)
						{
							ArrayHelper.SwapValues(j, j + 1);
						}
					}
				}
			}
		}
		else
		{
			FProperty* Property = nullptr;

			if (const FStructProperty* StructProperty = CastField<const FStructProperty>(ArrayProp->Inner))
			{
				Property = FindFProperty<FProperty>(StructProperty->Struct, VariableName);
			}
			else
			{
				Property = ArrayProp->Inner;
			}

			if (Property)
			{
				for (int32 i = 0; i < LastIndex; ++i)
				{
					for (int32 j = 0; j < LastIndex - 1 - i; ++j)
					{
						void* LeftValuePtr = Property->ContainerPtrToValuePtr<void>(ArrayHelper.GetRawPtr(j));
						void* RightValuePtr = Property->ContainerPtrToValuePtr<void>(ArrayHelper.GetRawPtr(j + 1));

						if (GenericArray_SortCompare(Property, LeftValuePtr, Property, RightValuePtr) != bAscendingOrder)
						{
							ArrayHelper.SwapValues(j, j + 1);
						}
					}
				}
			}
		}
	}
}

void URuntimeBpLibrary::Array_Sort(const TArray<int32>& TargetArray, bool bAscendingOrder /* = true */, FName VariableName /* = NAME_None */)
{
	// We should never hit these!  They're stubs to avoid NoExport on the class.  Call the Generic* equivalent instead
	check(0);
}