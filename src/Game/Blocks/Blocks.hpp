/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Shaders/Shaders.hpp"

namespace Game {
    class Blocks : public GameObject {
        public:
            Blocks() = delete;
            Blocks(const std::string &name, const GameObjectInfo &type, const std::string &vPath, const std::string &fPath);
            ~Blocks();

            void updateObj(const Camera &cam, const Transform &trs);
            void renderObj();
        protected:
        private:
            std::unique_ptr<Shaders> __shader;
            ::GLuint __ibo;
    };
}
