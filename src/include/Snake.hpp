#pragma once

#include <vector>
#include <utility>

#include "Renderer.hpp" 
#include "Types.hpp"

class Snake {
public:
    Snake();
    Snake(uint length, int head_x, int head_y);
    void Init(uint length, int head_x, int head_y);
    void Draw(Renderer *renderer, uint rectWidth);
    void Grow();
    void Shrink();

    ~Snake();
private:

    std::vector<std::pair<int, int>> m_snake;
    uint m_length;
};