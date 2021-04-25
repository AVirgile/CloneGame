/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include <regex>

namespace Utils {
    class ParseKeys {
        public:
            ParseKeys() = delete;
            ParseKeys(const std::string &pathToCsv);

            ParseKeys(const ParseKeys &) = delete;
            ParseKeys &operator = (const ParseKeys &) = delete;
            ~ParseKeys() = default;


            inline std::string &getPath()
            {
                return (this->__path);
            }

            inline const std::map<ActionsOnEvents, char> &getKeysMap() const
            {
                return (this->__keysMap);
            }

        protected:
        private:
            void __parseFile();
            void __linkToken(const size_t &lineNb, const std::vector<std::string> &vec);
            
            
            std::string __path;
            std::map<ActionsOnEvents, char> __keysMap;
    };
}
