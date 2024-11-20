#pragma once
#include "../Base/npc.hpp"

class INPCFactory
{
public:
    virtual NPC* CreateNPC(double xCord, double yCord) = 0;
};