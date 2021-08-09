#pragma once

#include <vector>
#include <utility>

#include "Renderer.hpp" 
#include "Types.hpp"
#include "Structs.hpp"
#include "InputHandler.hpp"

#define SNAKE_COLOR Color(0, 230, 80)
#define SNAKE_MOVEMENT_INTERVAL 0.3f // snake moves 1 tile each INTERVAL seconds
// forward declaration 
class SnakeGame;


class Snake {
public:
    Color color;
    Snake();
    void Init(Renderer *renderer, InputHandler *kbHandler, uint length, int head_x, int head_y, uint rectWidth);
    void Draw() const;
    void Grow(SnakeGame *game);
    void AddSnakeToGame(SnakeGame *game);
    void Shrink();
    void Update();
    bool IsAlive() const;
    ~Snake();
private:
    Renderer *m_renderer;
    InputHandler *m_input;
    std::vector<Point> m_snakePositions;
    Direction2d m_direction;
    Clock_t m_lastMovementUpdate;
    uint m_length;
    uint m_rectWidth;
    bool m_isAlive;
};