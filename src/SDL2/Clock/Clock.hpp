/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace SDL2 {
    class Clock {
        public:
            Clock();
            ~Clock() = default;

            bool calculTime(const uint32_t &time);

        protected:
        private:
            std::map<uint32_t, uint32_t> __tracker;
    };
}
