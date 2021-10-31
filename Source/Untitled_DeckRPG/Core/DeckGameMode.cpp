#include "DeckGameMode.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"
#include "Untitled_DeckRPG/Core/DeckSaveGame.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"

ADeckGameMode::ADeckGameMode() { PlayerControllerClass = ADeckPlayerController::StaticClass(); }

ADeckPlayerController* ADeckGameMode::GetPlayerController() {
    auto controller = Cast<ADeckPlayerController>(GetWorld()->GetFirstPlayerController());
    if (!IsValid(controller))
    {
#if WITH_EDITOR
        SCREENMSGT("SummonerGameMode was unable to cast first player controller to ADeckPlayerController", 10);
#endif
        return nullptr;
    }
    return controller;
}

void ADeckGameMode::BeginPlay() {
    Super::BeginPlay();
#if WITH_EDITOR
    SCREENMSGT("ADeckGameMode has been created", 10);
    auto controller =  GetPlayerController();
    if (!IsValid(controller))
    {
        SCREENMSG("Controller wasn't instaniated in time for summoner data instantiation");
        return;
    }
    auto new_player = FDeckSummonerStats{};
    new_player.Name = "The Debugger";
    controller->SetPersistentData(new_player);
#endif
}

void ADeckGameMode::SavePlayerPersistentData(FDeckSummonerStats data) {
    auto data_to_save = Cast<UDeckSaveGame>(
        UGameplayStatics::CreateSaveGameObject(UDeckSaveGame::StaticClass()));
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
            FString msg = "Error loading Summoner Persistent Data of name '" + summoner_name + "' ; IsValidSave() = false";
            SCREENMSGT(msg, 10.0f);
        }
    }
    else
    {
#if WITH_EDITOR
        FString msg = "Error loading Summoner Persistent Data of name '" + summoner_name + "' ; IsValid() = false";
        SCREENMSGT(msg, 10.0f);
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
