/*
** EPITECH PROJECT, 2021
** CloneGame [WSL: Ubuntu-18.04]
** File description:
** ErrorSDL
*/

#pragma once

#ifndef ERRORSDL_HPP_
#define ERRORSDL_HPP_

#include "required.hpp"

namespace Error {
    class ErrorSDL : public std::exception {
        public:
            ErrorSDL(const std::string &) throw();
            ~ErrorSDL() throw() = default;

            const char *what() const throw();
        protected:
        private:
            const std::string _msg;
    };
}

#endif /* !ERRORSDL_HPP_ */
