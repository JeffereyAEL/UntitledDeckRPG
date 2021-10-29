#include "DeckSummonerStats.h"

FDeckSummonerStats::FDeckSummonerStats() {
    Name = "Uninitialized_Player";
    Inventory = TArray<UDeckObjectInstance *>{};
    Decks = TArray<USummonerDeck *>{};
}
