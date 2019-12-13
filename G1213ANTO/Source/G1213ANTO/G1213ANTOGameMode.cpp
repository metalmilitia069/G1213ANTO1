// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "G1213ANTOGameMode.h"
#include "G1213ANTOHUD.h"
#include "G1213ANTOCharacter.h"
#include "UObject/ConstructorHelpers.h"

AG1213ANTOGameMode::AG1213ANTOGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AG1213ANTOHUD::StaticClass();
}
