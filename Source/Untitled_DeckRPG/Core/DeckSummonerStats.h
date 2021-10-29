#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckSummonerStats.generated.h"


USTRUCT(BlueprintType)
struct FDeckSummonerStats {
    GENERATED_BODY()
    /** the player's chosen name */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    FString Name;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    int32 InventorySize; // TODO: eventually check/ limit inventory size
    
    /** All summons the player owns */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    TArray<FDeckSummon> InventorySummons;
    
    /** All armors the player owns */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    TArray<FDeckArmor> InventoryArmors;
    
    /// The decks the player has created
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    TArray<FDeckSummonerLoadout> LoadOuts;

    FDeckSummonerStats() :
    Name("__UNINITIALIZED_SUMMONER__"),
    InventorySize(100) {}
};
