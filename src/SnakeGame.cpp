#include "SnakeGame.hpp"

SnakeGame::SnakeGame() {

}

void SnakeGame::Init(Renderer *renderer, Window *window, InputHandler *kbHandler, int x, int y, int rectWidth) {
    m_renderer = renderer;
    m_rectWidth = rectWidth;
    m_input = kbHandler;
    SDL_Rect r = window->getWindowRect();
    m_windowW = r.w;
    m_windowH = r.h;

    for (int iy = x; iy < m_windowH; iy += m_rectWidth) {
        std::vector<SnakeGridRect> tmp;
        for (int ix = y; ix < m_windowW; ix += m_rectWidth) {
            SnakeGridRect rect {ix, iy, m_rectWidth, SnakeRectState::None};
            tmp.push_back(rect);
        }
        m_grid.push_back(tmp);
    }

    int approx_middleX = (int)m_rectWidth*m_grid[0].size()/2; // index x
    int approx_middleY = (int)m_rectWidth*m_grid.size()/2; // index y

    m_snake.Init(m_renderer, m_input, 10, approx_middleX, approx_middleY-m_rectWidth/2, m_rectWidth);
}


void SnakeGame::Draw() {
    ClearGrid();
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

// adds apple to random square on grid every m_interval 
// XXX add m_interval
void SnakeGame::GenApple() {

}

void SnakeGame::Update() {
    if (m_input->isMouseButtonPressed(SDL_BUTTON_LEFT)) {
        m_snake.Grow(this);
    }
    if (m_input->isMouseButtonPressed(SDL_BUTTON_RIGHT)) {
        m_snake.Shrink();
    }
    m_snake.Update();
    GenApple();
}

int SnakeGame::GetWidth() const {
    return m_grid.size();
}

int SnakeGame::GetHeight() const {
    return m_grid[0].size();
}

bool SnakeGame::Set(int x_index, int y_index, const SnakeRectState& state) {
    if (x_index >= 0 &&
        y_index >= 0 &&
        x_index < GetWidth() &&
        y_index < GetHeight()) {
            m_grid[y_index][x_index].state = state;
            return true;
    }
    return false;
}

SnakeRectState SnakeGame::Get(int x_index, int y_index) {
    if (x_index >= 0 &&
        y_index >= 0 &&
        x_index < GetWidth() &&
        y_index < GetHeight()) {
        return m_grid[y_index][x_index].state;
    }
    return SnakeRectState::None;
}

void SnakeGame::ClearGrid() {
    for (auto& rects : m_grid) {
        for (auto& rect : rects) {
            rect.state = SnakeRectState::None;
        }
    }
}


SnakeGame::~SnakeGame() {
}