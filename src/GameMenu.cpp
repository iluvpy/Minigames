#include  "GameMenu.hpp"

#include <filesystem>


void GameMenu::Init(Window *window, Renderer *renderer, InputHandler *input, Timer *timer) {
    m_window = window;
    m_renderer = renderer;
    m_input = input;
	m_timer = timer;
    m_currentGame = CurrentGame::NOGAME;
	
	InitButtons();
    InitGames();
}

void GameMenu::InitButtons() {
	Color background(100, 100, 100);
	Color outline(60, 60, 60);
	int outlineWidth = 5;

	int x = m_window->GetWidth() * GAME_BUTTON_STARTX;
	int y = m_window->GetHeight() * GAME_BUTTON_STARTY;
	int spacing = m_window->GetWidth() * GAME_BUTTON_SPACING;

	m_snakeButton.Init(m_renderer, x, y, "./res/img/snake.png", outlineWidth, background, outline);
	m_pongButton.Init(m_renderer, x+=spacing, y, "./res/img/pong.png", outlineWidth, background, outline);
}

void GameMenu::InitGames() {
    m_snakeGame.Init(m_renderer, m_window, m_input, SNAKE_GAME_RECT_WIDTH * m_window->GetWidth());
	m_pongGame.Init(m_renderer, m_window, m_input);
}

void GameMenu::Draw() {
    if (GameActive())
        DrawCurrentGame();
    else 
        DrawGameMenu();
}   


void GameMenu::Update() {
    if (GameActive())
        UpdateCurrentGame();
    else    
        UpdateGameMenu();
}


void GameMenu::UpdateCurrentGame() {
    if (m_input->isPressed(SDLK_ESCAPE)) {
        m_currentGame = CurrentGame::NOGAME;
    }
    switch (m_currentGame) {
        case CurrentGame::SNAKEGAME:
            m_snakeGame.Update();
            break;
		case CurrentGame::PONGGAME:
			m_pongGame.Update(m_timer);
			break;
        default:
            break;
    }
}

void GameMenu::UpdateGameMenu() {
    
    // XXX add update buttons to play a game
    m_snakeButton.Update(m_input);
    if (m_snakeButton.GetButton().WasReleased()) m_currentGame = CurrentGame::SNAKEGAME;

	m_pongButton.Update(m_input);
	if (m_pongButton.GetButton().WasReleased()) m_currentGame = CurrentGame::PONGGAME;

}

void GameMenu::DrawCurrentGame() {
    switch (m_currentGame) {
        case CurrentGame::SNAKEGAME:
            m_snakeGame.Draw();
            break;
		case CurrentGame::PONGGAME:
			m_pongGame.Draw();
			break;
        default:
            break;
    }
}

void GameMenu::DrawGameMenu() {

	int fontSize = 42;
	Rect rect = m_renderer->GetTextRect("Game Menu", fontSize);
	m_renderer->DrawText((int)m_window->GetWidth()/2-rect.w/2, 100, "Game Menu", fontSize);

	m_snakeButton.Draw();
	m_pongButton.Draw();
}


bool GameMenu::GameActive() { 
    return m_currentGame != CurrentGame::NOGAME; 
}

