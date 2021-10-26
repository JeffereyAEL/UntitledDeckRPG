#pragma once

#include "CoreMinimal.h"

#include "SummonerPersistentData.h"
#include "GameFramework/PlayerController.h"
#include "SummonerPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStorableInstanceDelegate, class UStorableInstance*, storable_instance);

UCLASS()
class UNTITLED_DECKRPG_API ASummonerPlayerController : public APlayerController
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
	FSummonerPersistentData PersistentData;
	
	public:
	/// A reference to this summoner instance's achievement/event manager
	/// Instantiated based on FSummonerPersistentData
	UPROPERTY(BlueprintReadOnly, Category=SummonerPlayerController)
	class UGlobalEventManager * EventManager;

	/// A delegate for ItemObtained event broadcasting
	UPROPERTY(BlueprintAssignable, Category=SummonerPlayerController)
	FStorableInstanceDelegate OnItemObtained;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	ASummonerPlayerController();
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	/// Sets the PlayerController's Player reference by replacing PersistentData
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	void SetPersistentData(FSummonerPersistentData persistent_data);

	/// Gets the PlayerController's Player reference (IE, the USummonerPersistentData)
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
    FSummonerPersistentData GetPersistentData() const { return PersistentData; };
	
	/// Returns the player's chosen name
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	FString GetSummonerName() const { return PersistentData.Name; }

	/// Returns the current summoner's inventory
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	TArray<UStorableInstance*> GetInventory() const { return PersistentData.Inventory; }
	
	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
	UFUNCTION(BlueprintCallable)
    virtual void BeginPlay() override;
	
	/// creates a copy of the given UStorableInstance and appends that to the inventory of the current summoner
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	void AppendSummonerInventor(UStorableInstance * instance);

	/// Saves the current player data
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
	void SaveSummoner() const;

	/// Loads the last saved instance of this player's data
	UFUNCTION(BlueprintCallable, Category=SummonerPlayerController)
    void LoadCurrentSummoner();
};
