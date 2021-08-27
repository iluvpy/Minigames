#include "PongPlayers.hpp"

void PongPlayers::Init(Window *window) {
	int w = window->GetWidth() * PONG_PLAYERS_WIDTH;
	int h = window->GetHeight() * PONG_PLAYERS_HEIGHT;

	int middle_y = window->GetHeight() / 2 - h / 2;
	m_player1Rect.Init(window->GetWidth() * PONG_PLAYERS_X, middle_y, w, h);
	m_player2Rect.Init(window->GetWidth() - window->GetWidth() * PONG_PLAYERS_X, middle_y, w, h);
}

void PongPlayers::Update(InputHandler *input) {

}

void PongPlayers::Draw(Renderer *renderer) {
	m_player1Rect.Draw(renderer);
	m_player2Rect.Draw(renderer);
}


Rect PongPlayers::GetLeftRect()  {
	return m_player1Rect.GetRect();
}

Rect PongPlayers::GetRightRect()  {
	return m_player2Rect.GetRect();
}

