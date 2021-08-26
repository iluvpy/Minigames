#include "Snake.hpp"
#include "SnakeGame.hpp"


Snake::Snake() 
: m_direction(Direction2d::up),
  m_isAlive(true)
{
    m_lastMovementUpdate = Util::GetClock();
}

void Snake::Init(Renderer *renderer, InputHandler *kbHandler, uint length, int head_x, int head_y) {
    m_renderer = renderer;
    m_input = kbHandler;
    m_length = length;
    for (int i = 0; i < length; i++) {
        m_snakePositions.push_back(Point{head_x, head_y+i});
    }
}

void Snake::Grow(SnakeGame *game) {
    Point last = m_snakePositions[m_snakePositions.size()-1];
    Point new_;

    if (game->Get(last.x+1, last.y) == SnakeRectState::SnakeSection) {
        new_ = Point{last.x-1, last.y};
    }
    else if (game->Get(last.x-1, last.y) == SnakeRectState::SnakeSection) {
        new_ = Point{last.x+1, last.y};
    }
    else if (game->Get(last.x, last.y+1) == SnakeRectState::SnakeSection) {
        new_ = Point{last.x, last.y-1};
    }
    else if (game->Get(last.x, last.y-1) == SnakeRectState::SnakeSection) {
        new_ = Point{last.x, last.y+1};
    }

    m_snakePositions.push_back(new_);

}

// Why do i need this again? // XXX: ?
void Snake::Shrink() {
    if (m_snakePositions.size() > 1) 
        m_snakePositions.pop_back();
    else
        m_isAlive = false;
}


void Snake::AddSnakeToGame(SnakeGame *game) {
    Point head = m_snakePositions[0];
    if (!game->Set(head.x, head.y, SnakeRectState::SnakeHead)) {            
        m_isAlive = false;
        return;
    }

    for (int i = 1; i < m_snakePositions.size(); i++) {
        if (!game->Set(m_snakePositions[i].x, m_snakePositions[i].y, SnakeRectState::SnakeSection)) {
            m_isAlive = false;
            break;
        }   
    }
}

void Snake::Update() {

    if (m_input->isPressed(SDLK_w) && m_direction != Direction2d::down) {
        m_direction = Direction2d::up;
    }
    if (m_input->isPressed(SDLK_a) && m_direction != Direction2d::right) {
        m_direction = Direction2d::left;
    }
    if (m_input->isPressed(SDLK_d) && m_direction != Direction2d::left) {
        m_direction = Direction2d::right;
    }
    if (m_input->isPressed(SDLK_s) && m_direction != Direction2d::up) {
        m_direction = Direction2d::down;
    }

    Clock_t now = Util::GetClock();
    if (Util::GetClockDifference(now, m_lastMovementUpdate) >= SNAKE_MOVEMENT_INTERVAL) {
        m_lastMovementUpdate = now;

        Point lastPos = m_snakePositions[0];
        switch (m_direction) {
            case Direction2d::up:
                m_snakePositions[0].y -= 1;
                break;

            case Direction2d::down:
                m_snakePositions[0].y += 1;
                break;
            
            case Direction2d::left:
                m_snakePositions[0].x -= 1;
                break;
                
            case Direction2d::right:
                m_snakePositions[0].x += 1;
                break;

            default:
                break;
        }

        for (int i = 1; i < m_snakePositions.size(); i++) {
            Point copy_pos = m_snakePositions[i];
            if (copy_pos == m_snakePositions[0]) {m_isAlive = false;} // snake is on top of other piece of the snake
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