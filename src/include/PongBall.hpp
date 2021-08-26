#pragma once

#include "Renderer.hpp"
#include "Window.hpp"

#define PONG_BALL_RADIUS 15

class PongBall {
public:

	void Init(Window *window);
	void Update();
	void Draw(Renderer *renderer);

private:
	Window *m_window;
	int m_x, m_y ; // center of sphere
	int m_radius;
};