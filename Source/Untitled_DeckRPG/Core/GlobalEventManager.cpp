#include "GlobalEventManager.h"
#include "DeckGameMode.h"
#include "../Externals/DefinedDebugHelpers.h"
#include "Untitled_DeckRPG/InstanceClasses/StorableInstanceClasses/ArmorInstance.h"
#include "Untitled_DeckRPG/InstanceClasses/StorableInstanceClasses/SummonInstance.h"

UGlobalEventManager::UGlobalEventManager() {}
void UGlobalEventManager::PostConstruct(ADeckPlayerController* controller) {
    controller->OnSummonObatained.AddDynamic(this, &UGlobalEventManager::PlayerGotItem);
    controller->OnArmorObatained.AddDynamic(this, &UGlobalEventManager::PlayerGotItem);
}

void UGlobalEventManager::PlayerGotItem_Implementation(FDeckArmor armor) {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (!IsValid(game_mode))
    {
        const auto controller = game_mode->GetPlayerController();
    
        msg = "The summoner, " + controller->GetSummonerName() +
            ", has attained a new piece of armor!\nA level " +
            FString::FromInt(armor.Level) + " set of " +
            armor.ArmorData.GetAsset()->ItemName + "!";
        SCREENMSGT(msg, 10.0);
    }
}

void UGlobalEventManager::PlayerGotItem_Implementation(UDeckObjectInstance* item_instance) {
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (!IsValid(game_mode))
    {
#if WITH_EDITOR
        SCREENMSG("Unable to cast GetAuthGameMode() to ADeckGameMode");
#endif
        return;
    }
    const auto controller = game_mode->GetPlayerController();
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

