#pragma once

#include "GameplayEffect.h"

#include "UObject/PrimaryAssetId.h"
#include "DeckRPGTypes.generated.h"

/** stores information for init UDeckAttributeSet initialization */
USTRUCT(BlueprintType)
struct FDeckAttributeInfo {
    GENERATED_BODY()
    float HealthMax;
    float Power;
    float DamageThreshold;
    float DamageResistance;
};

class UDeckSummonAsset;

/** defines an instance of a given UDeckSummonAsset */
USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckSummon {
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Summon)
    UDeckSummonAsset * SummonData UMETA(ExposeOnSpa=true);
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Summon)
    int32 Level UMETA(ExposeOnSpa=true);
};

/** the weight of an armor, modifies player 'stamina' AKA the size of summon's loadout */
UENUM(BlueprintType)
enum EDeckArmorWeight {
    ArmorWeight_Light UMETA(DisplayName="Light"),

    ArmorWeight_Medium UMETA(DisplayName="Medium"),

    ArmorWeight_Heavy UMETA(DisplayName="Heavy")
};

/** where a piece of armor fits on a character */
UENUM(BlueprintType)
enum EDeckArmorSlot {
    ArmorSlot_Head UMETA(DisplayName="Head"),

    ArmorSlot_Chest UMETA(DisplayName="Chest"),

    ArmorSlot_Arms UMETA(DisplayName="Arms"),

    ArmorSlot_Legs UMETA(DisplayName="Legs"),

    ArmorSlot_Feet UMETA(DisplayName="Feet")
};

class UDeckArmorAsset;

/** defines an instance of a given UDeckArmorAsset */
USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckArmor {
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Armor)
    UDeckArmorAsset * ArmorData;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Armor)
    int32 Level;
};

USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckSummonerLoadout {
    GENERATED_BODY()
    
private:
    /// The size of a deck without any modifiers
    UPROPERTY()
    int SizeDefault = 5;

    /// The size of a deck without any modifiers
    UPROPERTY()
    int SizeMax = 7;
    
public:
    /// The size of this deck, including modifiers
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=DeckConfig)
    int Size UMETA(ClampMin="3", ClampMax="7");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Deck)
    TArray<FDeckSummon> Summons;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Deck)
    FDeckArmor Head;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Deck)
    FDeckArmor Chest;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Deck)
    FDeckArmor Arms;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Deck)
    FDeckArmor Legs;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Deck)
    FDeckArmor Feet;
	
    FDeckSummonerLoadout();
};

class UDeckEnemyAsset;

/** defines an instance of a given UDeckEnemyAsset */
USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckEnemy {
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=EnemyConfig)
    UDeckEnemyAsset * Asset;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=EnemyConfig)
    int Level;
};

USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckSummonerStats {
    GENERATED_BODY()
    
    /** the player's chosen name */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SummonerStats)
    FString Name;
    
    /** player level, modifies attributes */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonerStats)
    int32 Level;
    
    /** All summons the player owns */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonerStats)
    TArray<FDeckSummon> InventorySummons;
    
    /** All armors the player owns */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonerStats)
    TArray<FDeckArmor> InventoryArmors;
    
    /// The decks the player has created
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SummonerStats)
    TArray<FDeckSummonerLoadout> LoadOuts;
};

/** indicates classes of messages the debugger can handle */
UENUM(BlueprintType)
enum ELogType {
    /** to be used when something has gone wrong that needs to be logged ;
     *  red on screen ;
     *  Don't use with UDebugFunctions::LogToScreen() unless you can catch the error w/o crashing
     */
    LogType_Error UMETA(DisplayName="Error"),

    /** to be used for debugging code ;
     *  green on screen
     */
    LogType_Debug UMETA(DisplayName="Debug"),

    /** to be used to indicate a possibly error-inducing code/situations ; yellow on screen */
    LogType_Warning UMETA(DisplayName="Warning")
};

UENUM(BlueprintType)
enum EDeckAbilityInputID {
    AbilityInput_None UMETA(DisplayName="None"),
    AbilityInput_Confirm UMETA(DisplayName="Confirm"),
    AbilityInput_Cancel UMETA(DisplayName="Cancel"),
    AbilityInput_FlailingBlades UMETA(DisplayName="Flailing Blades"),
};

class ADeckCombatCharacter;
/* TODO: find a better naming convention for delegates */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeModified, ADeckCombatCharacter *, target_character, int32, amt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeStateChange, ADeckCombatCharacter *, target_character);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCombatStateChange);