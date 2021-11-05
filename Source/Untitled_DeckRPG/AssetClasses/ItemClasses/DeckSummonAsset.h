#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "Untitled_DeckRPG/AssetClasses/DeckItemAsset.h"
#include "DeckSummonAsset.generated.h"

/** defines a Summon Item */
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckSummonAsset : public UDeckItemAsset
{
	GENERATED_BODY()

	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	UDeckSummonAsset() { AssetType = "Summons"; }
	
	// ======================
	// ===== PROPERTIES =====
	// ======================
	private:
	protected:
	public:
	/** combines with the name to make the summon sound impressive
	 *  Common', being a combat summon is a competitive industry, cut them some slack
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Summon)
	FText SummonTitle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Summon)
	float BasePower;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Armor)
	TSubclassOf<UDeckGameplayAbility> SpecialAbility;
	
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
