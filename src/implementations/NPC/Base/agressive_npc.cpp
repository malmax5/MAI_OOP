#include "../../../../include/NPC/Base/agressive_npc.hpp"

void AgressiveNPC::SetWeapon(std::shared_ptr<Weapon> weapon)
{
    weapon_ = weapon;
}

double AgressiveNPC::GetAttackDistance() const
{
    return weapon_->GetAttackDistance();
}

double AgressiveNPC::GetAttackDamage() const
{
    return weapon_->GetAttackDamage();
}

bool AgressiveNPC::ReadyToAttack() const
{
    return reloadedTime <= Time::GetLastIterTime();
}

void AgressiveNPC::Reload()
{
    reloadedTime = std::chrono::time_point_cast<std::chrono::system_clock::duration>(Time::GetLastIterTime() + std::chrono::duration<double>(weapon_->GetReloadingTime()));
}

GameSettings::WeaponId AgressiveNPC::GetWeaponId()
{
    return weapon_->GetWeaponId();
}
