#include "PongPlayers.hpp"

void PongPlayers::Init(Window *window) {
	m_window = window;
	int w = m_window->GetWidth() * PONG_PLAYERS_WIDTH;
	int h = m_window->GetHeight() * PONG_PLAYERS_HEIGHT;

	int middle_y = m_window->GetHeight() / 2 - h / 2;
	m_player1Rect.Init(m_window->GetWidth() * PONG_PLAYERS_X, middle_y, w, h);
	m_player2Rect.Init(m_window->GetWidth() - m_window->GetWidth() * PONG_PLAYERS_X, middle_y, w, h);

	m_player1_dy = 0.0f;
	m_player2_dy = 0.0f;
}

void PongPlayers::Update(InputHandler *input, Timer *timer) {
	float deltaTime = timer->GetDeltaTime();
	float speed = PONG_PLAYERS_SPEED * m_window->GetHeight() * deltaTime;
	// handle movement of left player
	if (input->isPressed(SDLK_w)) {
		m_player1_dy -= speed;
	}
	if (input->isPressed(SDLK_s)) {
		m_player1_dy += speed;
	}

	// handle movement of right player
	if (input->isPressed(SDLK_UP)) {
		m_player2_dy -= speed;
	}
	if (input->isPressed(SDLK_DOWN)) {
		m_player2_dy += speed;
	}


	m_player1_dy *= PONG_PLAYERS_DRAG;
	m_player2_dy *= PONG_PLAYERS_DRAG;

	float p1_y = m_player1Rect.GetY() + m_player1_dy;
	float p2_y = m_player2Rect.GetY() + m_player2_dy;
	float h = m_player1Rect.GetH();
	
	if (p1_y >= 0 && p1_y + h <= m_window->GetHeight())
		m_player1Rect.SetY(p1_y);
	if (p2_y >= 0 && p2_y + h <= m_window->GetHeight())
		m_player2Rect.SetY(p2_y);




}	

void PongPlayers::Draw(Renderer *renderer) {
	m_player1Rect.Draw(renderer);
	m_player2Rect.Draw(renderer);
}


FRect PongPlayers::GetLeftRect()  {
	return m_player1Rect.GetRect();
}

FRect PongPlayers::GetRightRect()  {
	return m_player2Rect.GetRect();
}

float PongPlayers::GetLeftVelocity() {
	return m_player1_dy;
}
float PongPlayers::GetRightVelocity() {
	return m_player2_dy;
}
