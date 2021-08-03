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
    none, // empty
    food,
    SnakeSection // part of snake
};

struct Point {
    int x, y;
};


struct SnakeGridRect {
    int x, y, w;
    SnakeRectState state;
};
