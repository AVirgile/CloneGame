/*
** Clone Game Virgile Agnel
*/

#include "Vertex.hpp"
#include <SDL2/SDL_opengl.h>
#include <ios>
#include <memory>

Game::Vertex::Vertex(const vertexData_t *arr, const ::GLuint *indices, const size_t &dataSize, const size_t &arrSize, const size_t &indicesSize)
{
    this->__dataArrSize = arrSize;
    this->__indicesSize = indicesSize;
    this->__dataSize = dataSize;
    this->__data = std::make_unique<vertexData_t[]>(this->__dataArrSize);
    this->__indices = std::make_unique<::GLuint[]>(this->__indicesSize);
    this->__copyArray<vertexData_t>(&(*this->__data.get()), arr, this->__dataArrSize);
    this->__copyArray<::GLuint>(&(*this->__indices.get()), indices, this->__indicesSize);

}

Game::Vertex &Game::Vertex::operator=(const Vertex &mod)
{
    this->__dataArrSize = mod.__dataArrSize;
    this->__indicesSize = mod.__indicesSize;
    this->__dataSize = mod.__dataSize;
    this->__data = std::make_unique<vertexData_t[]>(this->__dataArrSize);
    this->__indices = std::make_unique<::GLuint[]>(this->__indicesSize);
    this->__copyArray<vertexData_t>(&(*this->__data.get()), &(*mod.__data.get()), this->__dataArrSize);
    this->__copyArray<::GLuint>(&(*this->__indices.get()), &(*mod.__indices.get()), this->__indicesSize);
    return (*this);
}

Game::Vertex::Vertex(const Vertex &mod)
{
    this->__dataArrSize = mod.__dataArrSize;
    this->__indicesSize = mod.__indicesSize;
    this->__dataSize = mod.__dataSize;
    this->__data = std::make_unique<vertexData_t[]>(this->__dataArrSize);
    this->__indices = std::make_unique<::GLuint[]>(this->__indicesSize);
    this->__copyArray<vertexData_t>(&(*this->__data.get()), &(*mod.__data.get()), this->__dataArrSize);
    this->__copyArray<::GLuint>(&(*this->__indices.get()), &(*mod.__indices.get()), this->__indicesSize);
}

size_t Game::Vertex::getSpecificDataSize(const specificDataSize &data) const
{
    (void)data;
    return (0);
}

Game::Vertex::~Vertex()
{

}
