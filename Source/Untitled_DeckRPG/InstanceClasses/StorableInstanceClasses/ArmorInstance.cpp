#include "ArmorInstance.h"

UArmorInstance::UArmorInstance() {
    Config.StorableType = EStorableType::StorableType_Armor;
}

UArmorDataAsset* UArmorInstance::GetAsset() const {
    if (bAssetLoaded) return Cast<UArmorDataAsset>(AssetReference);
    return nullptr;
}
