#include "SummonerSaveData.h"

#include "Untitled_DeckRPG/Externals/DefinedDebugHelpers.h"
#include "Untitled_DeckRPG/InstanceClasses/StorableInstanceClasses/ArmorInstance.h"
#include "Untitled_DeckRPG/InstanceClasses/StorableInstanceClasses/SummonInstance.h"

USummonerSaveData::USummonerSaveData() {
    Name = "UNINSTANTIATED_PLAYER";
    Inventory = TArray<FStorableInstanceConfig>();
    bValidSave = false;
}

void USummonerSaveData::SetPlayerData(FSummonerPersistentData summoner) {
    for (auto storable_instance : summoner.Inventory)
    {
        Inventory.Add(storable_instance->Config);
    }
    Name = summoner.Name;
    // TODO: add in deck save functionality
    bValidSave = true;
}

FSummonerPersistentData USummonerSaveData::GetPlayerData(APlayerController* controller) const {
    FSummonerPersistentData temp_data{};
    temp_data.Name = Name;
    for (auto config : Inventory)
    {
        UStorableInstance* new_instance = nullptr;
        switch(config.StorableType)
        {
        case StorableType_Armor:
            new_instance = NewObject<UStorableInstance>(controller,
                UArmorInstance::StaticClass());
            break;
        case StorableType_Summon:
            new_instance = NewObject<UStorableInstance>(controller,
                USummonInstance::StaticClass());
            break;
        default:
            break;
            
        }
        if (!IsValid(new_instance))
        {
#if WITH_EDITOR
            SCREENMSGT("Storable Instance construction from GetData() failed", 10);
#endif
            return FSummonerPersistentData{}; 
        }
        if (config.StorableType != StorableType_None)
            new_instance->PostConstruction(config.AssetIDString,
                    config.Level, config.Rank);
        temp_data.Inventory.Add(new_instance);
    }
    return temp_data;
}

void USummonerSaveData::PostConstruction(FSummonerPersistentData data) {
    SetPlayerData(data);
}
