/*
** Clone Game Virgile Agnel
*/

#include "MouseMotion.hpp"
#include "glm/glm/fwd.hpp"
#include <SDL2/SDL_events.h>

SDL2::MouseMotion::MouseMotion()
{
}

void SDL2::MouseMotion::handleType(Game::GameData &data, const SDL_Event &input)
{
    this->__mousePos = glm::vec2(input.motion.x, input.motion.y);
    this->__handleCameraLink(data, input.motion);
}

void SDL2::MouseMotion::__handleCameraLink(Game::GameData &data, const ::SDL_MouseMotionEvent &mot)
{
    glm::vec2 relPos;
    
    relPos.x = mot.xrel;
    relPos.y = mot.yrel;
    data.getCam().processMouveMove(relPos);
}

