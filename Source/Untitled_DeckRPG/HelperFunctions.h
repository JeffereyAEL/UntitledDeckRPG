#pragma once

/// attempts to set a class variable to a loaded UDataAsset using UE4 UAssetManager class,
/// otherwise creates a streamable delegate to set it once the asset is loaded.
/// deferred_class_setter must be void class_function(FPrimaryAssetID)
#define TryAssetLoadWithDeferred(class_ref_data_asset, asset_id, deferred_class_setter, asset_owner_instance) \
    {\
        if (UAssetManager * manager = UAssetManager::GetIfValid())\
        {\
            class_ref_data_asset = Cast<UPrimaryDataAsset>(manager->GetPrimaryAssetObject(asset_id));\
            if (!IsValid(class_ref_data_asset))\
            {\
                TArray<FName> load_state;\
                load_state.Add(FName("Game"));\
                manager->LoadPrimaryAsset(asset_id, load_state,\
                    FStreamableDelegate::CreateUObject(asset_owner_instance, deferred_class_setter, asset_id)\
                    );\
                SCREENMSGT("asset assignment in '" + GetName() +\
                    "' has been delegated to post asset load", 6);\
            }\
        }\
        else\
        {\
            checkNoEntry()\
        }\
    }

/// attempts to set a class variable to a loaded UDataAsset using UE4 UAssetManager class.
#define TryAssetLoad(class_ref_data_asset, asset_id) \
    {\
        if (UAssetManager * manager = UAssetManager::GetIfValid())\
        {\
        class_ref_data_asset = Cast<UPrimaryDataAsset>(manager->GetPrimaryAssetObject(asset_id));\
        }\
    }