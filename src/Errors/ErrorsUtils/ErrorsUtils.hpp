/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace Errors {
    class ErrorsUtils : public std::exception {
        public:
            ErrorsUtils(const std::string &msg) throw();
            ~ErrorsUtils() throw() = default;
            const char *what(void) const throw();

        protected:
        private:
            const std::string __msg;
    };
}
