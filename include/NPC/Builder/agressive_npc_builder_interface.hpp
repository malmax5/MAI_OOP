#pragma once

#include "../../Equipment/Equip/my_equip.hpp"
#include "../../Weapon/Base/weapon.hpp"

class IAgressiveNPCBuilder
{
public:
    virtual void Reset() = 0;
    virtual void SetCurrentId(unsigned int currentId) = 0;
    virtual void SetHp(double hp) = 0;
    virtual void SetBaseArmor(double armor) = 0;
    virtual void SetEquip(std::shared_ptr<MyEquip> equip) = 0;
    virtual void SetSpeed(double speed) = 0;
    virtual void SetWeapon(std::shared_ptr<Weapon> weapon) = 0;
};