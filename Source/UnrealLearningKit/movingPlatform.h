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

	UPROPERTY(EditAnywhere, Category = "Appearance")
	FVector platform_size = FVector(2, 2, 1);
};
                           