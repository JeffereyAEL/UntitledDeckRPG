#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"
#include "Untitled_DeckRPG/DeckRPGTypes.h"

#include "Abilities/GameplayAbility.h"
/* parent class includes go here ^^^ */
#include "DeckGameplayAbility.generated.h"

/* native c++ class pre-declarations go here ^^^ */

/** DeckGameplayAbility doc string */
UCLASS(BlueprintType)
class UNTITLED_DECKRPG_API UDeckGameplayAbility : public UGameplayAbility {
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
    /** TODO: fill this in when I know what this does better */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayAbility")
    TEnumAsByte<EDeckAbilityInputID> InputId = AbilityInput_None;
    
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
private:
protected:
public:
    /** CDO Constructor */
    UDeckGameplayAbility();

    // ===================
    // ===== METHODS =====
    // ===================
private:
protected:
public:
    
};
