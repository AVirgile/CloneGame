/*
** Clone Game Virgile Agnel
*/

#include "Transform.hpp"
#include "glm/glm/ext/matrix_transform.hpp"
#include "glm/glm/fwd.hpp"
#include "glm/glm/gtx/transform.hpp"

Game::Transform::Transform(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scale)
{
    this->__pos = pos;
    this->__rot = rot;
    this->__scale = scale;
}

Game::Transform::Transform(const Transform &model)
{
    this->__pos = model.__pos;
    this->__rot = model.__rot;
    this->__scale = model.__scale;
}

Game::Transform &Game::Transform::operator = (const Transform &model)
{
    this->__pos = model.__pos;
    this->__rot = model.__rot;
    this->__scale = model.__scale;
    return (*this);
}

glm::mat4 Game::Transform::getMVP(const Camera &cam) const
{
    glm::mat4 posMat = glm::translate(this->__pos);
    glm::mat4 scaleMat = glm::scale(this->__scale);
    glm::mat4 rotX = glm::rotate(this->__rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rotY = glm::rotate(this->__rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotZ = glm::rotate(this->__rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 rotMat = rotX * rotY * rotZ;
    
    return (cam.getViewProjection() * (posMat * rotMat * scaleMat));
}
