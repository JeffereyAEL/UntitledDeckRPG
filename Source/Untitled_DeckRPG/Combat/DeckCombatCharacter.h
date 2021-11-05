#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"

#include "DeckCombatCharacter.generated.h"

class ASkeletalMeshActor;
class UDeckCombatAttributes;
class UDeckAbilitySystemComponent;
class UDeckAttributeSet;
class UDeckGameplayAbility;
class UGameplayEffect;

UCLASS(Abstract, BlueprintType)
class UNTITLED_DECKRPG_API ADeckCombatCharacter : public AActor, public IAbilitySystemInterface {
    GENERATED_BODY()
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
    private:
    protected:
    public:
    ADeckCombatCharacter();

    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    virtual void PostInitializeComponents() override;
    
    // ======================
    // ===== PROPERTIES =====
    // ======================
private:
protected:
	/** a component that handles all ability functionality */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=CombatCharacter)
	USkeletalMeshComponent * CombatAvatar;
	
    /** a component that handles all ability functionality */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatCharacter, meta=(AllowPrivateAccess="true"))
    UDeckAbilitySystemComponent * AbilitySystemComponent;

    /** a component that handles all combat attribute functionality */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CombatCharacter, meta=(AllowPrivateAccess="true"))
    UDeckAttributeSet * AttributeSet;
	
    /** initializes default attributes */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AttrbuteSet")
    TSubclassOf<UDeckAttributeSet> AttributeSetClass;
    
    /** default abilities for a character */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=CombatCharacter)
    TArray<TSubclassOf<UDeckGameplayAbility>> DefaultGameplayAbilities;
	
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=CombatCharacter)
    FString CharacterName;

    /** Whether it is this character's turn to make combat moves */
    UPROPERTY(BlueprintReadOnly, Category=CombatCharacter)
    bool bIsTurn;

    /** the combat character to deal damage to */
    UPROPERTY(BlueprintReadOnly, Category=CombatCharacter)
    ADeckCombatCharacter * CombatTarget;
    
    public:
    /** called at the start of every turn, before any calculations/actions have been taken */
    UPROPERTY(BlueprintAssignable, Category=CombatCharacter)
    FOnCombatStateChange TurnStart;

    /** called at the end of every turn, after all calculations/actions have been taken */
    UPROPERTY(BlueprintAssignable, Category=CombatCharacter)
    FOnCombatStateChange TurnEnd;

    /** called at the end of every turn, after all calculations/actions have been taken */
    UPROPERTY(BlueprintAssignable, Category=CombatCharacter)
    FOnAttributeStateChange TargetChanged;

	UPROPERTY(BlueprintReadOnly, Category=CombatCharacter)
	TSubclassOf<UGameplayEffect> FullRevive;
	
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
    private:
    protected:
    public:
    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    void SetCombatTarget(ADeckCombatCharacter * new_target);
    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    ADeckCombatCharacter * GetCombatTarget() const { return CombatTarget; }

    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    FString GetCharacterName() const { return CharacterName; }
    
    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;

    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    void GiveAbilities(TArray<TSubclassOf<UDeckGameplayAbility>> abilities);

    UFUNCTION(BlueprintCallable, Category=CombatCharacter)
    void GiveAbility(TSubclassOf<UDeckGameplayAbility> ability, int32 level);
    
    // ===================
    // ===== METHODS =====
    // ===================
    private:
    protected:
    public:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category=CombatCharacter)
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> effect);
	
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=CombatCharacter)
    void TakeTurn();
    virtual void TakeTurn_Implementation();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=CombatCharacter)
    void EndTurn();
    virtual void EndTurn_Implementation();

    /** initializes attributes, called in PostInitializeComponents */
	virtual void InitializeAttributes();
};

