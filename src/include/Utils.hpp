#pragma once

#include <thread>
#include <chrono>


#include "Types.hpp"
#include "Color.hpp"
#include "Structs.hpp"
#include "Snake.hpp"
#include "SnakeGame.hpp"

namespace Util {
    void Sleep(uint ms);
    int64 GetTimeMs();
    Color GetSnakeGridRectColor(const SnakeGridRect& rect);
    inline Clock_t GetClock() { return std::chrono::steady_clock::now(); }
    // returns clock1-clock2 in seconds
    float GetClockDifference(Clock_t clock1, Clock_t clock2);
    inline int GetKeyCode(SDL_Event e) { return e.key.keysym.sym; }
};