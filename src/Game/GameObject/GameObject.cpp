/*
** CloneGame Virgile AGNEL
*/

#include "GameObject.hpp"

Game::GameObject::GameObject(const std::string &name, const GameObjectInfo &type)
{
    this->__name = name;
    this->__type = type;
}

Game::GameObject::~GameObject()
{
}
