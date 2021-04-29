/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../Camera/Camera.hpp"
#include "../Transform/Transform.hpp"

namespace Game {
    class IGameObject {
        public:
            virtual ~IGameObject() = default;

            virtual std::string &getName() = 0;
            virtual GameObjectInfo &getInfo() = 0;
            virtual void updateObj(const Camera &cam, const Transform &trs) = 0;
            virtual void renderObj() = 0;
            // more method to follow like an update method to change pos of a block
        protected:
        private:
    };
}
