/*
** CloneGame Virgile AGNEL
*/

#include "Window.hpp"
#include "../../Errors/ErrorsSDL2/ErrorsSDL2.hpp"
#include "../../Errors/ErrorsGameEngine/ErrorsGameEngine.hpp"
#include "glm/glm/fwd.hpp"
#include "../../Errors/StopOccured/StopOccured.hpp"

SDL2::Window::Window(const size_t &width, const size_t &height, const uint32_t &flags, const std::string &name, const std::chrono::_V2::steady_clock::time_point &start)
{
    float aspect = 0.0f;

    this->__timeManager = std::make_shared<Clock>(start);
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
    this->__running = false;
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glViewport(0, 0, this->__width, this->__height);
    aspect = static_cast<float>(this->__width) / static_cast<float>(this->__height);
    this->__gameInfo = std::make_unique<Game::GameData>(glm::vec3(0, 0, -3), 70.0f, aspect, 0.01f, 1000.0f, 0.05f, this->__timeManager);
}

void SDL2::Window::runWindow()
{
    if (this->__running == false) {
        this->__running = true;
        this->__gameLoop();
    } else {
        throw Errors::ErrorsSDL2("Window is already running");
    }
}

void SDL2::Window::__gameLoop()
{
    while (this->__running) {
        // if (this->__timeManager->calculTime(500)) {
        //     std::cout << "half a second" << std::endl;
        // }
        // if (this->__timeManager->calculTime(1000)) {
        //     std::cout << "one second" << std::endl;
        // }
        glClear(GL_COLOR_BUFFER_BIT);
        try {
            this->__eventsHandler.processEvent(this->__running, *this->__gameInfo);
            this->__gameInfo->updateGame();
            this->__timeManager->calulDeltaTime();
            this->__gameInfo->render();
        } catch (const Errors::StopOccured &ex) {
            this->__running = false;
        }
        SDL_GL_SwapWindow(this->__window);
    }
}

SDL2::Window::~Window()
{
    SDL_GL_DeleteContext(this->__context);  
	SDL_DestroyWindow(this->__window);
	SDL_Quit();
}
