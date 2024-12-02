#include "../../../include/Game/game.hpp"

Game::Game() : getInfoVisitor(std::make_shared<GetInfoVisitor>()),
               isThreadRunning(false)
{
    shouldStop_.store(false);
}

Game::~Game()
{
    tce::stopFlag.store(true);

    tce::attackCommandQueueCV.notify_one();
    if (tce::attackThr.joinable())
    {
        tce::attackThr.join();
    }
    tce::isAttackThreadRunning = false;

    tce::moveCommandQueueCV.notify_one();
    if (tce::moveThr.joinable())
    {
        tce::moveThr.join();
    }
    tce::isMoveThreadRunning = false;

    shouldStop_.store(true);
    if (gameThread.joinable())
    {
        gameThread.join();
    }
    isThreadRunning = false;
}

void Game::Start()
{
    if (tce::isAttackThreadRunning || tce::isMoveThreadRunning)
    {
        tce::stopFlag.store(true);

        tce::attackCommandQueueCV.notify_one();
        if (tce::attackThr.joinable())
        {
            tce::attackThr.join();
        }
        tce::isAttackThreadRunning = false;

        tce::moveCommandQueueCV.notify_one();
        if (tce::moveThr.joinable())
        {
            tce::moveThr.join();
        }
        tce::isMoveThreadRunning = false;
    }

    //Preparing environment to game
    if (gameThread.joinable())
    {
        gameThread.join();
    }
    Notify("----------------------------------\n");
    Notify("NPC before start:");
    std::stringstream buffer;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    PrintNPC();
    std::cout.rdbuf(coutbuf);
    Notify(buffer.str());

    tce::stopFlag.store(false);
    tce::attackThr = std::thread([this]() { tce::attackCommandExecutionThread([this](const std::string& event) { Notify(event); }); });
    tce::isAttackThreadRunning = true;
    tce::moveThr = std::thread([this]() { tce::moveCommandExecutionThread([this](const std::string& event) { Notify(event); }); });
    tce::isMoveThreadRunning = true;

    Time::Start();
    gameThread = std::thread(&Game::Update, this);
    isThreadRunning = true;

    Notify("Start Game");
    // Update();
}

void Game::Update()
{
    //Game Logic
    int commandsAdd = 0;
    while(!shouldStop_.load())
    {
        commandsAdd = 0;
        Time::Update();
        for (int i = 0; i < npcInGame_.size(); i++)
        {
            for (int j = 0; j < npcInGame_.size(); j++)
            {
                if (i == j)
                    continue;
                if (InMaskAttack(npcInGame_[i]->GetTypeId(), npcInGame_[j]->GetTypeId()))
                {
                    commandsAdd++;
                    if (AttackCommand::CanAttackNow(npcInGame_[i], npcInGame_[j]))
                    {
                        {
                            std::unique_lock<std::mutex> lock(tce::attackCommandQueueMutex);
                            tce::attackCommandQueue.push(std::make_shared<AttackCommand>(npcInGame_[i], npcInGame_[j]));
                            tce::attackCommandQueueCV.notify_one();
                        }
                    }
                }
            }
        }

        // while (!tce::commandQueue.empty()) {
        //     std::this_thread::sleep_for(std::chrono::microseconds(10));
        // }

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
                std::unique_lock<std::mutex> lock(tce::moveCommandQueueMutex);
                tce::moveCommandQueue.push(std::make_shared<MoveCommand>(npcInGame_[i], target));
                tce::moveCommandQueueCV.notify_one();
                commandsAdd++;
            }
        }

        // while (!tce::commandQueue.empty()) {
        //     std::this_thread::sleep_for(std::chrono::microseconds(10));
        // }

        if (!commandsAdd)
        {
            break;
        }
    }

    End();
    Notify("End Game\n");
    Notify("NPC after end:");
    std::stringstream buffer;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    PrintNPC();
    std::cout.rdbuf(coutbuf);
    Notify(buffer.str());
    Notify("----------------------------------");
}

void Game::End()
{
    //Destroy environment
    tce::stopFlag.store(true);
    
    tce::attackCommandQueueCV.notify_one();
    if (tce::attackThr.joinable())
    {
        tce::attackThr.join();
    }
    tce::isAttackThreadRunning = false;

    tce::moveCommandQueueCV.notify_one();
    if (tce::moveThr.joinable())
    {
        tce::moveThr.join();
    }
    tce::isMoveThreadRunning = false;
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

