#include "PongGame.hpp"

void PongGame::Init(Renderer *renderer, Window *window,InputHandler *inputHandler)  {
	m_renderer = renderer;
	m_window = window;
	m_input = inputHandler;
	m_points1 = 0;
	m_points2 = 0;

	Rect r = m_renderer->GetTextRect("0|0", PONG_GAME_FONT_SIZE);
	m_pointsCounterSize.x = r.w;
	m_pointsCounterSize.y = r.h;

	m_backgroundRect.Init(0, 0, m_window->GetWidth(), m_window->GetHeight(), PONG_GAME_BACKGROUND_COLOR);
	m_ball.Init(m_window);
	m_players.Init(m_window);
}

void PongGame::Update()  {
	int result = m_ball.Update(&m_players);
	if (result) {
		if (result == 1)
			m_points1++;
		else
			m_points2++;
		m_ball.CenterAndAddRandomVelocity();
	}
	m_players.Update(m_input);
}

void PongGame::Draw()  {
	m_backgroundRect.Draw(m_renderer);
	m_ball.Draw(m_renderer);
	m_players.Draw(m_renderer);

	std::string points = std::to_string(m_points1) + "|" + std::to_string(m_points2);
	int center_x = m_window->GetWidth() / 2 - m_pointsCounterSize.x / 2;
	m_renderer->DrawText(center_x, 60, points, PONG_GAME_FONT_SIZE, PONG_GAME_TEXT_COLOR);
}
