#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "GameFramework/Actor.h"
#include "DeckCombatCharacter.generated.h"

class UDeckCombatAttributes;

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ADeckCombatCharacter : public AActor {
    GENERATED_BODY()
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
    private:
    protected:
    public:
    ADeckCombatCharacter();

    /** constructs an enemy character in combat given a configuration */
    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    virtual void PostConstruction(FDeckEnemy config);
    
    // ======================
    // ===== PROPERTIES =====
    // ======================
    private:
    protected:
    public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatCharacter)
    UDeckCombatAttributes * CharacterAttributes;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatCharacter)
    FString CharacterName;

    /** Whether it is this character's turn to make combat moves */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatCharacter)
    bool bIsTurn;

    /** the combat character to deal damage to */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatCharacter)
    ADeckCombatCharacter * Target;
    
    /** called at the start of every turn, before any calculations/actions have been taken */
    UPROPERTY(BlueprintAssignable, Category=CombatCharacter)
    FOnCombatStateChange TurnStart;

    /** called at the end of every turn, after all calculations/actions have been taken */
    UPROPERTY(BlueprintAssignable, Category=CombatCharacter)
    FOnCombatStateChange TurnEnd;

    /** called at the end of every turn, after all calculations/actions have been taken */
    UPROPERTY(BlueprintAssignable, Category=CombatCharacter)
    FOnAttributeStateChange TargetChanged;
    
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
    private:
    protected:
    public:
    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    void SetTarget(ADeckCombatCharacter * new_target);
    
    // ===================
    // ===== METHODS =====
    // ===================
    private:
    protected:
    public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=CombatCharacter)
    void TakeTurn();
    virtual void TakeTurn_Implementation();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=CombatCharacter)
    void EndTurn();
    virtual void EndTurn_Implementation();
};

