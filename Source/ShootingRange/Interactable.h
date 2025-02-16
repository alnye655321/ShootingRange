// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class SHOOTINGRANGE_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* InteractableMesh;

	UFUNCTION(BlueprintImplementableEvent, Category = "On Interact") // BluePrintImplementable - let blueprints deal with this function
		void OnInteract();
	
};
