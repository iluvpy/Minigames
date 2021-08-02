#include "Snake.hpp"
#include "SnakeGrid.hpp"

Snake::Snake() 
: color(SNAKE_COLOR),
  m_direction(Direction2d::up),
  m_isAlive(true)
{

}

void Snake::Init(Renderer *renderer, uint length, int head_x, int head_y, uint rectWidth) {
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
    if (m_snake.size() > 0) 
        m_snake.pop_back();
    else
        m_isAlive = false;
}


void Snake::AddSnakeToGrid(SnakeGrid *grid) {
    for (const auto& position : m_snake) {
        if (!grid->Set(position.y/m_rectWidth-1, position.x/m_rectWidth-1, SnakeRectState::SnakeSection)) {
            m_isAlive = false;
            break;
        }   
    }
}

void Snake::Move() {
    switch (m_direction)
    {
        case Direction2d::up:

            break;

        case Direction2d::down:

            break;
        
        case Direction2d::left:

            break;
        
        case Direction2d::right:

            break;

        default:
            break;
    }
}

bool Snake::IsAlive() const{
    return m_isAlive;
}

Snake::~Snake() {

}