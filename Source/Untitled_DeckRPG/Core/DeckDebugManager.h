#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckDebugManager.generated.h"

class ADeckPlayerController;
class ADeckCombatCharacter;

/** achievements?? currently just a debug class */
UCLASS()
class UNTITLED_DECKRPG_API UDeckDebugManager : public UObject
{
	GENERATED_BODY()
	// ==============================
	// ===== DEFINES_/_TYPEDEFS =====
	// ==============================

	// ======================================
	// ===== FRIEND_FUNCTIONS_/_CLASSES =====
	// ======================================

	// ========================
	// ===== ENUM_CLASSES =====
	// ========================
	private:
	protected:
	public:
	// ==========================
	// ===== NESTED_CLASSES =====
	// ==========================
	private:
	protected:
	public:
	// ======================
	// ===== ATTRIBUTES =====
	// ======================
	private:
	protected:
	public:
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	UDeckDebugManager();

	void PostConstruct(ADeckPlayerController * controller);
	
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
	/// the current summoner attained a new item
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
	void PlayerGotArmor(FDeckArmor item_instance);
	virtual void PlayerGotArmor_Implementation(FDeckArmor item_instance);

	/// the current summoner attained a new item
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void PlayerGotSummon(FDeckSummon item_instance);
	virtual void PlayerGotSummon_Implementation(FDeckSummon summon);

	/// the summoner combat character took damage
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void PlayerDamaged(ADeckCombatCharacter * player, int32 amt);
	virtual void PlayerDamaged_Implementation(ADeckCombatCharacter * player, int32 amt);

	/// a default combat character took damage
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void EnemyDamaged(ADeckCombatCharacter * player, int32 amt);
	virtual void EnemyDamaged_Implementation(ADeckCombatCharacter * enemy, int32 amt);

	/// a summoner combat character died
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void PlayerDied(ADeckCombatCharacter * player);
	virtual void PlayerDied_Implementation(ADeckCombatCharacter * player);
};
