#include "DeckSaveGame.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

UDeckSaveGame::UDeckSaveGame() : bValidSave(false) {}

void UDeckSaveGame::SetPlayerData(FDeckSummonerStats summoner_data) {
    SaveData = summoner_data;
    bValidSave = true;
}

FDeckSummonerStats UDeckSaveGame::GetPlayerData(APlayerController* controller) const {
    if (bValidSave) return SaveData;
    return FDeckSummonerStats{};
}

void UDeckSaveGame::PostConstruction(FDeckSummonerStats data) {
    SetPlayerData(data);
}
