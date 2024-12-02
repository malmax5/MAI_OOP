#include "../Base/agressive_npc.hpp"

using GameSettings::SquirrelStat;

class Squirrel : public AgressiveNPC, public CreateLog<Squirrel>
{
public:
    Squirrel();
    ~Squirrel();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;
    std::string GetClassName() final;

    void Attack(std::shared_ptr<NPC> target) override;
    // void Reload() final;
};