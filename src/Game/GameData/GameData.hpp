/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "Builder/ObjectBuilder.hpp"
#include "../../Utils/ParseKeys/ParseKeys.hpp"

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

            inline const std::map<ActionsOnEvents, char> &getKeysMap() const
            {
                return (this->__keyRetriever.getKeysMap());
            }

            void updateGame();
            void render();

        protected:
        private:
            Utils::ParseKeys __keyRetriever;
            ObjectBuilder __objectsBuilder;
            std::vector<std::unique_ptr<IGameObject>> __gameObjs;
    };
}
