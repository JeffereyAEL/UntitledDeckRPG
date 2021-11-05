#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "Untitled_DeckRPG/Core/DeckDataAsset.h"
#include "DeckEnemyAsset.generated.h"

class UGameplayEffect;

UCLASS(Blueprintable)
class UNTITLED_DECKRPG_API UDeckEnemyAsset : public UDeckDataAsset
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
	
	/// the default attributes of this enemy when initialized
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Enemy)
	TSubclassOf<UGameplayEffect> DefaultAttributes;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	/** CDO constructor */
	UDeckEnemyAsset() { AssetType = "Enemies"; }
	
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
