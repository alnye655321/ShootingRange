// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "ShootingRangeGameMode.generated.h"

UCLASS(minimalapi)
class AShootingRangeGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AShootingRangeGameMode();

	virtual void Tick(float DeltaTime) override;

	void AddPoint(); // successful hit give point to character
	void RemovePoint(); // unsuccessful hit remove point from character

	UFUNCTION(BlueprintCallable, Category = "Game Over")
		void SetGameOver(bool bGameOver); // function to end the game, can be called in blueprints

	bool GetGameIsOver(); // check if game is over

private:

	int32 Score = 0;

	float Time = 0.f;

	int32 TargetsShot = 0;

	int32 PointsToFinish = 0;

	bool bGameIsOver = true; // default game is over, until player starts it
};



