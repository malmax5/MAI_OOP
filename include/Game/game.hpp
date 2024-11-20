#pragma once

#include <iostream>
#include <vector>
#include <thread>

#include "../NPC/Base/npc.hpp"
#include "../NPC/FightLogic/command_executer.hpp"

#include "../NPC/FightLogic/Command/move_command.hpp"
#include "../NPC/FightLogic/Command/attack_command.hpp"
#include "../NPC/FightLogic/Command/command_interface.hpp"

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