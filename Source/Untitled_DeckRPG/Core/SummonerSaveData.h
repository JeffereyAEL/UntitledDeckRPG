#pragma once

#include "CoreMinimal.h"

#include "SummonerPersistentData.h"
#include "GameFramework/SaveGame.h"
#include "SummonerSaveData.generated.h"

UCLASS()
class UNTITLED_DECKRPG_API USummonerSaveData : public USaveGame
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
	UPROPERTY()
	bool bValidSave;

	UPROPERTY()
	FSummonerPersistentData ConstructedData;
	
	protected:
	public:
	UPROPERTY(EditAnywhere, Category=SummonerSaveData);
	FString Name;
	
	UPROPERTY(EditAnywhere, Category=SummonerSaveData);
	TArray<FStorableInstanceConfig> Inventory;
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	USummonerSaveData();

	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	UFUNCTION(BlueprintCallable, Category=SummonerSaveGame)
    bool IsValidSave() const { return bValidSave; }
	
	// ===================s
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
	UFUNCTION(BlueprintCallable, Category=SummonerSaveGame)
	void SetPlayerData(FSummonerPersistentData data);

	UFUNCTION(BlueprintCallable, Category=SummonerSaveGame)
	FSummonerPersistentData GetPlayerData(APlayerController* controller) const;

	UFUNCTION(BlueprintCallable, Category=SummonerSaveGame)
	void PostConstruction(FSummonerPersistentData data);
};
