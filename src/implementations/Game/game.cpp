#include "../../../include/Game/game.hpp"

Game::Game() : getInfoVisitor(std::make_shared<GetInfoVisitor>()) {}

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
                        std::unique_lock<std::mutex> lock(tce::commandQueueMutex);
                        tce::commandQueue.push(std::make_shared<AttackCommand>(npcInGame_[i], npcInGame_[j]));
                        tce::commandQueueCV.notify_one();
                    }
                }
            }
        }

        sleep(1);

        while(tce::commandQueue.size() != 0) {}

        RemoveDeads();

        for (int i = 0; i < npcInGame_.size(); i++)
        {
            std::shared_ptr<NPC> target;
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
                std::unique_lock<std::mutex> lock(tce::commandQueueMutex);
                tce::commandQueue.push(std::make_shared<MoveCommand>(npcInGame_[i], target));
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

void Game::AddNPC(std::shared_ptr<NPC> npc)
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

void Game::RemoveDeads()
{
    int i = 0;
    while(i < npcInGame_.size())
    {
        if (npcInGame_[i]->GetHp() <= 0)
        {
            std::stringstream ss;
            ss << "NPC with id: " << npcInGame_[i]->GetCurrentId() << " Killed";
            Notify(ss.str());
            npcInGame_.erase(npcInGame_.begin() + i);
            i--;
        }

        i++;
    }
}

void Game::PrintNPC()
{
    for (auto& npc : npcInGame_)
    {
        npc->AcceptVisitor(getInfoVisitor);
    }
}

void Game::Notify(const std::string& event) 
{
    for (const auto& observer : observers) 
    {
        observer->update(event);
    }
}

void Game::Attach(std::shared_ptr<Observer> observer)
{
    observers.push_back(observer);
}

void Game::Detach(std::shared_ptr<Observer> observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

