/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../Camera/Camera.hpp"

namespace Game {
    class IGameObject {
        public:
            virtual ~IGameObject() = default;

            virtual std::string &getName() = 0;
            virtual GameObjectInfo &getInfo() = 0;
            virtual void renderObj(const Camera &cam) = 0;
            // more method to follow like an update method to change pos of a block
        protected:
        private:
    };
}
