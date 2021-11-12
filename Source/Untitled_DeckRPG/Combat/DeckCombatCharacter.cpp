#include "DeckCombatCharacter.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Animation/SkeletalMeshActor.h"
#include "Untitled_DeckRPG/AssetClasses/DeckEnemyAsset.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"
#include "Untitled_DeckRPG/Core/DeckDebugManager.h"
#include "Untitled_DeckRPG/GAS/DeckAbilitySystemComponent.h"
#include "Untitled_DeckRPG/GAS/DeckGameplayAbility.h"
#include "Untitled_DeckRPG/GAS/DeckAttributeSet.h"

ADeckCombatCharacter::ADeckCombatCharacter() :
    CharacterName("PostConstruction()_wasn't_called"),
    bIsTurn(false),
    CombatTarget(nullptr)
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    CombatAvatar = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CombatAvatar"));
    AbilitySystemComponent = CreateDefaultSubobject<UDeckAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

    AttributeSet = CreateDefaultSubobject<UDeckAttributeSet>(TEXT("AttributeSet"));
    InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("InputComponent"));
    
    ConstructorHelpers::FClassFinder<UGameplayEffect> full_revive_effect(TEXT("/Game/UntitledGame/Abilities/GE_FullRevive"));
    if (full_revive_effect.Succeeded()) {
        FullRevive = full_revive_effect.Class;
    }
    else { NO_ENTRY_LOG; }
}

void ADeckCombatCharacter::PostInitializeComponents() {
    Super::PostInitializeComponents();

    CombatAvatar->RegisterComponent();
    CombatAvatar->SetupAttachment(RootComponent);
    
    /* initialize character ability system information */
    AbilitySystemComponent->InitAbilityActorInfo(this, this);
    AbilitySystemComponent->RegisterComponent();
    InitializeAttributes();
    GiveAbilities(DefaultGameplayAbilities);
}

void ADeckCombatCharacter::SetCombatTarget(ADeckCombatCharacter* new_target) {
    if (CombatTarget != new_target)
    {
        CombatTarget = new_target;
        TargetChanged.Broadcast(CombatTarget);
    }
}

UAbilitySystemComponent* ADeckCombatCharacter::GetAbilitySystemComponent() const {
    return AbilitySystemComponent;
}

void ADeckCombatCharacter::GiveAbilities(TArray<TSubclassOf<UDeckGameplayAbility>> abilities) {
    if (HasAuthority() && AbilitySystemComponent)
    {
        for (auto& ability : abilities)
        {
            AbilitySystemComponent->GiveAbility(
                FGameplayAbilitySpec(ability, 1,
                    static_cast<int32>(ability.GetDefaultObject()->InputId), this));
        }
    }
    else NO_ENTRY_LOG;
}

void ADeckCombatCharacter::GiveAbility(TSubclassOf<UDeckGameplayAbility> ability, int32 level) {
    if (HasAuthority() && AbilitySystemComponent)
    {
        AbilitySystemComponent->GiveAbility(
                FGameplayAbilitySpec(ability, level,
                    static_cast<int32>(ability.GetDefaultObject()->InputId), this));
    }
    else NO_ENTRY_LOG;
}

void ADeckCombatCharacter::BeginPlay() {
    Super::BeginPlay();
}

void ADeckCombatCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> effect) {
    if (IsValid(AbilitySystemComponent))
    {
        if (!IsValid(effect)) {   NO_ENTRY_LOG; return; }   // if invalid effect, skip it
    
        // context for effects, ex who is attacking and who is being attacked
        FGameplayEffectContextHandle effect_context = AbilitySystemComponent->MakeEffectContext();
        effect_context.AddSourceObject(this);

        // the specifications for an effect- takes the context, an effect, and a given level
        FGameplayEffectSpecHandle spec_handle = AbilitySystemComponent->MakeOutgoingSpec(
            effect, 1, effect_context);
    
        if (spec_handle.IsValid())
        {
            // applies the given affect to self given the prior spec
            FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->
                ApplyGameplayEffectSpecToSelf(*spec_handle.Data.Get());
        }
        else NO_ENTRY_LOG;   
    }
    else NO_ENTRY_LOG;
}

void ADeckCombatCharacter::TakeTurn_Implementation() {
    bIsTurn = true;
    TurnStart.Broadcast();

    /* TODO: use enemy special if ready && valid, otherwise use default ability */

    EndTurn(); // the ability triggered above should call this when it's finished
}

void ADeckCombatCharacter::EndTurn_Implementation() {
    bIsTurn = false;
    TurnEnd.Broadcast();
}

void ADeckCombatCharacter::InitializeAttributes() {
}

void ADeckCombatCharacter::OrientateAvatar() {
    CombatAvatar->SetWorldLocation(GetActorLocation(),
        false, nullptr, ETeleportType::ResetPhysics);
    CombatAvatar->SetWorldRotation(GetActorRotation(),
        false, nullptr, ETeleportType::ResetPhysics);
}
