#include "DeckDebugManager.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckArmorAsset.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckSummonAsset.h"
#include "Untitled_DeckRPG/New Classes/DeckCombatCharacter.h"
#include "Untitled_DeckRPG/New Classes/DeckSummonerCombatCharacter.h"
#include "Untitled_DeckRPG/New Classes/DeckCombatAttributes.h"
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
            armor.GetAsset()->ItemName.ToString() + "!";
        SCREENMSGT(msg, 10.0);
    }
}

void UDeckDebugManager::PlayerGotSummon_Implementation(FDeckSummon summon) {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (IsValid(game_mode))
    {
        const auto controller = game_mode->GetPlayerController();
    
        FString msg = "The summoner, " + controller->GetSummonerName() +
            ", has attained a summon\nWelcome " +
            summon.GetAsset()->ItemName.ToString() + " to our ranks!";
        SCREENMSGT(msg, 10.0);
    }
#if WITH_EDITOR
    else
    {
        SCREENMSGT("Player got item, but the game mode aint workin", 3);
    }
#endif
}

void UDeckDebugManager::PlayerDamaged_Implementation(ADeckCombatCharacter * player, int32 amt) {
    FString msg = player->CharacterName + " was attacked for " + FString::FromInt(amt) + " damage!";
    SCREENMSGT(msg, 5);
}

void UDeckDebugManager::EnemyDamaged_Implementation(ADeckCombatCharacter* enemy, int32 amt) {
    FString msg = "An enemy called \"" + enemy->CharacterName + "\" was attacked for " + FString::FromInt(amt) + " damage!";
    SCREENMSGT(msg, 5);
}

void UDeckDebugManager::PlayerDied_Implementation(ADeckCombatCharacter* player) {
    SCREENMSGT("The player , \"" + player->CharacterName + "\", went and got killed :/", 5);
}

