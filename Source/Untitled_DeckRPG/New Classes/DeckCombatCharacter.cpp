#include "Untitled_DeckRPG/New Classes/DeckCombatCharacter.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Untitled_DeckRPG/New Classes/DeckCombatAttributes.h"
#include "Untitled_DeckRPG/AssetClasses/DeckEnemyAsset.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"
#include "Untitled_DeckRPG/Core/DeckDebugManager.h"
ADeckCombatCharacter::ADeckCombatCharacter(): CharacterAttributes(nullptr) {
    CharacterAttributes = CreateDefaultSubobject<UDeckCombatAttributes>(TEXT("CharacterAttributes"));
}

void ADeckCombatCharacter::PostConstruction(FDeckEnemy config) {
    CharacterAttributes = Cast<UDeckCombatAttributes>(
        AddComponentByClass(UDeckCombatAttributes::StaticClass(), false, GetTransform(), false)
        );
    UDeckEnemyAsset * asset = config.Asset;
    CharacterName = asset->Name;
    CharacterAttributes->PostConstruction(100, asset->Attack, asset->DamageThreshold);
    auto game_mode = Cast<ADeckGameMode>(GetWorld()->GetAuthGameMode());
    if (IsValid(game_mode))
    {
        auto controller = game_mode->GetPlayerController();
        CharacterAttributes->OnDamaged.AddDynamic(controller->GetDebugger(), &UDeckDebugManager::EnemyDamaged);
    }
    Target = nullptr;
}

void ADeckCombatCharacter::SetTarget(ADeckCombatCharacter* new_target) {
    if (Target != new_target)
    {
        Target = new_target;
        TargetChanged.Broadcast(Target);
    }
}

void ADeckCombatCharacter::TakeTurn_Implementation() {
    bIsTurn = true;
    TurnStart.Broadcast();
    EndTurn();
    
}

void ADeckCombatCharacter::EndTurn_Implementation() {
    SCREENMSGT(CharacterName + " simple stood there and drooled for their turn.", 5);
    bIsTurn = false;
    TurnEnd.Broadcast();
}
