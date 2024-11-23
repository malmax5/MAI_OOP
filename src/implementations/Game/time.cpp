#include "../../../include/Game/time.hpp"

std::chrono::system_clock::time_point Time::lastIterTime_ = std::chrono::system_clock::now();
std::chrono::duration<double> Time::deltaTime_ = std::chrono::duration<double>::zero();

void Time::Start()
{
    lastIterTime_ = std::chrono::system_clock::now();
}

void Time::Update()
{
    auto currentTime = std::chrono::system_clock::now();
    deltaTime_ = currentTime - lastIterTime_;
    lastIterTime_ = currentTime;
}

double Time::GetDeltaTime()
{
    return deltaTime_.count();
}

std::chrono::system_clock::time_point Time::GetLastIterTime()
{
    return lastIterTime_;
}
