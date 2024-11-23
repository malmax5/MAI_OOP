#pragma once

#include <memory>

#include "../../Game/Visitor/visitor.hpp"

#include "../Enums/type_id_enum.hpp"
#include "../../Positionable/positionable.hpp"
#include "../../Equipment/Equip/my_equip.hpp"

class NPC : public Position
{
    friend class PeacefulNPCBuilder;
    friend class AgressiveNPCBuilder;
    //friend class AttackCommand;

public:
    NPCId GetTypeId();
    unsigned int GetCurrentId();
    double GetHp();
    double GetArmor();
    double GetSpeed();
    virtual double GetAttackDistance() = 0;
    virtual double GetAttackDamage() = 0;

    virtual void GetDamage(double damage);

    virtual void AcceptVisitor(std::shared_ptr<Visitor> visitor) = 0;

protected:
    void SetTypeId(NPCId typeId);

    void SetCurrentId(unsigned int currentId);
    void SetHp(double hp);
    void SetBaseArmor(double armor);
    void SetEquip(std::shared_ptr<MyEquip> equip);
    void SetSpeed(double speed);


private:
    NPCId typeId_;
    unsigned int currentId_;
    double hp_;
    double armor_;
    double totalArmor_ = 0;
    double speed_;
    std::shared_ptr<MyEquip> equip_;
};
