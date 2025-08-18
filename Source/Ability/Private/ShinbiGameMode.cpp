// Fill out your copyright notice in the Description page of Project Settings.


#include "ShinbiGameMode.h"

#include "ShinbiCharacter.h"
#include "ShinbiPlayerController.h"

AShinbiGameMode::AShinbiGameMode()
{
	PlayerControllerClass = AShinbiPlayerController::StaticClass();
	DefaultPawnClass = AShinbiCharacter::StaticClass();
}
