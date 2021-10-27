#pragma once

#include "CoreMinimal.h"

#include "UObject/ObjectMacros.h"


#include "SummonerDeck.generated.h"

USTRUCT(BlueprintType)
struct FSummonInstanceConfig {
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category=SummonInstanceConfig)
	FString Name;
};

USTRUCT(BlueprintType)
struct FArmorInstanceConfig {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category=ArmorInstanceConfig)
	FString Name;
};

USTRUCT(BlueprintType)
struct FSummonerDeckConfig {
	GENERATED_BODY()
	// ======================
	// ===== ATTRIBUTES =====
	// ======================
private:
protected:
	// UPROPERTY(BlueprintReadOnly)
	// int StandardSize = 5;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	int Size UMETA(ClampMin="3", ClampMax="7");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FSummonInstanceConfig SummonOne;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FSummonInstanceConfig SummonTwo;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FSummonInstanceConfig SummonThree;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FSummonInstanceConfig SummonFour UMETA(EditCondition="Size>=4");
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FSummonInstanceConfig SummonFive UMETA(EditCondition="Size>=5");
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FSummonInstanceConfig SummonSix UMETA(EditCondition="Size>=6");
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FSummonInstanceConfig SummonSeven UMETA(EditCondition="Size=7");
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FArmorInstanceConfig Head;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FArmorInstanceConfig Chest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FArmorInstanceConfig Arms;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FArmorInstanceConfig Legs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
	FArmorInstanceConfig Feet;
	
	// ======================================
	// ===== CONSTRUCTORS_/_DESTRUCTORS =====
	// ======================================
private:
protected:
public:
	FSummonerDeckConfig() = default;
	
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
