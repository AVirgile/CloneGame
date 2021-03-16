/*
** CloneGame Virgile AGNEL
*/

#include "ErrorSDL.hpp"

Error::ErrorSDL::ErrorSDL(const std::string &msg) throw() : _msg(msg)
{
}

const char *Error::ErrorSDL::what() const throw()
{
    std::string error(SDL_GetError());

    return ((this->_msg + ": " + error).c_str());
}