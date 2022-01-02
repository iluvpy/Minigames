#include "TictactoeBoard.hpp"

void TictactoeBoard::Init(Window *window) {
    const int WIN_WIDTH = window->GetWidth();
	const int WIN_HEIGHT = window->GetHeight();
	const int LENGTH = 300;
	const int WIDTH = 10;
	const int SPACING = 100;
	const int START_X = (int)(WIN_WIDTH/2-(LENGTH+2*WIDTH)/2);
	const int START_Y = (int)(WIN_HEIGHT/2-LENGTH/2);
	m_row1.Init(START_X+SPACING, START_Y, WIDTH, LENGTH, TIC_TAC_TOE_BOARD_COLOR);
	m_row2.Init(START_X+SPACING*2, START_Y, WIDTH, LENGTH, TIC_TAC_TOE_BOARD_COLOR);
	m_column1.Init(START_X, START_Y+SPACING, LENGTH, WIDTH, TIC_TAC_TOE_BOARD_COLOR);
	m_column2.Init(START_X, START_Y+SPACING*2, LENGTH, WIDTH, TIC_TAC_TOE_BOARD_COLOR);
}

void TictactoeBoard::Draw(Renderer *renderer) {
    m_row1.Draw(renderer);
    m_row2.Draw(renderer);
    m_column1.Draw(renderer);
    m_column2.Draw(renderer);
}

void TictactoeBoard::Update() {

}