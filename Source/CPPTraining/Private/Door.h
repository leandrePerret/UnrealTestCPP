// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Door.generated.h"

UCLASS()
class ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Collider;

	UPROPERTY(EditAnywhere)
	bool IsOpen = false;

	UPROPERTY(EditAnywhere)
	bool IsAnimated = false;

	UPROPERTY(EditAnywhere)
	FVector Goal = FVector(0., 0., 0.);

	UPROPERTY(EditAnywhere)
	float Duration = 0.;

	UPROPERTY(VisibleAnywhere)
	float Velocity = 0.;

	UPROPERTY(VisibleAnywhere)
	FVector Distance = FVector(0., 0., 0.);

	UPROPERTY(VisibleAnywhere)
	FVector Direction = FVector(0., 0., 0.);

	UPROPERTY(VisibleAnywhere)
	FVector BaseLocation = FVector(0., 0., 0.);

	UPROPERTY(VisibleAnywhere)
	bool CurrentDirection = false;

	UPROPERTY(VisibleAnywhere)
	float CurrentTime = 0.;

	UFUNCTION(BlueprintCallable)
	void DeplaceDoor(bool direction);
};
