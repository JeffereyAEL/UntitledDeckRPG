#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

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
	
	protected:
	public:
	UPROPERTY(BlueprintReadOnly, Category=SaveGame)
	FDeckSummonerStats SaveData;
	
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
	UFUNCTION(BlueprintCallable, Category=SaveGame)
    bool IsValidSave() const { return bValidSave; }
	
	// ===================s
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
	UFUNCTION(BlueprintCallable, Category=SaveGame)
	void SetPlayerData(FDeckSummonerStats data);

	UFUNCTION(BlueprintCallable, Category=SaveGame)
	FDeckSummonerStats GetPlayerData(APlayerController* controller) const;

	UFUNCTION(BlueprintCallable, Category=SaveGame)
	void PostConstruction(FDeckSummonerStats data);
};
