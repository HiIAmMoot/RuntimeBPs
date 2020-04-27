// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class RuntimeBlueprintsEditorTarget : TargetRules
{
	public RuntimeBlueprintsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        // For some reason, the LongUnion update does not happen after the first build since the change. You will have to cancel and build again to have the TypeAmount value updated.
        // This seems to be a bug with UHT, although unsure.
        int TypeAmount = 27;

        PreBuildSteps.Add("powershell -executionpolicy bypass \"$(ProjectDir)\\Source\\UpdateLongUnion.ps1\" " + 
            "-filepath \"$(ProjectDir)\\Source\\RuntimeBlueprints\\LongUnion.h\" " +
            "-union_path '$(EngineDir)\\Source\\Runtime\\Core\\Public\\Containers\\Union.h' " + 
            "-type_amount " + TypeAmount.ToString());

        //bUseUBTMakefiles = false;

        ExtraModuleNames.AddRange( new string[] { "RuntimeBpExample", "RuntimeBlueprints" } );

	}
}
