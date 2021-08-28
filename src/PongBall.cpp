#include "PongBall.hpp"


void PongBall::Init(Window *window) {
	m_window = window;
	m_radius = PONG_BALL_RADIUS;

	CenterAndAddRandomVelocity();

}

void PongBall::CenterAndAddRandomVelocity() {
	Center();

	m_dx = Util::GetRandomInt(1, 0) ? PONG_BALL_VELOCITY : -PONG_BALL_VELOCITY; 
	m_dy = Util::GetRandomInt(PONG_BALL_VELOCITY, -PONG_BALL_VELOCITY);
}

void PongBall::Center() {
	m_x = m_window->GetWidth() / 2 - m_radius;
	m_y = m_window->GetHeight() / 2 - m_radius;
}

int PongBall::Update(PongPlayers *players) {

	FRect left = players->GetLeftRect();
	FRect right = players->GetRightRect();
	
	float ydy = m_y + m_dy;
	float xdx = m_x + m_dx;

	if (ydy > m_window->GetHeight() || ydy <= 0 ) 
		m_dy = -m_dy;

	bool touching_right = ydy >= right.y && ydy <= right.y + right.h;
	bool touching_left = ydy >= left.y && ydy <= left.y + left.h;
	bool at_right = xdx > right.x;
	bool at_left = xdx < left.x + left.w;
	
	if (at_left) {
		if (touching_left) {
			m_dx = -m_dx;
			m_dy += players->GetLeftVelocity() / 2;
		}
		else 
			return PONG_PLAYER2; // player 2 gets point
	}

	else if (at_right) {
		if (touching_right) {
			m_dx = -m_dx;
			m_dy += players->GetRightVelocity() / 2;
		}
		else
			return PONG_PLAYER1; // player 1 gets point
	}

	m_y += m_dy;
	m_x += m_dx;

	return 0; // no player got any points
}



void PongBall::Draw(Renderer *renderer) {
	renderer->DrawCircle(m_x, m_y, m_radius, Color(255, 255, 255));
}
