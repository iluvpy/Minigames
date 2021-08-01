#pragma once

#include "Snake.hpp"
#include "Types.hpp"

enum SnakeRectState : ubyte {
    none, // empty
    food,
    snakeSection // part of snake
};

class SnakeGrid {
public:
    // rect width 0 mean auto
    SnakeGrid(int x, int y, uint rectWidth=0);
    void Draw() const;
    void GenApple(); // adds apple to random square on grid
    void Update();
    ~SnakeGrid();
private:
    Snake m_snake;
};