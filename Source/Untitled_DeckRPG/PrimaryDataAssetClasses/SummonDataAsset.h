#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "SummonDataAsset.generated.h"

/// Describes what any given FSummonAction does
UENUM(BlueprintType)
enum EActionType{
	/// attacks
	Action_Damage UMETA(DisplayName="Damage"),

	/// raises attack
    Action_AttackBuff UMETA(DisplayName="AttackBuff"),

	/// lowers attack
    Action_AttackDebuff UMETA(DisplayName="AttackDebuff"),

	/// raises defense
    Action_DefenseBuff UMETA(DisplayName="DefenseBuff"),

	/// lowers defense
    Action_DefenseDebuff UMETA(DisplayName="DefenseDebuff"),

	/// heals
    Action_Heal UMETA(DisplayName="Heal"),

	/// modifies damage
	Action_DamageMod UMETA(DisplayName="DamageMod")
};

/// Describes the different target types that an FSummonAction can have
UENUM(BlueprintType)
enum EActionTarget {
	/// affects the caster
	Target_Self UMETA(DisplayName="Self"),

	/// affects a targeted enemy
    Target_EnemyActor UMETA(DisplayName="EnemyActor"),

	/// affects all enemies
    Target_AllEnemyActors UMETA(DisplayName="AllEnemyActors"),

	/// affects all enemies and the caster
    Target_AllActors UMETA(DisplayName="AllActors"),

	/// affects the next summon
	Target_NextSummon UMETA(DisplayName="NextSummon")
};

/// An element of any given USummonBase::Ability
/// (ex. FSummonAction(0, Target_Self, Action_Heal, 2.0) is the first
/// part of an ability; it heals the caster for two times the caster's attack
USTRUCT(BlueprintType)
struct FSummonAction {
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonAction)
	int Order;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonAction)
	TEnumAsByte<EActionType> Type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonAction)
	TEnumAsByte<EActionTarget> Target;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonAction)
	float Modifier;
};

UCLASS()
class UNTITLED_DECKRPG_API USummonActionFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
     
	public:
	UFUNCTION(BlueprintCallable)
    static FString ToString(const FSummonAction a, const class USummonInstance* s);
};

/// A reference class for Summons. Blueprint instances of this class define a specific Summon and then USummonInstance
/// blueprints define a Player's own version of that summon including their level and Rank.
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API USummonDataAsset : public UPrimaryDataAsset
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
	/// The Name of this 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonDataAsset)
	FString Name;
	
	/// The modifier for the effectiveness of native abilities
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonDataAsset)
	float Attack;

	/// The modifier for the resistance to foreign Abilities
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonDataAsset)
	float Defense;

	/// The special ability of this Summon
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonDataAsset)
	TArray<FSummonAction> Ability;
	
public:
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
	UFUNCTION(BlueprintCallable, Category=SummonDataAsset)
    float GetAttack() const { return Attack; }

	UFUNCTION(BlueprintCallable, Category=SummonDataAsset)
    float GetDefense() const { return Defense; }

	UFUNCTION(BlueprintCallable, Category=SummonDataAsset)
    TArray<FSummonAction> GetAbility() const { return Ability; }

	UFUNCTION(BlueprintCallable, Category=SummonDataAsset)
	FString GetSummonName() const { return Name; }

	UFUNCTION(BlueprintCallable, Category=SummonDataAsset)
	virtual FPrimaryAssetId GetPrimaryAssetId() const override {
		
		return FPrimaryAssetId("Summons", GetFName());
	};
	
	
	// ===================
	// ===== METHODS =====
	// ===================
private:
protected:
public:
};
