#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "Untitled_DeckRPG/InstanceClasses/EnemyInstance.h"
#include "MissionDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FMissionWave {
	GENERATED_BODY()
	
	/// What enemies are in a wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MissionWave)
	TArray<FEnemyInstanceConfig> Enemies;
};

UCLASS(Blueprintable)
class UNTITLED_DECKRPG_API UMissionDataAsset : public UPrimaryDataAsset
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
	/// The waves for the mission, stored in the order that they appear
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MissionDataAsset)
	TArray<FMissionWave> Waves;
	
	// TODO: put in some information data for backdrops/scenery/global_effects/etc

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
	UFUNCTION(BlueprintCallable, Category=MissionDataAsset)
    virtual FPrimaryAssetId GetPrimaryAssetId() const override {
		return FPrimaryAssetId("Missions", GetFName());
	};
	
	// ===================
	// ===== METHODS =====
	// ===================
private:
protected:
public:
};
