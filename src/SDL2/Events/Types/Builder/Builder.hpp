/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../ITypes.hpp"
#include "../KeyDown/KeyDown.hpp"

namespace SDL2 {
    class Builder {
        public:
            Builder();
            ~Builder();

            std::unique_ptr<ITypes> createType(const uint32_t &type);
        protected:
        private:
            std::unique_ptr<ITypes> __createKeyDown() const noexcept;

            using fct_type = std::unique_ptr<ITypes>(const Builder &);
            std::map<uint32_t, std::function<fct_type>> _fctMap;
    };
}