#pragma once

#include "peaceful_npc_builder_interface.hpp"
#include "agressive_npc_builder_interface.hpp"
#include "../Base/peaceful_npc.hpp"
#include "../Base/agressive_npc.hpp"
#include "../Derived/knight.hpp"
#include "../Derived/pegasus.hpp"
#include "../Derived/squirrel.hpp"

class PeacefulNPCBuilder : IPeacefulNPCBuilder
{
public:
    virtual void Reset() override;
    void SetCurrentId(unsigned int currentId) override;
    void SetHp(double hp) override;
    void SetBaseArmor(double armor) override;
    void SetEquip(std::shared_ptr<MyEquip> equip) override;
    void SetSpeed(double speed) override;

    std::shared_ptr<PeacefulNPC> GetResult();

protected:
    std::shared_ptr<PeacefulNPC> npc_;
};

class AgressiveNPCBuilder : IAgressiveNPCBuilder
{
public:
    virtual void Reset() override;
    void SetCurrentId(unsigned int currentId) override;
    void SetHp(double hp) override;
    void SetBaseArmor(double armor) override;
    void SetEquip(std::shared_ptr<MyEquip> equip) override;
    void SetSpeed(double speed) override;
    void SetAttackDamage(double attackDamage) override;
    void SetAttackDistance(double attackDistance) override;

    std::shared_ptr<AgressiveNPC> GetResult();

protected:
    std::shared_ptr<AgressiveNPC> npc_;
};

class PegasusBuilder : public PeacefulNPCBuilder
{
    void Reset() final;
};

class KnightBuilder : public AgressiveNPCBuilder
{
    void Reset() final;
};

class SquirrelBuilder : public AgressiveNPCBuilder
{
    void Reset() final;
};
