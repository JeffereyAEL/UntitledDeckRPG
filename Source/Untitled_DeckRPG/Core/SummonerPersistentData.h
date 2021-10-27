#pragma once

#include "CoreMinimal.h"

#include "../InstanceClasses/StorableInstance.h"
#include "../SummonerDeck.h"
#include "SummonerPersistentData.generated.h"

UCLASS()
class UNTITLED_DECKRPG_API USummonerDeck : public UObject {
    GENERATED_BODY()
    USummonerDeck() = default;
};

USTRUCT(BlueprintType)
struct FSummonerPersistentData {
    GENERATED_BODY()
    /// The Player's chosen name
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerPersistentData)
    FString Name;

    /// All armor, items, and summons the player owns
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerPersistentData)
    TArray<UStorableInstance*> Inventory;

    /// The decks the player has created
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerPersistentData)
    TArray<USummonerDeck*> Decks;

    FSummonerPersistentData();
};
