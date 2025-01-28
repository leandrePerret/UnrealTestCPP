// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	PVelocity = (PGoTo->GetComponentLocation() - PDoor->GetComponentLocation()) / PDuration;
	PInitPose = PDoor->GetComponentLocation();
	POpenPose = PGoTo->GetComponentLocation();
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (PStateOnAnimation)
	{
		if (PStateOpen)
		{
			if (DeltaTime > PUntil) SetActorLocation(PInitPose);
			else SetActorLocation(GetActorLocation() - PVelocity * DeltaTime);
		}

		else
		{
			if (DeltaTime > PUntil) SetActorLocation(POpenPose);
			else SetActorLocation(GetActorLocation() + PVelocity * DeltaTime);
		}
	}
}

void ADoor::DeplaceDoor()
{
	if (!PStateOnAnimation)
	{
		PStateOpen = !PStateOpen;
		PUntil = GetWorld()->GetDeltaSeconds() + PDuration;
		PActualGoingTo = PStateOpen ? PInitPose : PGoTo->GetComponentLocation();
		PStateOpen = !PStateOpen;
		PStateOnAnimation = true;
	}
}


