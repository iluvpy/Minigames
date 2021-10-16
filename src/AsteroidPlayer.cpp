#include "AsteroidPlayer.hpp"


void AsteroidPlayer::Init(Renderer *renderer, Window *window) {
	m_window = window;
	m_isAlive = true;
	m_angle = 0.0f;
	m_dangle = 0.0f;
	m_dy = 0.0f;
	m_playerImg.Init(renderer, 0, 0, "./res/img/arrow.png");
	m_playerImg.SetX(m_window->GetWidth() / 2 - m_playerImg.GetWidth() / 2);
	m_playerImg.SetY(m_window->GetHeight() / 2 - m_playerImg.GetHeight() / 2);
}

void AsteroidPlayer::Update(InputHandler *input, float deltaTime) {
	if (input->isPressed(SDLK_w)) {
		m_dy--;
	}
	if (input->isPressed(SDLK_s)) {
		m_dy++;
	}

	if (input->isPressed(SDLK_LEFT)) {
		m_dangle -= 0.5f;
	}
	if (input->isPressed(SDLK_RIGHT)) {
		m_dangle += 0.5f;
	}

	m_dy *= ASTEROID_PLAYER_DRAG;
	m_dangle *= ASTEROID_PLAYER_ANGLE_DRAG;
	m_angle += m_dangle;

	if (m_dy > 0.01f || m_dy < -0.01f) {
		float x = m_playerImg.GetX() + ASTEROID_PLAYER_VELOCITY * deltaTime;
		float y = m_playerImg.GetY() + m_dy + ASTEROID_PLAYER_VELOCITY * deltaTime;
		FPoint p = Util::Rotate(FPoint{x, y}, FPoint{m_playerImg.GetX(), m_playerImg.GetY()}, Util::toRad(m_angle)); 

		int win_w = m_window->GetWidth();
		int win_h = m_window->GetHeight();
		float distance_to_screen = 1.0f;
		if (p.x > win_w)
			m_playerImg.SetX(distance_to_screen);
		else if (p.x < 0.0f)
			m_playerImg.SetX(win_w - distance_to_screen);
		else 
			m_playerImg.SetX(p.x);
		if (p.y > win_h)
			m_playerImg.SetY(distance_to_screen);
		else if (p.y < 0.0f)
			m_playerImg.SetY(win_h - distance_to_screen);
		else 
			m_playerImg.SetY(p.y);

	}
	
	// so that m_angle doesnt grow too large
	if (m_angle > 360.0f) m_angle = 0.0f;
	else if (m_angle <= 0.0f) m_angle = 360.0f;

}

void AsteroidPlayer::Draw(Renderer *renderer) {
	m_playerImg.AngleDraw(m_angle);
}
