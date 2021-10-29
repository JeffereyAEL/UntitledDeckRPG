#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/SummonerDeck.h"


#include "GlobalEventManager.generated.h"

class ADeckPlayerController;

/** achievements?? currently just a debug class */
UCLASS()
class UNTITLED_DECKRPG_API UGlobalEventManager : public UObject
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
	UGlobalEventManager();

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
	void PlayerGotItem(FDeckArmor item_instance);
	virtual void PlayerGotItem_Implementation(FDeckArmor item_instance);

	/// the current summoner attained a new item
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void PlayerGotItem(FDeckSummon item_instance);
	virtual void PlayerGotItem_Implementation(FDeckSummon item_instance);
};
