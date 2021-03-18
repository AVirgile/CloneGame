/*
** CloneGame Virgile AGNEL
*/

#include "ErrorSys.hpp"

Error::ErrorSys::ErrorSys(const std::string &msg) throw() : _msg(msg)
{
}

const char *Error::ErrorSys::what() const throw()
{
    const std::string final = "ERROR CRITICAL [SYSTEM] : " + this->_msg;
    size_t len = final.length();
    char *res = new char[len + 1];

    memmove(res, final.c_str(), len + 1);
    return (res);
}
