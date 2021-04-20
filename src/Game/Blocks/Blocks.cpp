/*
** CloneGame Virgile AGNEL
*/

#include "Blocks.hpp"

Game::Blocks::Blocks(const std::string &name, const GameObjectInfo &type) : GameObject(name, type)
{
    // create a cube here
}

void Game::Blocks::renderObj()
{
    // fct will be call by SDL2 classes engine handler
    // render the block on screen
}

Game::Blocks::~Blocks()
{
}
