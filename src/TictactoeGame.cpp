#include "TictactoeGame.hpp"

void TictactoeGame::Init(Renderer *renderer, Window *window, InputHandler *input) {
	m_renderer = renderer;
	m_window = window;
	m_input = input;
	m_turn = false;
	m_game_started = false;
	// position button on the left, 100px away from window border and 50px away from top
	m_turnX.Init(100, 50, TurnButton::X, m_renderer, TIC_TAC_TOE_BACKGROUND_COLOR);
	// position button on the right,100px away from window border and 50px away from top
	m_turnO.Init(m_window->GetWidth()-100-TTTT_BUTTON_NORMAL_WIDTH, 50, TurnButton::CIRLCE, m_renderer, TIC_TAC_TOE_BACKGROUND_COLOR);
	m_backgroundRect.Init(0, 0, m_window->GetWidth(), m_window->GetHeight(), TIC_TAC_TOE_BACKGROUND_COLOR);
	m_board.Init(m_window);
	
}

void TictactoeGame::Draw() {
	m_backgroundRect.Draw(m_renderer);
	m_board.Draw(m_renderer);
	m_turnO.Draw();
	m_turnX.Draw();
	if (!m_game_started) {
		Rect rect = m_renderer->GetTextRect("Choose Player");
		// draw text that is centered on x axis and 100px away from top
		m_renderer->DrawText(Point{(int)(m_window->GetWidth() / 2 - rect.w / 2), 100}, "Choose Player", 28, Color());
	}
}

void TictactoeGame::Update(float deltaTime) {
	m_board.Update();
	m_turnO.Update(m_input);
	m_turnX.Update(m_input);
}
