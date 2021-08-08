#pragma once

#include "Types.hpp"

enum CurrentGame : ubyte {
    Snake_,
    Pong,
    Tetris
};

enum Direction2d : ubyte {
    up,
    down,
    left,
    right
};

enum SnakeRectState : ubyte {
    None, // empty
    Food,
    SnakeSection // part of snake
};

struct Point {
    int x, y;

    Point& operator=(const Point& other) noexcept {
        x = other.x;
        y = other.y;
        return *this;
    }
};


struct SnakeGridRect {
    int x, y, w;
    SnakeRectState state;
};
