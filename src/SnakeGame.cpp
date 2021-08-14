#include "SnakeGame.hpp"
#include "SnakeFood.hpp"

#define FOOD_INTERVAL 5.0f



void SnakeGame::Init(Renderer *renderer, Window *window, InputHandler *kbHandler, int rectWidth) {
    m_renderer = renderer;
    m_rectWidth = rectWidth;
    m_input = kbHandler;
    SDL_Rect r = window->GetWindowRect();
    m_windowW = r.w;
    m_windowH = r.h;

    for (int iy = 0; iy < m_windowH; iy += m_rectWidth) {
        std::vector<SnakeGridRect> tmp;
        for (int ix = 0; ix < m_windowW; ix += m_rectWidth) {
            SnakeGridRect rect {ix, iy, m_rectWidth, SnakeRectState::None};
            tmp.push_back(rect);
        }
        m_grid.push_back(tmp);
    }

    int approx_middleX = (int)GetIndexWidth()/2; // index x
    int approx_middleY = (int)GetIndexHeight()/2; // index y

    m_snake.Init(m_renderer, m_input, 10, approx_middleX, approx_middleY);

    m_deathMessage.Init(Color(30, 200, 30), window);
}


void SnakeGame::Draw() {
    ClearGrid();
    m_food.AddFoodToGame(this);
    m_snake.AddSnakeToGame(this);
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

    if (!m_snake.IsAlive()) m_deathMessage.Draw(m_renderer);

}

// adds apple to random square on grid every m_interval 
void SnakeGame::GenApple() {
    Clock_t now = Util::GetClock();
    if (Util::GetClockDifference(now, m_lastFoodUpdate) >= FOOD_INTERVAL) {
        m_lastFoodUpdate = now;
        m_food.AddNewRandomFood(this);
    }
}

void SnakeGame::Update() {
    if (m_snake.IsAlive()) {
        m_snake.Update();

        if (m_food.FoodWasEaten(this)) {
            m_snake.Grow(this);
        }
        GenApple();
    }
}

int SnakeGame::GetIndexHeight() const {
    return m_grid.size();
}

int SnakeGame::GetIndexWidth() const {
    return m_grid[0].size();
}

int SnakeGame::GetRectWidth() const  {
    return m_rectWidth;
}

int SnakeGame::XtoXIndex(int x) {
    return (x/m_rectWidth-1);
}

int SnakeGame::YtoYIndex(int y) {
    return (y/m_rectWidth-1);
}


bool SnakeGame::Set(int x_index, int y_index, const SnakeRectState& state) {
    if (PosExists(x_index, y_index)) {
        m_grid[y_index][x_index].state = state;
        return true;
    }
    return false;
}

SnakeRectState SnakeGame::Get(int x_index, int y_index) {
    if (PosExists(x_index, y_index)) {
        return m_grid[y_index][x_index].state;
    }
    return SnakeRectState::None;
}

bool SnakeGame::PosExists(int x_index, int y_index) {
    return x_index >= 0 &&
           y_index >= 0 &&
           y_index < GetIndexHeight() &&
           x_index < GetIndexWidth();
}

void SnakeGame::ClearGrid() {
    for (auto& rects : m_grid) {
        for (auto& rect : rects) {
            rect.state = SnakeRectState::None;
        }
    }
}

