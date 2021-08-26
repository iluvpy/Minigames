#include "PongBall.hpp"


void PongBall::Init(Window *window) {
	m_window = window;
	m_x = 500;
	m_y = 500;
	m_radius = PONG_BALL_RADIUS;
}

void PongBall::Update() {

}

void PongBall::Draw(Renderer *renderer) {
	renderer->DrawCircle(m_x, m_y, m_radius, Color(255, 255, 255));
}
