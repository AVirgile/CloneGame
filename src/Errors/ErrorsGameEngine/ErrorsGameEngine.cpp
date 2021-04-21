/*
** CloneGame Virgile AGNEL
*/

#include "ErrorsGameEngine.hpp"

Errors::ErrorsGameEngine::ErrorsGameEngine(const std::string &msg) throw() : _msg("Errors in the game engine: " + msg)
{
}

const char *Errors::ErrorsGameEngine::what(void) const throw()
{
    return (this->_msg.c_str());
}

