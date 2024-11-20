#include "../../../include/Game/game.hpp"

void Game::Start()
{
    //Preparing environment to game
    std::cout << "Start\n";
    tce::thr = std::thread(tce::CommandExecutionThread);
    Update();
}

void Game::Update()
{
    //Game Logic
    std::cout << "Update\n";
    while(npcInGame_.size() > 1)
    {
        std::cout << "Attack\n";
        for (int i = 0; i < npcInGame_.size(); i++)
        {
            for (int j = 0; j < npcInGame_.size(); j++)
            {
                if (i == j)
                    continue;
                if (InMaskAttack(npcInGame_[i]->GetTypeId(), npcInGame_[j]->GetTypeId()) && 
                    AttackCommand::CanAttack(npcInGame_[i], npcInGame_[j]))
                {
                    {
                        std::cout << " - " << npcInGame_[i]->GetCurrentId() << " an " << npcInGame_[j]->GetCurrentId() << "\n";
                        std::unique_lock<std::mutex> lock(tce::commandQueueMutex);
                        tce::commandQueue.push(new AttackCommand(npcInGame_[i], npcInGame_[j]));
                        tce::commandQueueCV.notify_one();
                    }
                }
            }
        }

        sleep(1);

        while(tce::commandQueue.size() != 0) {}

        npcInGame_.erase(std::remove_if(npcInGame_.begin(), npcInGame_.end(), 
        [](NPC* npc) {
            return npc->GetHp() <= 0;
        }), npcInGame_.end());

        std::cout << "Move\n";
        for (int i = 0; i < npcInGame_.size(); i++)
        {
            NPC* target;
            double dist = -1;
            for (int j = 0; j < npcInGame_.size(); j++)
            {
                if (i == j)
                    continue;
                if (InMaskAttack(npcInGame_[i]->GetTypeId(), npcInGame_[j]->GetTypeId()) &&
                    !AttackCommand::CanAttack(npcInGame_[i], npcInGame_[j]))
                {
                    double newDist = NPCPositionFuncs::DistanceBetNPC(npcInGame_[i], npcInGame_[j]);
                    if (newDist > dist)
                    {
                        target = npcInGame_[j];
                        dist = newDist;
                    }
                }
                else if (InMaskAttack(npcInGame_[i]->GetTypeId(), npcInGame_[j]->GetTypeId()))
                {
                    break;
                }
            }
            if (dist != -1)
            {
                std::cout << "- " << npcInGame_[i]->GetCurrentId() << " to " << target->GetCurrentId() << "\n";
                std::unique_lock<std::mutex> lock(tce::commandQueueMutex);
                tce::commandQueue.push(new MoveCommand(npcInGame_[i], target));
                tce::commandQueueCV.notify_one();
            }
        }

        sleep(1);

        while(tce::commandQueue.size() != 0) {}
    }
        
    End();
}

void Game::End()
{
    //Destroy environment
    tce::stopFlag = true;
    tce::commandQueueCV.notify_one();
    tce::thr.join();
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
