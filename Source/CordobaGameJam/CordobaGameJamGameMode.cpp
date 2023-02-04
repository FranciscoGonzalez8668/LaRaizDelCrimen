// Copyright Epic Games, Inc. All Rights Reserved.

#include "CordobaGameJamGameMode.h"
#include "CordobaGameJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACordobaGameJamGameMode::ACordobaGameJamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
