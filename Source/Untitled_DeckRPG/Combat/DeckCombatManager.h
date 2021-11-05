#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

/* parent class includes go here ^^^ */
#include "DeckCombatManager.generated.h"

class ADeckSummonerCombatCharacter;
class ADeckEnemyCombatCharacter;

/* native c++ class pre-declarations go here ^^^ */

/** DeckCombatManager doc string */
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ADeckCombatManager : public APawn {
	GENERATED_BODY()

	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	// ======================
	// ===== PROPERTIES =====
	// ======================
private:
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatManager)
	USceneComponent * SummonerSpawn;
	
	UPROPERTY(BlueprintReadOnly, Category=CombatManager)
	ADeckSummonerCombatCharacter * Summoner;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatManager)
	USceneComponent * EnemySpawn;
	UPROPERTY(BlueprintReadOnly, Category=CombatManager)
	ADeckEnemyCombatCharacter * Enemy;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatManager)
	UCameraComponent * PlayerCamera;

	UPROPERTY(BlueprintReadOnly, Category=CombatManager)
	UUserWidget * PlayerCombatUI;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=CombatManager)
	TSubclassOf<ADeckSummonerCombatCharacter> SummonerToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=CombatManager)
	TSubclassOf<ADeckEnemyCombatCharacter> EnemyToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=CombatManager)
	TSubclassOf<UUserWidget> CombatUIClass;
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
private:
protected:
public:
	/** CDO Constructor */
	ADeckCombatManager();

	virtual void PostInitializeComponents() override;
	
	// ===================
	// ===== METHODS =====
	// ===================
private:
protected:
public:
	virtual void BeginPlay() override;
};
