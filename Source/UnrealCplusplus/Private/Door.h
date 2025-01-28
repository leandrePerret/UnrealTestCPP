// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS(BlueprintType)
class ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY()
	bool PStateOpen = false;

	UPROPERTY(EditAnywhere)
	float PDuration = 0.;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	bool PStateOnAnimation = false;

	UPROPERTY()
	FVector PInitPose = FVector(0., 0., 0.);

	UPROPERTY()
	FVector POpenPose = FVector(0., 0., 0.);

	UPROPERTY()
	FVector PActualGoingTo = FVector(0., 0., 0.);

	UPROPERTY()
	float PUntil = 0.;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	UStaticMeshComponent* PDoor;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	UStaticMeshComponent* PGoTo;

	UPROPERTY()
	FVector PVelocity = FVector(0., 0., 0.);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void DeplaceDoor();
};
