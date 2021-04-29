/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "glm/glm/fwd.hpp"
#include "required.hpp"

#define MAX_PITCH_ANGLE 89.0f
#define MIN_PITCH_ANGLE -89.0f

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
            inline glm::vec2 &getLastMousePos()
            {
                return (this->__lastMousePos);
            }
            inline float &getMouseSensitivity()
            {
                return (this->__mouseSensitivity);
            }

            glm::mat4 getViewProjection() const;

            void processInput(const CameraAction &action);
            void processMouveMove(const glm::vec2 &mousePos);

        protected:
        private:
            glm::mat4 __perspective;
            glm::vec3 __cameraPos;
            glm::vec3 __cameraForward;
            glm::vec3 __cameraUp;
            glm::vec2 __lastMousePos;    

            float __fov;
            float __aspect;
            float __near;
            float __far;
            float __saveSpeed;
            float __camSpeed;
            float __mouseSensitivity;
            float __pitch;
            float __yaw;
            bool __firstMouseMotion;
    };
}
