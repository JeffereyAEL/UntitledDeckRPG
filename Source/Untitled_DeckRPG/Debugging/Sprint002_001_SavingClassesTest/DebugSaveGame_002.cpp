#include "DebugSaveGame_002.h"
#include "Untitled_DeckRPG/Externals/DefinedDebugHelpers.h"

FDebugStructConfig_002::FDebugStructConfig_002() {
    PrivateUProperty = -1;
    PrivateProperty = -1;
    
    ProtectedUProperty = -1;
    ProtectedProperty = -1;
    
    PublicUProperty = -1;
    PublicProperty = -1;
}

void FDebugStructConfig_002::GenerateRandomValues(int seed) {
    
    FRandomStream rand{seed};
    PrivateUProperty = rand.RandRange(0, 100000000);
    PrivateProperty = rand.RandRange(0, 100000000);
    
    ProtectedUProperty = rand.RandRange(0, 100000000);
    ProtectedProperty = rand.RandRange(0, 100000000);
    
    PublicUProperty = rand.RandRange(0, 100000000);
    PublicProperty = rand.RandRange(0, 100000000);
}

UDebugClassConfig_002::UDebugClassConfig_002() {
    PrivateUProperty = -1;
    PrivateProperty = -1;
    
    ProtectedUProperty = -1;
    ProtectedProperty = -1;
    
    PublicUProperty = -1;
    PublicProperty = -1;
}

void UDebugClassConfig_002::GenerateRandomValues(int seed) {
    FRandomStream rand{seed};
    PrivateUProperty = rand.RandRange(0, 100000000);
    PrivateProperty = rand.RandRange(0, 100000000);
    
    ProtectedUProperty = rand.RandRange(0, 100000000);
    ProtectedProperty = rand.RandRange(0, 100000000);
    
    PublicUProperty = rand.RandRange(0, 100000000);
    PublicProperty = rand.RandRange(0, 100000000);
}

UDebugSaveGame_002::UDebugSaveGame_002() {
    StructRef = FDebugStructConfig_002{};
    ClassRef = nullptr;
}

void UDebugSaveGame_002::PostConstruction(AActor * outer) {
    StructRef = FDebugStructConfig_002{};
    ClassRef = NewObject<UDebugClassConfig_002>(outer, UDebugClassConfig_002::StaticClass());
}

void UDebugSaveGame_002::PrintContent() {
    SCREENMSGT( FString::FromInt(ClassRef->GetPrivateU()) + " == " +
        FString::FromInt(StructRef.GetPrivateU()), 10 );

    SCREENMSGT( FString::FromInt(ClassRef->GetPrivate()) + " == " +
        FString::FromInt(StructRef.GetPrivate()), 10 );

    SCREENMSGT( FString::FromInt(ClassRef->GetProtectedU()) + " == " +
        FString::FromInt(StructRef.GetProtectedU()), 10 );

    SCREENMSGT( FString::FromInt(ClassRef->GetProtected()) + " == " +
        FString::FromInt(StructRef.GetProtected()), 10 );

    SCREENMSGT( FString::FromInt(ClassRef->PublicUProperty) + " == " +
        FString::FromInt(StructRef.PublicUProperty), 10 );

    SCREENMSGT( FString::FromInt(ClassRef->PublicProperty) + " == " +
        FString::FromInt(StructRef.PublicProperty), 10 );
}

void UDebugSaveGame_002::Load() {
    if (UGameplayStatics::DoesSaveGameExist(SAVE_NAME, 0))
    {
        UDebugSaveGame_002 * temp = Cast<UDebugSaveGame_002>(UGameplayStatics::LoadGameFromSlot(SAVE_NAME, 0));
        PrintContent();
        SCREENMSGT("PreLoad:", 10);
        ClassRef = temp->ClassRef;
        StructRef = temp->StructRef;
        
        SCREENMSGT("", 10);
        PrintContent();
        SCREENMSGT("PostLoad:", 10);
    }
    else
    {
        SCREENMSGT("Haven't created a save for '" + SAVE_NAME + "' yet", 3.5);
    }
}

void UDebugSaveGame_002::Save() {
    UGameplayStatics::SaveGameToSlot(Cast<USaveGame>(this), SAVE_NAME, 0);
}

void UDebugSaveGame_002::RandomizeBody() {
    int seed = FMath::Rand();
    StructRef.GenerateRandomValues(seed);
    ClassRef->GenerateRandomValues(seed);
}
