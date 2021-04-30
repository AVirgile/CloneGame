/*
** CloneGame Virgile AGNEL
*/

#include "ErrorsUtils.hpp"

Errors::ErrorsUtils::ErrorsUtils(const std::string &msg) throw() : __msg("Error in tools classes: " + msg)
{
}

const char *Errors::ErrorsUtils::what(void) const throw()
{
    return (this->__msg.c_str());
}