#include "../../../../include/NPC/FightLogic/command_executer.hpp"

namespace tce {
    std::thread thr;
    std::queue<std::shared_ptr<ICommand>> commandQueue;
    std::mutex commandQueueMutex;
    std::condition_variable commandQueueCV;
    std::atomic<bool> stopFlag(false);
    bool isThreadRunning = false;

    void CommandExecutionThread(std::function<void(const std::string&)> Notify)
    {
        while (true) {
            std::shared_ptr<ICommand> command = std::make_shared<ICommand>();
            {
                std::unique_lock<std::mutex> lock(commandQueueMutex);
                commandQueueCV.wait(lock, [] { return !commandQueue.empty() || stopFlag.load(); });
                if (stopFlag.load()) {
                    break;
                }
                command = commandQueue.front();
                commandQueue.pop();
            }
            command->execute(Notify); 
        }
        return;
    }
}
