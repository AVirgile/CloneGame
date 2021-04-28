/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace Errors {
    class StopOccured : public std::exception {
        public:
            StopOccured(const std::string &msg) throw();
            StopOccured() = delete;
            ~StopOccured() throw();

            const char *what(void) const throw();
        protected:
        private:
            const std::string __msg;
    };
};
