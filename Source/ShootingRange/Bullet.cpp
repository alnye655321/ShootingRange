// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootingRange.h"
#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FHitResult HitResult;

	FVector StartTrace = this->GetActorLocation();
	FVector EndTrace = (Velocity * DeltaTime) + StartTrace;
	EndTrace.Z += this->GetActorRotation().Pitch; // if looking up the bullet will also travel up

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // ignore line trace for this actor hitting itself

	// line trace single by channel: if you hit something will return true else falase
	// this working only on destructible objects, can also replace with ECC_Visible
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Destructible, CollisionParams))
	{
		if(HitResult.GetActor()) // if hit result is an actor
		{
			// draw debug box around impact point of bullet, true parameter will leave box there, can also have a timed death
			DrawDebugSolidBox(GetWorld(), HitResult.ImpactPoint, FVector(10.f), FColor::Blue, true);

			// whatever we hit try to cast to destructible actor
			//ADestructibleActor* Mesh = Cast<ADestructibleActor>(HitResult.GetActor());
			//Mesh->GetDestructibleComponent()->ApplyRadiusDamage(10.f, HitResult.ImpactPoint, 32.f, 10.f, false);
		}
		else
		{
			// debug message, get name of actor class hit to log
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Could not get mesh. Type is %s"), *HitResult.GetActor()->StaticClass()->GetFName().ToString()));
		}

		Destroy();

	}
	else
	{
		BulletExpiry += DeltaTime;

		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(0.f, -BulletExpiry * 80.f, 100.f)); // change debug color based on bullet time

		// if we havent hit anything move the bullet to the end of the line trace
		SetActorLocation(EndTrace);

		// changing velocity, dropping bullet, using DeltaTime to keep frame rate consistency
		Velocity += FVector(0.f, 0.f, -200.f) * DeltaTime;

	}
}

