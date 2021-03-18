/*
** CloneGame Virgile AGNEL
*/

#pragma once

#ifndef ERRORSYS_HPP_
#define ERRORSYS_HPP_

#include "required.hpp"

namespace Error {
    class ErrorSys : public std::exception {
        public:
            ErrorSys(const std::string &)  throw();
            ~ErrorSys() throw() = default;

            const char *what() const throw();
        protected:
        private:
            std::string _msg;
    };
}

#endif /* !ERRORSYS_HPP_ */
