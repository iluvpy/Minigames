#include "AsteroidGame.hpp"

void AsteroidGame::Init(Renderer *renderer, Window *window, InputHandler *input) {
	m_renderer = renderer;
	m_window = window;
	m_input = input;

	m_backgroundRect.Init(0, 0, m_window->GetWidth(), m_window->GetHeight(), ASTEROID_BACKGROUND_COLOR);

}

void AsteroidGame::Draw() {
	m_backgroundRect.Draw(m_renderer);
	m_renderer->DrawText(10, 10, "hello asteroids", 50, Color());
}

void AsteroidGame::Update(Timer *timer) {

}
