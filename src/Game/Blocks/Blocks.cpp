/*
** CloneGame Virgile AGNEL
*/

#include "Blocks.hpp"
#include "../../Errors/ErrorsGameEngine/ErrorsGameEngine.hpp"

Game::Blocks::Blocks(const std::string &name, const GameObjectInfo &type, const std::string &vPath, const std::string &fPath) : GameObject(name, type)
{
    ::GLint size = 0;
    std::cout << "constructing a block..." << std::endl;
    // first trying to draw a triangle
    const float positions[] = { // vertex here is really symple it is only position
        -0.5f, -0.5f, // may need to create a struct/class for better vertex
        0.5f, -0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
    };

    const ::GLuint indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    this->__bufferId = 0;
    this->__ibo = 0;
    ::glGenBuffers(1, &this->__bufferId);
    ::glBindBuffer(GL_ARRAY_BUFFER, this->__bufferId);
    ::glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), &positions, GL_STATIC_DRAW);
    ::glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    if (6 * 2 * sizeof(float) != size) {
        ::glDeleteBuffers(1, &this->__bufferId);
        throw Errors::ErrorsGameEngine("error creating buffer -> " + std::to_string(::glGetError())); 
    }
    ::glEnableVertexAttribArray(0);
    ::glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    // multiple call of vertexAttrib and enableVertex if vertex contains multiple info
    
    // create buffer index
    ::glGenBuffers(1, &this->__ibo);
    ::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->__ibo);
    ::glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(::GLuint), &indices, GL_STATIC_DRAW);
    
    this->__shader = std::make_unique<Shaders>(vPath, fPath);
    ::glUseProgram(this->__shader->getProgramID());
    ::glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Game::Blocks::renderObj(const Camera &cam)
{
    //std::cout << "rendering -> " << this->__bufferId << std::endl;
    (void)cam;
    ::glBindBuffer(GL_ARRAY_BUFFER, this->__ibo);
    ::glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    ::glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Game::Blocks::~Blocks()
{
    ::glDeleteBuffers(1, &this->__bufferId);
    ::glDeleteBuffers(1, &this->__ibo);
}
