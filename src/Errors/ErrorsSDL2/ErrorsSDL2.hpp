/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace Errors {
    class ErrorsSDL2 : public std::exception {
        public:
            ErrorsSDL2(const std::string &msg) throw();
            ~ErrorsSDL2() throw() = default;
            const char *what(void) const throw();
        protected:
        
        private:
            const std::string _msg;
    };
}