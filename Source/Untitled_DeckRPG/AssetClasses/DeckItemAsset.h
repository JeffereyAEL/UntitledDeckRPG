#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

#include "Untitled_DeckRPG/Core/DeckDataAsset.h"
#include "DeckItemAsset.generated.h"

class UDeckGameplayAbility;

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckItemAsset : public UDeckDataAsset {
	GENERATED_BODY()
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	UDeckItemAsset() {}
	
	// ======================
	// ===== PROPERTIES =====
	// ======================
private:
protected:
public:
	/** The long description of this item show when clicked */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Item)
	FText ItemDescription;
	
	/** the short description of this item shown in pop-ups */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Item)
	FText ItemFlavorText;

	/** the ability of this item */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Item)
	TSubclassOf<UDeckGameplayAbility> ItemAbility;

	/** (used by summons) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Item)
	FText ItemAbilityDescription;
	
	
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