/*
** Clone Game Virgile Agnel
*/

#pragma once

#include "glm/glm/fwd.hpp"
#include "required.hpp"
#include "../ITypes.hpp"
#include <SDL2/SDL_events.h>

namespace SDL2 {
    class MouseMotion : public ITypes {
        public:
            MouseMotion();
            MouseMotion(const MouseMotion &model) = delete;
            MouseMotion &operator = (const MouseMotion &model) = delete;
            ~MouseMotion() = default;

            void handleType(Game::GameData &data, const SDL_Event &input);
        protected:
        private:
            void __handleCameraLink(Game::GameData &data, const ::SDL_MouseMotionEvent &mot);

            glm::vec2 __mousePos;
    };
};
