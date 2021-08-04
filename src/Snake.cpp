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
        m_snake.push_back(Point{head_x, head_y});
        head_y += rectWidth;
    }
}

void Snake::Grow(SnakeGame *grid) {
    Point last = m_snake[m_snake.size()-1];

    //  here im checking which position the new snake piece can grow to
    // what im checking;
    //    □
    //  ■ □ □
    //    □
    Point p = {static_cast<int>(last.x/m_rectWidth-2), static_cast<int>(last.y/m_rectWidth-1)}; 
    if (grid->Get(p.x, p.y) == SnakeRectState::none) m_snake.push_back(p);
    // im checking;
    //    □
    //  □ □ ■
    //    □
    p.x += 2; 
    if (grid->Get(p.x, p.y) == SnakeRectState::none) m_snake.push_back(p);
    // im checking;
    //    □
    //  □ □ □
    //    ■
    p.x -= 1;
    p.y++; 
    if (grid->Get(p.x, p.y) == SnakeRectState::none) m_snake.push_back(p);
    // im checking;
    //    ■
    //  □ □ □
    //    □
    p.y -= 2; 
    if (grid->Get(p.x, p.y) == SnakeRectState::none) m_snake.push_back(p);

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

        Point lastPos = m_snake[0];
        switch (m_direction) {
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
        
        for (int i = 1; i < m_snake.size(); i++) {
            Point copy_pos = m_snake[i];
            m_snake[i] = lastPos;
            lastPos = copy_pos;
        }
    }
}

bool Snake::IsAlive() const{
    return m_isAlive;
}

Snake::~Snake() {

}