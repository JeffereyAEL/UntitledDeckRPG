#include "DeckPlayerController.h"
#include "GlobalEventManager.h"
#include "DeckGameMode.h"
#include "../Externals/DefinedDebugHelpers.h"

ADeckPlayerController::ADeckPlayerController() {
}

void ADeckPlayerController::SetPersistentData(FDeckSummonerStats persistent_data) {
    PersistentData = persistent_data;
}

void ADeckPlayerController::BeginPlay() {
    Super::BeginPlay();
#if WITH_EDITOR
    SCREENMSG("SummonerPlayerController has been created");
#endif
    EventManager = NewObject<UGlobalEventManager>(this, UGlobalEventManager::StaticClass());
}

void ADeckPlayerController::AppendInventory(FDeckArmor armor) {
    OnArmorObatained.Broadcast(armor);
    PersistentData.InventoryArmors.Add(armor);
}

void ADeckPlayerController::AppendInventory(FDeckSummon summon) {
    OnSummonObatained.Broadcast(summon);
    PersistentData.InventorySummons.Add(summon);
}

void ADeckPlayerController::SaveSummoner() const {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    game_mode->SavePlayerPersistentData(PersistentData);
}

void ADeckPlayerController::LoadCurrentSummoner() {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    auto temp = game_mode->LoadPlayerPersistentData(this, PersistentData.Name);
#if WITH_EDITOR
    if (PersistentData.Name.Compare(temp.Name, ESearchCase::CaseSensitive) != 0)
    {
        SCREENMSGT("Couldn't load a save for the current summoner", 5);
        return;
    }
#endif
    PersistentData = temp;
}
