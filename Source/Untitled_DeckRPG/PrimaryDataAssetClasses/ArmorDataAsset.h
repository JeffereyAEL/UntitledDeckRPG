// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ArmorDataAsset.generated.h"

UENUM(BlueprintType)
enum EArmorType {
	ArmorType_Light UMETA(DisplayName="Light"),

    ArmorType_Medium UMETA(DisplayName="Medium"),

    ArmorType_Heavy UMETA(DisplayName="Heavy")
};

UENUM(BlueprintType)
enum EArmorLocation {
	ArmorLocation_Head UMETA(DisplayName="Head"),

    ArmorLocation_Chest UMETA(DisplayName="Chest"),

    ArmorLocation_Arms UMETA(DisplayName="Arms"),

    ArmorLocation_Legs UMETA(DisplayName="Legs"),

    ArmorLocation_Feet UMETA(DisplayName="Feet")
};

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UArmorDataAsset : public UPrimaryDataAsset
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
	/// The armor's name
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ArmorDataAsset)
	FString Name;
	
	/// The Armor Type, modifies deck length
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ArmorDataAsset)
	TEnumAsByte<EArmorType> Type;

	/// The Armor location, summoners can only wear one of each armor in each location
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ArmorDataAsset)
	TEnumAsByte<EArmorLocation> Location;

	/// How much it adds to the defense of the Summoner
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ArmorDataAsset)
	float Defense;

	/// How much it adds to the attack of the Summoner
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ArmorDataAsset)
	float Attack;
	
	/// TODO: At some point figure out the actual combat system and damage formula
	/// so I know what properties to give everything
	// float PiercingResistance;
	
	/// TODO: add affects that can be a part of the base item
	/// IE, some higher tier armors will have base modifiers and abilities
	 
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
	UFUNCTION(BlueprintCallable, Category=ArmorDataAsset)
    float GetAttack() const { return Attack; }

	UFUNCTION(BlueprintCallable, Category=ArmorDataAsset)
    float GetDefense() const { return Defense; }

	/// returns the name of the data asset for this armor instance
	UFUNCTION(BlueprintCallable, Category=ArmorDataAsset)
    FString GetArmorName() const { return Name; }

	UFUNCTION(BlueprintCallable, Category=ArmorDataAsset)
	virtual FPrimaryAssetId GetPrimaryAssetId() const override {
		return FPrimaryAssetId("Armors", GetFName());
	};

	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:

};
