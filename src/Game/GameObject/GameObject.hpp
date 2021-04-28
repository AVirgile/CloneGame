/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "IGameObject.hpp"

namespace Game {
    class GameObject : public IGameObject {
        public:
            GameObject() = delete;
            GameObject(const std::string &name, const GameObjectInfo &type);
            ~GameObject();

            inline std::string &getName()
            {
                return (this->__name);
            }

            inline GameObjectInfo &getInfo()
            {
                return (this->__type);
            }

            virtual void renderObj(const Camera &cam) = 0;
        protected:
            std::string __name;
            GameObjectInfo __type;
            ::GLuint __bufferId;
        private:
    };
}
