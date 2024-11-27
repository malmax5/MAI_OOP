#include "../Base/agressive_npc.hpp"

using GameSettings::KnightStat;

class Knight : public AgressiveNPC
{
public:
    Knight();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;

    void Attack(std::shared_ptr<NPC> target) override;
    void Reload() final;
};