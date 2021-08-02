#include "SnakeGrid.hpp"

SnakeGrid::SnakeGrid(Renderer *renderer, Window *window, int x, int y, int rectWidth) 
: m_renderer(renderer),
  m_rectWidth(rectWidth)
{
    SDL_Rect r = window->getWindowRect();
    m_windowW = r.w;
    m_windowH = r.h;

    for (int iy = x; iy < m_windowH; iy += m_rectWidth) {
        std::vector<SnakeGridRect> tmp;
        for (int ix = y; ix < m_windowW; ix += m_rectWidth) {
            SnakeGridRect rect {ix, iy, m_rectWidth, SnakeRectState::none};
            tmp.push_back(rect);
        }
        m_grid.push_back(tmp);
    }

    int approx_middleX = (int)m_rectWidth*m_grid[0].size()/2; // index x
    int approx_middleY = (int)m_rectWidth*m_grid.size()/2; // index y
    m_snake.Init(m_renderer, 5, approx_middleX, approx_middleY-m_rectWidth/2, m_rectWidth);
}


void SnakeGrid::Draw() {

    m_snake.AddSnakeToGrid(this);

    for (const auto& rectLayer : m_grid) {
        for (const auto& rect : rectLayer) {
            m_renderer->DrawRect(rect.x, rect.y, rect.w, rect.w, Util::GetSnakeGridRectColor(rect));
        }
    }

    // draw grid
    for (int yi = 0; yi < m_windowH; yi += m_rectWidth) {
        m_renderer->DrawRect(0, yi, m_windowW, -1, Color(0, 0, 0));
    }

    for (int xi = 0; xi < m_windowW; xi += m_rectWidth) {
        m_renderer->DrawRect(xi, 0, -1, m_windowH, Color(0, 0, 0));
    }

}

// adds apple to random square on grid every m_interval XXX add m_interval
void SnakeGrid::GenApple() {

}

void SnakeGrid::Update() {
    m_snake.Move();
    GenApple();
}

int SnakeGrid::GetWidth() const {
    return m_grid.size();
}

int SnakeGrid::GetHeight() const {
    return m_grid[0].size();
}

bool SnakeGrid::Set(int x, int y, const SnakeRectState& state) {
    if (x >= 0 &&
        y >= 0 &&
        x < GetWidth() &&
        y < GetHeight()) {
            m_grid[x][y].state = state;
            return true;
    }
    return false;
}


SnakeGrid::~SnakeGrid() {
}