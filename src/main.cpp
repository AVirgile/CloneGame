/*
** CloneGame Virgile AGNEL
*/

#include "required.hpp"
#include "SDL2/Window/Window.hpp"

int main(int const argc, char const *argv[])
{ 
    (void)argc;
    (void)argv;
    try {
        SDL2::Window(1600, 900, SDL_WINDOW_OPENGL, "clone").runWindow();
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return (84);
    }
    return (0);
}