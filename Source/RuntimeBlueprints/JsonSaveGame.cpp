// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonSaveGame.h"

FString UJsonSaveGame::GetJsonString()
{
	return JsonString;
}

void UJsonSaveGame::SetJsonString(FString NewString)
{
	JsonString = NewString;
}

bool UJsonSaveGame::SaveTextFile(const FString& FileName)
{
	FFileHelper FileHelper = FFileHelper();
	FString AbsoluteFilePath = FPaths::ProjectSavedDir() + "\\SaveGames\\" + FileName + ".json"; 


	return FileHelper.SaveStringToFile(JsonString, *AbsoluteFilePath);
}

bool UJsonSaveGame::LoadTextFile(const FString& FileName)
{
	FFileHelper FileHelper = FFileHelper();
	FString AbsoluteFilePath = FPaths::ProjectSavedDir() + "\\SaveGames\\" + FileName + ".json";

	return FileHelper.LoadFileToString(JsonString, *AbsoluteFilePath);
}
