/*
** CloneGame Virgile AGNEL
*/

#include "Events.hpp"
#include <SDL2/SDL_events.h>
#include <cstdlib>

SDL2::Events::Events() 
{
    this->__typeMap[SDL_KEYDOWN] = this->__filler.createType(SDL_KEYDOWN);
    this->__typeMap[::SDL_MOUSEMOTION] = this->__filler.createType(::SDL_MOUSEMOTION);
}

void SDL2::Events::processEvent(bool &running, Game::GameData &data)
{
    ::SDL_Event event;
    while (::SDL_PollEvent(&event) > 0) {
        this->__frameEvts.push_back(event);      
    }
    for (SDL_Event const &val : this->__frameEvts) {
        if (val.type == SDL_QUIT) {
            running = false;
        } else {
            for (auto const &callback : this->__typeMap) {
                if (val.type == callback.first) {
                    callback.second->handleType(data, val);
                }
            }
        }
    }
    this->__frameEvts.clear();
}

SDL2::Events::~Events()
{
}
