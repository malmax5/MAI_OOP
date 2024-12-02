#include "../../../../include/NPC/FightLogic/command_executer.hpp"

namespace tce {
    std::atomic<bool> stopFlag(false);

    std::thread attackThr;
    std::queue<std::shared_ptr<ICommand>> attackCommandQueue;
    std::mutex attackCommandQueueMutex;
    std::condition_variable attackCommandQueueCV;
    bool isAttackThreadRunning = false;

    std::thread moveThr;
    std::queue<std::shared_ptr<ICommand>> moveCommandQueue;
    std::mutex moveCommandQueueMutex;
    std::condition_variable moveCommandQueueCV;
    bool isMoveThreadRunning = false;

    void attackCommandExecutionThread(std::function<void(const std::string&)> Notify)
    {
        while (true) {
            std::shared_ptr<ICommand> command = std::make_shared<ICommand>();
            {
                std::unique_lock<std::mutex> lock(attackCommandQueueMutex);
                attackCommandQueueCV.wait(lock, [] { return !attackCommandQueue.empty() || stopFlag.load(); });
                if (stopFlag.load()) {
                    break;
                }
                command = attackCommandQueue.front();
                attackCommandQueue.pop();
            }
            command->execute(Notify); 
        }
        return;
    }

    void moveCommandExecutionThread(std::function<void(const std::string&)> Notify)
    {
        while (true) {
            std::shared_ptr<ICommand> command = std::make_shared<ICommand>();
            {
                std::unique_lock<std::mutex> lock(moveCommandQueueMutex);
                moveCommandQueueCV.wait(lock, [] { return !moveCommandQueue.empty() || stopFlag.load(); });
                if (stopFlag.load()) {
                    break;
                }
                command = moveCommandQueue.front();
                moveCommandQueue.pop();
            }
            command->execute(Notify); 
        }
        return;
    }
}
