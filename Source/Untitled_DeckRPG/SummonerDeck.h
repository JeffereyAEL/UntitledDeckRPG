#pragma once

#include "CoreMinimal.h"

#include "SummonerDeck.generated.h"

UCLASS()
class UNTITLED_DECKRPG_API USummonerDeck : public UObject
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
	const int StandardDeckSize = 5;
	
	protected:
	public:
	UPROPERTY(BlueprintReadOnly, Category=Deck)
	int DeckSize;
	
	UPROPERTY(BlueprintReadOnly, Category=Deck)
	TArray<class USummonInstance*> Summons;
	
	UPROPERTY(BlueprintReadOnly, Category=Deck)
	class UArmorInstance * Head;

	UPROPERTY(BlueprintReadOnly, Category=Deck)
	UArmorInstance * Chest;

	UPROPERTY(BlueprintReadOnly, Category=Deck)
	UArmorInstance * Arms;

	UPROPERTY(BlueprintReadOnly, Category=Deck)
	UArmorInstance * Legs;

	UPROPERTY(BlueprintReadOnly, Category=Deck)
	UArmorInstance * Feet;
	
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
	// ===================
	// ===== METHODS =====
	// ===================
	private:
	protected:
	public:
};
