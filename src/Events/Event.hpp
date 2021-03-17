/*
** CloneGame Virgile AGNEL
*/

#pragma once

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "required.hpp"
#include "../SDL2/window/Window.hpp"

namespace Clone {
    class Event {
        public:
            Event(Window &);
            void handleEvent();
            ~Event();

        protected:
        private:
            void handleQuit() const noexcept;

            SDL_Event _sdlEvent;
            Window &_current;
            std::map<SDL_EventType, std::function<void(const Event &)>> _eventList;
    };
}

#endif /* !EVENT_HPP_ */
