#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "Untitled_DeckRPG/Core/DeckDataAsset.h"
#include "DeckEnemyAsset.generated.h"

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
	/// The name of the enemy
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyDataAsset)
	FString Name;

	/// Affects damage as; damage - DamageThreshold
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyDataAsset)
	float DamageThreshold;

	/// Affects damage as; damage - damage * DamageResistance
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyDataAsset)
	float DamageResistance;

	/// The Attack of this enemy
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyDataAsset)
	float Attack;

	/// Implement some sort of elemental resistance system
	// /// The Name of this 
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=MissionDataAsset)
	// int Resistances;
	//
	// /// The Name of this 
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=MissionDataAsset)
	// int Weaknesses;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	/** CDO constructor */
	UDeckEnemyAsset() { ItemType = "Enemies"; }
	
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
