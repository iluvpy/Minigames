#include  "GameMenu.hpp"

void GameMenu::Init(Renderer *renderer, InputHandler *input) {
    m_gameSelected = false;
    m_renderer = renderer;
    m_input = input;
    m_currentGame = CurrentGame::NOGAME;
    m_testRect.Init(100, 100, 50, 50, Color(120, 50, 160));
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

}

void GameMenu::UpdateGameMenu() {

}

void GameMenu::DrawCurrentGame() {

}

void GameMenu::DrawGameMenu() {
    m_testRect.Draw(m_renderer);
}


