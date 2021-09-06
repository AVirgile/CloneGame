/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace Errors {
    class ErrorsGameEngine : public std::exception  {
        public:
            ErrorsGameEngine(const std::string &msg) throw();
            ~ErrorsGameEngine() throw() = default;
            const char *what(void) const throw();
        protected:
        private:
            const std::string _msg;
    };  
}
