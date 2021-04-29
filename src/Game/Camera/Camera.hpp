/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace Game {
    class Camera {
        public:
            enum CameraAction {
                LEFT,
                RIGHT,
                FORWARD,
                BACKWARD,
                UP,
                DOWN,
            };

            Camera() = delete;
            Camera(const glm::vec3 &pos, const float &fov, const float &aspect, const float &near, const float &far, const float &speed);
            Camera(const Camera &) = delete;
            Camera &operator = (const Camera &) = delete;

            ~Camera();

            inline glm::vec3 &getCameraPos()
            {
                return (this->__cameraPos);
            }

            inline glm::vec3 &getCameraForward()
            {
                return (this->__cameraForward);
            }

            inline glm::vec3 &getCameraUp()
            {
                return (this->__cameraUp);
            }

            inline float &getCamSpeed()
            {
                this->__camSpeed = this->__saveSpeed;
                return (this->__camSpeed);
            }

            inline float &getFov()
            {
                return (this->__fov);
            }
            inline float &getAspect()
            {
                return (this->__aspect);
            }
            inline float &getNear()
            {
                return (this->__near);
            }
            inline float &getFar()
            {
                return (this->__near);
            }

            glm::mat4 getViewProjection() const;

            void processInput(const CameraAction &action);
            // handle mouseMovement;

        protected:
        private:
            glm::mat4 __perspective;
            glm::vec3 __cameraPos;
            glm::vec3 __cameraForward;
            glm::vec3 __cameraUp;

            float __fov;
            float __aspect;
            float __near;
            float __far;
            float __saveSpeed;
            float __camSpeed;
    };
}
