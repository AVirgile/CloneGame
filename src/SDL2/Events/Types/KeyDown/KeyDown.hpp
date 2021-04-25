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
            void handleType(Game::GameData &data, const SDL_Event &input);
        protected:
        private:
            void __handleForward();
            void __handleBackward();
            void __handleLeft();
            void __handleRight();
            void __handleQuit();

            std::map<ActionsOnEvents, std::function<void (KeyDown &)>> __callbackMap;
    };
}
