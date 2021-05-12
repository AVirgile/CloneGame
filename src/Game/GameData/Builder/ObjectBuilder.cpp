/*
** CloneGame Virgile AGNEL
*/


#include "ObjectBuilder.hpp"
#include "../../../Errors/ErrorsGameEngine/ErrorsGameEngine.hpp"

Game::ObjectBuilder::ObjectBuilder()
{
    this->__fctMap[BLOCK] = &ObjectBuilder::__createBlocks;
}

std::unique_ptr<Game::IGameObject> Game::ObjectBuilder::__createBlocks(const std::string &name, const GameObjectInfo &info, const std::string &vPath, const std::string &fPath, const Vertex &vertex) const
{
    return (std::make_unique<Blocks>(name, info, vPath, fPath, vertex));
}

std::unique_ptr<Game::IGameObject> Game::ObjectBuilder::createObject(const std::string &name, const GameObjectInfo &info, const std::string &vPath, const std::string &fPath, const Vertex &vertex)
{
    for (auto const &val : this->__fctMap) {
        if (val.first == info) {
            return (this->__fctMap[info](*this, name, info, vPath, fPath, vertex));
        }
    }
    throw Errors::ErrorsGameEngine("unknown type requested for creation of object -> " + std::to_string(info));
}
