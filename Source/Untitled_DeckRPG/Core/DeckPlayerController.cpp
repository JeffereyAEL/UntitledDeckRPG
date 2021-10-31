#include "DeckPlayerController.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckArmorAsset.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckSummonAsset.h"

ADeckPlayerController::ADeckPlayerController() {
}


void ADeckPlayerController::SetPersistentData(FDeckSummonerStats persistent_data) {
    PersistentData = persistent_data;
}

UDeckDebugManager* ADeckPlayerController::GetDebugger() const { return EventManager; }

void ADeckPlayerController::PostActorCreated() {
#if WITH_EDITOR
    SCREENMSG("SummonerPlayerController has been created");
#endif
    EventManager = NewObject<UDeckDebugManager>(this, UDeckDebugManager::StaticClass());
    EventManager->PostConstruct(this);
}

void ADeckPlayerController::AppendInventorySummon(UDeckSummonAsset* asset) {
    FDeckSummon summon{};
    summon.SummonData = FDeckAssetRef{Cast<UDataAsset>(asset)};
    OnSummonObatained.Broadcast(summon);
    PersistentData.InventorySummons.Add(summon);
}

void ADeckPlayerController::AppendInventoryArmor(UDeckArmorAsset * asset) {
    FDeckArmor armor{};
    armor.ArmorData = FDeckAssetRef{Cast<UDeckDataAsset>(asset)};
    OnArmorObatained.Broadcast(armor);
    PersistentData.InventoryArmors.Add(armor);
}


void ADeckPlayerController::SaveSummoner() const {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    game_mode->SavePlayerPersistentData(PersistentData);
}

void ADeckPlayerController::LoadCurrentSummoner() {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    auto temp = game_mode->LoadPlayerPersistentData(this, PersistentData.Name);

    if (PersistentData.Name.Compare(temp.Name, ESearchCase::CaseSensitive) != 0)
    {
#if WITH_EDITOR
        SCREENMSGT("Couldn't load a save for the current summoner", 5);
#endif
        return;
    }
    PersistentData = temp;
}

