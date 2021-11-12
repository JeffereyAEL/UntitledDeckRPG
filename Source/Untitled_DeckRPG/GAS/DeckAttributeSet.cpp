// Fill out your copyright notice in the Description page of Project Settings.

#include "DeckAttributeSet.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

UDeckAttributeSet::UDeckAttributeSet() :
    HealthMax(1),
    Health(HealthMax),
    Power(1),
    DamageThreshold(0),
    DamageResistance(0.0f),
    Damage(0) {
}

void UDeckAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UDeckAttributeSet, HealthMax, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDeckAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDeckAttributeSet, Power, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDeckAttributeSet, DamageThreshold, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDeckAttributeSet, DamageResistance, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDeckAttributeSet, Damage, COND_None, REPNOTIFY_Always);
}

void UDeckAttributeSet::OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax) {
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDeckAttributeSet, HealthMax, OldHealthMax);
    //HealthModified.Broadcast(HealthMax, Health);
}

void UDeckAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) {
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDeckAttributeSet, Health, OldHealth);
    //HealthModified.Broadcast(HealthMax, Health);
}

void UDeckAttributeSet::OnRep_Power(const FGameplayAttributeData& OldPower) {
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDeckAttributeSet, Power, OldPower);
}

void UDeckAttributeSet::OnRep_DamageThreshold(const FGameplayAttributeData& OldDamageThreshold) {
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDeckAttributeSet, DamageThreshold, OldDamageThreshold);
}

void UDeckAttributeSet::OnRep_DamageResistance(const FGameplayAttributeData& OldDamageResistance) {
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDeckAttributeSet, DamageResistance, OldDamageResistance);
}

void UDeckAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldDamage) {
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDeckAttributeSet, Damage, OldDamage);
}

void UDeckAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
    Super::PreAttributeChange(Attribute, NewValue);
}

void UDeckAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		const float LocalDamageDone = GetDamage();
		SetDamage(0.f);

		if (LocalDamageDone > 0)
		{
			// Apply the health change and then clamp it
			const float OldHealth = GetHealth();
			SetHealth(FMath::Clamp(OldHealth - LocalDamageDone, 0.0f, GetHealthMax()));
			HealthModified.Broadcast(HealthMax, Health);
		}
	}
}