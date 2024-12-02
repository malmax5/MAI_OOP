#include "../Base/peaceful_npc.hpp"

class Pegasus : public PeacefulNPC, public CreateLog<Pegasus>
{
public:
    Pegasus();
    ~Pegasus();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;
    std::string GetClassName() final;
};