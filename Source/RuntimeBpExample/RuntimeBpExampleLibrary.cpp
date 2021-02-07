// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RuntimeBpExampleLibrary.h"
#include "RuntimeBlueprints/RuntimeBpMacros.h"

TArray<ARuntimeBpGrenade*> URuntimeBpExampleLibrary::GetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, bool Array)
{
	NODE_VAR_ARG_GETTER_SAFE(ARuntimeBpGrenade*, Grenade)
}

void URuntimeBpExampleLibrary::SetGrenadeArg(UPARAM(ref) TArray<FNodeVarArgs>& Values, TArray<ARuntimeBpGrenade*> Value)
{
	NODE_VAR_ARG_SETTER_SAFE(ARuntimeBpGrenade*, Grenade)
}