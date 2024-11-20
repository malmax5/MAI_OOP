#pragma once

#include "../../Equipment/Equip/my_equip.hpp"

class IAgressiveNPCBuilder
{
public:
    virtual void Reset() = 0;
    virtual void SetCurrentId(unsigned int currentId) = 0;
    virtual void SetHp(double hp) = 0;
    virtual void SetBaseArmor(double armor) = 0;
    virtual void SetEquip(MyEquip* equip) = 0;
    virtual void SetSpeed(double speed) = 0;
    virtual void SetAttackDamage(double attackDamage) = 0;
    virtual void SetAttackDistance(double attackDistance) = 0;
};