/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "../ITypes.hpp"

namespace SDL2 {
    class KeyDown : public ITypes {
        public:
            KeyDown();
            ~KeyDown();
            void handleType(Game::GameData &data);
        protected:
        private:
    };
}
