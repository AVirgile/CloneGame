/*
** CloneGame Virgile AGNEL
*/

#include "Events.hpp"

SDL2::Events::Events() 
{
    this->__typeMap[SDL_KEYDOWN] = this->__filler.createType(SDL_KEYDOWN);
}

void SDL2::Events::processEvent(bool &running, Game::GameData &data)
{
    while (::SDL_PollEvent(&this->__inputs) > 0) {
        if (this->__inputs.type == SDL_QUIT) {
            running = false;
        } else {
            for (auto const &val : this->__typeMap) {
                if (this->__inputs.type == val.first) {
                    val.second->handleType(data, this->__inputs);
                }
            }
        }
    }
}

SDL2::Events::~Events()
{
}