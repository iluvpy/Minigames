#include "SnakeGrid.hpp"

SnakeGrid::SnakeGrid(Renderer *renderer, Window *window, int x, int y, uint rectWidth) 
: m_renderer(renderer),
  m_startX(x),
  m_startY(y),
  m_rectWidth(rectWidth)
{
    SDL_Rect r = window->getWindowRect();
    m_windowW = r.w;
    m_windowH = r.h;

    for (int iy = m_startY; iy < m_windowH; iy += m_rectWidth) {
        std::vector<SnakeRectState> tmp;
        for (int ix = m_startX; ix < m_windowW; ix += m_rectWidth) {
            tmp.push_back(SnakeRectState::none);
        }
        m_grid.push_back(tmp);
    }

    int approx_middleX = (int)m_rectWidth*m_grid[0].size()/2;
    int approx_middleY = (int)m_rectWidth*m_grid.size()/2;
    m_snake.Init(m_renderer, 5, approx_middleX-1, approx_middleY-m_rectWidth/2, m_rectWidth+2);
}


void SnakeGrid::Draw() const {
    // draw grid
    for (int yi = 0; yi < m_windowH; yi += m_rectWidth) {
        m_renderer->DrawRect(0, yi, m_windowW, -1, Color(0, 0, 0));
    }

    for (int xi = 0; xi < m_windowW; xi += m_rectWidth) {
        m_renderer->DrawRect(xi, 0, -1, m_windowH, Color(0, 0, 0));
    }

    m_snake.Draw();
}
// adds apple to random square on grid
void SnakeGrid::GenApple() {

}

void SnakeGrid::Update() {

}

SnakeGrid::~SnakeGrid() {

}