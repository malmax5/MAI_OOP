#pragma once
#include "../Base/npc.hpp"

class INPCFactory
{
public:
    virtual NPC* CreateNPC() = 0;
};