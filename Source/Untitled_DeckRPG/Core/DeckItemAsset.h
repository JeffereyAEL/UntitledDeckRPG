#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckItemAsset.generated.h"

UCLASS(Abstract, BlueprintType)
class UNTITLED_DECKRPG_API UDeckItemAsset : public UPrimaryDataAsset {
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	UDeckItemAsset() : MaxStackCount(1), MaxLevel(1) {}
	
	// ======================
	// ===== PROPERTIES =====
	// ======================
private:
protected:
public:
	/** The type of item this is, defined in native parent class */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	FPrimaryAssetType ItemType;
	
	/** The name of this item show in the Inventory */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	FText ItemName;
	
	/** The long description of this item show when clicked */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	FText ItemDescription;
	
	/** the short description of this item shown in pop-ups */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	FText ItemFlavorText;
	
	/** Max stack of items in one inventory slot; <= 0 means infinite */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	int32 MaxStackCount;

	/** Max stack of items in one inventory slot; <= 0 means infinite */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	int32 ItemPower;

	/** Max stack of items in one inventory slot; <= 0 means infinite */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	int32 ItemDefense;
	
	/** Max stack of items in one inventory slot; <= 0 means infinite 
	 *  This might get depricated and moved into an Attribute Set 
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	int32 MaxLevel;
	
	/** The ability of this item (used by summons) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	TArray<FDeckAction> ItemAbility;
	
	/** (used by summons) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	FText ItemAbilityDescription;
	
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
private:
protected:
public:
	/** returns a string representation of FPrimaryAssetId */
	FString GetAssetIdAsString() const { return GetPrimaryAssetId().ToString(); }
	
	/** Override of GetPrimaryAssetId, returns pair of ItemType : GetFName() */
	virtual FPrimaryAssetId GetPrimaryAssetId() const override { return FPrimaryAssetId(ItemType, GetFName()); }
	
	// ===================
	// ===== METHODS =====
	// ===================
private:
protected:
public:
};