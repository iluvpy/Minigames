#include "AsteroidPlayer.hpp"


void AsteroidPlayer::Init(Renderer *renderer, Window *window) {
	m_window = window;
	m_isAlive = true;
	m_angle = 0.0f;
	m_playerImg.Init(renderer, 0, 0, "./res/img/arrow.png");
	m_playerImg.SetX(m_window->GetWidth() / 2 - m_playerImg.GetWidth() / 2);
	m_playerImg.SetY(m_window->GetHeight() / 2 - m_playerImg.GetHeight() / 2);
}

void AsteroidPlayer::Update(Timer *timer) {
	m_angle += timer->GetDeltaTime()*100.0f;
}

void AsteroidPlayer::Draw(Renderer *renderer) {
	m_playerImg.AngleDraw(m_angle);
}
