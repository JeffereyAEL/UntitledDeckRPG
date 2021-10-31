#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckCombatAttributes.generated.h"

class ADeckCombatCharacter;

UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckCombatAttributes : public UActorComponent {
    GENERATED_BODY()
	
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

    UFUNCTION(BlueprintCallable)
    void PostConstruction(int32 health_max, int32 power, int32 defense);
    
    // ======================
    // ===== PROPERTIES =====
    // ======================
private:
protected:
    /** the max value of health */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
    int32 HealthMax;
    
    /** used to determine if a character is alive */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
    int32 Health;
	
    /** modifies the effects of the owner's actions */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
    int32 Power;
	
    /** modifies the effect on the owner from external actions */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
    int32 Defense;

    /* TODO: include combat stats ex. damage, healed, shielded, characters killed, etc */
    
public:
    /** executes when Health is lowered */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
    FOnAttributeModified OnDamaged;

    /** executes when Health is raised */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
    FOnAttributeModified OnHealed;

    /** executes when power is raised */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
    FOnAttributeModified OnPowerBuffed;

    /** executes when power is lowered */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
    FOnAttributeModified OnPowerDebuffed;

    /** executes when defense is raised */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
    FOnAttributeModified OnDefenseBuffed;

    /** executes when defense is lowered */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
    FOnAttributeModified OnDefenseDebuffed;

    /** executes when Health goes from positive to <= 0 */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
    FOnAttributeStateChange OnKilled;

    /** executes when Health goes from <= 0 to positive */
    UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category=AttributeDelegate)
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
    void ApplyHealthDelta(int32 amt, bool b_revivable = false);

    /** does a straight modification of the named attribute by the amount given */
    UFUNCTION(BlueprintCallable, Category=Attributes)
    void ApplyHealthMaxDelta(int32 amt);

    /** does a straight modification of the named attribute by the amount given */
    UFUNCTION(BlueprintCallable, Category=Attributes)
    void ApplyPowerDelta(int32 amt);

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
    // virtual void BeginPlay() override;
};
