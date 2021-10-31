#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "Untitled_DeckRPG/Core/DeckDataAsset.h"
#include "DeckItemAsset.generated.h"

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckItemAsset : public UDeckDataAsset {
	GENERATED_BODY()
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	UDeckItemAsset() : MaxStackCount(1), ItemPower(0), ItemDefense(0) {}
	
	// ======================
	// ===== PROPERTIES =====
	// ======================
private:
protected:
public:
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
	// TODO: everything stacks in a stack of one, currently
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	int32 MaxStackCount;

	/** Amplifies this items abilities */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	int32 ItemPower;

	/** This items ability to resist external actions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	int32 ItemDefense;
	
	// /** The Max level of this item; <= 0 means infinite 
	//  *  This might get deprecated and moved into an Attribute Set 
	//  */
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	// int32 MaxLevel;

	// TODO: uncomment
	// /** The ability of this item (used by summons) */
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	// TArray<FDeckAction> ItemAbility;

	/** (used by summons) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
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