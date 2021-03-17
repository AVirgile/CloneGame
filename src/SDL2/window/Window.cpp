/*
** CloneGame Virgile AGNEL
*/

#include "Window.hpp"
#include "../../Errors/SDL2/ErrorSDL.hpp"
#include "../../Events/Event.hpp"

Clone::Window::Window(const size_t &x, const size_t &y, const size_t &flags)
{
    this->_win_flags = flags;
    this->_win_height = y;
    this->_win_lenght = x;
    this->_win = nullptr;
    this->_isRunning = false;
    this->_eventHandler = std::make_unique<Event>(*this);
}

Clone::Window::Window(const Window &cpy)
{
    this->_isRunning = cpy._isRunning;
    this->_context = cpy._context;
    this->_win = cpy._win;
    this->_win_flags = cpy._win_flags;
    this->_win_height = cpy._win_height;
    this->_win_lenght = cpy._win_lenght;
    this->_eventHandler = cpy._eventHandler;
}

void Clone::Window::setIsRunning(const bool &val)
{
    this->_isRunning = val;
}

void Clone::Window::createWindow(const std::string &name)
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        throw Error::ErrorSDL("Error while initiating SDL library");
    }
    this->_win = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        this->_win_lenght,
        this->_win_height,
        this->_win_flags
    );
    if (this->_win == nullptr) {
        throw Error::ErrorSDL("Error while creating window '" + name + "'");
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	this->_context = SDL_GL_CreateContext(this->_win);
    glClearColor(1.f, 0.f, 1.f, 0.f); // pink background
    glViewport(0, 0, this->_win_lenght, this->_win_height);
}

void Clone::Window::mainLoop()
{
    this->_isRunning = true;
    while (this->_isRunning == true) {
        this->_eventHandler->handleEvent();
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(this->_win);
    }
}

Clone::Window::~Window()
{
    SDL_GL_DeleteContext(this->_context);  
	SDL_DestroyWindow(this->_win);
	SDL_Quit();
}
