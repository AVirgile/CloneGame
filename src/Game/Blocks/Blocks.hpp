/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Shaders/Shaders.hpp"
#include "../Vertex/Vertex.hpp"
#include <memory>

namespace Game {
    class Blocks : public GameObject {
        public:
            Blocks() = delete;
            Blocks(const std::string &name, const GameObjectInfo &type, const std::string &vPath, const std::string &fPath, const Vertex &info);
            ~Blocks();

            void updateObj(const Camera &cam, const Transform &trs);
            void renderObj();

            inline bool &getVisibility()
            {
                return (this->__visible);
            }

            inline std::unique_ptr<Shaders> &getShaders()
            {
                return (this->__shader);
            }
        protected:
        private:
            std::unique_ptr<Shaders> __shader;
            std::unique_ptr<Vertex> __vertex;
            ::GLuint __ibo;
            bool __visible;
    };
}
