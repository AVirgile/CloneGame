/*
** CloneGame Virgile AGNEL
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "required.hpp"
#include "IEventType.hpp"

namespace Clone {
    class Event {
        public:
            Event();
            void handleEvent();
            ~Event();

        protected:
        private:
            SDL_Event _sdlEvent;
            std::map<SDL_EventType, std::unique_ptr<IEventType>> _eventList;
    };
}

#endif /* !EVENT_HPP_ */
