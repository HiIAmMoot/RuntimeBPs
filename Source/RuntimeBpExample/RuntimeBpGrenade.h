// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuntimeBpGrenade.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGrenadeStartExplosion, class ARuntimeBpGrenade*, Self, class APawn*, Instigator, const FTransform, ExplosionTransform);

class UGrenadeScript;

UCLASS()
class RUNTIMEBPEXAMPLE_API ARuntimeBpGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARuntimeBpGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Blueprint call for when the explosion starts
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Start Explosion"))
	void ReceiveStartExplosion();

	// Blueprint call for the explosion, use this for effects 
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Explosion Effects"))
	void ReceiveExplode();

	// Blueprint call for when a grenade's pin has been pulled and it is about to explode
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Pull Pin"))
	void ReceivePullPin();

public:	

	FGrenadeStartExplosion Grenade_OnStartExplosion;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Scripting")
	bool CreateScript;

	// The saved path of the script, relative from the Saved folder and with file extension
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Scripting")
	FString ScriptPath;

	UGrenadeScript* GrenadeScript;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when a grenade's pin has been pulled and it is about to explode, supposed to be called on the server
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void PullPin();

	// Called when an explosion starts, supposed to be called on the server. Call this if you want to start an explosion
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void StartExplosion();

	// Called to all clients for effects purposes
	UFUNCTION(NetMulticast, Reliable)
	virtual void ClientExplode();

};
