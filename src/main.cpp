/*
** CloneGame Virgile AGNEL
*/

#include "required.hpp"
#include "SDL2/Window/Window.hpp"

int main(int const argc, char const *argv[])
{ 
    (void)argc;
    (void)argv;
    auto start = std::chrono::steady_clock::now();

    try {
        SDL2::Window(1600, 900, SDL_WINDOW_OPENGL, "clone", start).runWindow();
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return (84);
    }
    return (0);
}