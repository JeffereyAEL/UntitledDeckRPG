#pragma once

#include "CoreMinimal.h"

#include "GameFramework/SaveGame.h"
#include "UObject/ObjectMacros.h"
#include "DebugSaveGame_002.generated.h"

#define SAVE_NAME "The Debug Save Name"

USTRUCT(BlueprintType)
struct UNTITLED_DECKRPG_API FDebugStructConfig_002 {
    GENERATED_BODY()
    private:
    UPROPERTY(EditAnywhere, Category=SaveStruct)
    int PrivateUProperty;
    
    int PrivateProperty;
    
    protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SaveStruct)
    int ProtectedUProperty;
    
    int ProtectedProperty;
    
    public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SaveStruct)
    int PublicUProperty;
    
    int PublicProperty;
    
    FDebugStructConfig_002();

    void GenerateRandomValues(int seed);
    
    int GetPrivateU() const { return PrivateUProperty; }
    int GetPrivate() const { return PrivateProperty; }
    
    int GetProtectedU() const { return PrivateUProperty; }
    int GetProtected() const { return PrivateProperty; }
};

UCLASS()
class UNTITLED_DECKRPG_API UDebugClassConfig_002 : public UObject {
    GENERATED_BODY()
    private:
    UPROPERTY(EditAnywhere, Category=SaveStruct)
    int PrivateUProperty;
    
    int PrivateProperty;
    
    protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SaveStruct)
    int ProtectedUProperty;
    
    int ProtectedProperty;
    
    public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SaveStruct)
    int PublicUProperty;
    
    int PublicProperty;
    
    UDebugClassConfig_002();

    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    void GenerateRandomValues(int seed);

    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    int GetPrivateU() const { return PrivateUProperty; }
    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    int GetPrivate() const { return PrivateProperty; }

    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    int GetProtectedU() const { return PrivateUProperty; }
    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    int GetProtected() const { return PrivateProperty; }
};


UCLASS()
class UNTITLED_DECKRPG_API UDebugSaveGame_002 : public USaveGame{
    GENERATED_BODY()
    public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SaveGame)
    UDebugClassConfig_002 * ClassRef;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SaveGame)
    FDebugStructConfig_002 StructRef;

    UDebugSaveGame_002();
    
    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    void PostConstruction(AActor * outer);
    
    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    void PrintContent();

    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    void Load();

    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    void Save();

    UFUNCTION(BlueprintCallable, Category=SaveStruct)
    void RandomizeBody();
};
