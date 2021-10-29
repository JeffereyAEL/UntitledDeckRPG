#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "Untitled_DeckRPG/DeckItemAsset.h"
#include "SummonDataAsset.generated.h"

/** defines a Summon Item */
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API USummonDataAsset : public UDeckItemAsset
{
	GENERATED_BODY()
	USummonDataAsset() { ItemType = "Summons"; }
};
