#pragma once

#include <thread>
#include <chrono>
#include <ctime>
#include <random>
#include <cmath>

#include "Types.hpp"
#include "Color.hpp"
#include "Structs.hpp"

namespace Util {
    void Sleep(uint ms);
    int64 GetTimeMs();
    Color GetSnakeGridRectColor(const SnakeGridRect& rect);
	FPoint Rotate(const FPoint& p, const FPoint& origin, float angle);
	float toRad(float angle);
    float toDeg(float angle);
    inline Clock_t GetClock() { return std::chrono::steady_clock::now(); }
    // returns clock1-clock2 in seconds
    float GetClockDifference(const Clock_t& clock1, const Clock_t& clock2);
    inline int GetKeyCode(const SDL_Event& e) { return e.key.keysym.sym; }
    int GetRandomInt(int max, int min=0);
};