#include "Snake.hpp"
#include "SnakeGame.hpp"


Snake::Snake() 
: color(SNAKE_COLOR),
  m_direction(Direction2d::up),
  m_isAlive(true)
{
    m_lastUpdate = Util::GetClock();
}

void Snake::Init(Renderer *renderer, KeyboardHandler *kbHandler, uint length, int head_x, int head_y, uint rectWidth) {
    m_renderer = renderer;
    m_keyboard = kbHandler;
    m_length = length;
    m_rectWidth = rectWidth;
    for (int i = 0; i < length; i++) {
        m_snake.push_back(Point{head_x, head_y});
        head_y += rectWidth;
    }
}

void Snake::Grow(SnakeGame *grid) {
    
}

void Snake::Shrink() {
    if (m_snake.size() > 0) 
        m_snake.pop_back();
    else
        m_isAlive = false;
}


void Snake::AddSnakeToGrid(SnakeGame *game) {
    for (const auto& position : m_snake) {
        if (!game->Set(position.y/m_rectWidth-1, position.x/m_rectWidth-1, SnakeRectState::SnakeSection)) {
            m_isAlive = false;
            break;
        }   
    }
}

void Snake::Update() {

    if (m_keyboard->isPressed(SDLK_w)) {
        m_direction = Direction2d::up;
    }
    if (m_keyboard->isPressed(SDLK_s)) {
        m_direction = Direction2d::down;
    }
    if (m_keyboard->isPressed(SDLK_a)) {
        m_direction = Direction2d::left;
    }
    if (m_keyboard->isPressed(SDLK_d)) {
        m_direction = Direction2d::right;
    }
    Clock_t now = Util::GetClock();
    float diff = Util::GetClockDifference(now, m_lastUpdate);
    std::cout << "diff: " << diff << std::endl; 
    if (diff >= 0.5f) {
        m_lastUpdate = now;

        switch (m_direction)
        {
            case Direction2d::up:
                m_snake[0].y -= m_rectWidth;
                break;

            case Direction2d::down:
                m_snake[0].y += m_rectWidth;
                break;
            
            case Direction2d::left:
                m_snake[0].x -= m_rectWidth;
                break;
            
            case Direction2d::right:
                m_snake[0].x += m_rectWidth;
                break;

            default:
                break;
        }
    }
}

bool Snake::IsAlive() const{
    return m_isAlive;
}

Snake::~Snake() {

}