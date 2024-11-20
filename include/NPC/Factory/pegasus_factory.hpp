#include "npc_factory_interface.hpp"

class PegasusFactory : public INPCFactory
{
public:
    NPC* CreateNPC(double xCord, double yCord);
};