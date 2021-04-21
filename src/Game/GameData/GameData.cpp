/*
** CloneGame Virgile AGNEL
*/

#include "GameData.hpp"

Game::GameData::GameData()
{
    this->__gameObjs.emplace_back(this->__objectsBuilder.createObject("test", BLOCK, "./src/Game/Shaders/src/DefaultBlock/block.vert", "./src/Game/Shaders/src/DefaultBlock/block.frag"));
}

void Game::GameData::updateGame()
{
    // update Game Here
}

void Game::GameData::render()
{
    for (auto const &val : this->__gameObjs) {
        val->renderObj();
    }
}

Game::GameData::~GameData()
{
}
