// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PhysicsEngine/DestructibleActor.h"
#include "Bullet.generated.h"

UCLASS()
class SHOOTINGRANGE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
	FVector Velocity = FVector(100.f); // set to 100 on all axis

	float BulletExpiry = 0.f;
	
};
