#include "npc_factory_interface.hpp"

class PegasusFactory : public INPCFactory
{
public:
    std::shared_ptr<NPC> CreateNPC(double xCord, double yCord);
};