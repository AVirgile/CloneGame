/*
** CloneGame Virgile AGNEL
*/

#include "Event.hpp"

Clone::Event::Event()
{
}

void Clone::Event::handleEvent()
{
    while (SDL_PollEvent(&this->_sdlEvent) != 0) {

    }
}

Clone::Event::~Event()
{
}
