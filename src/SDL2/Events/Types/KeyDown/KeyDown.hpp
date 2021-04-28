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
            void __handleForward(Game::GameData &data);
            void __handleBackward(Game::GameData &data);
            void __handleLeft(Game::GameData &data);
            void __handleRight(Game::GameData &data);
            void __handleQuit(Game::GameData &data);

            std::map<ActionsOnEvents, std::function<void (KeyDown &, Game::GameData &data)>> __callbackMap;
    };
}
