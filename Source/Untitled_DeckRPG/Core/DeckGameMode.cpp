#include "DeckGameMode.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"
#include "Untitled_DeckRPG/Core/DeckSaveGame.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"

ADeckGameMode::ADeckGameMode() { PlayerControllerClass = ADeckPlayerController::StaticClass(); }

ADeckPlayerController* ADeckGameMode::GetPlayerController() {
    auto controller = Cast<ADeckPlayerController>(GetWorld()->GetFirstPlayerController());
    if (!IsValid(controller))
    {
        SCREEN_LOG("SummonerGameMode was unable to cast first player controller to ADeckPlayerController", 5,
            LogType_Error);
        return nullptr;
    }
    return controller;
}

void ADeckGameMode::BeginPlay() {
    Super::BeginPlay();
    SCREEN_LOG_DEBUG("ADeckGameMode has been created", 5);
    auto controller =  GetPlayerController();
    if (!IsValid(controller))
    {
        SCREEN_LOG("Controller wasn't instaniated in time for summoner data instantiation", 5, LogType_Error);
        return;
    }
    auto new_player = FDeckSummonerStats{};
    new_player.Name = "The Debugger";
    controller->SetPersistentData(new_player);
}

void ADeckGameMode::SavePlayerPersistentData(FDeckSummonerStats data) {
    auto data_to_save = Cast<UDeckSaveGame>(
        UGameplayStatics::CreateSaveGameObject(UDeckSaveGame::StaticClass()));
    if (!IsValid(data_to_save)) 
    {
        SCREEN_LOG("saving Summoner Persistent Data; IsValid() = false", 10.0f, LogType_Error);
        return;
    }

    FString msg = "Saving data for summoner '" + data.Name + "'";
    SCREEN_LOG_DEBUG(msg, 10);
    
    data_to_save->SetPlayerData(data);
    if (!UGameplayStatics::SaveGameToSlot(data_to_save, data.Name, 0))
    {
        SCREEN_LOG("saving Summoner Persistent Data; UGameplayStatics::SaveGameToSlot() = false", 10.0f,
            LogType_Error);
    }
}

FDeckSummonerStats ADeckGameMode::LoadPlayerPersistentData(APlayerController* controller, const FString summoner_name) {
    UDeckSaveGame * temp_save = Cast<UDeckSaveGame>(UGameplayStatics::LoadGameFromSlot(summoner_name, 0));

    FDeckSummonerStats data{};
    if (IsValid(temp_save))
    {
        if (temp_save->IsValidSave())
        {
            return temp_save->GetPlayerData(controller);
        }
        else
        {
            FString msg = "loading Summoner Persistent Data of name '" + summoner_name + "' ; IsValidSave() = false";
            SCREEN_LOG(msg, 10.0f, LogType_Error);
        }
    }
    else
    {
#if WITH_EDITOR
        FString msg = "loading Summoner Persistent Data of name '" + summoner_name + "' ; IsValid() = false";
        SCREEN_LOG(msg, 10.0f, LogType_Error);
#endif
    }
    return data;
}

bool ADeckGameMode::DoesSummonerSaveExist(const FString summoner_name) {
    return UGameplayStatics::DoesSaveGameExist(summoner_name, 0);
}

void ADeckGameMode::EraseSummonerSave(const FString summoner_name) {
    UGameplayStatics::DeleteGameInSlot(summoner_name, 0);
}
