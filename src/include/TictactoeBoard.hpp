#pragma once

#include "Window.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "GUIImage.hpp"
#include <array>

// board width and height
#define BOARD_WH 3

#define TIC_TAC_TOE_BOARD_COLOR Color(101, 102, 104)
#define BOARD_SPACING 128 // size of icons

class TictactoeBoard {
public:
    void Init(Window *window, Renderer *renderer);
    void Update(InputHandler *input);
    void Draw(Renderer *renderer);
private:
    GUIRect m_row1;
	GUIRect m_row2;
	GUIRect m_column1;
	GUIRect m_column2;
    GUIImage m_imageX;
    GUIImage m_imageO;
    std::array<Point, BOARD_WH * BOARD_WH> m_boardPositions;
};