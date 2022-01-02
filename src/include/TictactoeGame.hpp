#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "GUIRect.hpp"
#include "InputHandler.hpp"
#include "Color.hpp"
#include "TictactoeBoard.hpp"
#include "TictactoeTurnButton.hpp"

#define TIC_TAC_TOE_BACKGROUND_COLOR Color(51, 52, 54)


class TictactoeGame {
public:
	void Init(Renderer *renderer, Window *window, InputHandler *input);
	void Draw();
	void Update(float deltaTime);
private:
	Renderer *m_renderer;
	Window *m_window;
	InputHandler *m_input;
	GUIRect m_backgroundRect;
	TictactoeBoard m_board;
	TictactoeTurnButton m_turnO;
	TictactoeTurnButton m_turnX;
	bool m_turn;

};