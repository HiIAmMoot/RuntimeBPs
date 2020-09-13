// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "GameFramework/SaveGame.h"
#include "JsonSaveGame.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class RUNTIMEBLUEPRINTS_API UJsonSaveGame : public USaveGame
{
	GENERATED_BODY()

private:

	UPROPERTY(SaveGame)
	FString JsonString;

public:

	UFUNCTION(BlueprintPure, Category = "JSON", meta = (Keywords = "Get Json String"))
	FString GetJsonString();

	UFUNCTION(BlueprintCallable, Category = "JSON", meta = (Keywords = "Set Json String"))
	void SetJsonString(FString NewString);

	UFUNCTION(BlueprintCallable, Category = "Game", meta = (Keywords = "Save Text File"))
	bool SaveTextFile(const FString& FileName);

	UFUNCTION(BlueprintCallable, Category = "Game", meta = (Keywords = "Load Text File"))
	bool LoadTextFile(const FString& FileName);

};
