
/**
USummonInstance::USummonInstance() {
    Config.StorableType = EStorableType::StorableType_Summon;
}

USummonDataAsset* USummonInstance::GetAsset() const { 
    if (bAssetLoaded) return Cast<USummonDataAsset>(AssetReference);
    return nullptr;
}

float USummonInstance::GetAttack() const {
    if (bAssetLoaded)
        return Cast<USummonDataAsset>(AssetReference)->GetAttack() *
            (0.95f + 0.05f * Config.Level) * pow(2, Config.Rank);
   return 0.0f;
}

float USummonInstance::GetDefense() const {
    if (bAssetLoaded)
        return Cast<USummonDataAsset>(AssetReference)->GetDefense() *
            (0.95f + 0.05f * Config.Level) * pow(2, Config.Rank);
    return 0.0f;
}

FString USummonInstance::GetAbilityAsText() const {
    FString description = "unloaded_description";
    if (bAssetLoaded)
    {
        description = Cast<USummonDataAsset>(AssetReference)->GetSummonName() + " ";
        const auto ability = Cast<USummonDataAsset>(AssetReference)->GetAbility();
        int curr_order = ability[0].Order-1;
        bool b_is_list = false;
        bool b_transition = false;
        for (int i = 0; i < ability.Num(); ++i)
        {
            if (curr_order == ability[i].Order) b_is_list = true;
            curr_order = ability[i].Order;
            
            bool b_end = i == ability.Num()-1;

            const auto action = ability[i];
            if (b_is_list) description += FString(", ");
            
            if (!b_end) // not the end of ability actions
                if (curr_order < ability[i+1].Order) // next action is of higher order
                    {
                    if (b_is_list)
                    {
                        description += FString("and ");
                        b_is_list = false;
                    }
                    b_transition = true;
                    }
            description += USummonActionFunctions::ToString(action, this);
            
            if (b_transition)
            {
                description += FString(".");
                if (!b_end) description += FString("\n Then they ");
            }
        }
    }
    return description;
}
*/