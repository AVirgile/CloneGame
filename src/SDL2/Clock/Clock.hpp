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
            void calulDeltaTime();

            inline float getDeltaTime() const
            {
                return (this->__delta);
            }

            inline const std::chrono::_V2::steady_clock::time_point &getStartTime() const
            {
                return (this->__progStart);
            }
        protected:
        private:
            std::map<uint32_t, uint32_t> __tracker;
            float __lastFrame;
            float __currentFrame;
            float __delta;
            std::chrono::_V2::steady_clock::time_point __progStart;
    };
}
