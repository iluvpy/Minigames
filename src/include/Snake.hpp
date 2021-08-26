#pragma once

#include <vector>
#include <utility>

#include "Renderer.hpp" 
#include "Types.hpp"
#include "Structs.hpp"
#include "InputHandler.hpp"

#define SNAKE_COLOR Color(0, 180, 40)
#define SNAKE_MOVEMENT_INTERVAL 0.25f // snake moves 1 tile each INTERVAL seconds
#define SNAKE_HEAD_COLOR Color(0, 250, 40)
// forward declaration 
class SnakeGame;


class Snake {
public:
    Snake();
    void Init(Renderer *renderer, InputHandler *kbHandler, uint length, int head_x, int head_y);
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
    bool m_isAlive;
};