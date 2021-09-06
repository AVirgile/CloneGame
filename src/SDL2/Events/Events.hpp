/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "Types/ITypes.hpp"
#include "Types/Builder/Builder.hpp"
#include <vector>

namespace SDL2 {
    class Events {
        public:
            Events();
            ~Events();
            
            void processEvent(bool &running, Game::GameData &data);
        protected:
        private:
            ::SDL_Event __inputs;
            std::vector<SDL_Event> __frameEvts;
            std::map<uint32_t, std::unique_ptr<ITypes>> __typeMap;
            Builder __filler;
    };
}
