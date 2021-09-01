#pragma once

#include "Window.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "Timer.hpp"
#include "GUIImage.hpp"

#define ASTEROID_PLAYER_COLOR Color(255, 255, 255)

class AsteroidPlayer {
public:
	void Init(Renderer *renderer, Window *window);
	void Update(Timer *timer);
	void Draw(Renderer *renderer);
private:
	Window *m_window;
	GUIImage m_playerImg;
	float m_angle;
	bool m_isAlive;
};