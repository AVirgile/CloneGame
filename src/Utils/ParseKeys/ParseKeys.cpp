/*
** CloneGame Virgile AGNEL
*/

#include "ParseKeys.hpp"
#include "../../Errors/ErrorsUtils/ErrorsUtils.hpp"

Utils::ParseKeys::ParseKeys(const std::string &pathToCsv)
{
    this->__path = pathToCsv;
    this->__parseFile();
}

void Utils::ParseKeys::__linkToken(const size_t &lineNb, const std::vector<std::string> &vec)
{
    char key = 0;
    ActionsOnEvents act;
    bool confirm = false;

    if (vec[0] == "action" && vec[1] == "key")
        return;
    for (auto const &val : strToActions) {
        if (val.first == vec[0]) {
            act = val.second;
            confirm = true;
        }
    }
    if (confirm == false) {
        throw Errors::ErrorsUtils("undifined actions -> " + vec[0] + " at " + std::to_string(lineNb));
    }
    confirm = false;
    for (auto const &val : strToSDL) {
        if (val.first == vec[1]) {
            key = val.second;
            confirm = true;
        }
    }
    if (confirm == false) {
        throw Errors::ErrorsUtils("undifined key -> " + vec[1] + " at " + std::to_string(lineNb));
    }
    this->__keysMap[act] = key;
}

void Utils::ParseKeys::__parseFile()
{
    std::ifstream infile(this->__path);
    std::string line = "";
    std::regex re = std::regex{R"([\s,]+)"};
    std::vector<std::string> vec;
    size_t lineNb = 1;

    if (infile.is_open()) {
        while (std::getline(infile, line)) {
            if (line.length() == 0)
                continue;
            vec = std::vector<std::string>(
                std::sregex_token_iterator{begin(line), end(line), re, -1},
                std::sregex_token_iterator{}
            );
            if (vec.size() != 2)
                throw Errors::ErrorsUtils("csv format error at line -> " + std::to_string(lineNb));
            this->__linkToken(lineNb, vec);
            lineNb++;
        }
    } else {
        throw Errors::ErrorsUtils("opening file -> " + this->__path + " failed");
    }
    if (this->__keysMap.size() != NB_OF_ACTIONS) {
        throw Errors::ErrorsUtils("csv errors -> all handled actions have not been all mapped");
    }
}

