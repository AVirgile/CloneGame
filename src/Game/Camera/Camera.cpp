/*
** EPITECH PROJECT, 2021
** CloneGame
** File description:
** Camera
*/

#include "Camera.hpp"
#include "glm/glm/fwd.hpp"
#include "glm/glm/geometric.hpp"
#include "glm/glm/trigonometric.hpp"

Game::Camera::Camera(const glm::vec3 &pos, const float &fov, const float &aspect, const float &near, const float &far, const float &speed)
{
    this->__pitch = 0.0f;
    this->__yaw = 90.0f;
    this->__mouseSensitivity = 0.1f; // change this to variable number;
    this->__firstMouseMotion = true;
    this->__fov = fov;
    this->__aspect = aspect;
    this->__near = near;
    this->__far = far;
    this->__perspective = glm::perspective(this->__fov, this->__aspect, this->__near, this->__far);
    this->__cameraPos = pos;
    this->__cameraForward = glm::vec3(0.0f, 0.0f, 1.0f);
    this->__cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->__camSpeed = speed;
    this->__saveSpeed = speed;
}

glm::mat4 Game::Camera::getViewProjection() const
{
    return (this->__perspective * glm::lookAt(this->__cameraPos, this->__cameraPos + this->__cameraForward, this->__cameraUp));
}

void Game::Camera::processInput(const CameraAction &action)
{
    if (action == CameraAction::FORWARD) {
        this->__cameraPos += this->__camSpeed * this->__cameraForward;
    }
    if (action == CameraAction::BACKWARD) {
        this->__cameraPos -= this->__camSpeed * this->__cameraForward;
    }
    if (action == CameraAction::LEFT) {
        this->__cameraPos -= glm::normalize(glm::cross(this->__cameraForward, this->__cameraUp)) * this->__camSpeed;
    }
    if (action == CameraAction::RIGHT) {
        this->__cameraPos += glm::normalize(glm::cross(this->__cameraForward, this->__cameraUp)) * this->__camSpeed;
    }
    if (action == CameraAction::UP) {
        this->__cameraPos += this->__camSpeed * this->__cameraUp;
    }
    if (action == CameraAction::DOWN) {
        this->__cameraPos -= this->__camSpeed * this->__cameraUp;
    }
}

void Game::Camera::processMouveMove(const glm::vec2 &mousePos)
{
    float xOffset = mousePos.x;
    float yOffset = mousePos.y;
    glm::vec3 direction;

    this->__pitch += -yOffset * this->__mouseSensitivity;
    this->__yaw += xOffset * this->__mouseSensitivity;
    if (this->__pitch > MAX_PITCH_ANGLE) {
        this->__pitch = MAX_PITCH_ANGLE;
    }
    if (this->__pitch < MIN_PITCH_ANGLE) {
        this->__pitch = MIN_PITCH_ANGLE;
    }
    direction.x = cos(glm::radians(this->__yaw)) * cos(glm::radians(this->__pitch));
    direction.y = sin(glm::radians(this->__pitch));
    direction.z = sin(glm::radians(this->__yaw)) * cos(glm::radians(this->__pitch));
    this->__cameraForward = glm::normalize(direction);
}

Game::Camera::~Camera()
{
}
