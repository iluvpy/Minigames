#pragma once

#include "Window.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "Timer.hpp"
#include "GUIRect.hpp"
#include "AsteroidPlayer.hpp"

#define ASTEROID_BACKGROUND_COLOR Color(30, 30, 30)

class AsteroidGame {
public:
	void Init(Renderer *renderer, Window *window, InputHandler *input);
	void Draw();
	void Update(float deltaTime);
private:
	Renderer *m_renderer;
	Window *m_window;
	InputHandler *m_input;
	GUIRect m_backgroundRect;
	AsteroidPlayer m_player;
};