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
    void PostConstruction(FDeckSummonerStats config, int deck_num = 0);
    
    // ======================
    // ===== PROPERTIES =====
    // ======================
private:
protected:
	/** where you are in the player's current deck during their turn */
	int SummonIdx;
	
	/** initializes default attributes */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AttrbuteSet")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;
	
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
    /** returns the index to the active summon in the player's deck, returns -1 during the enemies turn **/
    UFUNCTION(BlueprintCallable, Category=SummonerCombatCharacter)
    int GetCurrentDeckIdx() const { return bIsTurn ? SummonIdx : -1; }

    /** returns the summon instance structure from the given index in player's deck */
    UFUNCTION(BlueprintCallable, Category=SummonerCombatCharacter)
    FDeckSummon GetSummonAtIdx(int summon_idx) const { return Loadout.Summons[summon_idx]; }
    
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
    
    UFUNCTION(BlueprintCallable, Category=SummonerCombatCharacter)
    void AttackSingleTargetForAction();
	
    UFUNCTION(BlueprintCallable, Category=SummonerCombatCharacter)
    void AttackAllTargetsForAction();
    
    /** executes the current special as long as the player has >0 mana */
    UFUNCTION(BlueprintCallable, Category=SummonerCombatCharacter)
    void UseCurrentSpecialForAction();
    
    /** an event for handling internal summoner turn logic */
    UFUNCTION(BlueprintNativeEvent, Category=SummonerCombatCharacter)
    void OnActionTaken();
    void OnActionTaken_Implementation();

	virtual void InitializeAttributes() override;
};
 
