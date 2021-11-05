#pragma once

#include "Components/WidgetComponent.h"

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

#include "Untitled_DeckRPG/Combat/DeckCombatCharacter.h"
/* parent class includes go here ^^^ */
#include "DeckEnemyCombatCharacter.generated.h"

/* native c++ class pre-declarations go here ^^^ */
/** DeckEnemyCombatCharacter doc string */
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ADeckEnemyCombatCharacter : public ADeckCombatCharacter {
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
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=EnemyCombatCharacter)
    UWidgetComponent * StatusUI;
	
    /** default UI for this character, initialization manage by subclasses */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=EnemyCombatCharacter)
    TSubclassOf<UUserWidget> UIClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=EnemyCombatCharacter)
    FDeckEnemy Configuration;
    
public:
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
private:
protected:
public:
    /** CDO Constructor */
    ADeckEnemyCombatCharacter();

    void PostInitializeComponents() override;
    
    void PostConstruction(FDeckEnemy configuration);
    
    // ===================
    // ===== METHODS =====
    // ===================
private:
protected:
public:
    virtual void BeginPlay() override;

    virtual void InitializeAttributes() override;
};
