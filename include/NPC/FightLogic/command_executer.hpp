#pragma once

#include "Command/command_interface.hpp"

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

namespace tce {
    extern std::thread thr;
    extern std::queue<ICommand*> commandQueue;
    extern std::mutex commandQueueMutex;
    extern std::condition_variable commandQueueCV;
    extern bool stopFlag;

    void CommandExecutionThread();
}
