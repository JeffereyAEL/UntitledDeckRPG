#include "StorableInstance.h"

#include "Engine/AssetManager.h"
#include "Untitled_DeckRPG/Externals/DefinedDebugHelpers.h"
#include "Untitled_DeckRPG/HelperFunctions.h"

FStorableInstanceConfig::FStorableInstanceConfig() {
    AssetIDString = "";
    StorableType = EStorableType::StorableType_None;
    Level = 0;
    Rank = 0; 
}

UStorableInstance::UStorableInstance() {
    Config = FStorableInstanceConfig{};
    AssetReference = nullptr;
    bAssetLoaded = false;
}

void UStorableInstance::SetAssetReference(FPrimaryAssetId primary_id) {
    bAssetLoaded = false;
    TryAssetLoad(AssetReference, primary_id);
    if (IsValid(AssetReference)) bAssetLoaded = true;
}

void UStorableInstance::PostConstruction(FString id_string, int level, int rank) {
    Config.AssetIDString = id_string;
    Config.Level = level;
    Config.Rank = rank;
    const FPrimaryAssetId primary_id = FPrimaryAssetId::FromString(Config.AssetIDString);
    AssetReference = nullptr;
    TryAssetLoadWithDeferred(AssetReference, primary_id, &UStorableInstance::SetAssetReference, this);
    if (IsValid(AssetReference)) bAssetLoaded = true;
}

void UStorableInstance::PostConstruction_Poly(UStorableInstance* instance) {
    Config = instance->Config;
    bAssetLoaded = instance->bAssetLoaded;
    AssetReference = instance->AssetReference;
}
