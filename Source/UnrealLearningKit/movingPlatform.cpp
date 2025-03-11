// Fill out your copyright notice in the Description page of Project Settings.


#include "movingPlatform.h"

// Sets default values
AmovingPlatform::AmovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AmovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	start_location = GetActorLocation();
}

// Called every frame
void AmovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

	SetActorScale3D(FVector(5, 5, 0.5));

	cube_location.Y = cube_location.Y + speed;
	SetActorLocation(cube_location);
	
    distination = FVector::Dist(start_location, cube_location);
    if (distination >= move_distance) {
        speed = -speed; 
		start_location = cube_location;
    }

}
