/*
** EPITECH PROJECT, 2021
** CloneGame [WSL: Ubuntu-18.04]
** File description:
** KeyDown
*/

#include "KeyDown.hpp"

SDL2::KeyDown::KeyDown()
{
}

void SDL2::KeyDown::handleType(Game::GameData &data)
{
    (void)data;
    std::cout << "keyPressed" << std::endl;
}

SDL2::KeyDown::~KeyDown()
{
}
