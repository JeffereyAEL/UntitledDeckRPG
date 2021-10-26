#include "SummonerPlayerController.h"
#include "GlobalEventManager.h"
#include "SummonerGameMode.h"
#include "../Externals/DefinedDebugHelpers.h"

ASummonerPlayerController::ASummonerPlayerController() {
}

void ASummonerPlayerController::SetPersistentData(FSummonerPersistentData persistent_data) {
    PersistentData = persistent_data;
}

void ASummonerPlayerController::BeginPlay() {
    Super::BeginPlay();
#if WITH_EDITOR
    SCREENMSG("SummonerPlayerController has been created");
#endif
    EventManager = NewObject<UGlobalEventManager>(this, UGlobalEventManager::StaticClass());
    OnItemObtained.AddDynamic(EventManager, &UGlobalEventManager::PlayerGotItem);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void ASummonerPlayerController::AppendSummonerInventor(UStorableInstance* instance) {
    OnItemObtained.Broadcast(instance);
    PersistentData.Inventory.Add(instance);
}

void ASummonerPlayerController::SaveSummoner() const {
    auto game_mode = Cast<ASummonerGameMode>(GetWorld()->GetAuthGameMode());
    game_mode->SavePlayerPersistentData(PersistentData);
}

void ASummonerPlayerController::LoadCurrentSummoner() {
    auto game_mode = Cast<ASummonerGameMode>(GetWorld()->GetAuthGameMode());
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
