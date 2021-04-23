/*
** CloneGame Virgile AGNEL
*/

#include "Clock.hpp"

SDL2::Clock::Clock(const std::chrono::_V2::steady_clock::time_point &start)
{
    this->__lastFrame = 0.0f;
    this->__currentFrame = 0.0f;
    this->__progStart = start;
}

float SDL2::Clock::getDeltaTime()
{
    float delta = 0.0f;
    std::chrono::_V2::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    
    this->__currentFrame = std::chrono::duration_cast<std::chrono::seconds>(currentTime - this->__progStart).count();
    delta = this->__currentFrame - this->__lastFrame;
    this->__lastFrame = this->__currentFrame;
    return (delta);
}

bool SDL2::Clock::calculTime(const uint32_t &time)
{
    uint32_t actualTime = SDL_GetTicks();
    uint32_t prevTime = 0;
    
    if (this->__tracker.count(time) <= 0) {
        this->__tracker[time] = 0;
    }
    prevTime = this->__tracker[time];
    if (actualTime - prevTime > time) {
        this->__tracker[time] = actualTime;
        return (true);
    }
    return (false);
}