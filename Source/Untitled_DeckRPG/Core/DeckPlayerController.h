#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckSummonerStats.h"
#include "GameFramework/PlayerController.h"
#include "DeckPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventorySummonDelegate, FDeckSummon, instance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryArmorDelegate, FDeckArmor, instance);
UCLASS()
class UNTITLED_DECKRPG_API ADeckPlayerController : public APlayerController
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
	/// The player's persistent data
	UPROPERTY()
	FDeckSummonerStats PersistentData;
	
	public:
	/// A reference to this summoner instance's achievement/event manager
	/// Instantiated based on FDeckSummonerStats
	UPROPERTY(BlueprintReadOnly, Category=SummonerPlayerController)
	class UGlobalEventManager * EventManager; // TODO: make this make sense

	/** broadcasts when the player has obtained a new armor instance */
	UPROPERTY(BlueprintAssignable, Category=SummonerPlayerController)
	FInventorySummonDelegate OnSummonObatained;

	/// broadcasts when the player has obtained a new armor instance
	UPROPERTY(BlueprintAssignable, Category=SummonerPlayerController)
	FInventoryArmorDelegate OnArmorObatained;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	ADeckPlayerController();
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	/// Sets the PlayerController's Player reference by replacing PersistentData
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	void SetPersistentData(FDeckSummonerStats persistent_data);

	/// Gets the PlayerController's Player reference (IE, the USummonerPersistentData)
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
    FDeckSummonerStats GetPersistentData() const { return PersistentData; };
	
	/// Returns the player's chosen name
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	FString GetSummonerName() const { return PersistentData.Name; }

	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
	UFUNCTION(BlueprintCallable)
    virtual void BeginPlay() override;
	
	/// creates a copy of the given UDeckObjectInstance and appends that to the inventory of the current summoner
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	void AppendInventory(FDeckSummon summon);
	
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
    void AppendInventory(FDeckArmor armor);
	
	/// Saves the current player data
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	void SaveSummoner() const;

	/// Loads the last saved instance of this player's data
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
    void LoadCurrentSummoner();
};
