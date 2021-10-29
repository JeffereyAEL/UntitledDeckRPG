#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "UDeckCombatAttributes.generated.h"

class ADeckCombatCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeModified, ADeckCombatCharacter *, target_character, int32, amt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeStateChange, ADeckCombatCharacter *, target_character);

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckCombatAttributes : public UActorComponent {
    GENERATED_BODY();
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
private:
protected:
public:
    UDeckCombatAttributes() :
    HealthMax(1),
    Health(HealthMax),
    Power(-1),
    Defense(-1) {}

    // ======================
    // ===== PROPERTIES =====
    // ======================
private:
protected:
    /** the max value of health */
    UPROPERTY(BlueprintReadOnly, Category=Attributes)
    int32 HealthMax;
    
    /** used to determine if a character is alive */
    UPROPERTY(BlueprintReadOnly, Category=Attributes)
    int32 Health;
	
    /** modifies the effects of the owner's actions */
    UPROPERTY(BlueprintReadOnly, Category=Attributes)
    int32 Power;
	
    /** modifies the effect on the owner from external actions */
    UPROPERTY(BlueprintReadOnly, Category=Attributes)
    int32 Defense;
    
public:
    /** executes when Health is lowered */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeModified OnDamaged;

    /** executes when Health is raised */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeModified OnHealed;

    /** executes when power is raised */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeModified OnPowerBuffed;

    /** executes when power is lowered */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeModified OnPowerDebuffed;

    /** executes when defense is raised */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeModified OnDefenseBuffed;

    /** executes when defense is lowered */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeModified OnDefenseDebuffed;

    /** executes when Health goes from positive to <= 0 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeStateChange OnKilled;

    /** executes when Health goes from <= 0 to positive */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AttributeDelegate)
    FOnAttributeStateChange OnRevived;
    
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
private:
protected:
public:
    UFUNCTION(BlueprintCallable, Category=Attributes)
    int32 GetHealth() const { return Health; }
    UFUNCTION(BlueprintCallable, Category=Attributes)
    int32 GetHealthMax() const { return HealthMax; }
    UFUNCTION(BlueprintCallable, Category=Attributes)
    int32 GetPower() const { return Power; }
    UFUNCTION(BlueprintCallable, Category=Attributes)
    int32 GetDefense() const { return Defense; }
    
    /** returns the damage that would be dealt to this object's owner given a power */
    UFUNCTION(BlueprintCallable, Category=Attributes)
    int32 CalcDamageFromPower(int32 modified_power);
    
    /** does a straight modification of the named attribute by the amount given */
    UFUNCTION(BlueprintCallable, Category=Attributes)
    void ApplyHealthDelta(int32 amt);

    /** does a straight modification of the named attribute by the amount given */
    UFUNCTION(BlueprintCallable, Category=Attributes)
    void ApplyHealthMaxDelta(int32 amt);

    /** does a straight modification of the named attribute by the amount given */
    UFUNCTION(BlueprintCallable, Category=Attributes)
    void ApplyAttackDelta(int32 amt);

    /** does a straight modification of the named attribute by the amount given */
    UFUNCTION(BlueprintCallable, Category=Attributes)
    void ApplyDefenseDelta(int32 amt);
    
    // ===================
    // ===== METHODS =====
    // ===================
private:
protected:
public:
    /** calls to the owning ADeckCombatCharacter for their initializing Attributes */
    virtual void BeginPlay() override;
};
