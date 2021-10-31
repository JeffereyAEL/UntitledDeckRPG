#include "Untitled_DeckRPG/DeckRPGTypes.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Engine/AssetManager.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckArmorAsset.h"
#include "Untitled_DeckRPG/AssetClasses/ItemClasses/DeckSummonAsset.h"

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
    TryAssetLoad(AssetReference, AssetId);
    bAssetLoaded = IsValid(AssetReference);
}

FDeckArmor::FDeckArmor() : Level(1) {}

UDeckArmorAsset* FDeckArmor::GetAsset() const {
    return Cast<UDeckArmorAsset>(ArmorData.GetAsset());}

FDeckSummon::FDeckSummon() : Level(1) {}

UDeckSummonAsset* FDeckSummon::GetAsset() const {
    return Cast<UDeckSummonAsset>(SummonData.GetAsset());
}

FDeckSummonerLoadout::FDeckSummonerLoadout() : Size(SizeDefault) {}

