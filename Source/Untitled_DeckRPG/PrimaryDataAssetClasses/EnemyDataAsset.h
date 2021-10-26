// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLED_DECKRPG_API UEnemyDataAsset : public UPrimaryDataAsset
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=MissionDataAsset)
	FString Name;

	/// Affects damage as; damage - DamageThreshold
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=MissionDataAsset)
	float DamageThreshold;

	/// Affects damage as; damage - damage * DamageResistance
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=MissionDataAsset)
	float DamageResistance;

	/// The Attack of this enemy
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=MissionDataAsset)
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
