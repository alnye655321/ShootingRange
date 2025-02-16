// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootingRange.h"
#include "Target.h"


// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh")); // register the object in the world
	TargetMesh->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATarget::OnShot()
{
	Destroy(); // destroy the target once hit
}

