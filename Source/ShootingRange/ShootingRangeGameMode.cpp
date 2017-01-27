// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ShootingRange.h"
#include "ShootingRangeGameMode.h"
#include "ShootingRangeHUD.h"
#include "ShootingRangeCharacter.h"
#include "TargetSpawner.h"

AShootingRangeGameMode::AShootingRangeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShootingRangeHUD::StaticClass();

	PointsToFinish = 15;

}

void AShootingRangeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bGameIsOver)
	{
		Time += DeltaTime;
	}
}

void AShootingRangeGameMode::AddPoint()
{
	++Score;

	++TargetsShot;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Score is %d"), Score)); // print log message FString to screen, for 5 seconds. %d refers to first value of Score, can have multiples

	if (TargetsShot == PointsToFinish) // if we reach the goal points end the game
	{
		this->SetGameOver(true);
	}
}

void AShootingRangeGameMode::RemovePoint()
{
	if (Score > 0)
	{
		--Score;
	}
}

void AShootingRangeGameMode::SetGameOver(bool bGameOver)
{
	if (bGameOver)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Game Over! You scored %d in a time of %f seconds."), Score, Time));
	}
	else // reset game
	{
		Score = 0;
		TargetsShot = 0;
		Time = 0;
	}
	// iterate through actors, all the target spawners volumes in the world
	for (TActorIterator<ATargetSpawner> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ActorItr->TargetsSpawned = 0; // reset the target spawn count for each target spawner volume
	}

	bGameIsOver = bGameOver;
}

bool AShootingRangeGameMode::GetGameIsOver()
{
	return bGameIsOver;
}
