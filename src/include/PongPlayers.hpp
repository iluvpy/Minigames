#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"

#define PONG_PLAYERS_WIDTH 0.01f // % of screen width
#define PONG_PLAYERS_HEIGHT 0.5f // % of screen height
#define PONG_PLAYERS_X 0.05

#define PONG_PLAYER1 1
#define PONG_PLAYER2 2

class PongPlayers {
public:

	void Init(Window *window);
	void Update(InputHandler *input);
	void Draw(Renderer *renderer);
	Rect GetRightRect();
	Rect GetLeftRect();
private:

	GUIRect m_player1Rect;
	GUIRect m_player2Rect;

};