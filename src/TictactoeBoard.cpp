#include "TictactoeBoard.hpp"

void TictactoeBoard::Init(Window *window, Renderer *renderer) {
    const int WIN_WIDTH = window->GetWidth();
	const int WIN_HEIGHT = window->GetHeight();
	const int WIDTH = 10;
	const int LENGTH = BOARD_SPACING * BOARD_WH + WIDTH * 2;
	const int SPACING = BOARD_SPACING;
	const int START_X = static_cast<int>(WIN_WIDTH/2-(LENGTH+2*WIDTH)/2);
	const int START_Y = static_cast<int>(WIN_HEIGHT/2-LENGTH/2);
	m_row1.Init(START_X+SPACING, START_Y, WIDTH, LENGTH, TIC_TAC_TOE_BOARD_COLOR);
	m_row2.Init(START_X+SPACING*2 + WIDTH, START_Y, WIDTH, LENGTH, TIC_TAC_TOE_BOARD_COLOR);
	m_column1.Init(START_X, START_Y+SPACING, LENGTH, WIDTH, TIC_TAC_TOE_BOARD_COLOR);
	m_column2.Init(START_X, START_Y+SPACING*2 + WIDTH, LENGTH, WIDTH, TIC_TAC_TOE_BOARD_COLOR);

	int index = 0;
	for (int i = 0; i < BOARD_WH; i++) {
		for (int j = 0; j < BOARD_WH; j++) {
			int x = START_X + SPACING * j + WIDTH * j;
			int y = START_Y + SPACING * i + WIDTH * i;
			m_boardPositions[index] = Point{x, y};
			index++;
		}
	}
	
	m_imageO.Init(renderer, START_X, START_Y, "./res/icons/turnO.png");
	m_imageX.Init(renderer, START_X, START_Y, "./res/icons/turnX.png");
}

void TictactoeBoard::Draw(Renderer *renderer) {
    m_row1.Draw(renderer);
    m_row2.Draw(renderer);
    m_column1.Draw(renderer);
    m_column2.Draw(renderer);
	m_imageO.Draw();
	m_imageO.SetX(m_boardPositions[1].x);
	m_imageO.SetY(m_boardPositions[1].y);
	m_imageO.Draw();
	m_imageO.SetX(m_boardPositions[2].x);
	m_imageO.SetY(m_boardPositions[2].y);
	m_imageO.Draw();
	m_imageO.SetX(m_boardPositions[3].x);
	m_imageO.SetY(m_boardPositions[3].y);
	m_imageO.Draw();
	m_imageO.SetX(m_boardPositions[0].x);
	m_imageO.SetY(m_boardPositions[0].y); 

}

void TictactoeBoard::Update(InputHandler *input) {
	if (input->isMouseButtonPressed(SDL_BUTTON_LEFT)) {
		std::cout << "mouse button pressed in tic tac toe, from board::update\n";
	}
}