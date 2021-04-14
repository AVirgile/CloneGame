/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../Clock/Clock.hpp"

namespace SDL2 {
    class Window {
        public:
            Window(const size_t &width, const size_t &height, const uint32_t &flags, const std::string &name);
            ~Window();

            void runWindow();

            inline size_t getWidth() const
            {   
                return (this->__width);
            }
            inline size_t getHeight() const
            {
                return (this->__height);
            }
            inline uint32_t getFlags() const
            {
                return (this->__flags);
            }
            inline std::string getName() const
            {
                return (this->__name);
            }
        protected:
        
        private:
            void __gameLoop();

            size_t __width;
            size_t __height;
            uint32_t __flags;
            std::string __name;
            SDL_Window *__window;
            SDL_GLContext __context;
            bool __running;
            std::shared_ptr<Clock> __timeManager;
    };
}