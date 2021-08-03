#pragma once

#include <vector>
#include <utility>

#include "Renderer.hpp" 
#include "Types.hpp"
#include "Structs.hpp"
#include "KeyboardHandler.hpp"

#define SNAKE_COLOR Color(0, 230, 80)

// forward declaration 
class SnakeGame;


class Snake {
public:
    Color color;
    Snake();
    void Init(Renderer *renderer, KeyboardHandler *kbHandler, uint length, int head_x, int head_y, uint rectWidth);
    void Draw() const;
    void Grow(SnakeGame *grid);
    void AddSnakeToGrid(SnakeGame *grid);
    void Shrink();
    void Update();
    bool IsAlive() const;
    ~Snake();
private:
    Renderer *m_renderer;
    KeyboardHandler *m_keyboard;
    std::vector<Point> m_snake;
    Direction2d m_direction;
    Clock_t m_lastUpdate;
    uint m_length;
    uint m_rectWidth;
    bool m_isAlive;
};