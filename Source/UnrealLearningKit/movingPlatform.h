// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "movingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AmovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector start_location;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector cube_location;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector move_direction = FVector(1, 0, 0); 

	UPROPERTY(EditAnywhere, Category = "Movement")
	float speed = 3;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float move_distance = 500;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator rotation_speed= FRotator(0, 0, 0);

	UPROPERTY(EditAnywhere)
	FVector moving_platform_size = FVector(1, 1, 2);

	UPROPERTY(EditAnywhere)
	FVector pushing_platform_size = FVector(1, 1, 1);

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	void SetPushingPlatforms();
	void SetUpDownPlatforms();
	void SetRigthLeftPlatforms();
	void SetRotationPlatforms();
};
                           