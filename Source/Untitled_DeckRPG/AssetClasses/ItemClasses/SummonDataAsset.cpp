#include "SummonDataAsset.h"
#include "../InstanceClasses/StorableInstanceClasses/SummonInstance.h"
#include "../Externals/DefinedDebugHelpers.h"

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
