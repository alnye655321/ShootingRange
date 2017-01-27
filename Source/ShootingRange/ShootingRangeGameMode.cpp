// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ShootingRange.h"
#include "ShootingRangeGameMode.h"
#include "ShootingRangeHUD.h"
#include "ShootingRangeCharacter.h"

AShootingRangeGameMode::AShootingRangeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShootingRangeHUD::StaticClass();
}
