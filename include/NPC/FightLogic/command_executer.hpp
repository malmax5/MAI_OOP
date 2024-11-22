#pragma once

#include "Command/command_interface.hpp"

#include <string>
#include <functional>
#include <memory>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace tce 
{
    extern std::thread thr;
    extern std::queue<std::shared_ptr<ICommand>> commandQueue;
    extern std::mutex commandQueueMutex;
    extern std::condition_variable commandQueueCV;
    extern std::atomic<bool> stopFlag;
    extern bool isThreadRunning;

    void CommandExecutionThread(std::function<void(const std::string&)> Notify);
}
