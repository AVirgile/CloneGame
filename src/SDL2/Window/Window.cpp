/*
** CloneGame Virgile AGNEL
*/

#include "Window.hpp"
#include "../../Errors/ErrorsSDL2/ErrorsSDL2.hpp"

SDL2::Window::Window(const size_t &width, const size_t &height, const uint32_t &flags, const std::string &name)
{
    this->__width = width;
    this->__height = height;
    this->__flags = flags;
    this->__name = name;
    this->__window = SDL_CreateWindow(
        this->__name.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        this->__width,
        this->__height,
        this->__flags
    );
    if (this->__window == nullptr) {
        throw Errors::ErrorsSDL2("(Window constructor) Window creation has failed");
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    this->__context = SDL_GL_CreateContext(this->__window);
    this->__running = true;
    glClearColor(1.f, 0.f, 1.f, 0.f);
    glViewport(0, 0, this->__width, this->__height);
}

void SDL2::Window::runWindow()
{
    this->__gameLoop();
}

void SDL2::Window::__gameLoop()
{
    while (this->__running) {
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(this->__window);
    }
}

SDL2::Window::~Window()
{
    SDL_GL_DeleteContext(this->__context);  
	SDL_DestroyWindow(this->__window);
	SDL_Quit();
}