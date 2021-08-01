#include "Snake.hpp"

Snake::Snake() {
    Init(0, 0, 0);
}

Snake::Snake(uint length, int head_x, int head_y) {
    Init(length, head_x, head_y);
}

void Snake::Init(uint length, int head_x, int head_y) {
    m_length = length;
    
}

void Snake::Grow() {

}

void Snake::Shrink() {

}

Snake::~Snake() {
    
}