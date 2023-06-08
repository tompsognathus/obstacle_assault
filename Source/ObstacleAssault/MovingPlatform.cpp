// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
	MovementDirection.GetSafeNormal();

	TargetLocation = InitialLocation + MovementDistance * MovementDirection;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	// Move the platform
	SetActorLocation(CurrentLocation + MovementSpeed * DeltaTime * MovementDirection);

	// Track how far the platform has travelled since last direction change.
	float DistanceFromInitialLocation = FVector::Dist(CurrentLocation, InitialLocation);

	// Reverse movement direction once the platform has travelled the desired distance.
	if (DistanceFromInitialLocation > MovementDistance)
	{
		MovementDirection *= -1;

		// Swap initial and target locations since the platform is about to move in the opposite direction.
		CurrentLocation = TargetLocation;
		TargetLocation = InitialLocation;
		InitialLocation = CurrentLocation;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();

	// Rotate the platform
	SetActorRotation(CurrentRotation + FRotator(0, RotationSpeed * DeltaTime, 0));
}

