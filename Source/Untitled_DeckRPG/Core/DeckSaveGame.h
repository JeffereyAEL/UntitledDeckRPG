#pragma once

#include "CoreMinimal.h"

#include "DeckSummonerStats.h"
#include "GameFramework/SaveGame.h"
#include "DeckSaveGame.generated.h"

UCLASS()
class UNTITLED_DECKRPG_API UDeckSaveGame : public USaveGame
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
	FDeckSummonerStats ConstructedData;
	
	protected:
	public:
	UPROPERTY(EditAnywhere, Category=SummonerSaveData);
	FString Name;
	
	UPROPERTY(EditAnywhere, Category=SummonerSaveData);
	TArray<FDeckArmor> Inventory;
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	UDeckSaveGame();

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
	void SetPlayerData(FDeckSummonerStats data);

	UFUNCTION(BlueprintCallable, Category=SummonerSaveGame)
	FDeckSummonerStats GetPlayerData(APlayerController* controller) const;

	UFUNCTION(BlueprintCallable, Category=SummonerSaveGame)
	void PostConstruction(FDeckSummonerStats data);
};
