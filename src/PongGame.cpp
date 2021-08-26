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

}

void PongGame::Draw()  {
	m_backgroundRect.Draw(m_renderer);
	m_renderer->DrawText(100, 100, "hello Pong :p", PONG_GAME_FONT_SIZE, PONG_GAME_TEXT_COLOR);
	m_ball.Draw(m_renderer);
}
