// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "Blutility/Classes/EditorUtilityWidget.h"
#include "DeckCombatText.generated.h"

class UTextBlock;
class UCanvasPanel;

/**
 * 
 */
UCLASS(Abstract)
class UNTITLED_DECKRPG_API UDeckCombatText : public UEditorUtilityWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DeckCombatText)
	UCanvasPanel * TheRootWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=DeckCombatText)
	UTextBlock * CombatDamageText;

	UPROPERTY(BlueprintReadWrite, Category=DeckCombatText)
	FVector2D FinalViewportPosition;
	
public:
	UPROPERTY(BlueprintReadOnly, Category=DeckCombatText)
	float CombatDamageValue UMETA(ExposeOnSpawn="true");

	UPROPERTY(BlueprintReadOnly, Category=DeckCombatText)
	bool bCritical UMETA(ExposeOnSpawn="true");

	UPROPERTY(BlueprintReadOnly, Category=DeckCombatText)
	FVector2D InitialViewportPosition UMETA(ExposeOnSpawn="true");

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DeckCombatText, Transient)
	UWidgetAnimation * CombatDamageTextFadeAnim UMETA(BindWidgetAnim);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=DeckCombatText)
	FSlateFontInfo FontInfoCritical;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=DeckCombatText)
	FSlateFontInfo FontInfoNormal;

	UDeckCombatText();
	
	virtual void NativeConstruct() override;
};