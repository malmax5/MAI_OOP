#include "../Base/peaceful_npc.hpp"

class Pegasus : public PeacefulNPC
{
public:
    Pegasus();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;
};