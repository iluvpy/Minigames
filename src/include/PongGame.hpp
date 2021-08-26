#pragma once

#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "GUIRect.hpp"
#include "PongBall.hpp"

#define PONG_GAME_BACKGROUND_COLOR Color(20, 20, 20)
#define PONG_GAME_TEXT_COLOR Color(255, 255, 255)
#define PONG_GAME_FONT_SIZE 32

class PongGame {
public:

	void Init(Renderer *renderer, Window *window, InputHandler *inputHandler);
	void Update();
	void Draw();

private:
	Renderer *m_renderer;
	Window *m_window;
	InputHandler *m_input;
	GUIRect m_backgroundRect;
	int m_points1, m_points2; // points of player 1 and points of player 2

	PongBall m_ball;
};