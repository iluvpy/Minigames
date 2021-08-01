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
    SnakeGrid(Renderer *renderer, Window *window, int x, int y, uint rectWidth=10);
    void Draw() const;
    void GenApple(); // adds apple to random square on grid
    void Update();
    ~SnakeGrid();
private:
    Snake m_snake;
    std::vector<std::vector<SnakeRectState>> m_grid;
    Renderer *m_renderer;
    int m_startX, m_startY;
    uint m_windowW, m_windowH;
    uint m_rectWidth;
};