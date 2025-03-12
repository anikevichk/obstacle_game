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

	SetUpDownPlatforms();
	SetRigthLeftPlatforms();
	SetPushingPlatforms();
	SetRotationPlatforms();
}

// Called every frame
void AmovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AmovingPlatform::MovePlatform(float DeltaTime){
	cube_location += move_direction * speed;
	SetActorTransform(FTransform(GetActorRotation(), cube_location));

	float distance = FVector::Dist(start_location, cube_location);
	if (distance >= move_distance){
		move_direction *= -1; 
		start_location = cube_location; 
	}

	UE_LOG(LogTemp, Warning, TEXT("MovePlatform: Position = %s"), *cube_location.ToString());
}

void AmovingPlatform::RotatePlatform(float DeltaTime){
	if (rotation_speed.IsNearlyZero()) return;

	AddActorLocalRotation(rotation_speed * DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("RotatePlatform: Rotation = %s"), *GetActorRotation().ToString());
}

void AmovingPlatform::SetPushingPlatforms(){
	TArray<AActor*> pushing_platform;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("pushing_platform"), pushing_platform);

	for (int32 i = 0; i < pushing_platform.Num(); i++){
		AmovingPlatform* Platform = Cast<AmovingPlatform>(pushing_platform[i]);
		if (Platform){
			Platform->SetActorScale3D(pushing_platform_size);
			Platform->speed = 20 + i*2;
			Platform->move_distance = 4000;
		}
		
	}
}

void AmovingPlatform::SetUpDownPlatforms(){
	TArray<AActor*> first_platform;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("first_platform"), first_platform);

	for (int32 i = 0; i < first_platform.Num(); i++){
		AmovingPlatform* Platform = Cast<AmovingPlatform>(first_platform[i]);
		if (Platform){
			Platform->SetActorScale3D(moving_platform_size);
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
}
void AmovingPlatform::SetRigthLeftPlatforms(){
	TArray<AActor*> second_platform;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("second_platform"), second_platform);

	for (int32 i = 0; i < second_platform.Num(); i++)
	{
		AmovingPlatform* Platform = Cast<AmovingPlatform>(second_platform[i]);
        if (Platform){
			Platform->SetActorScale3D(moving_platform_size);
			if (i == 0){
				Platform->speed = -2;
			}
            Platform->move_direction = FVector(1, 0, 0); 

        }
    }

}

void AmovingPlatform::SetRotationPlatforms(){
	TArray<AActor*> rotation_platform;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("rotation_platform"), rotation_platform);

	for (int32 i = 0; i < rotation_platform.Num(); i++)
	{
		AmovingPlatform* Platform = Cast<AmovingPlatform>(rotation_platform[i]);
        if (Platform){
            Platform->move_distance = 0; 
			Platform->speed = 0; 
			Platform->rotation_speed = FRotator(0, 90, 0);

			if (i>5){
				if (i%2 == 0){Platform->rotation_speed = FRotator(0, 180, 0); }
				else {Platform->rotation_speed = FRotator(0, 220, 0);}
			}
			
        }
    }
}