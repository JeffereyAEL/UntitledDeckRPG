#include "Untitled_DeckRPG/DeckRPGTypes.h"
#include "Engine/AssetManager.h"
#include "Externals/DefinedDebugHelpers.h"
#include "Untitled_DeckRPG/HelperMacros.h"

void FDeckAssetRef::SetLoadedAssetReference() {
    TryAssetLoad(AssetReference, AssetId);
}

FDeckAssetRef::FDeckAssetRef(UDataAsset* asset) {
    if (!IsValid(asset))
    {
        checkNoEntry();
    }
    AssetReference = asset;
    AssetId = asset->GetPrimaryAssetId();
    bAssetLoaded = true;
}

FDeckAssetRef::FDeckAssetRef(FPrimaryAssetId asset_id) {
    AssetId = asset_id;
    AssetReference = nullptr;
    TryAssetLoadWithDeferred(AssetReference, asset_id, &FDeckAssetRef::SetLoadedAssetReference, this);
    bAssetLoaded = IsValid(AssetReference);
}

