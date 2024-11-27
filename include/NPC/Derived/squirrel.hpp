#include "../Base/agressive_npc.hpp"

using GameSettings::SquirrelStat;

class Squirrel : public AgressiveNPC
{
public:
    Squirrel();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;

    void Attack(std::shared_ptr<NPC> target) override;
    void Reload() final;
};