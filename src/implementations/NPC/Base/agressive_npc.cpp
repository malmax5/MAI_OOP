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
    return readyToAttack_;
}

void AgressiveNPC::Reload()
{
    ReloadingCoroutine();
}

void AgressiveNPC::SwitchReadyToAttackInFalse()
{
    readyToAttack_ = false;
}

GameSettings::WeaponId AgressiveNPC::GetWeaponId()
{
    return weapon_->GetWeaponId();
}
