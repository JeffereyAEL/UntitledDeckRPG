// Fill out your copyright notice in the Description page of Project Settings.
#include "DeckDamageExecution.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "DeckAttributeSet.h"

struct DeckDamageStatistics {
	DECLARE_ATTRIBUTE_CAPTUREDEF(Power);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageThreshold);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

	DeckDamageStatistics() {
		DEFINE_ATTRIBUTE_CAPTUREDEF(UDeckAttributeSet, Power, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UDeckAttributeSet, DamageThreshold, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UDeckAttributeSet, DamageResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UDeckAttributeSet, Damage, Target, false);
	}
};

static const DeckDamageStatistics& DamageStatistics() {
	static DeckDamageStatistics stats;
	return stats;
}

UDeckDamageExecution::UDeckDamageExecution() {
	RelevantAttributesToCapture.Add(DamageStatistics().PowerDef);
	RelevantAttributesToCapture.Add(DamageStatistics().DamageThresholdDef);
	RelevantAttributesToCapture.Add(DamageStatistics().DamageResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatistics().DamageDef);
}

void UDeckDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const {
	auto target_component = ExecutionParams.GetTargetAbilitySystemComponent();
	auto source_component = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor * target_actor = target_component ? target_component->GetAvatarActor() : nullptr;
	AActor * source_actor = source_component ? source_component->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* target_tags = spec.CapturedTargetTags.GetAggregatedTags();
	const FGameplayTagContainer* source_tags = spec.CapturedSourceTags.GetAggregatedTags();

	FAggregatorEvaluateParameters eval_params;
	eval_params.SourceTags = source_tags;
	eval_params.TargetTags = target_tags;

	// damage = ( Power - DamageThreshold ) * (1.0 - DamageResistance)

	float Power = 0.f, DamageThreshold = 0.f, DamageResistance = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatistics().PowerDef, eval_params, Power);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatistics().DamageThresholdDef, eval_params, DamageThreshold);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatistics().DamageResistanceDef, eval_params, DamageResistance);

	float Damage = ( Power - DamageThreshold ) * (1.0 - DamageResistance);
	if (Damage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(DamageStatistics().DamageProperty, EGameplayModOp::Additive, Damage));
		
		auto target_attribute_set = target_component->GetSet<UDeckAttributeSet>();
		if (!IsValid(target_attribute_set)) { NO_ENTRY_LOG; return; }
		target_attribute_set->Damaged.Broadcast(UDeckAttributeSet::GetHealthAttribute(), Damage);
	}
}

