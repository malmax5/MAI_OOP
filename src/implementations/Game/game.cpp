#include "../../../include/Game/game.hpp"

Game::Game() : getInfoVisitor(std::make_shared<GetInfoVisitor>()),
               isThreadRunning(false)
{
    shouldStop_.store(false);
}

void Game::Start()
{
    if (tce::isThreadRunning)
    {
        shouldStop_.store(true);
        if (gameThread.joinable())
        {
            gameThread.join();
        }
    }

    //Preparing environment to game
    if (gameThread.joinable())
    {
        gameThread.join();
    }

    tce::stopFlag.store(false);
    tce::thr = std::thread([this]() { tce::CommandExecutionThread([this](const std::string& event) { Notify(event); }); });
    tce::isThreadRunning = true;

    gameThread = std::thread(&Game::Update, this);
    isThreadRunning = true;

    Notify("Start Game");
    // Update();
}

void Game::Update()
{
    //Game Logic
    while(!shouldStop_.load())
    {
        int commandsAdd = 0;
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
                        commandsAdd++;
                    }
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));

        while (!tce::commandQueue.empty()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

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
                    !AttackCommand::CanAttack(npcInGame_[i], npcInGame_[j]) &&
                    MoveCommand::CanMove(npcInGame_[i], npcInGame_[j]))
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
                commandsAdd++;
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));

        while (!tce::commandQueue.empty()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        if (!commandsAdd)
        {
            break;
        }
    }

        
    End();
    Notify("End Game");
}

void Game::End()
{
    //Destroy environment
    tce::stopFlag.store(true);
    tce::commandQueueCV.notify_one();
    if (tce::thr.joinable()) {
        tce::thr.join();
    }
    tce::isThreadRunning = false;
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

