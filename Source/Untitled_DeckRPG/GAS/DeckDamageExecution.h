// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "GameplayEffectExecutionCalculation.h"
#include "DeckDamageExecution.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLED_DECKRPG_API UDeckDamageExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UDeckDamageExecution();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
