#pragma once

#include <vector>
#include <utility>

#include "Renderer.hpp" 
#include "Types.hpp"
#include "Structs.hpp"

#define SNAKE_COLOR Color(0, 230, 80)

// forward declaration 
class SnakeGrid;


class Snake {
public:
    Color color;
    Snake();
    void Init(Renderer *renderer, uint length, int head_x, int head_y, uint rectWidth);
    void Draw() const;
    void Grow(SnakeGrid *grid);
    void AddSnakeToGrid(SnakeGrid *grid);
    void Shrink();
    void Move();
    bool IsAlive() const;
    ~Snake();
private:
    Renderer *m_renderer;
    std::vector<Point> m_snake;
    Direction2d m_direction;
    uint m_length;
    uint m_rectWidth;
    bool m_isAlive;
};