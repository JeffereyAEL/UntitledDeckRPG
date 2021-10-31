#pragma once

#include "Core/DeckDataAsset.h"
#include "UObject/PrimaryAssetId.h"

#include "DeckRPGTypes.generated.h"

/** defines the unit of an event duration */
UENUM(BlueprintType)
enum EDeckDurationUnit {
    /** counts all actions a combat character makes */
    DurationUnit_Moves UMETA(DisplayName="Moves"),

    /** counts every time a combat character takes a turn */
    DurationUnit_Turns UMETA(DisplayName="Turns"),

    /** counts every time all combat characters have taken their turn */
    DurationUnit_Rounds UMETA(DisplayName="Rounds")
};

/** defines how long an event/ action should last */
USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckDuration {
    GENERATED_BODY()
    int32 Length;
    TEnumAsByte<EDeckDurationUnit> Type;
};

/** describes what action is being performed */
UENUM(BlueprintType)
enum EDeckActionType {
    /// attacks
    ActionType_Damage UMETA(DisplayName="Damage"),

    /// raises attack
    ActionType_AttackBuff UMETA(DisplayName="AttackBuff"),

    /// lowers attack
    ActionType_AttackDebuff UMETA(DisplayName="AttackDebuff"),

    /// raises defense
    ActionType_DefenseBuff UMETA(DisplayName="DefenseBuff"),

    /// lowers defense
    ActionType_DefenseDebuff UMETA(DisplayName="DefenseDebuff"),

    /// heals
    ActionType_Heal UMETA(DisplayName="Heal"),

    /// modifies damage
    ActionType_DamageMod UMETA(DisplayName="DamageMod")
};

/** describes the target of an action */
UENUM(BlueprintType)
enum EDeckActionTarget {
    /// affects the caster
    ActionTarget_Self UMETA(DisplayName="Self"),

    /// affects a targeted enemy
    ActionTarget_EnemyActor UMETA(DisplayName="EnemyActor"),

    /// affects all enemies
    ActionTarget_AllEnemyActors UMETA(DisplayName="AllEnemyActors"),

    /// affects all enemies and the caster
    ActionTarget_AllActors UMETA(DisplayName="AllActors"),

    /// affects the next summon
    ActionTarget_NextSummon UMETA(DisplayName="NextSummon")
};

/** Defines an action being taken by a combat character */
USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckAction {
    GENERATED_BODY()

    /** specifies the speed of the action relative to other actions, only relevant when actions are used in series */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Action)
    int Order;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Action)
    TEnumAsByte<EDeckActionType> Type;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Action)
    TEnumAsByte<EDeckActionTarget> Target;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Action)
    FDeckDuration Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Action)
    float Modifier;
};

class UDataAsset;

/** a smart wrapper for UDataAssets, allows them to be serialized and loaded from/ saved to disk */
USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckAssetRef {
    GENERATED_BODY()

protected:
    /** denotes whether the asset has been loaded from disk */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AssetReference)
    bool bAssetLoaded;
    
    /** the asset that this struct encapsulates */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=AssetReference, meta=(ExposeOnSpawn))
    UDataAsset * AssetReference UMETA(ExposeOnSpawn);

    /** an event called setter for deferred loading of assets from disk */
    void SetLoadedAssetReference();
    
public:
    /** the id for loading in unloaded assets */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=AssetReference)
    FPrimaryAssetId AssetId;

    /** CDO constructor */
    FDeckAssetRef() :
        bAssetLoaded(false),
        AssetReference(nullptr) {}

    /** constructor for a loaded asset, never use an unloaded asset to construct this struct */
    FDeckAssetRef(UDataAsset * asset);

    /** (eventually) loads in the asset and houses it's asset id for future reloading */
    FDeckAssetRef(FPrimaryAssetId asset_id);

    /** returns the UDataAsset *, nullptr if it isn't loaded yet */
    UDataAsset * GetAsset() const { return AssetReference; }

    bool IsLoaded() const { return bAssetLoaded; }
};

class UDeckSummonAsset;

/** defines an instance of a given UDeckSummonAsset */
USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckSummon {
    GENERATED_BODY()
    
    /// the data asset reference of FDeckArmor::StorableType
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Summon)
    FDeckAssetRef SummonData UMETA(ExposeOnSpa=true);
	
    /// the level of the item
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Summon)
    int32 Level UMETA(ExposeOnSpa=true);
	
    FDeckSummon();

    UDeckSummonAsset * GetAsset() const;
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
    
    /// the data asset reference of FDeckArmor::StorableType
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Armor)
    FDeckAssetRef ArmorData;
	
    /// the level of the item
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Armor)
    int32 Level;
	
    FDeckArmor();

    UDeckArmorAsset * GetAsset() const;
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
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=DeckConfig)
    int Size UMETA(ClampMin="3", ClampMax="7");

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
    TArray<FDeckSummon> Summons;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
    FDeckArmor Head;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
    FDeckArmor Chest;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
    FDeckArmor Arms;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
    FDeckArmor Legs;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Deck)
    FDeckArmor Feet;
	
    FDeckSummonerLoadout();
};

class UDeckEnemyAsset;

USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckEnemy {
    GENERATED_BODY()

    /** whether this enemy is important to clear the wave */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyConfig)
    bool bBoss;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyConfig)
    FPrimaryAssetId AssetId;
	
    /// the data asset reference of this config
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyConfig)
    UDeckEnemyAsset * Asset;
	
    /// The level of the enemy
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyConfig)
    int Level;

    /// dictates what order enemies in the same wave attack
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=EnemyConfig)
    float Speed;
};


USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FMissionWave {
    GENERATED_BODY()
    /// What enemies are in a wave
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MissionWave)
    TArray<FDeckEnemy> Enemies;
};

USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDeckSummonerStats {
    GENERATED_BODY()
    
    /** the player's chosen name */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    FString Name;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    int32 InventorySize; // TODO: eventually check/ limit inventory size
    
    /** All summons the player owns */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    TArray<FDeckSummon> InventorySummons;
    
    /** All armors the player owns */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    TArray<FDeckArmor> InventoryArmors;
    
    /// The decks the player has created
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=SummonerStats)
    TArray<FDeckSummonerLoadout> LoadOuts;

    FDeckSummonerStats() :
    Name("__UNINITIALIZED_SUMMONER__"),
    InventorySize(100) {}
};

UCLASS(Blueprintable, BlueprintType)
class UNTITLED_DECKRPG_API UReallyImportantClassDefinitely : public UObject
{
    GENERATED_BODY()
};

class ADeckCombatCharacter;

/* TODO: find a better naming convention for delegates */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeModified, ADeckCombatCharacter *, target_character, int32, amt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeStateChange, ADeckCombatCharacter *, target_character);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCombatStateChange);