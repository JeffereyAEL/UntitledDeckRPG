// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled_DeckRPG/Combat/DeckAttributeSet.h"

#include "Net/UnrealNetwork.h"

#include "Untitled_DeckRPG/DeckCPPHelper.h"

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
    HealthModified.Broadcast(HealthMax, Health);
}

void UDeckAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) {
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDeckAttributeSet, Health, OldHealth);
    HealthModified.Broadcast(HealthMax, Health);
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

