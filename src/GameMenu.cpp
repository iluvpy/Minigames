#include  "GameMenu.hpp"

void GameMenu::Init(Window *window, Renderer *renderer, InputHandler *input) {
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
    if (m_snakeButton.isPressed()) m_currentGame = CurrentGame::SNAKEGAME;

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

bool GameMenu::GameActive() { 
    return m_currentGame != CurrentGame::NOGAME; 
}

void GameMenu::DrawGameMenu() {
    m_snakeButton.Draw(m_renderer);
}


