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
    extern std::thread attackThr;
    extern std::queue<std::shared_ptr<ICommand>> attackCommandQueue;
    extern std::mutex attackCommandQueueMutex;
    extern std::condition_variable attackCommandQueueCV;
    extern bool isAttackThreadRunning;

    extern std::thread moveThr;
    extern std::queue<std::shared_ptr<ICommand>> moveCommandQueue;
    extern std::mutex moveCommandQueueMutex;
    extern std::condition_variable moveCommandQueueCV;
    extern bool isMoveThreadRunning;

    extern std::atomic<bool> stopFlag;

    void attackCommandExecutionThread(std::function<void(const std::string&)> Notify);
    void moveCommandExecutionThread(std::function<void(const std::string&)> Notify);
}
