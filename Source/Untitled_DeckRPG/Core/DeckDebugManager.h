#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckDebugManager.generated.h"

class ADeckPlayerController;
class ADeckCombatCharacter;

/** achievements?? currently just a debug class */
UCLASS()
class UNTITLED_DECKRPG_API UDeckDebugManager : public UObject
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
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
	private:
	protected:
	public:
	UDeckDebugManager();

	void PostConstruct(ADeckPlayerController * controller);
	
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
	private:
	protected:
	public:
	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
	/// the current summoner attained a new item
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
	void PlayerGotArmor(FDeckArmor item_instance);
	virtual void PlayerGotArmor_Implementation(FDeckArmor item_instance);

	/// the current summoner attained a new item
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void PlayerGotSummon(FDeckSummon item_instance);
	virtual void PlayerGotSummon_Implementation(FDeckSummon summon);

	/// the summoner combat character took damage
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void PlayerDamaged(ADeckCombatCharacter * player, int32 amt);
	virtual void PlayerDamaged_Implementation(ADeckCombatCharacter * player, int32 amt);

	/// a default combat character took damage
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void EnemyDamaged(ADeckCombatCharacter * player, int32 amt);
	virtual void EnemyDamaged_Implementation(ADeckCombatCharacter * enemy, int32 amt);

	/// a summoner combat character died
	UFUNCTION(BlueprintNativeEvent, Category=GlobalEvents)
    void PlayerDied(ADeckCombatCharacter * player);
	virtual void PlayerDied_Implementation(ADeckCombatCharacter * player);
};

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDebugFunctions : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
	
public:
	/** prints a message to the screen and to the output log */
	UFUNCTION(BlueprintCallable, Category=DebugFunctions)
	static void LogToScreen(FString cpp_location, FString msg, float time, ELogType log_type = LogType_Debug);

	/** prints a message to the output log */
	UFUNCTION(BlueprintCallable, Category=DebugFunctions)
	static void LogToOutput(FString cpp_location, FString msg, ELogType log_type = LogType_Debug);
};

#define SCREEN_LOG(msg, time, log_type) UDebugFunctions::LogToScreen(CUR_CLASS_LINE, msg, time, log_type)
#define SCREEN_LOG_DEBUG(msg, time) UDebugFunctions::LogToScreen(CUR_CLASS_LINE, msg, time)
#define OUTPUT_LOG(msg, log_type) UDebugFunctions::LogToScreen(CUR_CLASS_LINE, msg, log_type)
#define OUTPUT_LOG_DEBUG(msg) UDebugFunctions::LogToScreen(CUR_CLASS_LINE, msg)
#define NOT_IMPLEMENTED_LOG SCREEN_LOG("Function not implemented", 3, LogType_Warning)
#define NO_ENTRY_LOG SCREEN_LOG("Code should not be reached", 7.5, LogType_Warning)