/*
** Clone Game Virgile Agnel
*/

#pragma once

#include "glm/glm/fwd.hpp"
#include "required.hpp"
#include "../Camera/Camera.hpp"

namespace Game {
    class Transform {
        public:
            Transform(const Transform &model);
            Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(), const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f));
            ~Transform() = default;
            Transform &operator = (const Transform &model);

            glm::mat4 getMVP(const Camera &cam) const;

            inline glm::vec3 &getPos()
            {
                return (this->__pos);
            }

            inline glm::vec3 &getRot()
            {
                return (this->__rot);
            }

            inline glm::vec3 &getScale()
            {
                return (this->__scale);
            }

        private:
            glm::vec3 __pos;
            glm::vec3 __rot;
            glm::vec3 __scale;
        protected:
    };
};
