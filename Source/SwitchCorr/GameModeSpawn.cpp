// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeSpawn.h"

void AGameModeSpawn::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	data = NewObject<UDataObject>(this);
	Super::InitGame(MapName, Options, ErrorMessage);
	timerManager = GetWorld()->SpawnActor(timerManagerRef);
	//data = timerManager;
}