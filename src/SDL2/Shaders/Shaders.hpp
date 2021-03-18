/*
** CloneGame Virgile AGNEL
*/

#pragma once

#ifndef SHADERS_HPP_
#define SHADERS_HPP_

#include "required.hpp"

namespace Clone {
    class Shaders {
        public:
            Shaders(const std::string &, const std::string &);
            void createShader();
            uint32_t getShaderId() const noexcept;
            ~Shaders() = default;

        protected:
        private:
            uint32_t _compileShader(const int &type, const std::string &src) const;
            std::string _loadSource(const std::string &filepath);

            uint32_t _shaderId;
            std::string _vertexSrc;
            std::string _fragmentSrc;

    };
}

#endif /* !SHADERS_HPP_ */
