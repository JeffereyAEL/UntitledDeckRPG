#include "Untitled_DeckRPG/New Classes/DeckCombatAttributes.h"
#include "Untitled_DeckRPG/DeckCPPHelper.h"

#include "Untitled_DeckRPG/New Classes/DeckCombatCharacter.h"

void UDeckCombatAttributes::PostConstruction(int32 health_max, int32 power, int32 defense) {
    HealthMax = health_max;
    Health = HealthMax;
    Power = power;
    Defense = defense;
}

int32 UDeckCombatAttributes::CalcDamageFromPower(int32 modified_power) {
    return FMath::Max(modified_power - Defense, 1);
}

void UDeckCombatAttributes::ApplyHealthDelta(int32 amt, bool b_revivable) {
    if (amt == 0) return;
    if (Health == 0 && (amt < 0 || !b_revivable)) return;
    if (Health == HealthMax && amt > 0) return;
    
    int32 old_health = Health;
    Health += amt;
    int32 true_delta = amt;
    if (Health < 0)
    {
        true_delta -= Health;
        Health = 0;
    }
    else if (Health > HealthMax)
    {
        true_delta -= Health - HealthMax;
        Health = HealthMax;
    }
    
    if (true_delta > 0)
    {
        OnHealed.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()), true_delta);
        if (old_health <= 0 && Health > 0 && b_revivable) OnRevived.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()));
    }
    else if (true_delta < 0)
    {
        OnDamaged.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()), true_delta);
        if (old_health > 0 && Health <= 0) OnKilled.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()));
    }
}

void UDeckCombatAttributes::ApplyHealthMaxDelta(int32 amt) {
    if (amt == 0) return;
    
    float ratio = Health / static_cast<float>(HealthMax);
    HealthMax = FMath::Max(HealthMax + amt, 1); // Max Health Can't be below 1

    // keep health the same proportion of healthMax
    Health = FMath::Max(static_cast<int32>(Health * ratio), 1);
}

void UDeckCombatAttributes::ApplyPowerDelta(int32 amt) {
    if (amt == 0) return;

    int32 old_power = Power;
    Power = FMath::Max(Power + amt, 1); // Max Health Can't be below 1
    
    int32 true_delta = old_power - Power;
    if (true_delta > 0)
    {
        OnPowerBuffed.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()), true_delta);
        }
    else if (true_delta < 0)
    {
        OnPowerDebuffed.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()), true_delta);
    }
}

void UDeckCombatAttributes::ApplyDefenseDelta(int32 amt) {
    if (amt == 0) return;

    int32 old_power = Defense;
    Defense = FMath::Max(Defense + amt, 1); // Max Health Can't be below 1
    
    int32 true_delta = old_power - Defense;
    if (true_delta > 0)
    {
        OnDefenseBuffed.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()), true_delta);
    }
    else if (true_delta < 0)
    {
        OnDefenseDebuffed.Broadcast(Cast<ADeckCombatCharacter>(GetOwner()), true_delta);
    }
}
