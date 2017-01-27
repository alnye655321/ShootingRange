// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootingRange.h"
#include "TargetSpawner.h"
#include "ShootingRangeGameMode.h"
#include "Kismet/KismetMathLibrary.h"
#include "Target.h"


// Sets default values
ATargetSpawner::ATargetSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));

	TargetsSpawned = 0;

}

// Called when the game starts or when spawned
void ATargetSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ATargetSpawner::SpawnTarget, true, 1.0f); //set a timer
	
}

// Called every frame
void ATargetSpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATargetSpawner::SpawnTarget()
{
	FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(SpawnVolume->Bounds.Origin, SpawnVolume->Bounds.BoxExtent); // use math library to get a random point in box

	//find out if the game is currently being played - has pressed button
	AShootingRangeGameMode* GameMode = Cast<AShootingRangeGameMode>(GetWorld()->GetAuthGameMode()); //get the GameMode class then cast it into our  ShootingRangeGameMode
	if (Target != NULL && GetWorld() && TargetsSpawned < 5) // check target counts and make sure game is not over - && !GameMode->GetGameIsOver()
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this; // this is same as self in blueprints
		SpawnParams.Instigator = Instigator;

		GetWorld()->SpawnActor<ATarget>(Target, SpawnPoint, FRotator(0.f), SpawnParams); // spawn a target into the world with default initial rotation
		++TargetsSpawned; // increment targets spawned after new one is created
	}
	//spawn the target
	//increment targets spawned
}

