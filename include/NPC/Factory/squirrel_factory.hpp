#include "npc_factory_interface.hpp"

class SquirrelFactory : public INPCFactory
{
public:
    std::shared_ptr<NPC> CreateNPC(double xCord, double yCord);
};