/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "Builder/ObjectBuilder.hpp"
#include "../../Utils/ParseKeys/ParseKeys.hpp"
#include "../Camera/Camera.hpp"
#include "../../SDL2/Clock/Clock.hpp"
#include <memory>

namespace Game {
    class GameData {
        public:
            GameData(const glm::vec3 &pos, const float &fov, const float &aspect, const float &near, const float &far, const float &speed, std::shared_ptr<SDL2::Clock> clk);
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

            inline Camera &getCam()
            {
                return (this->__cam);
            }

            inline std::shared_ptr<SDL2::Clock> &getClock()
            {
                return (this->__clock);
            }

            void updateGame();
            void render(const Camera &cam);

        protected:
        private:
            Utils::ParseKeys __keyRetriever;
            Camera __cam;
            ObjectBuilder __objectsBuilder;
            std::shared_ptr<SDL2::Clock> __clock;
            std::vector<std::unique_ptr<IGameObject>> __gameObjs;
    };
}
