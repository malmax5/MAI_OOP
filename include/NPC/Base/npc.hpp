#pragma once
#include "../Enums/type_id_enum.hpp"
#include "../../Positionable/positionable.hpp"
#include "../../Equipment/Equip/my_equip.hpp"

class NPC : public Position
{
    friend class PeacefulNPCBuilder;
    friend class AgressiveNPCBuilder;
    friend class AttackCommand;

public:
    NPCId GetTypeId();
    unsigned int GetCurrentId();
    double GetHp();
    double GetArmor();
    double GetSpeed();
    virtual double GetAttackDistance();
    virtual double GetAttackDamage();

protected:
    void SetTypeId(NPCId typeId);

    void SetCurrentId(unsigned int currentId);
    void SetHp(double hp);
    void SetBaseArmor(double armor);
    void SetEquip(MyEquip* equip);
    void SetSpeed(double speed);

private:
    NPCId typeId_;
    unsigned int currentId_;
    double hp_;
    double armor_;
    double totalArmor_ = 0;
    double speed_;
    MyEquip* equip_;
};