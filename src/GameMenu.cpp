#include  "GameMenu.hpp"

void GameMenu::Init(Window *window, Renderer *renderer, InputHandler *input) {
    m_gameSelected = false;
    m_window = window;
    m_renderer = renderer;
    m_input = input;
    m_currentGame = CurrentGame::NOGAME;

    m_snakeButton.Init(100, 100, 60, 60, Color(), Color(255, 50, 50));

    InitGames();
}

void GameMenu::InitGames() {
    m_snakeGame.Init(m_renderer, m_window, m_input, 40);
}

void GameMenu::Draw() {
    if (m_gameSelected)
        DrawCurrentGame();
    else 
        DrawGameMenu();
}   


void GameMenu::Update() {
    if (m_gameSelected)
        UpdateCurrentGame();
    else    
        UpdateGameMenu();
}


void GameMenu::UpdateCurrentGame() {
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
    if (m_snakeButton.isPressed()) m_currentGame = CurrentGame::SNAKEGAME;

    if (m_currentGame != CurrentGame::NOGAME) m_gameSelected = true;

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
    m_snakeButton.Draw(m_renderer);
}


