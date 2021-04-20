/*
** CloneGame Virgile AGNEL
*/

#include "Builder.hpp"
#include "../../../../Errors/ErrorsSDL2/ErrorsSDL2.hpp"

SDL2::Builder::Builder()
{
    this->_fctMap[SDL_KEYDOWN] = &Builder::__createKeyDown;
}

std::unique_ptr<SDL2::ITypes> SDL2::Builder::__createKeyDown() const noexcept
{
    return (std::make_unique<KeyDown>());
}

std::unique_ptr<SDL2::ITypes> SDL2::Builder::createType(const uint32_t &type)
{
    if (this->_fctMap.count(type) > 0) {
        return (this->_fctMap[type](*this));
    } else {
        throw Errors::ErrorsSDL2("Type requested does not exist -> " + std::to_string(type));
    }
}

SDL2::Builder::~Builder()
{
}
