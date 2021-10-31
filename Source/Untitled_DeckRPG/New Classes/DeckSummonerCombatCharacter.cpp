#include "Untitled_DeckRPG/New Classes/DeckSummonerCombatCharacter.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Untitled_DeckRPG/New Classes/DeckCombatAttributes.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckSummonAsset.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckArmorAsset.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"
#include "Untitled_DeckRPG/Core/DeckDebugManager.h"
void ADeckSummonerCombatCharacter::PostConstructionSummoner(FDeckSummonerStats config, int deck_num) {
    CharacterAttributes = Cast<UDeckCombatAttributes>(
        AddComponentByClass(UDeckCombatAttributes::StaticClass(), false, GetTransform(), false)
    );

    Loadout = config.LoadOuts[deck_num];
    int32 TotalPower = 0, TotalDefense = 0;
    for (int i = 0; i < Loadout.Size; ++i)
    {
        UDeckSummonAsset * asset = Loadout.Summons[i].GetAsset();
        TotalPower += asset->ItemPower;
        TotalDefense += asset->ItemDefense;
    }

    GatherArmorData(Loadout.Head.GetAsset(), TotalPower, TotalDefense);
    GatherArmorData(Loadout.Chest.GetAsset(), TotalPower, TotalDefense);
    GatherArmorData(Loadout.Arms.GetAsset(), TotalPower, TotalDefense);
    GatherArmorData(Loadout.Legs.GetAsset(), TotalPower, TotalDefense);
    GatherArmorData(Loadout.Feet.GetAsset(), TotalPower, TotalDefense);

    CharacterName = config.Name;
    CharacterAttributes->PostConstruction(100, TotalPower, TotalDefense);
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (IsValid(game_mode))
    {
        auto controller = game_mode->GetPlayerController();
        CharacterAttributes->OnDamaged.AddDynamic(controller->GetDebugger(), &UDeckDebugManager::PlayerDamaged);
        CharacterAttributes->OnKilled.AddDynamic(controller->GetDebugger(), &UDeckDebugManager::PlayerDied);
    }
    Target = nullptr;
}

void ADeckSummonerCombatCharacter::GatherArmorData(UDeckArmorAsset* armor, int32& power, int32& defense) {
    if (IsValid(armor))
    {
        power += armor->ItemPower;
        defense += armor->ItemDefense;
    }
}

void ADeckSummonerCombatCharacter::TakeTurn_Implementation() {
    bIsTurn = true;
    TurnStart.Broadcast();
    SCREENMSGT(CharacterName + ", it's your turn player.", 5);
}

void ADeckSummonerCombatCharacter::EndTurn_Implementation() {
    SCREENMSGT(CharacterName + "- what? Why did you waste everyone's time doing that???", 5);
    bIsTurn = false;
    TurnEnd.Broadcast();
}

