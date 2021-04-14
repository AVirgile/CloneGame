/*
** CloneGame Virgile AGNEL
*/

#include "ErrorsSDL2.hpp"

Errors::ErrorsSDL2::ErrorsSDL2(const std::string &msg) throw() : _msg("SDL2 Error detected -> " + msg)
{
}

const char *Errors::ErrorsSDL2::what(void) const throw()
{
    return (this->_msg.c_str());
}
