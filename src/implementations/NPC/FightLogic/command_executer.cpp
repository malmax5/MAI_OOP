#include "../../../../include/NPC/FightLogic/command_executer.hpp"
#include <iostream>

namespace tce {
    std::thread thr;
    std::queue<ICommand*> commandQueue;
    std::mutex commandQueueMutex;
    std::condition_variable commandQueueCV;
    bool stopFlag = false;

    void CommandExecutionThread() {
        while (true) {
            ICommand* command;
            {
                std::unique_lock<std::mutex> lock(commandQueueMutex);
                commandQueueCV.wait(lock, [] { return !commandQueue.empty() || stopFlag; });
                if (stopFlag) {
                    break;
                }
                command = commandQueue.front();
                commandQueue.pop();
            }
            command->execute();
        }
    }
}
