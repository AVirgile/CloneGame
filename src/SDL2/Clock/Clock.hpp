/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"

namespace SDL2 {
    class Clock {
        public:
            Clock() = default;
            Clock(const std::chrono::_V2::steady_clock::time_point &start);
            ~Clock() = default;

            bool calculTime(const uint32_t &time);
            float getDeltaTime();

            inline const std::chrono::_V2::steady_clock::time_point &getStartTime() const
            {
                return (this->__progStart);
            }
        protected:
        private:
            std::map<uint32_t, uint32_t> __tracker;
            float __lastFrame;
            float __currentFrame;

            std::chrono::_V2::steady_clock::time_point __progStart;
    };
}
