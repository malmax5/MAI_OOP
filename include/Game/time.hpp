#pragma once

#include <chrono>

class Time
{
public:
    static void Start();
    static void Update();
    static double GetDeltaTime();

private:
    static std::chrono::system_clock::time_point lastIterTime_;
    static std::chrono::duration<double> deltaTime_;
};
