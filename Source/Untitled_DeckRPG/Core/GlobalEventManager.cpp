#include "GlobalEventManager.h"
#include "SummonerGameMode.h"
#include "../Externals/DefinedDebugHelpers.h"
#include "Untitled_DeckRPG/InstanceClasses/StorableInstanceClasses/ArmorInstance.h"
#include "Untitled_DeckRPG/InstanceClasses/StorableInstanceClasses/SummonInstance.h"

UGlobalEventManager::UGlobalEventManager() {}

void UGlobalEventManager::PlayerGotItem_Implementation(UStorableInstance* item_instance) {
    auto game_mode = Cast<ASummonerGameMode>(GetWorld()->GetAuthGameMode());
    if (!IsValid(game_mode))
    {
#if WITH_EDITOR
        SCREENMSG("Unable to cast GetAuthGameMode() to ASummonerGameMode");
#endif
        return;
    }
    const auto controller = game_mode->GetPlayerController();
    if (IsValid(controller))
    {
        const auto storable_type = item_instance->GetStorableType();
        FString msg{};
        switch (storable_type)
        {
        case EStorableType::StorableType_Armor:
        {
            const auto armor_instance = Cast<UArmorInstance>(item_instance);
            msg = "The summoner, " + controller->GetSummonerName() +
                ", has attained a new piece of armor!\nA level " +
                FString::FromInt(armor_instance->Config.Level) + ", rank " +
                FString::FromInt(armor_instance->Config.Rank) + " set of " +
                armor_instance->GetAsset()->GetArmorName() + "!";
            SCREENMSGT(msg, 10.0);
            break;
        }
        case EStorableType::StorableType_Summon:
        {
            const auto summon_instance = Cast<USummonInstance>(item_instance);
            msg = "The summoner ," + controller->GetSummonerName() +
                " , has enchanted a new summon!\nWelcome ";
            msg += summon_instance->GetAsset()->GetSummonName() +
                " to your ranks!";
            SCREENMSGT(msg, 10.0);
            break;
        }
        default:
            SCREENMSGT("The player has attained an item of a currently unknown instance. This could be an error", 10.0);
            break;
        }
    }
#if WITH_EDITOR
    else
    {
        SCREENMSGT("During Event 'PlayerGotItem' GetPlayerController() return nullptr", 10);
    }
#endif
}

