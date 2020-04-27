// Fill out your copyright notice in the Description page of Project Settings.

#include "GrenadeScript.h"
#include "RuntimeBpGrenade.h"

void UGrenadeScript::CallGrenadeExplosion(ARuntimeBpGrenade* Self, APawn* Instigator, const FTransform ExplosionTransform)
{
	if (GrenadeExplosionNode)
	{
		// Set the parameters that are passed with this call
		GrenadeExplosionNode->OutputPins[1].Value.Array[0].SetActorArg(Self);
		GrenadeExplosionNode->OutputPins[2].Value.Array[0].SetActorArg(Instigator);
		GrenadeExplosionNode->OutputPins[3].Value.Array[0].SetTransformArg(ExplosionTransform);

		if (EnableMultithread)
		{

			ContinueExecute(this, GrenadeExplosionNode->NodeIndex, 0, -1, GrenadeExplosionNode->FunctionIndex);
		}
		else
		{
			GrenadeExplosionNode->Execute(0);
		}
	}

}
