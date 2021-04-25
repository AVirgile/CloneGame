/*
** EPITECH PROJECT, 2021
** CloneGame [WSL: Ubuntu-18.04]
** File description:
** KeyDown
*/

#include "KeyDown.hpp"

SDL2::KeyDown::KeyDown()
{
    this->__callbackMap[FORWARD] = &KeyDown::__handleForward;
    this->__callbackMap[BACKWARD] = &KeyDown::__handleBackward;
    this->__callbackMap[LEFT] = &KeyDown::__handleLeft;
    this->__callbackMap[RIGHT] = &KeyDown::__handleRight;
    this->__callbackMap[QUIT] = &KeyDown::__handleQuit;
}

void SDL2::KeyDown::__handleForward()
{
    std::cout << "FORWARD" << std::endl;
}

void SDL2::KeyDown::__handleBackward()
{
    std::cout << "BACKWARD" << std::endl;
}

void SDL2::KeyDown::__handleLeft()
{
    std::cout << "LEFT" << std::endl;
}

void SDL2::KeyDown::__handleRight()
{
    std::cout << "RIGHT" << std::endl;
}

void SDL2::KeyDown::__handleQuit()
{
    std::cout << "QUIT" << std::endl;
}

void SDL2::KeyDown::handleType(Game::GameData &data, const SDL_Event &input)
{
    for (auto const &val : data.getKeysMap()) {
        if (input.key.keysym.sym == val.second) {
            this->__callbackMap[val.first](*this);
        }
    }
}

SDL2::KeyDown::~KeyDown()
{
}
