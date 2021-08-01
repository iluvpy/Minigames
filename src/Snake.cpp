#include "Snake.hpp"
#include "SnakeGrid.hpp"
Snake::Snake() 
: color(Color(0, 230, 80))
{

}

void Snake::Init(Renderer *renderer, uint length, int head_x, int head_y, uint rectWidth) 

{
    m_renderer = renderer;
    m_length = length;
    m_rectWidth = rectWidth;
    for (int i = 0; i < length; i++) {
        m_snake.push_back(Point{head_x, head_y});
        head_y += rectWidth;
    }
}

void Snake::Grow(SnakeGrid *grid) {
    
}

void Snake::Shrink() {
    m_snake.pop_back();
}

void Snake::Draw() const{
    for (const auto& position : m_snake) {
        m_renderer->DrawRect(position.x, position.y, m_rectWidth, m_rectWidth, Color(50, 200, 80));
    }
}

bool Snake::IsDead() {
    return m_length == 0;
}

Snake::~Snake() {
    m_snake.clear();
}