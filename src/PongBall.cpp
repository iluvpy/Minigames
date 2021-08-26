#include "PongBall.hpp"


void PongBall::Init(Window *window) {
	m_window = window;
	m_radius = PONG_BALL_RADIUS;
	m_x = m_window->GetWidth() / 2 - m_radius;
	m_y = m_window->GetHeight() / 2 - m_radius;

	m_dx = PONG_BALL_VELOCITY; 
	m_dy = PONG_BALL_VELOCITY;
}

void PongBall::Update() {
	if (m_y + m_dy > m_window->GetHeight() || m_y + m_dy <= 0) {
		m_dy = -m_dy;
	}
	if (m_x + m_dx > m_window->GetWidth() || m_x + m_dx <= 0) {
		m_dx = -m_dx;
	}
	m_y += m_dy;
	m_x += m_dx;
}

void PongBall::Draw(Renderer *renderer) {
	renderer->DrawCircle(m_x, m_y, m_radius, Color(255, 255, 255));
}
