/*
** CloneGame Virgile AGNEL
*/

#include "Event.hpp"

Clone::Event::Event(Window &current) : _current(current)
{
    this->_eventList[SDL_QUIT] = &Event::handleQuit;
    // this->_eventList[SDL_KEYDOWN]
}

void Clone::Event::handleQuit() const noexcept
{
    this->_current.setIsRunning(false);
}

void Clone::Event::handleEvent()
{
    while (SDL_PollEvent(&this->_sdlEvent) != 0) {
        if (this->_eventList.count(static_cast<SDL_EventType>(this->_sdlEvent.type)) > 0) {
            this->_eventList[static_cast<SDL_EventType>(this->_sdlEvent.type)](*this);
        }
    }
}

Clone::Event::~Event()
{
}
