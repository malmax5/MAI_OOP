#pragma once
#include "../Base/npc.hpp"

class INPCFactory
{
public:
    virtual std::shared_ptr<NPC> CreateNPC(double xCord, double yCord) = 0;
};