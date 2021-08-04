#pragma once

#include "Snake.hpp"
#include "InputHandler.hpp"
#include "Types.hpp"
#include "Structs.hpp"
#include "Utils.hpp"

#define SNAKE_GRID_GRAY Color(100, 100, 100)
#define SNAKE_GRID_APPLE_COLOR Color(200, 30, 30)

class SnakeGame {
public:
    SnakeGame();
    void Init(Renderer *renderer, Window *window, InputHandler *kbHandler,int x, int y, int rectWidth=10);
    void Draw();
    void GenApple(); // adds apple to random square on grid
    void Update();
    void ClearGrid();
    // returns true on success and false on failure
    bool Set(int x_index, int y_index, const SnakeRectState& state);
    SnakeRectState Get(int x_index, int y_index);
    int GetWidth() const;
    int GetHeight() const;
    ~SnakeGame();
private:
    Snake m_snake;
    std::vector<std::vector<SnakeGridRect>> m_grid;
    Renderer *m_renderer;
    InputHandler *m_input;
    int m_windowW, m_windowH;
    int m_rectWidth;
};