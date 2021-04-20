/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../GameObject/GameObject.hpp"

namespace Game {
    class Blocks : public GameObject {
        public:
            Blocks(const std::string &name, const GameObjectInfo &type);
            ~Blocks();

            void renderObj();
        protected:
        private:
    };
}
