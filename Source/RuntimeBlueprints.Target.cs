// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class RuntimeBlueprintsTarget : TargetRules
{
	public RuntimeBlueprintsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "RuntimeBpExample", "RuntimeBlueprints" } );
	}
}
