#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"
#include "GUIButton.hpp"
#include "Structs.hpp"
#include "Rect.hpp"
#include "SnakeGame.hpp"
#include "GUIText.hpp"

class GameMenu {
public:
    void Init(Window *window, Renderer *renderer, InputHandler *input);
    void Draw();
    void Update();
private:
    void InitGames();
    void UpdateGameMenu();
    void DrawGameMenu();
    void UpdateCurrentGame();
    void DrawCurrentGame();
    bool GameActive();

    Window *m_window;
    Renderer *m_renderer;
    InputHandler *m_input;
    CurrentGame m_currentGame;

    // buttons
    GUIButton m_snakeButton;

    // games
    SnakeGame m_snakeGame;

    // fonts
    GUIText m_testText;

};