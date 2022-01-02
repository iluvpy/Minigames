#pragma once

#include "Window.hpp"
#include "Renderer.hpp"

#define TIC_TAC_TOE_BOARD_COLOR Color(101, 102, 104)

class TictactoeBoard {
public:
    void Init(Window *window);
    void Update();
    void Draw(Renderer *renderer);
private:
    GUIRect m_row1;
	GUIRect m_row2;
	GUIRect m_column1;
	GUIRect m_column2;
};