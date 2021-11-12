// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckCombatText.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

UDeckCombatText::UDeckCombatText() {
	OUTPUT_LOG_DEBUG("CDO Constructor");
	TheRootWidget = nullptr;
	CombatDamageText = nullptr;
	
}

void UDeckCombatText::NativeConstruct() {
	Super::NativeConstruct();
	OUTPUT_LOG_DEBUG("Construct");
	
	TArray<UWidget*> widgets{};
	WidgetTree->GetAllWidgets(widgets);
	CombatDamageText = Cast<UTextBlock>(widgets[0]);
	if (!IsValid(CombatDamageText))
	{
		SCREEN_LOG("CombatDamageText isn't valid. BP implementations should have one widget that is a UTextBlock",
			5.f, LogType_Error);
		return;
	}
	
	if (!IsValid(CombatDamageTextFadeAnim)) { NO_ENTRY_LOG; return; }
	PlayAnimation(CombatDamageTextFadeAnim, 0.f, 1, EUMGSequencePlayMode::Forward,
		1.0f, false);
	
	SetPositionInViewport(InitialViewportPosition);
	
	FString damage_text_string = FString::FromInt(static_cast<int32>(CombatDamageValue));
	FText damage_text_text{};
	FLinearColor damage_text_color{};
	FSlateFontInfo damage_text_font{};
	if (bCritical)
	{
		damage_text_text = FText::FromString("CRIT " + damage_text_string);
		damage_text_color = FLinearColor::Red;
		damage_text_font = FontInfoCritical;
	}
	else
	{
		damage_text_text = FText::FromString(damage_text_string);
		damage_text_color = FLinearColor::Blue;
		damage_text_font = FontInfoNormal;
	}
	CombatDamageText->SetText(damage_text_text);
	CombatDamageText->SetColorAndOpacity(FSlateColor{damage_text_color});
	CombatDamageText->SetFont(damage_text_font);
	CombatDamageText->SetJustification(ETextJustify::Center);
}
