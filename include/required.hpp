/*
** CloneGame Virgile AGNEL
*/

#pragma once

#ifndef REQUIRED_HPP_
#define REQUIRED_HPP_

#define GL_GLEXT_PROTOTYPES

#include <iostream>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <vector>
#include <functional>
#include <memory>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "glm/glm/glm.hpp"
#include "glm/glm/gtx/transform.hpp"

#define ONE_SECOND 1000

enum GameObjectInfo {
    PLAYER,
    BLOCK,
};

#endif /* !REQUIRED_HPP_ */
