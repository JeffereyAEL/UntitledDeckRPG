// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyInstance.generated.h"

USTRUCT(BlueprintType)
struct FEnemyInstanceConfig {
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyInstanceConfig)
	bool bBoss;
	
	/// the data asset reference of this config
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyInstanceConfig)
	FString AssetIDString;
	
	/// The level of the enemy
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyInstanceConfig)
	int Level;

	/// dictates what order enemies in the same wave attack
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyInstanceConfig)
	float Speed;
};

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UEnemyInstance : public UObject
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
