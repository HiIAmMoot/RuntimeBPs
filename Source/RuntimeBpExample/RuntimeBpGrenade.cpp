// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeBpGrenade.h"
#include "Scripting/GrenadeScript.h"

// Sets default values
ARuntimeBpGrenade::ARuntimeBpGrenade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ARuntimeBpGrenade::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARuntimeBpGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARuntimeBpGrenade::PullPin()
{
	if (CreateScript)
	{
		GrenadeScript = NewObject<UGrenadeScript>(this);
		GrenadeScript->RegisterComponent();
		GrenadeScript->InitScriptFromSave(ScriptPath);
		Grenade_OnStartExplosion.AddDynamic(GrenadeScript, &UGrenadeScript::CallGrenadeExplosion);
	}

	ReceivePullPin();
}

void ARuntimeBpGrenade::StartExplosion()
{
	if (Grenade_OnStartExplosion.IsBound())
	{
		Grenade_OnStartExplosion.Broadcast(this, GetInstigator(), GetTransform());
	}

	ReceiveStartExplosion();

	// Apply damage here

	ClientExplode();
}

void ARuntimeBpGrenade::ClientExplode_Implementation()
{
	ReceiveExplode();
}

