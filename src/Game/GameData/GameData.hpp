/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "Builder/ObjectBuilder.hpp"

namespace Game {
    class GameData {
        public:
            GameData();
            ~GameData();

            GameData(const GameData &val) = delete;
            GameData &operator = (const GameData &val) = delete;

            inline std::vector<std::unique_ptr<IGameObject>> &getObjs()
            {
                return (this->__gameObjs);
            }

            void updateGame();
            void render();

        protected:
        private:
            ObjectBuilder __objectsBuilder;
            std::vector<std::unique_ptr<IGameObject>> __gameObjs;
    };
}
