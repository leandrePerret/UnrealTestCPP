// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealCplusplusGameMode.h"
#include "UnrealCplusplusCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealCplusplusGameMode::AUnrealCplusplusGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
