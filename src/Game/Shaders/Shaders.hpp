/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace Game {
    class Shaders {
        public:
            Shaders() = delete;
            Shaders(const std::string &vertexPath, const std::string &fragmentPath);
            ~Shaders();

            inline ::GLuint getProgramID() const
            {
                return (this->__programID);
            }
        protected:
        private:
            std::string __openFile(const std::string &path) const;
            ::GLuint __compileShader(const std::string &src, const ::GLenum &type);

            std::string __vertexPath;
            std::string __fragmentPath;
            std::string __vertexShader;
            std::string __fragmentShader;

            ::GLuint __programID;
            ::GLuint __vertexID;
            ::GLuint __fragmentID;
    };
}