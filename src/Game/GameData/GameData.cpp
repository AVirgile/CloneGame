/*
** CloneGame Virgile AGNEL
*/

#include "GameData.hpp"

#include "../Vertex/Vertex.hpp"

Game::GameData::GameData(const glm::vec3 &pos, const float &fov, const float &aspect, const float &near, const float &far, const float &speed, std::shared_ptr<SDL2::Clock> clk) : __keyRetriever("./assets/keys.csv"), __cam(pos, fov, aspect, near, far, speed)
{
    const vertexData_t data[] {
        {-0.5f, -0.5f, 0.0f},
        {0.5f, -0.5f, 0.0f},
        {0.5f, 0.5f, 0.0f},
        {-0.5f, 0.5f, 0.0f},
        {-0.5f, 0.5f, 1.0f},
        {-0.5f, -0.5f, 1.0f},
        {0.5f, 0.5f, 1.0f},
        {0.5f, -0.5f, 1.0f},
    };

    const ::GLuint indices[] {
        0, 1, 2,
        2, 3, 0,
        0, 3, 4,
        4, 5, 0,
        4, 5, 6,
        6, 7, 5,
        1, 2, 7,
        2, 6, 7,
        0, 1, 5,
        1, 5, 7,
        2, 3, 4,
        3, 4, 6
    };
    
    Vertex vertex(data, indices, 36, 8, 36);

    this->__clock = clk;
    this->__gameObjs.emplace_back(this->__objectsBuilder.createObject("test", BLOCK, "./src/Game/Shaders/src/DefaultBlock/block.vert", "./src/Game/Shaders/src/DefaultBlock/block.frag", vertex));
}

void Game::GameData::updateGame()
{
    for (auto const &val : this->__gameObjs) {
        val->updateObj(this->__cam, this->__transformEngine);
    }
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
