// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(SceneRoot);

    DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshOfDoor"));
    DoorMesh->SetMobility(EComponentMobility::Movable);
    SceneRoot->SetupAttachment(SceneRoot);

    Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
    Collider->SetMobility(EComponentMobility::Stationary);
    DoorMesh->SetupAttachment(Collider);
    

}


// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
    BaseLocation = DoorMesh->GetComponentLocation();
    Distance = Goal - BaseLocation;
    Direction = Distance;
    Direction.Normalize();
    Velocity = Distance.Size() / Duration;
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (CurrentDirection != IsOpen && !IsAnimated)
    {
        CurrentDirection = IsOpen;
        IsAnimated = true;
    }

    else if (IsAnimated)
    {
        if (CurrentDirection) DoorMesh->AddLocalOffset(Direction * Velocity / DeltaTime, false, nullptr, ETeleportType::None);
        else DoorMesh->AddLocalOffset(-Direction * Velocity / DeltaTime, false, nullptr, ETeleportType::None);
        CurrentTime += DeltaTime;
        if (CurrentTime > Duration)
        {
            if (CurrentDirection) DoorMesh->SetRelativeLocation(Goal);
            if (!CurrentDirection) DoorMesh->SetRelativeLocation(BaseLocation);
            IsAnimated = false;
        }
    }
}

void ADoor::DeplaceDoor(bool direction)
{
    IsOpen = direction;
}
