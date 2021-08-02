#pragma once

#include <thread>
#include <chrono>


#include "Types.hpp"
#include "Color.hpp"
#include "Structs.hpp"
#include "Snake.hpp"
#include "SnakeGrid.hpp"

namespace Util {
    void Sleep(uint ms);
    int64 GetTimeMs();
    Color GetSnakeGridRectColor(const SnakeGridRect& rect);
};