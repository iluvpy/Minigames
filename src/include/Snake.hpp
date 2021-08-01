#pragma once

#include <vector>
#include <utility>

#include "Renderer.hpp" 
#include "Types.hpp"
#include "Structs.hpp"

// forward declaration 
// why? I cant include 'SnakeGrid.hpp' as it includes 'Snake.hpp' 
// and compilers DONT like that
// ie i need to use a forward declaration;
class SnakeGrid;

class Snake {
public:
    Color color;
    Snake();
    void Init(Renderer *renderer, uint length, int head_x, int head_y, uint rectWidth);
    void Draw() const;
    void Grow(SnakeGrid *grid);
    void Shrink();
    bool IsDead();
    ~Snake();
private:
    Renderer *m_renderer;
    std::vector<Point> m_snake;
    uint m_length;
    uint m_rectWidth;
};