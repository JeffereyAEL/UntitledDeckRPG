#include "DeckEnemyCombatCharacter.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Blueprint/UserWidget.h"
#include "Untitled_DeckRPG/AssetClasses/DeckEnemyAsset.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"

ADeckEnemyCombatCharacter::ADeckEnemyCombatCharacter() {
    StatusUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("StatusUI"));
}

void ADeckEnemyCombatCharacter::PostInitializeComponents() {
    Super::PostInitializeComponents();

    StatusUI->RegisterComponent();
    StatusUI->SetupAttachment(RootComponent);
}

void ADeckEnemyCombatCharacter::PostConstruction(FDeckEnemy configuration) {
    UDeckEnemyAsset * asset = configuration.Asset;
    CharacterName = asset->AssetName;

    CombatTarget = nullptr;

    FString msg = "A level " + FString::FromInt(configuration.Level) + " " + CharacterName + " has spawned.";
    SCREEN_LOG_DEBUG(msg, 3.5);
}

void ADeckEnemyCombatCharacter::BeginPlay() {
    ApplyEffectToSelf(Configuration.Asset->DefaultAttributes);
    ApplyEffectToSelf(FullRevive);
    
    const auto world = GetWorld();
    if (!IsValid(world)) { NO_ENTRY_LOG; return; }
    const auto gamemode = Cast<ADeckGameMode>(world->GetAuthGameMode());
    if (!IsValid(gamemode)) { NO_ENTRY_LOG; return; }
    const auto controller = gamemode->GetPlayerController();
    if (!IsValid(controller)) { NO_ENTRY_LOG; return; }

    if (!IsValid(UIClass)) { NO_ENTRY_LOG; return; }
    auto widget = CreateWidget<UUserWidget>(controller, UIClass, TEXT("EnemyStatusUI"));
    if (!IsValid(UIClass)) { NO_ENTRY_LOG; return; }
    StatusUI->SetWidget(widget);
    
    Super::BeginPlay();
}

void ADeckEnemyCombatCharacter::InitializeAttributes() {
    Super::InitializeAttributes();
    SCREEN_LOG("Deferred enemy asset access until runtime", 2, LogType_Warning);
}

void ADeckEnemyCombatCharacter::OrientateAvatar() {
    Super::OrientateAvatar();
    FVector location = GetActorLocation();
    location += FVector(0, 0,
        CombatAvatar->GetCachedLocalBounds().BoxExtent.Z * 2.2f);
    StatusUI->SetWorldLocation(location,
        false, nullptr, ETeleportType::ResetPhysics);
}
