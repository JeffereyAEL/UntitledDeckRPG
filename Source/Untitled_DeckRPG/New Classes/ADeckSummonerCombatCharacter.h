#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "ADeckCombatCharacter.h"
#include "Untitled_DeckRPG/SummonerDeck.h"

#include "ADeckSummonerCombatCharacter.generated.h"

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ADeckSummonerCombatCharacter : public ADeckCombatCharacter {
    GENERATED_BODY();
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
    private:
    protected:
    public:
    ADeckSummonerCombatCharacter() : ADeckCombatCharacter() {}

    /** constructs a summoner character in combat given a configuration */
    virtual virtual void PostConstruction(FDeckSummonerStats config, int deck_num) override;
    
    // ======================
    // ===== PROPERTIES =====
    // ======================
    private:
    protected:
    public:
    FDeckSummonerLoadout Deck;
    
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
 
