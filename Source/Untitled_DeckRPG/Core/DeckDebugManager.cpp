#include "DeckDebugManager.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckArmorAsset.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckSummonAsset.h"
#include "Untitled_DeckRPG/Combat/DeckCombatCharacter.h"
#include "Untitled_DeckRPG/Combat/DeckSummonerCombatCharacter.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"

UDeckDebugManager::UDeckDebugManager() {}

void UDeckDebugManager::PostConstruct(ADeckPlayerController* controller) {
    controller->OnSummonObatained.AddDynamic(this, &UDeckDebugManager::PlayerGotSummon);
    controller->OnArmorObatained.AddDynamic(this, &UDeckDebugManager::PlayerGotArmor);
}

void UDeckDebugManager::PlayerGotArmor_Implementation(FDeckArmor armor) {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (IsValid(game_mode))
    {
        const auto controller = game_mode->GetPlayerController();
    
        FString msg = "The summoner, " + controller->GetSummonerName() +
            ", has attained a new piece of armor!\nA level " +
            FString::FromInt(armor.Level) + " set of " +
            armor.ArmorData->AssetName + "!";
        SCREEN_LOG_DEBUG(msg, 10.0);
    }
}

void UDeckDebugManager::PlayerGotSummon_Implementation(FDeckSummon summon) {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (IsValid(game_mode))
    {
        const auto controller = game_mode->GetPlayerController();
    
        FString msg = "The summoner, " + controller->GetSummonerName() +
            ", has attained a summon\nWelcome " +
            summon.SummonData->AssetName + " to our ranks!";
        SCREEN_LOG_DEBUG(msg, 10.0);
    }
#if WITH_EDITOR
    else
    {
        SCREEN_LOG("Player got item, but the game mode aint workin", 3, LogType_Error);
    }
#endif
}

void UDeckDebugManager::PlayerDamaged_Implementation(ADeckCombatCharacter * player, int32 amt) {
    FString msg = player->GetCharacterName() + " was attacked for " + FString::FromInt(amt) + " damage!";
    SCREEN_LOG_DEBUG(msg, 5);
}

void UDeckDebugManager::EnemyDamaged_Implementation(ADeckCombatCharacter* enemy, int32 amt) {
    FString msg = "An enemy called \"" + enemy->GetCharacterName() + "\" was attacked for " + FString::FromInt(amt) + " damage!";
    SCREEN_LOG_DEBUG(msg, 5);
}

void UDeckDebugManager::PlayerDied_Implementation(ADeckCombatCharacter* player) {
    SCREEN_LOG("The player , \"" + player->GetCharacterName() + "\", went and got killed :/", 5, LogType_Debug);
}

void UDebugFunctions::LogToScreen(FString cpp_location, FString msg, float time, ELogType log_type) {
#if WITH_EDITOR
    FColor color;
    switch(log_type)
    {
    case LogType_Error:
        color = FColor::Red;
        break;
    case LogType_Warning:
        color = FColor::Yellow;
        break;
    case LogType_Debug:
        color = FColor::Green;
        break;
    default:
        checkNoEntry();  
    }
    if(GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, time, color, cpp_location + ": " + msg);
    }
    LogToOutput(cpp_location, msg,  log_type);
#endif
}

void UDebugFunctions::LogToOutput(FString cpp_location, FString msg, ELogType log_type) {
#if WITH_EDITOR
    FString msg_declarer;
    switch(log_type)
    {
    case LogType_Error:
        msg_declarer = "Error: ";
        UE_LOG(LogTemp, Error, TEXT("%s: %s: %s"), *msg_declarer, *cpp_location, *msg);
        break;
    case LogType_Warning:
        msg_declarer = "Warning: ";
        UE_LOG(LogTemp, Warning, TEXT("%s: %s: %s"), *msg_declarer, *cpp_location, *msg);
        break;
    case LogType_Debug:
        msg_declarer = "Debug: ";
        UE_LOG(LogTemp, Display, TEXT("%s: %s: %s"), *msg_declarer, *cpp_location, *msg);
        break;
    default:
        checkNoEntry();  
    }
#endif
}

