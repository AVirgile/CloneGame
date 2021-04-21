/*
** CloneGame Virgile AGNEL
*/

#include "Blocks.hpp"

Game::Blocks::Blocks(const std::string &name, const GameObjectInfo &type, const std::string &vPath, const std::string &fPath) : GameObject(name, type)
{
    std::cout << "constructing a block..." << std::endl;
    // first trying to draw a triangle
    const float positions[] = { // vertex here is really symple it is only position
        -0.5f, -0.5f, // may need to create a struct/class for better vertex
        0.0f, 0.5f,
        0.5f, -0.5f,
    };

    this->__bufferId = 0;
    ::glGenBuffers(1, &this->__bufferId);
    ::glBindBuffer(GL_ARRAY_BUFFER, this->__bufferId);
    ::glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions, GL_STATIC_DRAW);
    ::glEnableVertexAttribArray(0);
    ::glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    // multiple call of vertexAttrib and enableVertex if vertex contains multiple info
    this->__shader = std::make_unique<Shaders>(vPath, fPath);
    ::glUseProgram(this->__shader->getProgramID());
    ::glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Game::Blocks::renderObj()
{
    std::cout << "rendering -> " << this->__bufferId << std::endl;
    ::glBindBuffer(GL_ARRAY_BUFFER, this->__bufferId);
    ::glDrawArrays(GL_TRIANGLES, 0, 3);
    ::glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Game::Blocks::~Blocks()
{
}
