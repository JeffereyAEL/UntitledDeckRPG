#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

#include "GameplayEffect.h"
/* parent class includes go here ^^^ */
#include "DeckDefaultAttributeEffect.generated.h"

/* native c++ class pre-declarations go here ^^^ */

/** DeckGameplayEffect doc string */
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckDefaultAttributeEffect : public UGameplayEffect {
	GENERATED_BODY()

	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	// ======================
	// ===== PROPERTIES =====
	// ======================
private:
protected:
public:
	// =============================
	// ===== GETTERS_/_SETTERS =====
	// =============================
private:
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=DefaultAttributeEffect)
	float DefaultHealthMax;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=DefaultAttributeEffect)
	float DefaultPower;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=DefaultAttributeEffect)
	float DefaultDamageThreshold;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=DefaultAttributeEffect)
	float DefaultDamageResistance;
	
public:
	/** CDO Constructor */
	UDeckDefaultAttributeEffect();

	
	// ===================
	// ===== METHODS =====
	// ===================
private:
protected:
public:
	
};
