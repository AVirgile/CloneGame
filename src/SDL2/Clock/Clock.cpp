/*
** CloneGame Virgile AGNEL
*/

#include "Clock.hpp"

SDL2::Clock::Clock()
{
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