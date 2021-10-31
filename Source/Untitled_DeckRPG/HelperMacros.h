#pragma once
			
/// attempts to set a class variable to a loaded UDataAsset using UE4 UAssetManager class,
/// otherwise creates a streamable delegate to set it once the asset is loaded.
/// deferred_class_setter must be void class_function(FPrimaryAssetID)
/// requires #include "Engine/AssetManager.h"
#define TryAssetLoadWithDeferred(class_ref_data_asset, asset_id, deferred_class_setter, asset_owner_instance) \
    {\
        if (UAssetManager * __manager__ = UAssetManager::GetIfValid())\
        {\
            class_ref_data_asset = Cast<UPrimaryDataAsset>(__manager__->GetPrimaryAssetObject(asset_id));\
            if (!IsValid(class_ref_data_asset))\
            {\
                TArray<FName> __load_state__;\
                __load_state__.Add(FName("Game"));\
                __manager__->LoadPrimaryAsset(asset_id, __load_state__,\
                    FStreamableDelegate::CreateUObject(asset_owner_instance, deferred_class_setter)\
                    );\
                SCREENMSGT("asset assignment has been delegated to post asset load", 6);\
            }\
        }\
    }

/// attempts to set a class variable to a loaded UDataAsset using UE4 UAssetManager class.
/// requires #include "Engine/AssetManager.h"
#define TryAssetLoad(class_ref_data_asset, asset_id) \
    {\
        if (UAssetManager * __manager__ = UAssetManager::GetIfValid())\
        {\
        class_ref_data_asset = Cast<UPrimaryDataAsset>(__manager__->GetPrimaryAssetObject(asset_id));\
        }\
    }

/** 
Class Name + Line# + First Param is a message, second is time on screen!
Ex:
SCREENMSGT("TEST", 10.5);
*/
#define SCREENMSGT(Param1,Param2) if(GEngine) ( GEngine->AddOnScreenDebugMessage(-1, Param2, FColor::Turquoise, *(CUR_CLASS_LINE + ": " + Param1)))