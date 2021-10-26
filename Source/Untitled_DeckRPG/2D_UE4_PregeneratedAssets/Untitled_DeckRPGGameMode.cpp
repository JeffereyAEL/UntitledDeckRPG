// Copyright Epic Games, Inc. All Rights Reserved.

#include "Untitled_DeckRPGGameMode.h"
#include "Untitled_DeckRPGCharacter.h"

AUntitled_DeckRPGGameMode::AUntitled_DeckRPGGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AUntitled_DeckRPGCharacter::StaticClass();	
}
