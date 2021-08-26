#include  "GameMenu.hpp"

#include <filesystem>


void GameMenu::Init(Window *window, Renderer *renderer, InputHandler *input) {
    m_window = window;
    m_renderer = renderer;
    m_input = input;
    m_currentGame = CurrentGame::NOGAME;

	m_snakeButton.Init(m_renderer, 200, 200, "./res/img/snake.png", 5, Color(100, 100, 100), Color(0, 0, 0));
    InitGames();
}

void GameMenu::InitGames() {
    m_snakeGame.Init(m_renderer, m_window, m_input, 60);
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
        default:
            break;
    }
}

void GameMenu::UpdateGameMenu() {
    
    // XXX add update buttons to play a game
    m_snakeButton.Update(m_input);
    if (m_snakeButton.GetButton().WasReleased()) m_currentGame = CurrentGame::SNAKEGAME;

}

void GameMenu::DrawCurrentGame() {
    switch (m_currentGame) {
        case CurrentGame::SNAKEGAME:
            m_snakeGame.Draw();
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
}


bool GameMenu::GameActive() { 
    return m_currentGame != CurrentGame::NOGAME; 
}

