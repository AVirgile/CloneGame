/*
** EPITECH PROJECT, 2021
** CloneGame [WSL: Ubuntu-18.04]
** File description:
** KeyDown
*/

#include "KeyDown.hpp"
#include "../../../../Errors/StopOccured/StopOccured.hpp"


SDL2::KeyDown::KeyDown()
{
    this->__callbackMap[FORWARD] = &KeyDown::__handleForward;
    this->__callbackMap[BACKWARD] = &KeyDown::__handleBackward;
    this->__callbackMap[LEFT] = &KeyDown::__handleLeft;
    this->__callbackMap[RIGHT] = &KeyDown::__handleRight;
    this->__callbackMap[QUIT] = &KeyDown::__handleQuit;
}

void SDL2::KeyDown::__handleForward(Game::GameData &data)
{
    float &camSpeed = data.getCam().getCamSpeed();

    camSpeed *= data.getClock()->getDeltaTime();
    data.getCam().processInput(Game::Camera::CameraAction::FORWARD);
    std::cout << "FORWARD" << std::endl;
}

void SDL2::KeyDown::__handleBackward(Game::GameData &data)
{
    float &camSpeed = data.getCam().getCamSpeed();
    
    camSpeed *= data.getClock()->getDeltaTime();    
    data.getCam().processInput(Game::Camera::CameraAction::BACKWARD);
    std::cout << "BACKWARD" << std::endl;
}

void SDL2::KeyDown::__handleLeft(Game::GameData &data)
{
    float &camSpeed = data.getCam().getCamSpeed();

    camSpeed *= data.getClock()->getDeltaTime();
    data.getCam().processInput(Game::Camera::CameraAction::LEFT);
    std::cout << "LEFT" << std::endl;
}

void SDL2::KeyDown::__handleRight(Game::GameData &data)
{
    float &camSpeed = data.getCam().getCamSpeed();

    camSpeed *= data.getClock()->getDeltaTime();
    data.getCam().processInput(Game::Camera::CameraAction::RIGHT);
    std::cout << "RIGHT" << std::endl;
}

void SDL2::KeyDown::__handleQuit(Game::GameData &data)
{
    (void)data;
    throw Errors::StopOccured("Quitting application with deticated key");
}

void SDL2::KeyDown::handleType(Game::GameData &data, const SDL_Event &input)
{
    for (auto const &val : data.getKeysMap()) {
        if (input.key.keysym.sym == val.second) {
            this->__callbackMap[val.first](*this, data);
        }
    }
}

SDL2::KeyDown::~KeyDown()
{
}
