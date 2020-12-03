// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeBpJsonLibrary.h"
#include "RuntimeBpMacros.h"
#include "RuntimeBpObject.h"

bool URuntimeBpJsonLibrary::RuntimeBpDataFromJson(const FString& Json, FRuntimeBpJsonFormat& RuntimeBpData)
{
	return FJsonObjectConverter::JsonObjectStringToUStruct<FRuntimeBpJsonFormat>(Json, &RuntimeBpData, 0, 0);
}

FString URuntimeBpJsonLibrary::StructToJson(const int32& AnyStruct, int Indent, bool PrettyPrint)
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

void URuntimeBpJsonLibrary::UpdateRuntimeScriptNodeDefaults(FRuntimeBpJsonFormat& Script, FSaveableBPJsonFormat& SaveableScript, TArray<FNodeStruct>& RuntimeNodes, TArray<FSaveableNode>& SaveableNodes,  int Index = -1)
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

			if (!DefaultObject->DynamicInput && DefaultObject->InputPins.Num() != 0)
			{
				RuntimeNodes[NodeIndex].InputPins.SetNum(DefaultObject->InputPins.Num());
			}

			if (!DefaultObject->DynamicOutput && DefaultObject->OutputPins.Num() != 0)
			{
				RuntimeNodes[NodeIndex].OutputPins.SetNum(DefaultObject->OutputPins.Num());
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
					UsedIndex = PinLength - 1;
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
						if (SaveableNodes[NodeIndex].i[PinIndex].p > -1 && SaveableNodes[NodeIndex].i[PinIndex].n == -1)
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
					UsedIndex = PinLength - 1;
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
						break;
					}
					case ENodeType::VariableSetter:
					{
						// First pin is the exec pin so skip that
						if (UsedIndex > 0)
						{
							// Get the variable type from the variable, the index of the variable is stored in the output variable pin index
							OutputPin.VariableType = SaveableScript.Variables[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
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
						break;
					}
					case ENodeType::LocalVariableSetter:
					{
						// First pin is the exec pin so skip that
						if (UsedIndex > 0)
						{
							// Get the variable type from the variable, the index of the variable is stored in the output variable pin index
							OutputPin.VariableType = SaveableScript.Functions[Index].v[SaveableNodes[NodeIndex].o[UsedIndex].p].t;
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


TArray<FNodeVarArgs> URuntimeBpJsonLibrary::JsonValueToScriptValue(TArray<TSharedPtr<FJsonValue>> Value, EVariableTypes VariableType, bool& Success)
{
	TArray<FNodeVarArgs> NodeVarArgs;

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
	
	return TArray<FNodeVarArgs>();
}

bool URuntimeBpJsonLibrary::JsonStringToScript(const FString& JsonString, FRuntimeBpJsonFormat& Script, bool LoadExternals = false)
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

				/*bool ExternalFunctionCall = false;
				FString FunctionName;
				if (NodeObject->Get()->TryGetStringField(FunctionNodeFieldName, FunctionName) && FunctionName.Contains("CallFunctionFromScript"))
				{
					ExternalFunctionCall = true;
				}*/

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
						int InputIndex = 0;
						// We should have the input pins now
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
	UpdateRuntimeScriptNodeDefaults(Script, SaveableScript, Script.Nodes, SaveableScript.Nodes);

	// And do the same for nodes nested in functions
	for (int i = 0; i < SaveableScript.Functions.Num(); i++)
	{
		UpdateRuntimeScriptNodeDefaults(Script, SaveableScript, Script.Functions[i].Nodes, SaveableScript.Functions[i].n, i);
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
					EVariableTypes VariableType = Script.Nodes[NodeIndex].InputPins[InputIndex].VariableType;
					bool Success = false;
					// We should be in the Input pin struct now and can set the value
					if (Input->TryGetObject(InputObject) && InputObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
					{
						Script.Nodes[NodeIndex].InputPins[InputIndex].Value = JsonValueToScriptValue(*ValueArray, VariableType, Success);
					}
					InputIndex++;
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
				EVariableTypes VariableType = Script.Variables[VariableIndex].t;
				// UE_LOG(LogJson, Warning, TEXT("VariableIndex: %s"), *FString::FromInt(VariableIndex));
				bool Success = false;
				if (Variable->TryGetObject(VariableObject) && VariableObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
				{
					// UE_LOG(LogJson, Warning, TEXT("VariableName: %s"), *Script.Variables[VariableIndex].n);
					Script.Variables[VariableIndex].v = JsonValueToScriptValue(*ValueArray, VariableType, Success);
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
								const TSharedPtr<FJsonObject>* InputObject;
								const TArray<TSharedPtr<FJsonValue>>* ValueArray;
								// UE_LOG(LogJson, Warning, TEXT("----------------"));
								// UE_LOG(LogJson, Warning, TEXT("InputIndex: %s, Length: %s"), *FString::FromInt(InputIndex), *FString::FromInt(Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins.Num()));
								// UE_LOG(LogJson, Warning, TEXT("NodeIndex: %s, Length: %s"), *FString::FromInt(NodeIndex), *FString::FromInt(Script.Functions[FunctionIndex].Nodes.Num()));
								// UE_LOG(LogJson, Warning, TEXT("FunctionIndex: %s, Length: %s"), *FString::FromInt(FunctionIndex), *FString::FromInt(Script.Functions.Num()));
								EVariableTypes VariableType = Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins[InputIndex].VariableType;
								bool Success = false;
								// We should be in the Input pin struct now and can set the value
								if (Input->TryGetObject(InputObject) && InputObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
								{
									Script.Functions[FunctionIndex].Nodes[NodeIndex].InputPins[InputIndex].Value = JsonValueToScriptValue(*ValueArray, VariableType, Success);
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
						// We now have the variable, we can set the value now
						const TSharedPtr<FJsonObject>* VariableObject;
						const TArray<TSharedPtr<FJsonValue>>* ValueArray;
						EVariableTypes VariableType = Script.Functions[FunctionIndex].LocalVariables[VariableIndex].t;
						// UE_LOG(LogJson, Warning, TEXT("VariableIndex: %s"), *FString::FromInt(VariableIndex));
						bool Success = false;
						if (Variable->TryGetObject(VariableObject) && VariableObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
						{
							// UE_LOG(LogJson, Warning, TEXT("VariableName: %s"), *Script.Variables[VariableIndex].n);
							Script.Functions[FunctionIndex].LocalVariables[VariableIndex].v = JsonValueToScriptValue(*ValueArray, VariableType, Success);
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
						EVariableTypes VariableType = Script.Functions[FunctionIndex].InputPins[InputIndex].VariableType;
						bool Success = false;
						// We should be in the Input pin struct now and can set the value
						if (Input->TryGetObject(InputObject) && InputObject->Get()->TryGetArrayField(ValueFieldName, ValueArray))
						{
							Script.Functions[FunctionIndex].InputPins[InputIndex].Value = JsonValueToScriptValue(*ValueArray, VariableType, Success);
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