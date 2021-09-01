#include "AsteroidPlayer.hpp"


void AsteroidPlayer::Init(Renderer *renderer, Window *window) {
	m_window = window;
	m_isAlive = true;
	m_angle = 0.0f;
	m_dangle = 0.0f;
	m_dx = 0.0f;
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

	m_dx *= ASTEROID_PLAYER_DRAG;
	m_dy *= ASTEROID_PLAYER_DRAG;
	m_dangle *= ASTEROID_PLAYER_ANGLE_DRAG;
	m_angle += m_dangle;

	float x = m_playerImg.GetX() + m_dx + ASTEROID_PLAYER_VELOCITY * deltaTime;
	float y = m_playerImg.GetY() + m_dy + ASTEROID_PLAYER_VELOCITY * deltaTime;
	FPoint p = Util::Rotate(FPoint{x, y}, FPoint{m_playerImg.GetX(), m_playerImg.GetY()}, Util::toRad(m_angle)); 

	m_playerImg.SetX(p.x);
	m_playerImg.SetY(p.y);

}

void AsteroidPlayer::Draw(Renderer *renderer) {
	m_playerImg.AngleDraw(m_angle);
}
