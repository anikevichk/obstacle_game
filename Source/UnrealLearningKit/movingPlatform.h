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

	UPROPERTY(EditAnywhere)
	FVector cube_location = FVector(-13850.0, -2840.0, 4050.0);

	UPROPERTY(EditAnywhere)
	FVector current_location;

	UPROPERTY(EditAnywhere)
	FVector start_location;

	//-----------------------------------

	UPROPERTY(EditAnywhere, Category = "Distination")
	float speed = 3;

	UPROPERTY(EditAnywhere, Category = "Distination")
	float distination = -1;

	UPROPERTY(EditAnywhere, Category = "Distination")
	float move_distance = 500;
};
                           