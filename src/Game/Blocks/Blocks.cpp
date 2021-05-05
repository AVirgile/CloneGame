/*
** CloneGame Virgile AGNEL
*/

#include "Blocks.hpp"
#include "../../Errors/ErrorsGameEngine/ErrorsGameEngine.hpp"
#include <SDL2/SDL_opengl.h>

Game::Blocks::Blocks(const std::string &name, const GameObjectInfo &type, const std::string &vPath, const std::string &fPath, const Vertex &info) : GameObject(name, type)
{
    ::GLint size = 0;
    std::cout << "constructing a block..." << std::endl;
;
    this->__vertex = std::make_unique<Vertex>(info);
    std::cout << this->__vertex->getDataBytes() << std::endl;
    this->__bufferId = 0;
    this->__ibo = 0;
    ::glGenBuffers(1, &this->__bufferId);
    ::glBindBuffer(GL_ARRAY_BUFFER, this->__bufferId);
    ::glBufferData(GL_ARRAY_BUFFER, this->__vertex->getDataBytes(), this->__vertex->getData().get(), GL_STATIC_DRAW);
    ::glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    if (static_cast<int>(this->__vertex->getDataBytes()) != size) {
        ::glDeleteBuffers(1, &this->__bufferId);
        throw Errors::ErrorsGameEngine("error creating buffer -> " + std::to_string(::glGetError())); 
    }
    ::glEnableVertexAttribArray(0);
    ::glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, this->__vertex->getSpecificDataSize(Vertex::specificDataSize::POSITION), 0);
    // multiple call of vertexAttrib and enableVertex if vertex contains multiple info
    
    // create buffer index
    ::glGenBuffers(1, &this->__ibo);
    ::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->__ibo);
    ::glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->__vertex->getIndicesBytes(), this->__vertex->getIndices().get(), GL_STATIC_DRAW);
    
    this->__shader = std::make_unique<Shaders>(vPath, fPath);
    ::glUseProgram(this->__shader->getProgramID());
    ::glBindBuffer(GL_ARRAY_BUFFER, 0);
    this->__visible = true;
}

void Game::Blocks::updateObj(const Camera &cam, const Transform &trs)
{
    this->__shader->updateShader(cam, trs);
}

void Game::Blocks::renderObj()
{
    //std::cout << "rendering -> " << this->__bufferId << std::endl;
    if (this->__visible == false) {
        return;
    }
    ::glBindBuffer(GL_ARRAY_BUFFER, this->__ibo);
    ::glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    ::glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Game::Blocks::~Blocks()
{
    ::glDeleteBuffers(1, &this->__bufferId);
    ::glDeleteBuffers(1, &this->__ibo);
}
