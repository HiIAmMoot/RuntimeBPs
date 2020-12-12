// Fill out your copyright notice in the Description page of Project Settings.

#include "ExampleNodes.h"
#include "RuntimeBpConstructor.h"

/**
* Called when this script comes into existence
*/
UBeginPlay::UBeginPlay()
{
	NodeName = "Begin Play";
	NodeDescription = "Called when this script comes into existence";
	NodeCategory = "Events";

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");
}

void UBeginPlay::ConstructNode(URuntimeBpConstructor* ConstructorClass, int ConstructedNodeIndex, const FString& ConstructedNodeName, UPARAM(ref) TArray<FPinStruct>& ConstructedInputPins, UPARAM(ref) TArray<FPinStruct>& ConstructedOutputPins)
{
	
	// Register this BeginPlay node in the constructor
	if (ConstructorClass)
	{
		ConstructorClass->BeginPlayNode = this;
	}

	Super::ConstructNode(ConstructorClass, ConstructedNodeIndex, ConstructedNodeName, ConstructedInputPins, ConstructedOutputPins);
}

/**
* Prints a string to the log, and optionally, to the screen
* If Print To Log is true, it will be visible in the Output Log window.  Otherwise it will be logged only as 'Verbose', so it generally won't show up.
*
* @param	InString		The string to log out
* @param	bPrintToScreen	Whether or not to print the output to the screen
* @param	bPrintToLog		Whether or not to print the output to the log
* @param	bPrintToConsole	Whether or not to print the output to the console
* @param	TextColor		Whether or not to print the output to the console
* @param	Duration		The display duration (if Print to Screen is True). Using negative number will result in loading the duration time from the config.
*/

UPrint::UPrint()
{
	NodeName = "Print String";
	NodeCategory = "Utilities|String";
	NodeDescription = "Prints a string to the log, and optionally, to the screen"
		"If Print To Log is true, it will be visible in the Output Log window.Otherwise it will be logged only as 'Verbose', so it generally won't show up."
		"@param	InString		The string to log out"
		"@param	bPrintToScreen	Whether or not to print the output to the screen"
		"@param	bPrintToLog		Whether or not to print the output to the log"
		"@param	bPrintToConsole	Whether or not to print the output to the console"
		"@param	TextColor		Whether or not to print the output to the console"
		"@param	Duration		The display duration(if Print to Screen is True).Using negative number will result in loading the duration time from the config.";

	InputPins.SetNum(6);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("In String", EVariableTypes::String);
	InputPins[1].Value.Array[0].SetStringArg("Hello"); // Default value
	InputPins[2].MakeNodePin("Print to Screen", EVariableTypes::Bool);
	InputPins[2].Value.Array[0].SetBoolArg(true); // Default value
	InputPins[3].MakeNodePin("Print to Log", EVariableTypes::Bool);
	InputPins[3].Value.Array[0].SetBoolArg(true); // Default value
	InputPins[4].MakeNodePin("Text Color", EVariableTypes::LinearColor);
	InputPins[4].Value.Array[0].SetLinearColorArg(FLinearColor(0.0, 0.66, 1.0, 1.0)); // Default value
	InputPins[5].MakeNodePin("Duration", EVariableTypes::Float);
	InputPins[5].Value.Array[0].SetFloatArg(2.f); // Default value

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodePin("Then");
}

void UPrint::Execute(int Index, int FromLoopIndex)
{
	// We set the values in local variables because of how async works with Print Strings.
	FString InString = GetConnectedPinValue(InputPins[1]).GetStringArg();
	bool PrintToScreen = GetConnectedPinValue(InputPins[2]).GetBoolArg();
	bool PrintToLog = GetConnectedPinValue(InputPins[3]).GetBoolArg();
	FLinearColor TextColor = GetConnectedPinValue(InputPins[4]).GetLinearColorArg();
	float Duration = GetConnectedPinValue(InputPins[5]).GetFloatArg();

	if (BPConstructor->GetMultiThread())
	{
		// We must execute the actual spawning inside the GameThread, a crash will occur otherwise
		AsyncTask(ENamedThreads::GameThread, [this, InString, PrintToScreen, PrintToLog, TextColor, Duration, FromLoopIndex]()
		{
			UKismetSystemLibrary::PrintString(this, InString, PrintToScreen, PrintToLog, TextColor, Duration);
			URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
		});
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, InString, PrintToScreen, PrintToLog, TextColor, Duration);
		Super::Execute(0, FromLoopIndex);// Index here is the output pins array index
	}
}

UBranch::UBranch()
{
	NodeName = "Branch";
	NodeCategory = "Flow Control";

	InputPins.SetNum(2);
	InputPins[0].MakeNodePin();// No args means execute

	InputPins[1].MakeNodePin("Condition", EVariableTypes::Bool);
	InputPins[1].Value.Array[0].SetBoolArg(true); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("True");
	OutputPins[1].MakeNodePin("False");

}

void UBranch::Execute(int Index, int FromLoopIndex)
{
	if (GetConnectedPinValue(InputPins[1]).GetBoolArg())
	{
		Super::Execute(0, FromLoopIndex);// 0 here is the output pins array index
	}
	else
	{
		Super::Execute(1, FromLoopIndex);// 1 here is the output pins array index
	}
}

UForLoop::UForLoop()
{
	NodeName = "For Loop";
	NodeDescription = "Executes LoopBody for each Index from StartIndex to LastIndex, inclusive";
	NodeCategory = "Flow Control";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
		
	InputPins[1].MakeNodePin("First Index", EVariableTypes::Int);
	InputPins[1].Value.Array[0].SetIntArg(0); // Default value

	InputPins[2].MakeNodePin("Last Index", EVariableTypes::Int);
	InputPins[2].Value.Array[0].SetIntArg(1); // Default value

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Loop Body");
	OutputPins[1].MakeNodePin("Loop Index", EVariableTypes::Int);
	OutputPins[2].MakeNodePin("Completed");
}

void UForLoop::Execute(int Index, int FromLoopIndex)
{
	CurrentLoopIndex = GetConnectedPinValue(InputPins[1]).GetIntArg();
	LastIndex = GetConnectedPinValue(InputPins[2]).GetIntArg();
	ReceivedFromLoopIndex = FromLoopIndex;
	// HalfWayPoint = LastIndex * 0.5;
	if (LastIndex >= 0 && CurrentLoopIndex >= 0)
	{
		Next();
	}
	else
	{
		Super::Execute(2, FromLoopIndex);// On Completed
	}
}

void UForLoop::Next()
{
	if (BPConstructor->GetMultiThread() && !(CurrentLoopIndex & 1023))
	{
		// Sleep to give the thread a bit of breathing room
		FPlatformProcess::Sleep(0.01);
		AsyncTask(ENamedThreads::GameThread, [this]()
		{
			if (CurrentLoopIndex <= LastIndex)
			{
				OutputPins[1].Value.Array[0].SetIntArg(CurrentLoopIndex);
				CurrentLoopIndex++;
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, NodeIndex, FunctionIndex);
				//Super::Execute(0, NodeIndex);// Loop Body
			}
			else
			{
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 2, ReceivedFromLoopIndex, FunctionIndex);
				//Super::Execute(2, ReceivedFromLoopIndex);// On Completed
			}
		});
	}
	else
	{
		if (CurrentLoopIndex <= LastIndex)
		{
			OutputPins[1].Value.Array[0].SetIntArg(CurrentLoopIndex);
			CurrentLoopIndex++;
			Super::Execute(0, NodeIndex);// Loop Body
		}
		else
		{
			if (BPConstructor->GetMultiThread())
			{
				FPlatformProcess::Sleep(0.01);
				AsyncTask(ENamedThreads::GameThread, [this]()
				{
					URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 2, ReceivedFromLoopIndex, FunctionIndex);
					//Super::Execute(2, ReceivedFromLoopIndex);// On Completed
				});
			}
			else
			{
				Super::Execute(2, ReceivedFromLoopIndex);// On Completed
			}
		}
	}

}

UForLoopWithBreak::UForLoopWithBreak()
{
	NodeName = "For Loop With Break";
	NodeDescription = "Executes LoopBody for each Index from StartIndex to LastIndex, inclusive";
	NodeCategory = "Flow Control";

	InputPins.SetNum(4);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("First Index", EVariableTypes::Int);
	InputPins[1].Value.Array[0].SetIntArg(0); // Default value
	InputPins[2].MakeNodePin("Last Index", EVariableTypes::Int);
	InputPins[2].Value.Array[0].SetIntArg(1); // Default value
	InputPins[3].MakeNodePin("Break");// No args means execute

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("Loop Body");
	OutputPins[1].MakeNodePin("Loop Index", EVariableTypes::Int);
	OutputPins[2].MakeNodePin("Completed");
}

void UForLoopWithBreak::Execute(int Index, int FromLoopIndex)
{
	// If the break exec is called (ala index 3), we stop the loop
	if (Index == 3)
	{
		if (ReceivedFromLoopIndex == -1)
		{
			FromLoopIndexFromBreak = FromLoopIndex;
		}
		else
		{
			FromLoopIndexFromBreak = ReceivedFromLoopIndex;
		}
		Break = true;
		return;
	}
	Break = false;

	Super::Execute(Index, FromLoopIndex);
}

void UForLoopWithBreak::Next()
{
	if (Break)
	{
		ReceivedFromLoopIndex = FromLoopIndexFromBreak;
		Super::Execute(2, FromLoopIndexFromBreak);// On Completed
		return;
	}

	Super::Next();
}

USpawn::USpawn()
{
	NodeName = "Spawn Actor";
	NodeCategory = "Actor";

	InputPins.SetNum(3);
	InputPins[0].MakeNodePin();// No args means execute
	InputPins[1].MakeNodePin("Class", EVariableTypes::Class);
	InputPins[1].Value.Array[0].SetClassArg(); // Default value
	InputPins[2].MakeNodePin("Transform", EVariableTypes::Transform);
	InputPins[2].Value.Array[0].SetTransformArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodePin("Spawned Actor", EVariableTypes::Actor);

}

void USpawn::Execute(int Index, int FromLoopIndex)
{
	SpawnedActor = nullptr;
	UClass* ActorToSpawn = GetConnectedPinValue(InputPins[1]).GetClassArg();

	if (ActorToSpawn)
	{
		FTransform const& Transform = GetConnectedPinValue(InputPins[2]).GetTransformArg();
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParameters.Owner = BPConstructor->GetOwner();
		UWorld* World = GetWorld();
		if (BPConstructor->GetMultiThread())
		{
			// We must execute the actual spawning inside the GameThread, a crash will occur otherwise
			AsyncTask(ENamedThreads::GameThread, [this, World, ActorToSpawn, Transform, SpawnParameters, FromLoopIndex]()
			{
				SpawnedActor = World->UWorld::SpawnActorAbsolute(ActorToSpawn, Transform, SpawnParameters);
				if (SpawnedActor)
				{
					FHitResult HitResult = FHitResult();
					SpawnedActor->K2_SetActorTransform(Transform, false, HitResult, true);
				}
				OutputPins[1].Value.Array[0].SetActorArg(SpawnedActor);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			SpawnedActor = World->UWorld::SpawnActorAbsolute(ActorToSpawn, Transform, SpawnParameters);
			if (SpawnedActor)
			{
				FHitResult HitResult = FHitResult();
				SpawnedActor->K2_SetActorTransform(Transform, false, HitResult, true);
			}
			OutputPins[1].Value.Array[0].SetActorArg(SpawnedActor);
			Super::Execute(0, FromLoopIndex);// Index here is the output pins array index
		}
	}
	else
	{
		Super::Execute(0, FromLoopIndex);// Index here is the output pins array index
	}
}

UStartTimer::UStartTimer()
{
	NodeName = "Start Timer";
	NodeCategory = "Latent";
	NodeDescription = "Starts a timer which can loop at a specified interval, triggering the timer while it's active will reset the timer. The minimum interval is 0.1 seconds.";
	Latent = true;

	InputPins.SetNum(4);
	InputPins[0].MakeNodePin("Start");
	InputPins[1].MakeNodePin("Stop");

	InputPins[2].MakeNodePin("Interval", EVariableTypes::Float);
	InputPins[2].Value.Array[0].SetFloatArg(0.2); // Default value

	InputPins[3].MakeNodePin("Loop", EVariableTypes::Bool);
	InputPins[3].Value.Array[0].SetBoolArg(false); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Update");
	OutputPins[1].MakeNodePin("Timer Stopped");

}

void UStartTimer::Execute(int Index, int FromLoopIndex)
{
	if (Index == 0) // Start
	{
		float Interval = GetConnectedPinValue(InputPins[2]).GetFloatArg();
		Interval = FMath::Clamp(Interval, 0.1f, FMath::Abs(Interval) + 1.f);
		bool Loop = GetConnectedPinValue(InputPins[3]).GetBoolArg();

		if (BPConstructor->GetMultiThread())
		{
			// We execute the timer on the gamethread
			AsyncTask(ENamedThreads::GameThread, [this, Interval, Loop]()
			{
			
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UStartTimer::HeartbeatAsync, Interval, Loop);
			});
		}
		else
		{
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UStartTimer::Heartbeat, Interval, Loop);
		}
	}
	else // Stop
	{
		if (TimerHandle.IsValid())
		{
			if (BPConstructor->GetMultiThread())
			{
				// We clear the timer on the gamethreads
				AsyncTask(ENamedThreads::GameThread, [this]()
				{
					GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
				});
			}
			else
			{
				GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
			}
		}
		Super::Execute(1, FromLoopIndex);
	}
}

void UStartTimer::Heartbeat()
{
	Super::Execute(0);// Index here is the output pins array index
}

void UStartTimer::HeartbeatAsync()
{
	URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, -1, FunctionIndex);
}

UFlipFlop::UFlipFlop()
{
	NodeName = "Flip Flop";
	NodeDescription = "Alternates between A and B outputs, starting with A.";
	NodeCategory = "Flow Control";

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin();// No args means execute

	OutputPins.SetNum(3);
	OutputPins[0].MakeNodePin("A");
	OutputPins[1].MakeNodePin("B");

	OutputPins[2].MakeNodePin("Is A", EVariableTypes::Bool);

	IsA = false;
}

void UFlipFlop::Execute(int Index, int FromLoopIndex)
{
	IsA = !IsA;
	OutputPins[2].Value.Array[0].SetBoolArg(IsA);

	if (IsA)
	{
		Super::Execute(0, FromLoopIndex);
	}
	else
	{
		Super::Execute(1, FromLoopIndex);
	}
}

void UFlipFlop::ResetInternalFunctionValues()
{
	IsA = false;
}

USequence::USequence()
{
	NodeName = "Sequence";
	NodeDescription = "Executes a series of pins in order.";
	NodeCategory = "Flow Control";

	DynamicOutput = true;

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin();// No args means execute

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then 0");
	OutputPins[1].MakeNodePin("Then 1");

}

void USequence::Execute(int Index, int FromLoopIndex)
{
	CurrentLoopIndex = 0;
	LastIndex = OutputPins.Num() - 1;
	ReceivedFromLoopIndex = FromLoopIndex;
	if (LastIndex >= 0)
	{
		Next();
	}
	else
	{
		Super::Execute(2, FromLoopIndex);// On Completed
	}
}

void USequence::Next()
{
	if (CurrentLoopIndex < LastIndex)
	{
		CurrentLoopIndex++;
		Super::Execute(CurrentLoopIndex - 1, NodeIndex);// Loop Body
	}
	else
	{
		Super::Execute(LastIndex, ReceivedFromLoopIndex);// Loop Body
	}
}

UMakeArray::UMakeArray()
{
	NodeName = "Make Array";
	NodeDescription = "Creates a new array from a series of items.";
	NodeCategory = "Utilities|Array";

	DynamicInput = true;

	InputPins.SetNum(1);
	InputPins[0].MakeNodePin("[0]", EVariableTypes::WildCard);
	//InputPins[1].MakeNodePin("[1]", EVariableTypes::WildCard);

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodeArray("Array", EVariableTypes::WildCard);

}

void UMakeArray::Execute(int Index, int FromLoopIndex)
{
	TArray<FNodeVarArgs> Array;
	Array.Reserve(InputPins.Num());

	for (FPinStruct& InputPin : InputPins)
	{
		Array.Add(GetConnectedPinValue(InputPin));
	}

	OutputPins[0].Value.Array = Array;

	Super::Execute(0, FromLoopIndex);// On Completed
}

UMakeEmptyArray::UMakeEmptyArray()
{
	NodeName = "Make Empty Array";
	NodeDescription = "Creates a new array with no items";
	NodeCategory = "Utilities|Array";

	InputPins.SetNum(0);

	OutputPins.SetNum(1);
	OutputPins[0].MakeNodeArray("Array", EVariableTypes::WildCard);

}

void UMakeEmptyArray::Execute(int Index, int FromLoopIndex)
{
	TArray<FNodeVarArgs> Array;
	Array.SetNum(0);

	OutputPins[0].Value.Array = Array;

	Super::Execute(0, FromLoopIndex);// On Completed
}

UGetAllActorsOfClass::UGetAllActorsOfClass()
{
	NodeName = "Get All Actors Of Class";
	NodeCategory = "Utilities";

	InputPins.SetNum(2);
	InputPins[0].MakeNodePin();// No args means execute

	InputPins[1].MakeNodePin("Actor Class", EVariableTypes::Class);
	InputPins[1].Value.Array[0].SetClassArg(); // Default value

	OutputPins.SetNum(2);
	OutputPins[0].MakeNodePin("Then");
	OutputPins[1].MakeNodeArray("Out Actors", EVariableTypes::Actor);

}

void UGetAllActorsOfClass::Execute(int Index, int FromLoopIndex)
{
	TSubclassOf<AActor> ActorClass = GetConnectedPinValue(InputPins[1]).GetClassArg();
	if (ActorClass)
	{
		if (BPConstructor->GetMultiThread())
		{
			// We must execute the actual spawning inside the GameThread, a crash will occur otherwise
			AsyncTask(ENamedThreads::GameThread, [this, ActorClass, FromLoopIndex]()
			{
				UGameplayStatics::GetAllActorsOfClass(this, ActorClass, OutActors);
				OutputPins[1].Value.SetActorArg(OutActors);
				URuntimeBpConstructor::Thread->ContinueExecute(BPConstructor, NodeIndex, 0, FromLoopIndex, FunctionIndex);
			});
		}
		else
		{
			UGameplayStatics::GetAllActorsOfClass(this, GetConnectedPinValue(InputPins[1]).GetClassArg(), OutActors);
			OutputPins[1].Value.SetActorArg(OutActors);
			Super::Execute(0, FromLoopIndex);// Index here is the output pins array index
		}
	}
	else
	{
		Super::Execute(0, FromLoopIndex);// 0 here is the output pins array index
	}
}