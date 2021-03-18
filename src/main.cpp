/*
** CloneGame Virgile AGNEL
*/

#include "required.hpp"
#include "SDL2/window/Window.hpp"

int main(void)
{
    const char *msg = nullptr;
    std::unique_ptr<Clone::Window> core = std::make_unique<Clone::Window>(1200, 800, SDL_WINDOW_OPENGL);

    try {
        core->createWindow("Clone");
        core->mainLoop();
    }
    catch(const std::exception& e) {
        msg = e.what();
        std::cerr << msg << std::endl;
        delete msg;
        return (84);
    }
    return (0);
}