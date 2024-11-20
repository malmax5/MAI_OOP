#include "../../../include/Game/game.hpp"

void Game::Start()
{
    //Preparing environment to game
    tce::thr = std::thread(tce::CommandExecutionThread);
    Update();
}

void Game::Update()
{
    //Game Logic
    std::cout << npcInGame_[0]->GetHp() << " " << npcInGame_[1]->GetHp() << "\n";
    ICommand* command = new AttackCommand(npcInGame_[0], npcInGame_[1]);
    tce::commandQueue.push(command);

    End();
}

void Game::End()
{
    //Destroy environment
    while (tce::commandQueue.size() != 0) {}
    tce::stopFlag = true;
    tce::thr.join();
    std::cout << npcInGame_[0]->GetHp() << " " << npcInGame_[1]->GetHp() << "\n";
}

void Game::AddNPC(NPC* npc)
{
    npcInGame_.push_back(npc);
}

void Game::RemoveNPC(int npcId)
{
    for (int i = 0; i < npcInGame_.size(); i++)
    {
        if (npcInGame_[i]->GetCurrentId() == npcId)
        {
            npcInGame_.erase(npcInGame_.begin() + npcId);
            break;
        }
    }
}

void Game::PrintNPC()
{
    for (auto& npc : npcInGame_)
    {
        std::cout << "TypeId: " << npc->GetTypeId() << " " <<
                     "Name: " << npc->GetCurrentId() << " " <<
                     "X: " << npc->GetXCord() << " " <<
                     "Y: " << npc->GetYCord() << "\n";
    }
}
