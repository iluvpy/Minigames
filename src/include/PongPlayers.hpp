#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"
#include "Timer.hpp"

#define PONG_PLAYERS_WIDTH 15.0f 
#define PONG_PLAYERS_HEIGHT 200.0f 
#define PONG_PLAYERS_X 80.0f
#define PONG_PLAYERS_DRAG 0.8f // friction
#define PONG_PLAYER1 1
#define PONG_PLAYER2 2
#define PONG_PLAYERS_SPEED 500.0f

class PongPlayers {
public:

	void Init(Window *window);
	void Update(InputHandler *input, float deltaTime);
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