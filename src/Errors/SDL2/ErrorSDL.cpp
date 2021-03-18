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
    const std::string final = this->_msg + ": " + error;
    size_t len = final.length();
    char *res = new char[len + 1];

    memmove(res, final.c_str(), len + 1);
    return (res);
}