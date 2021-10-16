#pragma once

#include "Window.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "Timer.hpp"
#include "GUIImage.hpp"

#define ASTEROID_PLAYER_COLOR Color(255, 255, 255)
#define ASTEROID_PLAYER_DRAG 0.9f
#define ASTEROID_PLAYER_ANGLE_DRAG 0.9f
#define ASTEROID_PLAYER_VELOCITY 10.0f
class AsteroidPlayer {
public:
	void Init(Renderer *renderer, Window *window);
	void Update(InputHandler *input, float deltaTime);
	void Draw(Renderer *renderer);
private:
	Window *m_window;
	GUIImage m_playerImg;
	float m_angle, m_dangle;
	float m_dy;
	bool m_isAlive;
};