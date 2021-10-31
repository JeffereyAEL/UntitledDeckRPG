
/**
USummonInstance::USummonInstance() {
    Config.StorableType = EStorableType::StorableType_Summon;
}

UDeckSummonAsset* USummonInstance::GetAsset() const { 
    if (bAssetLoaded) return Cast<UDeckSummonAsset>(AssetReference);
    return nullptr;
}

float USummonInstance::GetAttack() const {
    if (bAssetLoaded)
        return Cast<UDeckSummonAsset>(AssetReference)->GetAttack() *
            (0.95f + 0.05f * Config.Level) * pow(2, Config.Rank);
   return 0.0f;
}

float USummonInstance::GetDefense() const {
    if (bAssetLoaded)
        return Cast<UDeckSummonAsset>(AssetReference)->GetDefense() *
            (0.95f + 0.05f * Config.Level) * pow(2, Config.Rank);
    return 0.0f;
}

FString USummonInstance::GetAbilityAsText() const {
    FString description = "unloaded_description";
    if (bAssetLoaded)
    {
        description = Cast<UDeckSummonAsset>(AssetReference)->GetSummonName() + " ";
        const auto ability = Cast<UDeckSummonAsset>(AssetReference)->GetAbility();
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

FString USummonActionFunctions::ToString(const FDeckAction a, const USummonInstance* s) {
    FString description = FString();
    switch (a.Type)
    {
    case ActionType_Damage:
        description += "attacks ";
        break;
    case ActionType_AttackBuff:
        description += "raises the attack of ";
        break;
    case ActionType_AttackDebuff:
        description += "lowers the attack of ";
        break;
    case Action_DefenseBuff:
        description += "raises the defense of ";
        break;
    case Action_DefenseDebuff:
        description += "lowers the defense of ";
        break;
    case Action_Heal:
        description += "heals ";
        break;
    default:
        const auto error_msg = FString("ERROR: unknown EActionType enum : ") +
            FString::FromInt(a.Type);
        SCREENMSGT(error_msg, 8.0f);
        return "INVALID_ACTION";
    }
    switch (a.Target)
    {
    case Target_Self:
        description += "the caster ";
        break;
    case Target_EnemyActor:
        description += "target enemy ";
        break;
    case Target_AllEnemyActors:
        description += "all enemies ";
        break;
    case Target_AllActors:
        description += "all enemies and the caster ";
        break;
    default:
        const auto error_msg = FString("ERROR: unknown EActionTarget enum : ") +
            FString::FromInt(a.Target);
        SCREENMSGT(error_msg, 8.0f);
        return "INVALID_ACTION";
    }
    // ReSharper disable CppDefaultCaseNotHandledInSwitchStatement
    switch (a.Type)
    {
    case ActionType_Damage:
    case Action_Heal:
        description += "for ";
        break;
    case ActionType_AttackBuff:
    case ActionType_AttackDebuff:
    case Action_DefenseBuff:
    case Action_DefenseDebuff:
        description += "by ";
        break;
    }
    switch (a.Type)
    {
    case ActionType_Damage:
        description += FString::FromInt(s->GetAttack() * a.Modifier) + " ";
        break;
    case ActionType_AttackBuff:
    case Action_DefenseBuff:
    case ActionType_AttackDebuff:
    case Action_DefenseDebuff:
        description += FString::FromInt(a.Modifier) + " ";
        break;
    case Action_Heal:
        description += FString::FromInt(s->GetAttack()/2 * a.Modifier) + " ";
        break;
    }
    switch (a.Type)
    {
    case ActionType_Damage:
        description += "damage";
        break;
    case ActionType_AttackBuff:
    case Action_DefenseBuff:
    case ActionType_AttackDebuff:
    case Action_DefenseDebuff:
        description += "levels";
        break;
    case Action_Heal:
        description += "HP";
        break;
    }
    // ReSharper restore CppDefaultCaseNotHandledInSwitchStatement
    return description;
}
*/