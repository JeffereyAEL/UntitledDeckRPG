#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckCombatCharacter.h"
#include "DeckSummonerCombatCharacter.generated.h"

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ADeckSummonerCombatCharacter : public ADeckCombatCharacter {
    GENERATED_BODY()
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
    private:
    protected:
    public:
    ADeckSummonerCombatCharacter() : ADeckCombatCharacter() {}

    /** constructs a summoner character in combat given a configuration */
    UFUNCTION(BlueprintCallable, Category=SummonerCombatCharacter)
    void PostConstructionSummoner(FDeckSummonerStats config, int deck_num = 0);
    
    // ======================
    // ===== PROPERTIES =====
    // ======================
    private:
    protected:
    public:
    /** the deck the player is using for this combat instance */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonerCombatCharacter)
    FDeckSummonerLoadout Loadout;

    /** broadcasts every time the player takes an action */
    UPROPERTY(BlueprintAssignable, Category=SummonerCombatCharacter)
    FOnCombatStateChange ActionTaken;
    
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
    /** helper function for gathering stat information from DeckArmorAssets */
    inline void GatherArmorData(UDeckArmorAsset * armor, int32& power, int32& defense);
    
    public:
    virtual void TakeTurn_Implementation() override;

    virtual void EndTurn_Implementation() override;

    
};
 
