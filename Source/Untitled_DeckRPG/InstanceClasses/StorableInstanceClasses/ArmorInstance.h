#pragma once

#include "CoreMinimal.h"

#include "../StorableInstance.h"
#include "../../PrimaryDataAssetClasses/ArmorDataAsset.h"
#include "ArmorInstance.generated.h"

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UArmorInstance : public UStorableInstance
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
	UArmorInstance();
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	/// returns the armor's asset reference as it's native class
	UFUNCTION(BlueprintCallable, Category=ArmorInstance)
	UArmorDataAsset* GetAsset() const;

	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
};
