/*
** CloneGame Virgile AGNEL
*/

#include "GameData.hpp"

Game::GameData::GameData(const glm::vec3 &pos, const float &fov, const float &aspect, const float &near, const float &far, const float &speed, std::shared_ptr<SDL2::Clock> clk) : __keyRetriever("./assets/keys.csv"), __cam(pos, fov, aspect, near, far, speed)
{
    this->__clock = clk;
    this->__gameObjs.emplace_back(this->__objectsBuilder.createObject("test", BLOCK, "./src/Game/Shaders/src/DefaultBlock/block.vert", "./src/Game/Shaders/src/DefaultBlock/block.frag"));
}

void Game::GameData::updateGame()
{
    // update Game Here
}

void Game::GameData::render(const Camera &cam)
{
    for (auto const &val : this->__gameObjs) {
        val->renderObj(cam);
    }
}

Game::GameData::~GameData()
{
}
