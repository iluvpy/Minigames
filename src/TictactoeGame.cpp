#include "TictactoeGame.hpp"

void TictactoeGame::Init(Renderer *renderer, Window *window, InputHandler *input) {
	m_renderer = renderer;
	m_window = window;
	m_input = input;

	m_backgroundRect.Init(0, 0, m_window->GetWidth(), m_window->GetHeight(), TIC_TAC_TOE_BACKGROUND_COLOR);
	m_board.Init(m_window);

}

void TictactoeGame::Draw() {
	m_backgroundRect.Draw(m_renderer);
	m_board.Draw(m_renderer);
}

void TictactoeGame::Update(float deltaTime) {
	m_board.Update();
}
