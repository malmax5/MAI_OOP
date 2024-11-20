#pragma once

#include <iostream>
#include <vector>

#include "../NPC/Base/npc.hpp"

class Game
{
    friend class Terminal;
    friend class BattleVisitor;

private:
    void Start();
    void Update();
    void End();

    void AddNPC(NPC* npc);
    void RemoveNPC(int npcId);
    void PrintNPC();

private:
    std::vector<NPC*> npcInGame_;
};