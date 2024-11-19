#include "npc_factory_interface.hpp"

class KnightFactory : public INPCFactory
{
public:
    NPC* CreateNPC();
};