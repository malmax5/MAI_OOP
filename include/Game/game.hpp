#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <cmath>
#include <algorithm>
#include <memory>

#include "enemy_mask.hpp"

#include "../Positionable/position_funcs.hpp"

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

    void AddNPC(std::shared_ptr<NPC> npc);
    void RemoveNPC(int npcId);
    void PrintNPC();

private:
    std::vector<std::shared_ptr<NPC>> npcInGame_;
};