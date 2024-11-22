#pragma once

#include <vector>
#include <thread>
#include <unistd.h>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <memory>
#include <functional>

#include "enemy_mask.hpp"

#include "../Positionable/position_funcs.hpp"

#include "Observer/observer.hpp"
#include "Visitor/visitor.hpp"
#include "Visitor/get_info_visitor.hpp"

#include "../NPC/Base/npc.hpp"
#include "../NPC/FightLogic/command_executer.hpp"

#include "../NPC/FightLogic/Command/move_command.hpp"
#include "../NPC/FightLogic/Command/attack_command.hpp"
#include "../NPC/FightLogic/Command/command_interface.hpp"

class Game
{
    friend class Terminal;
    friend class BattleVisitor;
public:
    Game();

private:
    void Start();
    void Update();
    void End();

    void AddNPC(std::shared_ptr<NPC> npc);
    void RemoveNPC(int npcId);
    void RemoveDeads();
    void PrintNPC();

    void Attach(std::shared_ptr<Observer> observer);
    void Detach(std::shared_ptr<Observer> observer);
    void Notify(const std::string& event);

private:
    std::vector<std::shared_ptr<NPC>> npcInGame_;
    std::vector<std::shared_ptr<Observer>> observers;
    std::shared_ptr<Visitor> getInfoVisitor;

    std::thread gameThread;
    std::atomic<bool> shouldStop_;
    bool isThreadRunning;
};