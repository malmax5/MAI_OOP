#include "npc_factory_interface.hpp"

class SquirrelFactory : public INPCFactory
{
public:
    NPC* CreateNPC(double xCord, double yCord);
};