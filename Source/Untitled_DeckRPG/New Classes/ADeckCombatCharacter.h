#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

class UDeckCombatAttributes;
struct FDeckEnemyConfig;
struct FDeckSummonerStats;

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ADeckCombatCharacter : public ACharacter {
    GENERATED_BODY();
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
    private:
    protected:
    public:
    ADeckCombatCharacter() :
        CombatAttributes(nullptr) {}

    /** constructs an enemy character in combat given a configuration */
    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    virtual void PostConstruction(FDeckEnemyConfig config);

    /** constructs a summoner character in combat given a configuration.
     *  To be defined in a subclass, base class should assume enemy configuration
     */
    virtual void PostConstruction(FDeckSummonerStats config, int deck_number) = 0;
    
    // ======================
    // ===== PROPERTIES =====
    // ======================
    private:
    protected:
    public:
    UPROPERTY(VisibleAnywhere, BlueprintGetter, Category=CombatCharacter)
    UDeckCombatAttributes * CombatAttributes;
    
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
    private:
    protected:
    public:
    // ===================
    // ===== METHODS =====
    // ===================
    private:
    protected:
    public:
};

