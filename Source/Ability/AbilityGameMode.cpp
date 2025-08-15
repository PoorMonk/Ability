// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityGameMode.h"
#include "AbilityCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAbilityGameMode::AAbilityGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
