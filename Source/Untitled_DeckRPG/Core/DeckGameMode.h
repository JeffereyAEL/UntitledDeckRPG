#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

#include "GameFramework/GameModeBase.h"
#include "DeckGameMode.generated.h"

class UDeckSaveGame;
class ADeckPlayerController;

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API ADeckGameMode : public AGameModeBase
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
	UDeckSaveGame * SaveData;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	ADeckGameMode();
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	/// returns the current SummonerPlayerController
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
	ADeckPlayerController * GetPlayerController();
	
	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
	/// Called when the level loads
	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;
	
	/// Saves the player's current FDeckSummonerStats to the disk
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
	void SavePlayerPersistentData(struct FDeckSummonerStats data);

	/// Loads some FDeckSummonerStats from the disk given a valid save name
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
    FDeckSummonerStats LoadPlayerPersistentData(APlayerController* controller, const FString summoner_name);

	/// returns whether there is a save of the given summoner's name on the disk
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
    bool DoesSummonerSaveExist(const FString summoner_name);

	/// destroys the relative save data given a summoner name
	UFUNCTION(BlueprintCallable, Category=SummonerGameMode)
	void EraseSummonerSave(const FString summoner_name);
};
