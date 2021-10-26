// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StorableInstance.generated.h"

UENUM(BlueprintType)
enum EStorableType {
	StorableType_None UMETA(DisplayName="NoneItem"),
    StorableType_Armor UMETA(DisplayName="Armor"),
    StorableType_Summon UMETA(DisplayName="Summon"),
    StorableType_Consumable UMETA(DisplayName="Consumable"),
    StorableType_Money UMETA(DisplayName="Money"),
    StorableType_Experience UMETA(DisplayName="Experience")
};

USTRUCT(BlueprintType)
struct FStorableInstanceConfig {
	GENERATED_BODY()
	/// The UPrimaryDataAsset of this item as EStorableType
	UPROPERTY(BlueprintReadOnly, Category=ArmorInstanceConfig)
	TEnumAsByte<EStorableType> StorableType;
	
	/// the data asset reference of FStorableInstanceConfig::StorableType
	UPROPERTY(BlueprintReadOnly, Category=ArmorInstanceConfig)
	FString AssetIDString;
	
	/// the level of the item
	UPROPERTY(BlueprintReadOnly, Category=ArmorInstanceConfig)
	int Level;

	/// the rank of the item
	UPROPERTY(BlueprintReadOnly, Category=ArmorInstanceConfig)
	int Rank;

	FStorableInstanceConfig();
};

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UStorableInstance : public UObject
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
	/// whether AssetReference has been loaded yet
	UPROPERTY(BlueprintReadOnly, Category=ArmorInstanceConfig)
	bool bAssetLoaded;
	
	/// the data asset reference of FStorableInstanceConfig::StorableType
	UPROPERTY(BlueprintReadOnly, Category=ArmorInstanceConfig)
	UDataAsset * AssetReference;
	
    public:
	/// Config of this storable item
	UPROPERTY(BlueprintReadOnly)
	FStorableInstanceConfig Config;
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
    private:
    protected:
    public:
    UStorableInstance();
    
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
    private:
    protected:
    public:
	/// returns the storable type of the item instance, defines the subclass for polymorphism
	UFUNCTION(BlueprintCallable, Category=StorableInstane)
	TEnumAsByte<EStorableType> GetStorableType() const { return Config.StorableType; }

	/// An internal setter function for deferred asset loading
	UFUNCTION()
	void SetAssetReference(FPrimaryAssetId primary_id);

	UFUNCTION(BlueprintCallable, Category=ArmorInstance)
	bool IsAssetLoaded() const { return bAssetLoaded; }
	
    // ===================
    // ===== METHODS =====
    // ===================
    private:
    protected:
    public:
	/// base initializer, can only be used on constructed subclasses of UStorableInstance
	UFUNCTION(BlueprintCallable, Category=StorableInstance)
	virtual void PostConstruction(FString id_string, int level, int rank);

	/// copy constructor, can be used on any instance of UStorableInstance or it's subclasses
	UFUNCTION(BlueprintCallable, Category=StorableInstance)
    void PostConstruction_Poly(UStorableInstance * instance);
};
 