/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "../../../Game/GameData/GameData.hpp"

namespace SDL2 {
    class ITypes {
        public:
            virtual ~ITypes() = default;
            virtual void handleType(Game::GameData &data, const SDL_Event &input) = 0; 
        protected:
        private:
    };
}
