#include "AsteroidGame.hpp"

void AsteroidGame::Init(Renderer *renderer, Window *window, InputHandler *input) {
	m_renderer = renderer;
	m_window = window;
	m_input = input;

	m_backgroundRect.Init(0, 0, m_window->GetWidth(), m_window->GetHeight(), ASTEROID_BACKGROUND_COLOR);
	m_player.Init(m_renderer, m_window);
}

void AsteroidGame::Draw() {
	m_backgroundRect.Draw(m_renderer);
	m_player.Draw(m_renderer);
}

void AsteroidGame::Update(float deltaTime) {
	m_player.Update(m_input, deltaTime);
}
