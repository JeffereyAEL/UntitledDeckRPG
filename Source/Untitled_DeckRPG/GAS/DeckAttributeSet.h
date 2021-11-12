#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "DeckAttributeSet.generated.h"

/** combines marcos from AttributeSet.h */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCappedAttributeModified, FGameplayAttributeData, AttributeCap, FGameplayAttributeData, Attribute);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChanged, FGameplayAttribute, Attribute, float, AbsoluteAmount);
class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class UNTITLED_DECKRPG_API UDeckAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
	// ======================
	// ===== PROPERTIES =====
	// ======================
private:
protected:
public:
	/** tracks the owner's maximum health */
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData HealthMax;
	ATTRIBUTE_ACCESSORS(UDeckAttributeSet, HealthMax);
	
	/** tracks the owner's health, tells us if the owner is alive, capped by HealthMax */
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDeckAttributeSet, Health);

	/** used to amplify the affects of the owner's combat abilities */
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_Power)
	FGameplayAttributeData Power;
	ATTRIBUTE_ACCESSORS(UDeckAttributeSet, Power);

	/** the barrier to causing damage to this set's owner, damage can't fall below 1 on a successful hit */
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_DamageThreshold)
	FGameplayAttributeData DamageThreshold;
	ATTRIBUTE_ACCESSORS(UDeckAttributeSet, DamageThreshold);

	/** modifies damage to owner after damageThreshold, damage - damageThreshold * (1.0 - damageResistance) */
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_DamageResistance)
	FGameplayAttributeData DamageResistance;
	ATTRIBUTE_ACCESSORS(UDeckAttributeSet, DamageResistance);

	/** a 'temporary' attribute for damage calculations */
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UDeckAttributeSet, Damage);

	/** broadcast whenever HealthMax/Health is modified */
	UPROPERTY(BlueprintAssignable, Category="Attributes|Events")
	FCappedAttributeModified HealthModified;

	/** broadcast whenever Health is lowered */
	UPROPERTY(BlueprintAssignable, Category="Attributes|Events")
	FAttributeChanged Damaged;

	/** broadcast whenever Health is raised */
	UPROPERTY(BlueprintAssignable, Category="Attributes|Events")
	FAttributeChanged Healed;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
	public:
	/** CDO Constructor */
	UDeckAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
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
	UFUNCTION()
	virtual void OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax);
	UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
    virtual void OnRep_Power(const FGameplayAttributeData& OldPower);
	UFUNCTION()
    virtual void OnRep_DamageThreshold(const FGameplayAttributeData& OldDamageThreshold);
	UFUNCTION()
    virtual void OnRep_DamageResistance(const FGameplayAttributeData& OldDamageResistance);
	UFUNCTION()
    virtual void OnRep_Damage(const FGameplayAttributeData& OldDamage);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
