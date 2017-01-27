// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Target.h"
#include "ShootingRangeGameMode.h"
#include "Kismet/KismetMathLibrary.h"
#include "TargetSpawner.generated.h"

UCLASS()
class SHOOTINGRANGE_API ATargetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* SpawnVolume; // volume box to spawn targets

	UPROPERTY(EditDefaultsOnly, Category = "Spawn Info")
		TSubclassOf<class ATarget> Target;  // spawning a subclass, Target, included above

	int32 TargetsSpawned; // counter of how many targets we have spawned

private:

	FTimerHandle SpawnTimerHandle; // handle to manage spawning of objects

	void SpawnTarget(); // when called spawn a target at random point in the volume
	
};
