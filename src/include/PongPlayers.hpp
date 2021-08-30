#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"
#include "Timer.hpp"

#define PONG_PLAYERS_WIDTH 0.01f // % of screen width
#define PONG_PLAYERS_HEIGHT 0.35f // % of screen height
#define PONG_PLAYERS_X 0.05f
#define PONG_PLAYERS_DRAG 0.8f // friction
#define PONG_PLAYER1 1
#define PONG_PLAYER2 2
#define PONG_PLAYERS_SPEED 0.5f // % of screen height 

class PongPlayers {
public:

	void Init(Window *window);
	void Update(InputHandler *input, Timer *timer);
	void Draw(Renderer *renderer);
	FRect GetRightRect();
	FRect GetLeftRect();
	float GetLeftVelocity();
	float GetRightVelocity();
private:
	Window *m_window;
	GUIRect m_player1Rect;
	GUIRect m_player2Rect;
	float m_player1_dy, m_player2_dy;

};