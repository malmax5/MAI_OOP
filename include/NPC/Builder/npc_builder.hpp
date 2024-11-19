#pragma once

#include "npc_builder_interface.hpp"
#include "../Base/npc.hpp"

class NPCBuilder : INPCBuilder
{
public:
    void Reset() override;
    void SetCurrentId(unsigned int currentId) override;
    void SetHp(double hp) override;
    void SetBaseArmor(double armor) override;
    void SetEquip(MyEquip* equip) override;
    void SetSpeed(double speed) override;

    NPC* GetResult();

private:
    NPC* npc;
};