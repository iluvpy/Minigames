#include "TictactoeGame.hpp"

void TictactoeGame::Init(Renderer *renderer, Window *window, InputHandler *input) {
	m_renderer = renderer;
	m_window = window;
	m_input = input;
	m_turn = false;
	m_game_started = false;
	// position button on the left, 100px away from window border and 50px away from top
	m_turnXButton.Init(100, 50, TurnButton::X, m_renderer, TIC_TAC_TOE_BACKGROUND_COLOR);
	// position button on the right,100px away from window border and 50px away from top
	m_turnOButton.Init(m_window->GetWidth()-100-TTTT_BUTTON_NORMAL_WIDTH, 50, TurnButton::CIRLCE, m_renderer, TIC_TAC_TOE_BACKGROUND_COLOR);
	m_backgroundRect.Init(0, 0, m_window->GetWidth(), m_window->GetHeight(), TIC_TAC_TOE_BACKGROUND_COLOR);
	m_board.Init(m_window, m_renderer);
	
}

void TictactoeGame::Draw() {
	m_backgroundRect.Draw(m_renderer);
	m_board.Draw(m_renderer);
	m_turnOButton.Draw();
	m_turnXButton.Draw();
	if (!m_game_started) {
		Rect rect = m_renderer->GetTextRect("Choose Player");
		// draw text that is centered on x axis and 100px away from top
		m_renderer->DrawText(Point{(int)(m_window->GetWidth() / 2 - rect.w / 2), 100}, "Choose Player", 28, Color());
	}
}

void TictactoeGame::Update(float deltaTime) {

	if (!m_game_started) {
		m_turnOButton.Update(m_input);
		m_turnXButton.Update(m_input);
		if (m_turnOButton.IsFocused() || m_turnXButton.IsFocused()) {
			m_game_started = true;
		}
	}
	else {
		m_board.Update(m_input);
	}
}
