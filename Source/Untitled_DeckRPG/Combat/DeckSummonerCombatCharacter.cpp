#include "DeckSummonerCombatCharacter.h"

#include "DeckAbilitySystemComponent.h"

#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckSummonAsset.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckArmorAsset.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"
#include "Untitled_DeckRPG/Core/DeckDebugManager.h"

void ADeckSummonerCombatCharacter::PostConstruction(FDeckSummonerStats config, int deck_num) {
    Loadout = config.LoadOuts[deck_num];
    int32 TotalPower = 0, TotalDefense = 0;
    for (int i = 0; i < Loadout.Size; ++i)
    {
        UDeckSummonAsset * asset = Loadout.Summons[i].SummonData;
        TotalPower += asset->BasePower;
    }

    GatherArmorData(Loadout.Head.ArmorData, TotalPower, TotalDefense);
    GatherArmorData(Loadout.Chest.ArmorData, TotalPower, TotalDefense);
    GatherArmorData(Loadout.Arms.ArmorData, TotalPower, TotalDefense);
    GatherArmorData(Loadout.Legs.ArmorData, TotalPower, TotalDefense);
    GatherArmorData(Loadout.Feet.ArmorData, TotalPower, TotalDefense);

    CharacterName = config.Name;
    
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (IsValid(game_mode))
    {
        auto controller = game_mode->GetPlayerController();
    }
}

void ADeckSummonerCombatCharacter::InitializeAttributes() {
    Super::InitializeAttributes();
    ApplyEffectToSelf(DefaultAttributeEffect);
    ApplyEffectToSelf(FullRevive);
}

void ADeckSummonerCombatCharacter::GatherArmorData(UDeckArmorAsset* armor, int32& power, int32& defense) {
}

void ADeckSummonerCombatCharacter::TakeTurn_Implementation() {
    bIsTurn = true;
    SummonIdx = 0;
    TurnStart.Broadcast();
    SCREEN_LOG_DEBUG(CharacterName + ", it's your turn", 5);
}

void ADeckSummonerCombatCharacter::EndTurn_Implementation() {
    bIsTurn = false;
    TurnEnd.Broadcast();
}

void ADeckSummonerCombatCharacter::AttackSingleTargetForAction() {
    
}

void ADeckSummonerCombatCharacter::AttackAllTargetsForAction() {
    
}

void ADeckSummonerCombatCharacter::UseCurrentSpecialForAction() {
    
}

void ADeckSummonerCombatCharacter::OnActionTaken_Implementation() {
    SummonIdx += 1;
    if (SummonIdx == Loadout.Size) EndTurn();
}

