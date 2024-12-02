#include "../Base/agressive_npc.hpp"

using GameSettings::KnightStat;

class Knight : public AgressiveNPC, public CreateLog<Knight>
{
public:
    Knight();
    ~Knight();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;
    std::string GetClassName() final;

    void Attack(std::shared_ptr<NPC> target) override;
    // void Reload() final;
};