/*
** CloneGame Virgile Agnel
*/

#include "StopOccured.hpp"

Errors::StopOccured::StopOccured(const std::string &msg) throw() : __msg("Stop Requested: " + msg)
{
}

const char *Errors::StopOccured::what() const throw()
{
    return (this->__msg.c_str());
}

Errors::StopOccured::~StopOccured() throw()
{
}
