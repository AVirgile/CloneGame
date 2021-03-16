/*
** CloneGame Virgile AGNEL
*/

#include "required.hpp"
#include "SDL2/window/Window.hpp"

int main(void)
{
    std::unique_ptr<Clone::Window> core = std::make_unique<Clone::Window>(1200, 800, SDL_WINDOW_OPENGL);

    try {
        core->createWindow("Clone");
        core->mainLoop();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}