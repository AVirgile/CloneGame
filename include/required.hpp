/*
** CloneGame Virgile AGNEL
*/

#pragma once

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
#include <array>
#include "glm/glm/glm.hpp"
#include "glm/glm/gtx/transform.hpp"

#define ONE_SECOND 1000

enum GameObjectInfo {
    PLAYER,
    BLOCK,
};

#define NB_OF_ACTIONS 5 // modify every time new key is added

// static tab linking key in csv to sdl key
static const std::pair<std::string, char> strToSDL[] = {
    std::make_pair("z", SDLK_z),
    std::make_pair("s", SDLK_s),
    std::make_pair("q", SDLK_q),
    std::make_pair("d", SDLK_d),
    std::make_pair("esc", SDLK_ESCAPE),
    // MORE...
};

enum ActionsOnEvents {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    QUIT,
    // MORE...
};

// static tab linking action in csv to events actions
static const std::pair<std::string, ActionsOnEvents> strToActions[] = {
    std::make_pair("forward", FORWARD),
    std::make_pair("backward", BACKWARD),
    std::make_pair("left", LEFT),
    std::make_pair("right", RIGHT),
    std::make_pair("quit", QUIT),
    // MORE...
};
