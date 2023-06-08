// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Movement direction for the platform. The vector will be normalized at launch, no need to do this manually.
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector MovementDirection = FVector(0, 1, 0);
	
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MovementSpeed = 5.0;

	// How far the platform should travel before reversing direction.
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MovementDistance = -1.0;

	// Track how far the platform has travelled since last direction change.
	FVector InitialLocation;
	FVector TargetLocation;

};

