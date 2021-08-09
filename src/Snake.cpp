#include "Snake.hpp"
#include "SnakeGame.hpp"


Snake::Snake() 
: color(SNAKE_COLOR),
  m_direction(Direction2d::up),
  m_isAlive(true)
{
    m_lastMovementUpdate = Util::GetClock();
}

void Snake::Init(Renderer *renderer, InputHandler *kbHandler, uint length, int head_x, int head_y, uint rectWidth) {
    m_renderer = renderer;
    m_input = kbHandler;
    m_length = length;
    m_rectWidth = rectWidth;
    for (int i = 0; i < length; i++) {
        m_snakePositions.push_back(Point{head_x, head_y});
        head_y += rectWidth;
    }
}

void Snake::Grow(SnakeGame *game) {
    Point last = m_snakePositions[m_snakePositions.size()-1];
    last.y += m_rectWidth;
    m_snakePositions.emplace_back(last);
}

void Snake::Shrink() {
    if (m_snakePositions.size() > 1) 
        m_snakePositions.pop_back();
    else
        m_isAlive = false;
}


void Snake::AddSnakeToGame(SnakeGame *game) {
    for (auto& position : m_snakePositions) {
        if (!game->Set(position.x/m_rectWidth-1, position.y/m_rectWidth-1, SnakeRectState::SnakeSection)) {
            m_isAlive = false;
            break;
        }   
    }
}

void Snake::Update() {

    if (m_input->isPressed(SDLK_w)) {
        m_direction = Direction2d::up;
    }
    if (m_input->isPressed(SDLK_s)) {
        m_direction = Direction2d::down;
    }
    if (m_input->isPressed(SDLK_a)) {
        m_direction = Direction2d::left;
    }
    if (m_input->isPressed(SDLK_d)) {
        m_direction = Direction2d::right;
    }

    Clock_t now = Util::GetClock();
    if (Util::GetClockDifference(now, m_lastMovementUpdate) >= SNAKE_MOVEMENT_INTERVAL) {
        m_lastMovementUpdate = now;

        Point lastPos = m_snakePositions[0];
        switch (m_direction) {
            case Direction2d::up:
                m_snakePositions[0].y -= m_rectWidth;
                break;

            case Direction2d::down:
                m_snakePositions[0].y += m_rectWidth;
                break;
            
            case Direction2d::left:
                m_snakePositions[0].x -= m_rectWidth;
                break;
                
            case Direction2d::right:
                m_snakePositions[0].x += m_rectWidth;
                break;

            default:
                break;
        }
        
        for (int i = 1; i < m_snakePositions.size(); i++) {
            Point copy_pos = m_snakePositions[i];
            m_snakePositions[i] = lastPos;
            lastPos = copy_pos;
        }
    }
}

bool Snake::IsAlive() const{
    return m_isAlive;
}

Snake::~Snake() {

}