#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "GUIRect.hpp"
#include "InputHandler.hpp"
#include "Color.hpp"

#define TIC_TAC_TOE_BACKGROUND_COLOR Color(21, 22, 24)

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
};