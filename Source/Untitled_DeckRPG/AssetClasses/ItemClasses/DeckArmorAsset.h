#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

#include "Untitled_DeckRPG/AssetClasses/DeckItemAsset.h"
#include "DeckArmorAsset.generated.h"

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckArmorAsset : public UDeckItemAsset
{
	GENERATED_BODY()
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	UDeckArmorAsset() {
		AssetType = "Armors";
	}
	
	// ======================
	// ===== PROPERTIES =====
	// ======================
	private:
	protected:
	public:
	/// The Armor Type, modifies deck length
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Armor)
	TEnumAsByte<EDeckArmorWeight> Weight;

	/// The Armor location, summoners can only wear one of each armor in each location
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Armor)
	TEnumAsByte<EDeckArmorSlot> Slot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Armor)
	float BaseDamageThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Armor)
	float BaseDamageResistance;
	
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
