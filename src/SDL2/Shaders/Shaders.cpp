/*
** CloneGame Virgile AGNEL
*/

#include "Shaders.hpp"
#include "../../Errors/System/ErrorSys.hpp"

Clone::Shaders::Shaders(const std::string &vertexFlp, const std::string &fragFlp)
{
    this->_shaderId = 0;
    this->_vertexSrc = _loadSource(vertexFlp);
    this->_fragmentSrc = _loadSource(fragFlp);
}

std::string Clone::Shaders::_loadSource(const std::string &filepath)
{
    std::ifstream ifs(filepath);

    if (ifs.is_open() == false)
        throw Error::ErrorSys("error while opening file -> " + filepath);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    std::cout << content << std::endl;    
    return (content);
}

uint32_t Clone::Shaders::getShaderId() const noexcept
{
    return (this->_shaderId);
}

uint32_t Clone::Shaders::_compileShader(const int &type, const std::string &src) const
{
    (void)type;
    (void)src;
    return (0);
}

void Clone::Shaders::createShader()
{
}