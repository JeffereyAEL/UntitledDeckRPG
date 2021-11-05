#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "GameFramework/PlayerController.h"
#include "DeckPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventorySummonDelegate, FDeckSummon, instance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryArmorDelegate, FDeckArmor, instance);

class UDeckDebugManager;

UCLASS(BlueprintType)
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
	UPROPERTY(BlueprintReadOnly, Category=PlayerController)
	UDeckDebugManager * EventManager; // TODO: make this make sense

	/** broadcasts when the player has obtained a new armor instance */
	UPROPERTY(BlueprintAssignable, Category=PlayerController)
	FInventorySummonDelegate OnSummonObatained;

	/// broadcasts when the player has obtained a new armor instance
	UPROPERTY(BlueprintAssignable, Category=PlayerController)
	FInventoryArmorDelegate OnArmorObatained;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	ADeckPlayerController();

	virtual void PostInitializeComponents() override;
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	/// Sets the PlayerController's SummonerSpawn reference by replacing PersistentData
	UFUNCTION(BlueprintCallable, Category=PlayerController)
	void SetPersistentData(FDeckSummonerStats persistent_data);

	/// Gets the PlayerController's SummonerSpawn reference (IE, the USummonerPersistentData)
	UFUNCTION(BlueprintCallable, Category=PlayerController)
    FDeckSummonerStats GetPersistentData() const { return PersistentData; };
	
	/// Returns the player's chosen name
	UFUNCTION(BlueprintCallable, Category=PlayerController)
	FString GetSummonerName() const { return PersistentData.Name; }

	UFUNCTION(BlueprintCallable, Category=PlayerController)
	UDeckDebugManager* GetDebugger() const;

	/** Get all summons the player owns */
	UFUNCTION(BlueprintCallable, Category=PlayerController)
	TArray<FDeckSummon> GetInventorySummons() const { return PersistentData.InventorySummons; }

	/** Get all armors the player owns */
	UFUNCTION(BlueprintCallable, Category=PlayerController)
	TArray<FDeckArmor> GetInventoryArmprs() const { return PersistentData.InventoryArmors; }

	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:\
	public:
	/** creates World reliant subobjects and properties */
	virtual void PostActorCreated() override;
	
	/// creates a copy of the given UDeckObjectInstance and appends that to the inventory of the current summoner
	UFUNCTION(BlueprintCallable, Category=PlayerController)
	void AppendInventorySummon(UDeckSummonAsset * asset);
	
	UFUNCTION(BlueprintCallable, Category=PlayerController)
    void AppendInventoryArmor(UDeckArmorAsset * armor);
	
	/// Saves the current player data
	UFUNCTION(BlueprintCallable, Category=PlayerController)
	void SaveSummoner() const;

	/// Loads the last saved instance of this player's data
	UFUNCTION(BlueprintCallable, Category=PlayerController)
    void LoadCurrentSummoner();
};
