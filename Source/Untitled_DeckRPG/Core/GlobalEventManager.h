#pragma once

#include "CoreMinimal.h"

#include "GlobalEventManager.generated.h"

/// The base class for a global event handler, centralizes event-based class interactions
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
	void PlayerGotItem(class UStorableInstance* item_instance);
	virtual void PlayerGotItem_Implementation(UStorableInstance* item_instance);
};
