#pragma once

#include "CoreMinimal.h"

#include "../StorableInstance.h"
#include "../../PrimaryDataAssetClasses/SummonDataAsset.h"
#include "UObject/NoExportTypes.h"
#include "SummonInstance.generated.h"

/// A Player relative instance of a USummonBase 
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API USummonInstance : public UStorableInstance
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
	USummonInstance();
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
private:
protected:
	public:
	/// returns the armor's asset reference as it's native class
	UFUNCTION(BlueprintCallable, Category=ArmorInstance)
	USummonDataAsset* GetAsset() const;

	/// Returns the Player relative attack of this summon
	UFUNCTION(BlueprintCallable)
	float GetAttack() const;

	/// Returns the Player relative defense of this summon
	UFUNCTION(BlueprintCallable)
	float GetDefense() const;

	/// Returns the Player relative ability text of this summon
	UFUNCTION(BlueprintCallable)
	FString GetAbilityAsText() const;
	
	// ===================
	// ===== METHODS =====
	// ===================
private:
protected:
public:
};
