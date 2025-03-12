// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
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
	cube_location = start_location;

	TArray<AActor*> first_platform;
	TArray<AActor*> second_platform;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("first_platform"), first_platform);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("second_platform"), second_platform);

	for (int32 i = 0; i < first_platform.Num(); i++){
		AmovingPlatform* Platform = Cast<AmovingPlatform>(first_platform[i]);
		if (Platform){
			if(i == 1){
				Platform->speed = 1.5;
			}
			else if (i == 2){
				Platform->speed = 1.25;
			}
			else {
				Platform->speed = 1; 
			}
		}
	}

	for (int32 i = 0; i < second_platform.Num(); i++)
	{
		AmovingPlatform* Platform = Cast<AmovingPlatform>(second_platform[i]);
        if (Platform){
			if (i == 0){
				Platform->speed = -2;
			}
            Platform->move_direction = FVector(1, 0, 0); 

        }
    }

	SetActorScale3D(platform_size);
}

// Called every frame
void AmovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

	cube_location += move_direction * speed;
	SetActorLocation(cube_location);

	float distance = FVector::Dist(start_location, cube_location);
	if (distance >= move_distance)
	{
		move_direction *= -1; 
		start_location = cube_location; 
	}
}
