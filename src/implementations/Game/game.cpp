#include "../../../include/Game/game.hpp"

void Game::Start()
{
    //Preparing environment to game

    Update();
}

void Game::Update()
{
    //Game Logic
}

void Game::End()
{
    //Destroy environment
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
