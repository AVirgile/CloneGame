/*
** CloneGame Virgile AGNEL
*/

#include "Shaders.hpp"
#include "../../Errors/ErrorsGameEngine/ErrorsGameEngine.hpp"
#include <SDL2/SDL_opengl_glext.h>

Game::Shaders::Shaders(const std::string &vertexPath, const std::string &fragmentPath)
{
    GLint programLinked = 0;
    int logLength = 0;
    char message[1024];

    // load source code
    this->__vertexPath = vertexPath;
    this->__fragmentPath = fragmentPath;
    this->__vertexShader = this->__openFile(this->__vertexPath);
    this->__fragmentShader = this->__openFile(this->__fragmentPath);
    // create shader with openGL
    this->__programID = ::glCreateProgram();
    this->__vertexID = this->__compileShader(this->__vertexShader, GL_VERTEX_SHADER);
    this->__fragmentID = this->__compileShader(this->__fragmentShader, GL_FRAGMENT_SHADER);
    ::glAttachShader(this->__programID, this->__vertexID);
    ::glAttachShader(this->__programID, this->__fragmentID);
    ::glLinkProgram(this->__programID);
    ::glValidateProgram(this->__programID);
    ::glDeleteShader(this->__vertexID);
    ::glDeleteShader(this->__fragmentID);
    ::glGetProgramiv(this->__programID, GL_LINK_STATUS, &programLinked);
    if (programLinked != GL_TRUE) {
        ::glGetProgramInfoLog(this->__programID, 1024, &logLength, message);
        ::glDeleteProgram(this->__programID);
        throw Errors::ErrorsGameEngine("Error linking shader -> " + std::string(message));
    }
}

::GLuint Game::Shaders::__compileShader(const std::string &src, const ::GLenum &type)
{
    GLuint id = ::glCreateShader(type);
    const char *rawSrc = src.c_str();
    GLint vertexCompiled = 0;
    int logLength = 0;
    char message[1024];

    ::glShaderSource(id, 1, &rawSrc, nullptr);
    ::glCompileShader(id);
    ::glGetShaderiv(id, GL_COMPILE_STATUS, &vertexCompiled);
    if (vertexCompiled != GL_TRUE) {
        ::glGetShaderInfoLog(id, 1024, &logLength, message);
        ::glDeleteShader(id);
        throw Errors::ErrorsGameEngine("Error compiling shader -> " + std::string(message));
    }
    return (id);
}

void Game::Shaders::updateShader(const Camera &cam, const Transform &trs)
{
    int mat4Location = ::glGetUniformLocation(this->__programID, "u_MVP");
 
    ::glUniformMatrix4fv(mat4Location, 1, GL_FALSE, &trs.getMVP(cam)[0][0]);
}

std::string Game::Shaders::__openFile(const std::string &path) const
{
    std::ifstream f(path);
    std::ostringstream ss;

    if (!f) {
        throw Errors::ErrorsGameEngine("opening file -> " + path + " failed");
    }
    ss << f.rdbuf();
    return (ss.str());
}

Game::Shaders::~Shaders()
{
    ::glDeleteProgram(this->__programID);
}
