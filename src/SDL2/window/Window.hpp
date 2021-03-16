/*
** CloneGame Virgile AGNEL
*/

#pragma once

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "required.hpp"

namespace Clone {
    class Window {
        public:
            Window(const size_t &, const size_t &, const size_t &);
            void createWindow(const std::string &);
            void mainLoop();
            ~Window();

        protected:
        private:
            bool _isRunning;
            SDL_Window *_win;
            size_t _win_flags;
            size_t _win_height;
            size_t _win_lenght;
            SDL_GLContext _context;
    };
}

#endif /* !WINDOW_HPP_ */
