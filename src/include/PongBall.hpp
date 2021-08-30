#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "PongPlayers.hpp"

#define PONG_BALL_RADIUS 15
#define PONG_BALL_VELOCITY 10
#define PONG_BALL_FRICTION 0.9f

class PongBall {
public:

	void Init(Window *window);
	int Update(PongPlayers *players);
	
	void CenterAndAddRandomVelocity();
	void Center();
	void Draw(Renderer *renderer);

private:

	Window *m_window;
	float m_x, m_y ; // center of sphere
	float m_dx, m_dy;
	float m_radius;
};