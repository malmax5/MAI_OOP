#pragma once
#include "../../Equipment/Equip/my_equip.hpp"

class NPC
{
    friend class NPCBuilder;

public:
    unsigned int GetTypeId();
    unsigned int GetCurrentId();
    double GetHp();
    double GetArmor();
    double GetSpeed();

protected:
    void SetTypeId(unsigned int typeId);

    void SetCurrentId(unsigned int currentId);
    void SetHp(double hp);
    void SetBaseArmor(double armor);
    void SetEquip(MyEquip* equip);
    void SetSpeed(double speed);

private:
    unsigned int typeId_;
    unsigned int currentId_;
    double hp_;
    double armor_;
    double speed_;
    MyEquip* equip_;
};