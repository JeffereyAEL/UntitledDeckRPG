#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "SummonerPlayerController.h"
#include "SummonerSaveData.h"
#include "SummonerGameMode.generated.h"

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ASummonerGameMode : public AGameModeBase
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
	/// The data save
	UPROPERTY()
	USummonerSaveData * SaveData;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	ASummonerGameMode() { PlayerControllerClass = ASummonerPlayerController::StaticClass(); };
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	/// returns the current SummonerPlayerController
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
	ASummonerPlayerController * GetPlayerController();
	
	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
	/// Called when the level loads
	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;
	
	/// Saves the player's current FSummonerPersistentData to the disk
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
	void SavePlayerPersistentData(struct FSummonerPersistentData data);

	/// Loads some FSummonerPersistentData from the disk given a valid save name
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
    FSummonerPersistentData LoadPlayerPersistentData(APlayerController* controller, const FString summoner_name);

	/// returns whether there is a save of the given summoner's name on the disk
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
    bool DoesSummonerSaveExist(const FString summoner_name);

	/// destroys the relative save data given a summoner name
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
	void EraseSummonerSave(const FString summoner_name);
};
