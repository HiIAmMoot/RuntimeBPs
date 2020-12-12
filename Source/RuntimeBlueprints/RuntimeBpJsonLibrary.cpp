// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeBpJsonLibrary.h"
#include "RuntimeBpMacros.h"
#include "RuntimeBpConstructor.h"
#include "RuntimeBpObject.h"

bool URuntimeBpJsonLibrary::RuntimeBpDataFromJson(const FString& Json, FRuntimeBpJsonFormat& RuntimeBpData)
{
	return FJsonObjectConverter::JsonObjectStringToUStruct<FRuntimeBpJsonFormat>(Json, &RuntimeBpData, 0, 0);
}

FString URuntimeBpJsonLibrary::StructToJson(UProperty* AnyStruct, int Indent, bool PrettyPrint)
{
	return FString{};
}

TArray<TSharedPtr<FJsonValue>> URuntimeBpJsonLibrary::ScriptValueToJsonValue(const TArray<FNodeVarArgs>& Value, EVariableTypes VariableType, bool& Success)
{
	switch (VariableType)
	{
		case EVariableTypes::Bool: SCRIPT_TO_JSON_CASE(FSaveableBoolArray)
		case EVariableTypes::Byte: SCRIPT_TO_JSON_CASE(FSaveableByteArray)
		case EVariableTypes::Int: SCRIPT_TO_JSON_CASE(FSaveableIntArray)
		case EVariableTypes::Float: SCRIPT_TO_JSON_CASE(FSaveableFloatArray)
		case EVariableTypes::Name: SCRIPT_TO_JSON_CASE(FSaveableStringArray)
		case EVariableTypes::String: SCRIPT_TO_JSON_CASE(FSaveableStringArray)
		case EVariableTypes::Text: SCRIPT_TO_JSON_CASE(FSaveableStringArray)
		case EVariableTypes::Vector: SCRIPT_TO_JSON_CASE(FSaveableVectorArray)
		case EVariableTypes::Rotator: SCRIPT_TO_JSON_CASE(FSaveableRotatorArray)
		case EVariableTypes::Transform: SCRIPT_TO_JSON_CASE(FSaveableTransformArray)
		case EVariableTypes::Vector2D: SCRIPT_TO_JSON_CASE(FSaveableVector2DArray)
		case EVariableTypes::Vector4: SCRIPT_TO_JSON_CASE(FSaveableVector4Array)
		case EVariableTypes::LinearColor: SCRIPT_TO_JSON_CASE(FSaveableLinearColorArray)
		case EVariableTypes::IntVector: SCRIPT_TO_JSON_CASE(FSaveableIntVectorArray)
		case EVariableTypes::IntVector4: SCRIPT_TO_JSON_CASE(FSaveableIntVector4Array)
		case EVariableTypes::Class: SCRIPT_TO_JSON_CASE(FSaveableClassArray)
		case EVariableTypes::StaticMesh: SCRIPT_TO_JSON_CASE(FSaveableStaticMeshArray)
		case EVariableTypes::MaterialInterface: SCRIPT_TO_JSON_CASE(FSaveableMaterialInterfaceArray)
		case EVariableTypes::ParticleSystem: SCRIPT_TO_JSON_CASE(FSaveableParticleSystemArray)
		case EVariableTypes::HitResult: SCRIPT_TO_JSON_CASE(FSaveableHitResultArray)
		default: break;
	}
	return TArray<TSharedPtr<FJsonValue>>();
}

bool URuntimeBpJsonLibrary::ScriptToJsonObject(const FRuntimeBpJsonFormat& Script, TSharedRef<FJsonObject> JsonObject)
{
	// Start by defining the field names
	FString NodeArrayFieldName = "nodes";
	FString VariableArrayFieldName = "variables";
	FString FunctionArrayFieldName = "functions";
	FString LocalVariableFieldName = "v";
	FString FunctionNodeFieldName = "n";
	FString InputPinFieldName = "i";
	FString ValueFieldName = "v";

	// Turn the runtime script into a saveable script with only saved data and shortened names
	FSaveableBPJsonFormat SaveableScript = FSaveableBPJsonFormat(Script);

	if (FJsonObjectConverter::UStructToJsonObject(FSaveableBPJsonFormat::StaticStruct(), &SaveableScript, JsonObject, 0, 0))
	{
		// We set the union values manually because it doesn't happen automatically
		// We get the array which contains the nodes and loop through
		const TArray<TSharedPtr<FJsonValue>>* NodeArray;
		if (JsonObject->TryGetArrayField(NodeArrayFieldName, NodeArray))
		{
			// Nodes
			int NodeIndex = 0;
			for (TSharedPtr<FJsonValue> Node : *NodeArray)
			{
				// We now have the node, we must get the input pin array now
				const TSharedPtr<FJsonObject>* NodeObject;
				const TArray<TSharedPtr<FJsonValue>>* InputArray;
				if (Node->TryGetObject(NodeObject) && NodeObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
				{
					// We should have the input pins now
					int InputIndex = 0;
					for (TSharedPtr<FJsonValue> Input : *InputArray)
					{
						const TSharedPtr<FJsonObject>* InputObject;
						// We should be in the Input pin struct now and can set the value
						if (Input->TryGetObject(InputObject))
						{
							FPinStruct Pin = Script.Nodes[NodeIndex].InputPins[InputIndex];
							TArray<TSharedPtr<FJsonValue>> ArrayField = TArray<TSharedPtr<FJsonValue>>();
							bool Success = true;
							if (!Pin.Array)
							{
								ArrayField = ScriptValueToJsonValue(Pin.Value.Array, Pin.VariableType, Success);
							}
							InputObject->Get()->SetArrayField(ValueFieldName, ArrayField);
						}
						InputIndex++;
					}
				}
				NodeIndex++;
			}
		}

		// Variables
		const TArray<TSharedPtr<FJsonValue>>* VariableArray;
		if (JsonObject->TryGetArrayField(VariableArrayFieldName, VariableArray))
		{
			// Loop through each variable
			int VariableIndex = 0;
			for (TSharedPtr<FJsonValue> Variable : *VariableArray)
			{
				// We now have the variable, we must get the values now
				const TSharedPtr<FJsonObject>* VariableObject;
				if (Variable->TryGetObject(VariableObject))
				{
					FSaveableVariable SaveableVariable = Script.Variables[VariableIndex];
					bool Success = false;
					TArray<TSharedPtr<FJsonValue>> ArrayField = ScriptValueToJsonValue(SaveableVariable.v, SaveableVariable.t, Success);
					VariableObject->Get()->SetArrayField(ValueFieldName, ArrayField);
				}
				VariableIndex++;
			}
		}

		// Functions
		const TArray<TSharedPtr<FJsonValue>>* FunctionArray;
		if (JsonObject->TryGetArrayField(FunctionArrayFieldName, FunctionArray))
		{
			int FunctionIndex = 0;
			for (TSharedPtr<FJsonValue> Function : *FunctionArray)
			{
				// Function nodes
				const TSharedPtr<FJsonObject>* FunctionObject;
				const TArray<TSharedPtr<FJsonValue>>* FunctionNodeArray;
				if (Function->TryGetObject(FunctionObject) && FunctionObject->Get()->TryGetArrayField(FunctionNodeFieldName, FunctionNodeArray))
				{
					int NodeIndex = 0;
					for (TSharedPtr<FJsonValue> Node : *FunctionNodeArray)
					{
						// We now have the node, we must get the input pin array now
						const TSharedPtr<FJsonObject>* NodeObject;
						const TArray<TSharedPtr<FJsonValue>>* InputArray;
						if (Node->TryGetObject(NodeObject) && NodeObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
						{
							// We should have the input pins now
							int InputIndex = 0;
							for (TSharedPtr<FJsonValue> Input : *InputArray)
							{
								const TSharedPtr<FJsonObject>* InputObject;
								// We should be in the Input pin struct now and can set the value
								if (Input->TryGetObject(InputObject))
								{
									FPinStruct Pin = Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins[InputIndex];
									TArray<TSharedPtr<FJsonValue>> ArrayField = TArray<TSharedPtr<FJsonValue>>();
									bool Success = true;
									if (!Pin.Array)
									{
										ArrayField = ScriptValueToJsonValue(Pin.Value.Array, Pin.VariableType, Success);
									}
									InputObject->Get()->SetArrayField(ValueFieldName, ArrayField);
								}
								InputIndex++;
							}
						}
						NodeIndex++;
					}
				}

				// Local variables
				VariableArray = nullptr; 
				if (FunctionObject->Get()->TryGetArrayField(LocalVariableFieldName, VariableArray))
				{
					// Loop through each variable
					int VariableIndex = 0;
					for (TSharedPtr<FJsonValue> Variable : *VariableArray)
					{
						// We now have the variable, we must get the values now
						const TSharedPtr<FJsonObject>* VariableObject;
						if (Variable->TryGetObject(VariableObject))
						{
							FSaveableLocalVariable SaveableVariable = Script.Functions[FunctionIndex].LocalVariables[VariableIndex];
							bool Success = false;
							TArray<TSharedPtr<FJsonValue>> ArrayField = ScriptValueToJsonValue(SaveableVariable.v, SaveableVariable.t, Success);
							VariableObject->Get()->SetArrayField(ValueFieldName, ArrayField);
						}
						VariableIndex++;
					}
				}

				// Function inputs
				const TArray<TSharedPtr<FJsonValue>>* InputArray;
				if (FunctionObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
				{
					int InputIndex = 0;
					for (TSharedPtr<FJsonValue> Input : *InputArray)
					{
						const TSharedPtr<FJsonObject>* InputObject;
						// We should be in the Input pin struct now and can set the value
						if (Input->TryGetObject(InputObject))
						{
							FPinStruct Pin = Script.Functions[FunctionIndex].InputPins[InputIndex];
							TArray<TSharedPtr<FJsonValue>> ArrayField = TArray<TSharedPtr<FJsonValue>>();
							bool Success = true;
							if (!Pin.Array)
							{
								ArrayField = ScriptValueToJsonValue(Pin.Value.Array, Pin.VariableType, Success);
							}
							InputObject->Get()->SetArrayField(ValueFieldName, ArrayField);
						}
						InputIndex++;
					}
				}
				FunctionIndex++;
			}
		}

		return true;
	}
	return false;
}

template<class CharType, class PrintPolicy>
bool JsonObjectToStringInternal(const TSharedRef<FJsonObject>& JsonObject, FString& OutJsonString, int32 Indent)
{
	TSharedRef<TJsonWriter<CharType, PrintPolicy> > JsonWriter = TJsonWriterFactory<CharType, PrintPolicy>::Create(&OutJsonString, Indent);
	bool bSuccess = FJsonSerializer::Serialize(JsonObject, JsonWriter);
	JsonWriter->Close();
	return bSuccess;
}

bool URuntimeBpJsonLibrary::ScriptToJsonString(const FRuntimeBpJsonFormat& Script, FString& JsonString, bool PrettyPrint, int Indent)
{
	TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	if (ScriptToJsonObject(Script, JsonObject))
	{
		bool Success = false;
		if (PrettyPrint)
		{
			Success = JsonObjectToStringInternal<TCHAR, TPrettyJsonPrintPolicy<TCHAR>>(JsonObject, JsonString, Indent);
		}
		else
		{
			Success = JsonObjectToStringInternal<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>(JsonObject, JsonString, Indent);
		}
		return Success;
	}
	return false;
}

void URuntimeBpJsonLibrary::UpdateRuntimeScriptNodeDefaults(FRuntimeBpJsonFormat& Script, FSaveableBPJsonFormat& SaveableScript, TArray<FNodeStruct>& RuntimeNodes, TArray<FSaveableNode>& SaveableNodes, const FString& ThisScriptName, const TMap<FIntPoint, FString>& FunctionReferences, int Index = -1)
{
	int NodeIndex = 0;
	for (FSaveableNode& Node : SaveableNodes)
	{
		URuntimeBpObject* DefaultObject = Cast<URuntimeBpObject>(Node.n->GetDefaultObject(true));

		if (DefaultObject)
		{	
			switch (DefaultObject->NodeType)
			{
				case ENodeType::CustomFunction:
				{
					// The Function Index is stored inside the Exec input's node index. So we get that first.
					// The custom function pins are used to define this node's input and output pins.
					int FunctionIndex = Node.i[0].n;
					FSaveableFunction Function = SaveableScript.Functions[FunctionIndex];

					RuntimeNodes[NodeIndex].InputPins.SetNum(Function.i.Num());
					int PinIndex = 0;
					for (FPinStruct& InputPin : RuntimeNodes[NodeIndex].InputPins)
					{
						Function.i[PinIndex].ToScriptTypeOnly(InputPin);
						PinIndex++;
					}

					// Save the function index in the first exec input pin because it is -1 by default.
					// This is needed for the function call nodes to know which custom function to call.
					RuntimeNodes[NodeIndex].InputPins[0].ConnectedNodeIndex = FunctionIndex;

					RuntimeNodes[NodeIndex].OutputPins.SetNum(Function.o.Num());
					PinIndex = 0;
					for (FPinStruct& OutputPin : RuntimeNodes[NodeIndex].OutputPins)
					{
						Function.o[PinIndex].ToScriptTypeOnly(OutputPin);
						PinIndex++;
					}

					NodeIndex++;
					continue;
					break;
				}
				case ENodeType::FunctionEnd:
				{
					FSaveableFunction Function = SaveableScript.Functions[Index];
					RuntimeNodes[NodeIndex].InputPins.SetNum(Function.o.Num());
					
					int PinIndex = 0;
					for (FPinStruct& InputPin : RuntimeNodes[NodeIndex].InputPins)
					{
						Node.i[PinIndex].ToScript(InputPin);
						Function.o[PinIndex].ToScriptTypeOnly(InputPin);
						InputPin.Input = true;
						PinIndex++;
					}
					NodeIndex++;
					continue;
					break;
				}
			}

			// We don't overwrite the custom function input and output lengths because right now we can't easily get the needed info to init this properly
			switch (DefaultObject->NodeType)
			{
				case ENodeType::ExternalFunction:
				{
					// Reference index is stored inside the Exec input's node index. So we get that first.
					int ReferenceIndex = Node.i[0].n;
					if (SaveableScript.References.IsValidIndex(ReferenceIndex))
					{
						FRuntimeBpJsonFormat RuntimeBpJson;
						FString ScriptName = SaveableScript.References[ReferenceIndex];
						bool UpdatePins = false;
						if (ThisScriptName == ScriptName)
						{
							UpdatePins = true;
							RuntimeBpJson = Script;
						}
						else
						{
							UpdatePins = URuntimeBpConstructor::FindLoadedScript(ScriptName, RuntimeBpJson, true);
						}

						auto FoundPair = FunctionReferences.Find(FIntPoint(Index, NodeIndex));
						if (UpdatePins && FoundPair)
						{
							FString FunctionName = *FoundPair;
							int FunctionCallIndex = -1;
							int i = 0;
							for (FRuntimeFunction& Function : RuntimeBpJson.Functions)
							{
								if (FunctionName == Function.FunctionName)
								{
									//UE_LOG(LogJson, Warning, TEXT("Function found: %s"), *FunctionName);
									FunctionCallIndex = i;
									break;
								}
								i++;
							}

							if (FunctionCallIndex != -1)
							{
								FRuntimeFunction& Function = RuntimeBpJson.Functions[FunctionCallIndex];

								RuntimeNodes[NodeIndex].InputPins.SetNum(Function.InputPins.Num() + 3); // External function calls have 4 function inputs by default, but it's 1 less because the function itself has an exec pin
								int PinIndex = 3; // We start 1 index early to skip the Exec of the referenced function
								for (FPinStruct& FunctionPin : Function.InputPins)
								{
									if (PinIndex < 4)
									{
										PinIndex++;
										continue;
									}
									//UE_LOG(LogJson, Warning, TEXT("Input PinName: %s"), *FunctionPin.PinName);

									int ConnectedNodeIndex = RuntimeNodes[NodeIndex].InputPins[PinIndex].ConnectedNodeIndex;
									int ConnectedPinIndex = RuntimeNodes[NodeIndex].InputPins[PinIndex].ConnectedPinIndex;
									ENodeType ConnectPinType = RuntimeNodes[NodeIndex].InputPins[PinIndex].ConnectPinType;

									RuntimeNodes[NodeIndex].InputPins[PinIndex] = FunctionPin;
									RuntimeNodes[NodeIndex].InputPins[PinIndex].ConnectedNodeIndex = ConnectedNodeIndex;
									RuntimeNodes[NodeIndex].InputPins[PinIndex].ConnectedPinIndex = ConnectedPinIndex;
									RuntimeNodes[NodeIndex].InputPins[PinIndex].ConnectPinType = ConnectPinType;
									PinIndex++;
								}

								RuntimeNodes[NodeIndex].OutputPins.SetNum(Function.OutputPins.Num() + 1); // External function calls have 2 function outputs by default, but it's 1 less because the function itself has an exec pin
								PinIndex = 1; // We start 1 index early to skip the Exec
								for (FPinStruct& FunctionPin : Function.OutputPins)
								{
									if (PinIndex < 2)
									{
										PinIndex++;
										continue;
									}
									//UE_LOG(LogJson, Warning, TEXT("Output PinName: %s"), *FunctionPin.PinName);

									int ConnectedNodeIndex = RuntimeNodes[NodeIndex].OutputPins[PinIndex].ConnectedNodeIndex;
									int ConnectedPinIndex = RuntimeNodes[NodeIndex].OutputPins[PinIndex].ConnectedPinIndex;
									ENodeType ConnectPinType = RuntimeNodes[NodeIndex].OutputPins[PinIndex].ConnectPinType;

									RuntimeNodes[NodeIndex].OutputPins[PinIndex] = FunctionPin;
									RuntimeNodes[NodeIndex].OutputPins[PinIndex].ConnectedNodeIndex = ConnectedNodeIndex;
									RuntimeNodes[NodeIndex].OutputPins[PinIndex].ConnectedPinIndex = ConnectedPinIndex;
									RuntimeNodes[NodeIndex].OutputPins[PinIndex].ConnectPinType = ConnectPinType;
									PinIndex++;
								}

								//NodeIndex++;
								//continue;
								break;
							}
						}
					}
					// If node is somehow invalid we continue as if it's a normal node
				}
				default:
				{
					if (!DefaultObject->DynamicInput && DefaultObject->InputPins.Num() != 0)
					{
						RuntimeNodes[NodeIndex].InputPins.SetNum(DefaultObject->InputPins.Num());
					}

					if (!DefaultObject->DynamicOutput && DefaultObject->OutputPins.Num() != 0)
					{
						RuntimeNodes[NodeIndex].OutputPins.SetNum(DefaultObject->OutputPins.Num());
					}
					break;
				}
			}

			int PinIndex = 0;
			int PinLength = DefaultObject->InputPins.Num();
			for (FPinStruct& InputPin : RuntimeNodes[NodeIndex].InputPins)
			{
				int UsedIndex;

				if (PinIndex < PinLength)
				{
					UsedIndex = PinIndex;
				}
				else
				{
					switch (DefaultObject->NodeType)
					{
						case ENodeType::ExternalFunction:
						{
							PinIndex++;
							continue;
							break;
						}
						default:
						{
							UsedIndex = PinLength - 1;
						}
					}
				}

				InputPin.PinName = DefaultObject->InputPins[UsedIndex].PinName;
				InputPin.ConnectPinType = DefaultObject->InputPins[UsedIndex].ConnectPinType;
				InputPin.Array = DefaultObject->InputPins[UsedIndex].Array;
				InputPin.Meta = DefaultObject->InputPins[UsedIndex].Meta;
				InputPin.Input = true;

				// We need to exclude variable pins and give them a proper variable type based on the variable itself, because the default type is a bool.
				// Not doing this will reset any SET node with no connected input to the default value and thus loses the original set value.
				switch (DefaultObject->NodeType)
				{
					case ENodeType::VariableSetter:
					{
						// First pin is the exec pin so skip that
						if (UsedIndex > 0)
						{
							// Get the variable type from the variable, the index of the variable is stored in the output variable pin index
							InputPin.VariableType = SaveableScript.Variables[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
							InputPin.PinName = SaveableScript.Variables[SaveableNodes[NodeIndex].o[UsedIndex].p].n;
						}
						else
						{
							InputPin.VariableType = DefaultObject->InputPins[UsedIndex].VariableType;
						}
						break;
					}
					case ENodeType::LocalVariableSetter:
					{
						// First pin is the exec pin so skip that
						if (UsedIndex > 0)
						{
							// Get the variable type from the variable, the index of the variable is stored in the output variable pin index
							InputPin.VariableType = SaveableScript.Functions[Index].v[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
							InputPin.PinName = SaveableScript.Functions[Index].v[SaveableNodes[NodeIndex].o[UsedIndex].p].n;
						}
						else
						{
							InputPin.VariableType = DefaultObject->InputPins[UsedIndex].VariableType;
						}
						break;
					}
					default:
					{
						// Wildcards have their used variable type stored in the pin index, however only when the pin isn't connected (node index = -1)
						// The index stored in the pin index is the enum index from EVariableTypes
						// We use PinIndex instead of UsedIndex here because we're not dealing with DefaultObject
						if (SaveableNodes[NodeIndex].i.IsValidIndex(PinIndex) && SaveableNodes[NodeIndex].i[PinIndex].p > -1 && SaveableNodes[NodeIndex].i[PinIndex].n == -1)
						{
							EVariableTypes WildCardType = static_cast<EVariableTypes>(SaveableNodes[NodeIndex].i[PinIndex].p);
							InputPin.VariableType = WildCardType;
							SaveableNodes[NodeIndex].i[PinIndex].p = -1;
							InputPin.ConnectedPinIndex = -1;
						}
						else
						{
							InputPin.VariableType = DefaultObject->InputPins[UsedIndex].VariableType;
						}
						break;
					}
				}

				PinIndex++;
			}

			PinIndex = 0;
			PinLength = DefaultObject->OutputPins.Num();
			for (FPinStruct& OutputPin : RuntimeNodes[NodeIndex].OutputPins)
			{
				int UsedIndex = 0;

				if (PinIndex < PinLength)
				{
					UsedIndex = PinIndex;
				}
				else
				{
					switch (DefaultObject->NodeType)
					{
						case ENodeType::ExternalFunction:
						{
							PinIndex++;
							continue;
							break;
						}
						default:
						{
							UsedIndex = PinLength - 1;
						}
					}
				}

				OutputPin.PinName = DefaultObject->OutputPins[UsedIndex].PinName;
				OutputPin.ConnectPinType = DefaultObject->OutputPins[UsedIndex].ConnectPinType;
				OutputPin.Array = DefaultObject->OutputPins[UsedIndex].Array;
				OutputPin.Meta = DefaultObject->OutputPins[UsedIndex].Meta;

				switch (DefaultObject->NodeType)
				{
					case ENodeType::VariableGetter:
					{
						OutputPin.VariableType = SaveableScript.Variables[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
						OutputPin.PinName = SaveableScript.Variables[SaveableNodes[NodeIndex].o[UsedIndex].p].n;
						break;
					}
					case ENodeType::VariableSetter:
					{
						// First pin is the exec pin so skip that
						if (UsedIndex > 0)
						{
							// Get the variable type from the variable, the index of the variable is stored in the output variable pin index
							OutputPin.VariableType = SaveableScript.Variables[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
							OutputPin.PinName = SaveableScript.Variables[SaveableNodes[NodeIndex].o[UsedIndex].p].n;
						}
						else
						{
							OutputPin.VariableType = DefaultObject->InputPins[UsedIndex].VariableType;
						}
						break;
					}
					case ENodeType::LocalVariableGetter:
					{
						OutputPin.VariableType = SaveableScript.Functions[Index].v[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
						OutputPin.PinName = SaveableScript.Functions[Index].v[SaveableNodes[NodeIndex].o[UsedIndex].p].n;
						break;
					}
					case ENodeType::LocalVariableSetter:
					{
						// First pin is the exec pin so skip that
						if (UsedIndex > 0)
						{
							// Get the variable type from the variable, the index of the variable is stored in the output variable pin index
							OutputPin.VariableType = SaveableScript.Functions[Index].v[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
							OutputPin.PinName = SaveableScript.Functions[Index].v[SaveableNodes[NodeIndex].o[UsedIndex].p].n;
						}
						else
						{
							OutputPin.VariableType = DefaultObject->InputPins[UsedIndex].VariableType;
						}
						break;
					}
					default:
					{
						OutputPin.VariableType = DefaultObject->OutputPins[UsedIndex].VariableType;
						break;
					}
				}
				PinIndex++;
			}
		}
		NodeIndex++;
	}
}


TArray<FNodeVarArgs> URuntimeBpJsonLibrary::JsonValueToScriptValue(TArray<TSharedPtr<FJsonValue>> Value, EVariableTypes VariableType, bool Array, bool& Success)
{

	switch (VariableType)
	{
		case EVariableTypes::Bool: JSON_TO_SCRIPT_CASE(FSaveableBoolArray)
		case EVariableTypes::Byte: JSON_TO_SCRIPT_CASE(FSaveableByteArray)
		case EVariableTypes::Int: JSON_TO_SCRIPT_CASE(FSaveableIntArray)
		case EVariableTypes::Float: JSON_TO_SCRIPT_CASE(FSaveableFloatArray)
		case EVariableTypes::Name: JSON_TO_SCRIPT_CASE(FSaveableStringArray)
		case EVariableTypes::String: JSON_TO_SCRIPT_CASE(FSaveableStringArray)
		case EVariableTypes::Text: JSON_TO_SCRIPT_CASE(FSaveableStringArray)
		case EVariableTypes::Vector: JSON_TO_SCRIPT_CASE(FSaveableVectorArray)
		case EVariableTypes::Rotator: JSON_TO_SCRIPT_CASE(FSaveableRotatorArray)
		case EVariableTypes::Transform: JSON_TO_SCRIPT_CASE(FSaveableTransformArray)
		case EVariableTypes::Vector2D: JSON_TO_SCRIPT_CASE(FSaveableVector2DArray)
		case EVariableTypes::Vector4: JSON_TO_SCRIPT_CASE(FSaveableVector4Array)
		case EVariableTypes::LinearColor: JSON_TO_SCRIPT_CASE(FSaveableLinearColorArray)
		case EVariableTypes::IntVector: JSON_TO_SCRIPT_CASE(FSaveableIntVectorArray)
		case EVariableTypes::IntVector4: JSON_TO_SCRIPT_CASE(FSaveableIntVector4Array)
		case EVariableTypes::Class: JSON_TO_SCRIPT_CASE(FSaveableClassArray)
		case EVariableTypes::StaticMesh: JSON_TO_SCRIPT_CASE(FSaveableStaticMeshArray)
		case EVariableTypes::MaterialInterface: JSON_TO_SCRIPT_CASE(FSaveableMaterialInterfaceArray)
		case EVariableTypes::ParticleSystem: JSON_TO_SCRIPT_CASE(FSaveableParticleSystemArray)
		case EVariableTypes::HitResult: JSON_TO_SCRIPT_CASE(FSaveableHitResultArray)
		default: break;
	}
	
	TArray<FNodeVarArgs> NodeVarArgs = TArray<FNodeVarArgs>();

	if (Array)
	{
		return NodeVarArgs;
	}

	NodeVarArgs.Add(FNodeVarArgs(VariableType));
	return NodeVarArgs;
}

bool URuntimeBpJsonLibrary::JsonStringToScript(const FString& JsonString, FRuntimeBpJsonFormat& Script, const FString& ThisScriptName, bool LoadExternals = false)
{
	// Start by defining the field names
	FString NodeArrayFieldName = "nodes";
	FString VariableArrayFieldName = "variables";
	FString FunctionArrayFieldName = "functions";
	FString LocalVariableFieldName = "v";
	FString FunctionNodeFieldName = "n";
	FString InputPinFieldName = "i";
	FString ValueFieldName = "v";

	// Make a saveable script struct to load the Json data into
	FSaveableBPJsonFormat SaveableScript;

	TSharedPtr<FJsonObject> PurgedJsonObject;
	TSharedRef<TJsonReader<>> PurgedJsonReader = TJsonReaderFactory<>::Create(JsonString);
	FJsonSerializer::Deserialize(PurgedJsonReader, PurgedJsonObject);
	if (!PurgedJsonObject.IsValid())
	{
		UE_LOG(LogJson, Warning, TEXT("1. JsonObjectStringToUStruct - Unable to parse json"));
		return false;
	}

	// We need to empty the values of the Json objects so we can properly turn it into a struct
	// We also need to make a copy of function references in case external function calls are used, these are the values of the second input pin of the node
	// X of intpoint is the function index of the placed node (-1 if in main graph), Y of the intpoint is the NodeIndex, the string is the functionname
	TMap<FIntPoint, FString> FunctionReferences = TMap<FIntPoint, FString>();

	// We get the array which contains the nodes and loop through
	const TArray<TSharedPtr<FJsonValue>>* NodeArray;
	if (PurgedJsonObject->TryGetArrayField(NodeArrayFieldName, NodeArray))
	{
		int NodeIndex = 0;
		for (TSharedPtr<FJsonValue> Node : *NodeArray)
		{
			// We now have the node, we must get the input pin array now
			const TSharedPtr<FJsonObject>* NodeObject;
			const TArray<TSharedPtr<FJsonValue>>* InputArray;
			if (Node->TryGetObject(NodeObject))
			{
				// We get external references at this stage before the values are cleared. This is because we'll need them when the defaults are updated.
				bool ExternalFunctionCall = false;
				FString FunctionName;
				if (NodeObject->Get()->TryGetStringField(FunctionNodeFieldName, FunctionName) && FunctionName.Contains("CallFunctionFromScript"))
				{
					ExternalFunctionCall = true;
				}

				if (NodeObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
				{

					int InputIndex = 0;
					// We should have the input pins now
					for (TSharedPtr<FJsonValue> Input : *InputArray)
					{
						// UE_LOG(LogJson, Verbose, TEXT("--- Purge ---"));
						// UE_LOG(LogJson, Verbose, TEXT("NodeIndex: %s"), *FString::FromInt(NodeIndex));
						// UE_LOG(LogJson, Verbose, TEXT("InputIndex: %s"), *FString::FromInt(InputIndex));
						const TSharedPtr<FJsonObject>* InputObject;
						const TArray<TSharedPtr<FJsonValue>> ValueArray = TArray<TSharedPtr<FJsonValue>>();
						// We should be in the Input pin struct now and can set the value
						if (Input->TryGetObject(InputObject))
						{
							if (ExternalFunctionCall && InputIndex == 1)
							{
								FString FunctionRef = "";
								if (InputObject->Get()->GetArrayField(ValueFieldName).Num() > 0 && InputObject->Get()->GetArrayField(ValueFieldName)[0]->TryGetString(FunctionRef))
								{
									FunctionReferences.Add(FIntPoint(-1, NodeIndex), FunctionRef);
								}
							}

							/*const TArray<TSharedPtr<FJsonValue>>* ScriptPathArray;
							if (ExternalFunctionCall && InputIndex == 1, InputObject->Get()->TryGetArrayField(ValueFieldName, ScriptPathArray))
							{
								for (TSharedPtr<FJsonValue> ScriptPath : *ScriptPathArray)
								{
									FString ScriptPathValue;
									if (ScriptPath->TryGetString(ScriptPathValue))
									{
										UE_LOG(LogJson, Warning, TEXT("Script path: %s"), *ScriptPathValue);
									}
								}
							}*/

							InputObject->Get()->SetArrayField(ValueFieldName, ValueArray);
						}
						InputIndex++;
					}
				}
			}
			NodeIndex++;
		}
	}

	// Do the same for variables
	const TArray<TSharedPtr<FJsonValue>>* VariableArray;
	if (PurgedJsonObject->TryGetArrayField(VariableArrayFieldName, VariableArray))
	{
		// Loop through each variable
		for (TSharedPtr<FJsonValue> Variable : *VariableArray)
		{
			// We now have the variable, we must get the values now
			const TSharedPtr<FJsonObject>* VariableObject;
			const TArray<TSharedPtr<FJsonValue>> ValueArray = TArray<TSharedPtr<FJsonValue>>();
			if (Variable->TryGetObject(VariableObject))
			{
				VariableObject->Get()->SetArrayField(ValueFieldName, ValueArray);
			}
		}
	}

	// Functions
	const TArray<TSharedPtr<FJsonValue>>* FunctionArray;
	if (PurgedJsonObject->TryGetArrayField(FunctionArrayFieldName, FunctionArray))
	{
		int FunctionIndex = 0;
		for (TSharedPtr<FJsonValue> Function : *FunctionArray)
		{
			// Function nodes
			const TSharedPtr<FJsonObject>* FunctionObject;
			const TArray<TSharedPtr<FJsonValue>>* FunctionNodeArray;
			if (Function->TryGetObject(FunctionObject) && FunctionObject->Get()->TryGetArrayField(FunctionNodeFieldName, FunctionNodeArray))
			{
				int NodeIndex = 0;
				for (TSharedPtr<FJsonValue> Node : *FunctionNodeArray)
				{
					// We now have the node, we must get the input pin array now
					const TSharedPtr<FJsonObject>* NodeObject;
					const TArray<TSharedPtr<FJsonValue>>* InputArray;
					if (Node->TryGetObject(NodeObject) && NodeObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
					{
						// We get external references at this stage before the values are cleared. This is because we'll need them when the defaults are updated.
						bool ExternalFunctionCall = false;
						FString FunctionName;
						if (NodeObject->Get()->TryGetStringField(FunctionNodeFieldName, FunctionName) && FunctionName.Contains("CallFunctionFromScript"))
						{
							ExternalFunctionCall = true;
						}

						int InputIndex = 0;
						// We should have the input pins now
						for (TSharedPtr<FJsonValue> Input : *InputArray)
						{
							const TSharedPtr<FJsonObject>* InputObject;
							const TArray<TSharedPtr<FJsonValue>> ValueArray = TArray<TSharedPtr<FJsonValue>>();
							// We should be in the Input pin struct now and can set the value
							if (Input->TryGetObject(InputObject))
							{
								// Store function ref values for later use
								if (ExternalFunctionCall && InputIndex == 1)
								{
									FString FunctionRef = "";
									if (InputObject->Get()->GetArrayField(ValueFieldName).Num() > 0 && InputObject->Get()->GetArrayField(ValueFieldName)[0]->TryGetString(FunctionRef))
									{
										FunctionReferences.Add(FIntPoint(FunctionIndex, NodeIndex), FunctionRef);
									}
								}

								InputObject->Get()->SetArrayField(ValueFieldName, ValueArray);
							}
							InputIndex++;
						}
					}
					NodeIndex++;
				}
			}

			// Local variables
			VariableArray = nullptr;
			if (FunctionObject->Get()->TryGetArrayField(LocalVariableFieldName, VariableArray))
			{
				// Loop through each variable
				int VariableIndex = 0;
				for (TSharedPtr<FJsonValue> Variable : *VariableArray)
				{
					// We now have the variable, we must get the values now
					const TSharedPtr<FJsonObject>* VariableObject;
					const TArray<TSharedPtr<FJsonValue>> ValueArray = TArray<TSharedPtr<FJsonValue>>();
					if (Variable->TryGetObject(VariableObject))
					{
						VariableObject->Get()->SetArrayField(ValueFieldName, ValueArray);
					}
					VariableIndex++;
				}
			}

			// Function inputs
			const TArray<TSharedPtr<FJsonValue>>* InputArray;
			if (FunctionObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
			{
				int InputIndex = 0;
				for (TSharedPtr<FJsonValue> Input : *InputArray)
				{
					const TSharedPtr<FJsonObject>* InputObject;
					const TArray<TSharedPtr<FJsonValue>> ValueArray = TArray<TSharedPtr<FJsonValue>>();
					// We should be in the Input pin struct now and can set the value
					if (Input->TryGetObject(InputObject))
					{
						InputObject->Get()->SetArrayField(ValueFieldName, ValueArray);
					}
					InputIndex++;
				}
			}

			FunctionIndex++;
		}
	}

	// Now that the values are emptied, we can turn the object into a struct
	if (!FJsonObjectConverter::JsonObjectToUStruct(PurgedJsonObject.ToSharedRef(), &SaveableScript, 0, 0))
	{
		UE_LOG(LogJson, Warning, TEXT("2. JsonObjectStringToUStruct - Unable to deserialize"));
		return false;
	}

	// The saveable script is populated but with empty values, we can turn it into a runtime script now
	SaveableScript.ToScript(Script);

	// We still need to update the runtime script with some class default values however
	UpdateRuntimeScriptNodeDefaults(Script, SaveableScript, Script.Nodes, SaveableScript.Nodes, ThisScriptName, FunctionReferences);

	// And do the same for nodes nested in functions
	for (int i = 0; i < SaveableScript.Functions.Num(); i++)
	{
		UpdateRuntimeScriptNodeDefaults(Script, SaveableScript, Script.Functions[i].Nodes, SaveableScript.Functions[i].n, ThisScriptName, FunctionReferences, i);
	}

	// We deserialize the json string again to the json object to restore the values to the object
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
	FJsonSerializer::Deserialize(JsonReader, JsonObject);
	if (!JsonObject.IsValid())
	{
		UE_LOG(LogJson, Warning, TEXT("3. JsonObjectStringToUStruct - Unable to parse json"));
		return false;
	}

	//TMap<FString, TArray<FRuntimeFunction>> 

	// We now have to restore the struct values, looping the same way we did when emptying the values.
	// We get the array which contains the nodes and loop through
	if (JsonObject->TryGetArrayField(NodeArrayFieldName, NodeArray))
	{
		int NodeIndex = 0;
		for (TSharedPtr<FJsonValue> Node : *NodeArray)
		{
			// Get the NodeType to check for external function calls
			//ENodeType NodeType = Cast<URuntimeBpObject>(Script.Nodes[NodeIndex].NodeClass->GetDefaultObject(true))->NodeType;
			// We now have the node, we must get the input pin array now
			const TSharedPtr<FJsonObject>* NodeObject;
			const TArray<TSharedPtr<FJsonValue>>* InputArray;
			if (Node->TryGetObject(NodeObject) && NodeObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
			{
				// We should have the input pins now
				int InputIndex = 0;
				for (TSharedPtr<FJsonValue> Input : *InputArray)
				{
					const TSharedPtr<FJsonObject>* InputObject;
					const TArray<TSharedPtr<FJsonValue>>* ValueArray;
					bool Success = false;
					// We should be in the Input pin struct now and can set the value
					if (Input->TryGetObject(InputObject) && InputObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
					{
						auto& InputPin = Script.Nodes[NodeIndex].InputPins[InputIndex];
						EVariableTypes VariableType = InputPin.VariableType;
						bool Array = InputPin.Array;
						InputPin.Value = JsonValueToScriptValue(*ValueArray, VariableType, Array, Success);
					}
					InputIndex++;
				}

				// If for whatever reason there are more pins than saved values, for example when a node changes its default inputs
				for (int i = InputIndex; i < Script.Nodes[NodeIndex].InputPins.Num(); i++)
				{
					auto& InputPin = Script.Nodes[NodeIndex].InputPins[i];
					if (!InputPin.Array)
					{
						InputPin.Value.Array.SetNum(1);
						InputPin.Value.Array[0] = FNodeVarArgs(InputPin.VariableType);
					}
				}
			}
			NodeIndex++;
		}

		// Do the same for variables
		if (JsonObject->TryGetArrayField(VariableArrayFieldName, VariableArray))
		{
			// Loop through each variable
			int VariableIndex = 0;
			for (TSharedPtr<FJsonValue> Variable : *VariableArray)
			{
				// We now have the variable, we can set the value now
				const TSharedPtr<FJsonObject>* VariableObject;
				const TArray<TSharedPtr<FJsonValue>>* ValueArray;
				// UE_LOG(LogJson, Warning, TEXT("VariableIndex: %s"), *FString::FromInt(VariableIndex));
				bool Success = false;
				if (Variable->TryGetObject(VariableObject) && VariableObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
				{
					EVariableTypes VariableType = Script.Variables[VariableIndex].t;
					bool Array = Script.Variables[VariableIndex].a;
					// UE_LOG(LogJson, Warning, TEXT("VariableName: %s"), *Script.Variables[VariableIndex].n);
					Script.Variables[VariableIndex].v = JsonValueToScriptValue(*ValueArray, VariableType, Array, Success);
				}
				VariableIndex++;
			}
		}


		// Functions
		FunctionArray = nullptr;
		if (JsonObject->TryGetArrayField(FunctionArrayFieldName, FunctionArray))
		{
			int FunctionIndex = 0;
			for (TSharedPtr<FJsonValue> Function : *FunctionArray)
			{
				// Function nodes
				const TSharedPtr<FJsonObject>* FunctionObject;
				const TArray<TSharedPtr<FJsonValue>>* FunctionNodeArray;
				if (Function->TryGetObject(FunctionObject) && FunctionObject->Get()->TryGetArrayField(FunctionNodeFieldName, FunctionNodeArray))
				{
					NodeIndex = 0;
					for (TSharedPtr<FJsonValue> Node : *FunctionNodeArray)
					{
						// We now have the node, we must get the input pin array now
						const TSharedPtr<FJsonObject>* NodeObject;
						const TArray<TSharedPtr<FJsonValue>>* InputArray;
						if (Node->TryGetObject(NodeObject) && NodeObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
						{
							// We should have the input pins now
							int InputIndex = 0;
							for (TSharedPtr<FJsonValue> Input : *InputArray)
							{
								bool Success = false;
								int InputLength = Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins.Num();
								if (!(InputIndex < InputLength))
								{
									UE_LOG(LogJson, Warning, TEXT("Warning: Looped with an InputIndex of %i with an array length of %i. This is coming from %s."), InputIndex, InputLength, *Script.Functions[FunctionIndex].FunctionName);
									UE_LOG(LogJson, Warning, TEXT("FunctionIndex: %s, Length: %s"), *FString::FromInt(FunctionIndex), *FString::FromInt(Script.Functions.Num()));
									UE_LOG(LogJson, Warning, TEXT("NodeIndex: %s, Length: %s"), *FString::FromInt(NodeIndex), *FString::FromInt(Script.Functions[FunctionIndex].Nodes.Num()));
									UE_LOG(LogJson, Warning, TEXT("InputIndex: %s, Length: %s"), *FString::FromInt(InputIndex), *FString::FromInt(Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins.Num()));
									break;
								}
								const TSharedPtr<FJsonObject>* InputObject;
								const TArray<TSharedPtr<FJsonValue>>* ValueArray;
								// UE_LOG(LogJson, Warning, TEXT("----------------"));
								// UE_LOG(LogJson, Warning, TEXT("FunctionIndex: %s, Length: %s"), *FString::FromInt(FunctionIndex), *FString::FromInt(Script.Functions.Num()));
								// UE_LOG(LogJson, Warning, TEXT("NodeIndex: %s, Length: %s"), *FString::FromInt(NodeIndex), *FString::FromInt(Script.Functions[FunctionIndex].Nodes.Num()));
								// UE_LOG(LogJson, Warning, TEXT("InputIndex: %s, Length: %s"), *FString::FromInt(InputIndex), *FString::FromInt(Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins.Num()));
								// We should be in the Input pin struct now and can set the value
								if (Input->TryGetObject(InputObject) && InputObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
								{
									auto& InputPin = Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins[InputIndex];
									EVariableTypes VariableType = InputPin.VariableType;
									bool Array = InputPin.Array;
									InputPin.Value = JsonValueToScriptValue(*ValueArray, VariableType, Array, Success);
								}
								InputIndex++;
							}

							// If for whatever reason there are more pins than saved values, for example when a node changes its default inputs
							for (int i = InputIndex; i < Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins.Num(); i++)
							{
								auto& InputPin = Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins[i];
								if (!InputPin.Array)
								{
									InputPin.Value.Array.SetNum(1);
									InputPin.Value.Array[0] = FNodeVarArgs(InputPin.VariableType);
								}
							}
						}
						NodeIndex++;
					}
				}

				// Local variables
				VariableArray = nullptr;
				if (FunctionObject->Get()->TryGetArrayField(LocalVariableFieldName, VariableArray))
				{
					// Loop through each variable
					int VariableIndex = 0;
					for (TSharedPtr<FJsonValue> Variable : *VariableArray)
					{
						// We now have the variable, we can set the value now
						const TSharedPtr<FJsonObject>* VariableObject;
						const TArray<TSharedPtr<FJsonValue>>* ValueArray;
						// UE_LOG(LogJson, Warning, TEXT("VariableIndex: %s"), *FString::FromInt(VariableIndex));
						bool Success = false;
						if (Variable->TryGetObject(VariableObject) && VariableObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
						{
							EVariableTypes VariableType = Script.Functions[FunctionIndex].LocalVariables[VariableIndex].t;
							bool Array = Script.Functions[FunctionIndex].LocalVariables[VariableIndex].a;
							// UE_LOG(LogJson, Warning, TEXT("VariableName: %s"), *Script.Variables[VariableIndex].n);
							Script.Functions[FunctionIndex].LocalVariables[VariableIndex].v = JsonValueToScriptValue(*ValueArray, VariableType, Array, Success);
						}
						VariableIndex++;
					}
				}

				// Function inputs
				const TArray<TSharedPtr<FJsonValue>>* InputArray;
				if (FunctionObject->Get()->TryGetArrayField(InputPinFieldName, InputArray))
				{
					int InputIndex = 0;
					for (TSharedPtr<FJsonValue> Input : *InputArray)
					{
						const TSharedPtr<FJsonObject>* InputObject;
						const TArray<TSharedPtr<FJsonValue>>* ValueArray;
						bool Success = false;
						// We should be in the Input pin struct now and can set the value
						if (Input->TryGetObject(InputObject) && InputObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
						{
							EVariableTypes VariableType = Script.Functions[FunctionIndex].InputPins[InputIndex].VariableType;
							bool Array = Script.Functions[FunctionIndex].InputPins[InputIndex].Array;
							Script.Functions[FunctionIndex].InputPins[InputIndex].Value = JsonValueToScriptValue(*ValueArray, VariableType, Array, Success);
						}
						InputIndex++;
					}
				}
				FunctionIndex++;
			}
		}
	}
	return true;
}