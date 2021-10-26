#include "SummonerPersistentData.h"

FSummonerPersistentData::FSummonerPersistentData() {
    Name = "Uninitialized_Player";
    Inventory = TArray<UStorableInstance *>{};
    Decks = TArray<USummonerDeck *>{};
}
