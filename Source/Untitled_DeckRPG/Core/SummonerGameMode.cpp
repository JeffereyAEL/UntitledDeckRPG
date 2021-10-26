#include "SummonerGameMode.h"

#include "SummonerSaveData.h"
#include "../Externals/DefinedDebugHelpers.h"

ASummonerPlayerController* ASummonerGameMode::GetPlayerController() {
    auto controller = Cast<ASummonerPlayerController>(GetWorld()->GetFirstPlayerController());
    if (!IsValid(controller))
    {
#if WITH_EDITOR
        SCREENMSGT("SummonerGameMode was unable to cast first player controller to ASummonerPlayerController", 10);
#endif
        return nullptr;
    }
    return controller;
}

void ASummonerGameMode::BeginPlay() {
    Super::BeginPlay();
#if WITH_EDITOR
    SCREENMSGT("ASummonerGameMode has been created", 10);
    auto controller =  GetPlayerController();
    if (!IsValid(controller))
    {
        SCREENMSG("Controller wasn't instaniated in time for summoner data instantiation");
        return;
    }
    auto new_player = FSummonerPersistentData{};
    new_player.Name = "The Debugger";
    controller->SetPersistentData(new_player);
#endif
}

void ASummonerGameMode::SavePlayerPersistentData(FSummonerPersistentData data) {
    auto data_to_save = Cast<USummonerSaveData>(
        UGameplayStatics::CreateSaveGameObject(USummonerSaveData::StaticClass()));
    if (!IsValid(data_to_save)) 
    {
#if WITH_EDITOR
        SCREENMSGT("Error saving Summoner Persistent Data; IsValid() = false", 10.0f);
#endif
        return;
    }
    
#if WITH_EDITOR
    FString msg = "Saving data for summoner '" + data.Name + "'";
    SCREENMSGT(msg, 10);
#endif
    data_to_save->SetPlayerData(data);
    if (!UGameplayStatics::SaveGameToSlot(data_to_save, data.Name, 0))
    {
#if WITH_EDITOR
        SCREENMSGT("Error saving Summoner Persistent Data; UGameplayStatics::SaveGameToSlot() = false", 10.0f);
#endif
    }
}

FSummonerPersistentData ASummonerGameMode::LoadPlayerPersistentData(APlayerController* controller, const FString summoner_name) {
    auto temp_save = Cast<USummonerSaveData>(UGameplayStatics::LoadGameFromSlot(summoner_name, 0));

    FSummonerPersistentData data{};
    if (IsValid(temp_save))
        if (temp_save->IsValidSave())
        {
            return temp_save->GetPlayerData(controller);
        }
    
#if WITH_EDITOR
    FString msg = "Error loading Summoner Persistent Data of name '" + summoner_name + "' ; IsValid() = false";
    SCREENMSGT(msg, 10.0f);
#endif
    return data;
}

bool ASummonerGameMode::DoesSummonerSaveExist(const FString summoner_name) {
    return UGameplayStatics::DoesSaveGameExist(summoner_name, 0);
}

void ASummonerGameMode::EraseSummonerSave(const FString summoner_name) {
    UGameplayStatics::DeleteGameInSlot(summoner_name, 0);
}
