#include "SnakeGame.hpp"
#include "SnakeFood.hpp"
#include "Snake.hpp"

#define FOOD_INTERVAL 3.5f // in seconds


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
            SnakeGridRect rect {ix, iy, m_rectWidth, SnakeRectState::Grid};
            tmp.push_back(rect);
        }
        m_grid.push_back(tmp);
    }

    int approx_middleX = (int)GetIndexWidth()/2; // index x
    int approx_middleY = (int)GetIndexHeight()/2; // index y

    m_snake.Init(m_renderer, m_input, 4, approx_middleX, approx_middleY);

    m_deathMessage.Init(m_renderer, Color(30, 200, 30), window);
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

    if (!m_snake.IsAlive()) m_deathMessage.Draw();

}

void SnakeGame::Update() {
    if (m_snake.IsAlive()) {
        m_snake.Update();

        if (m_food.NewFoodIfEaten(this)) {
            m_snake.Grow(this);
        }
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
		// if grid is on screen ()
		if (1)
		{
			m_grid[y_index][x_index].state = state;
        	return true;
		}
    }
    return false;
}

SnakeRectState SnakeGame::Get(int x_index, int y_index) {
    if (PosExists(x_index, y_index)) {
        return m_grid[y_index][x_index].state;
    }
    return SnakeRectState::Grid;
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
            rect.state = SnakeRectState::Grid;
        }
    }
}

