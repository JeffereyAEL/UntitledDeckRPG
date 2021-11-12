#include "DeckCombatManager.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "DeckSummonerCombatCharacter.h"
#include "DeckEnemyCombatCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Untitled_DeckRPG/Core/DeckGameMode.h"
#include "Untitled_DeckRPG/Core/DeckPlayerController.h"
#include "Components/ActorComponent.h"

ADeckCombatManager::ADeckCombatManager() {
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SummonerSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("SummonerSpawn"));
	EnemySpawn = CreateDefaultSubobject<USceneComponent>(TEXT("EnemySpawn"));
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCombatUI = nullptr;
	Summoner = nullptr;
	Enemy = nullptr;
}

void ADeckCombatManager::PostInitializeComponents() {
	Super::PostInitializeComponents();

	FAttachmentTransformRules rules = FAttachmentTransformRules::KeepWorldTransform;
	SummonerSpawn->RegisterComponent();
	SummonerSpawn->AttachToComponent(RootComponent, rules);
	EnemySpawn->RegisterComponent();
	EnemySpawn->AttachToComponent(RootComponent, rules);
	PlayerCamera->RegisterComponent();
	PlayerCamera->AttachToComponent(RootComponent, rules);
}


void ADeckCombatManager::BeginPlay() {
	const auto world = GetWorld();
	if (!IsValid(world)) { NO_ENTRY_LOG; return; }
	const auto gamemode = Cast<ADeckGameMode>(world->GetAuthGameMode());
	if (!IsValid(gamemode)) { NO_ENTRY_LOG; return; }
	const auto controller = gamemode->GetPlayerController();
	if (!IsValid(controller)) { NO_ENTRY_LOG; return; }

	if (!IsValid(CombatUIClass)) { NO_ENTRY_LOG; return; }
	PlayerCombatUI = CreateWidget<UUserWidget>(controller, CombatUIClass, TEXT("PlayerCombatUI"));
	if (!IsValid(CombatUIClass)) { NO_ENTRY_LOG; return; }
	PlayerCombatUI->AddToViewport();
	
	controller->Possess(this);

	
	if (!IsValid(SummonerToSpawn)) { NO_ENTRY_LOG; return; }
	auto params = FActorSpawnParameters{};
	params.Instigator = nullptr;
	params.Owner = this;
	params.Name = TEXT("SummonerAvatar");
	FVector location = SummonerSpawn->GetComponentLocation();
	FRotator rotation = SummonerSpawn->GetComponentRotation();
	Summoner = Cast<ADeckSummonerCombatCharacter>(
		world->SpawnActor(SummonerToSpawn, &location, &rotation, params)
		);
	Summoner->OrientateAvatar();

	if (!IsValid(EnemyToSpawn)) { NO_ENTRY_LOG; return; }
	params.Name = TEXT("EnemyAvatar");
	location = EnemySpawn->GetComponentLocation();
	rotation = EnemySpawn->GetComponentRotation();
	Enemy = Cast<ADeckEnemyCombatCharacter>(
		world->SpawnActor(EnemyToSpawn, &location, &rotation, params)
		);
	Enemy->OrientateAvatar();
	SCREEN_LOG_DEBUG("cpp", 5);

	// so the blueprint constructor is called after this, yes- I hate it too
	Super::BeginPlay();
}

