#include "PongGame.hpp"

void PongGame::Init(Renderer *renderer, Window *window,InputHandler *inputHandler)  {
	m_renderer = renderer;
	m_window = window;
	m_input = inputHandler;
	m_points1 = 0;
	m_points2 = 0;

	m_backgroundRect.Init(0, 0, window->GetWidth(), window->GetHeight(), PONG_GAME_BACKGROUND_COLOR);
	m_ball.Init(m_window);
}

void PongGame::Update()  {
	m_ball.Update();
}

void PongGame::Draw()  {
	m_backgroundRect.Draw(m_renderer);
	m_ball.Draw(m_renderer);
}
