#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"
#include "Structs.hpp"
#include "GUIRect.hpp"

class GameMenu {
public:
    void Init(Renderer *renderer, InputHandler *input);
    void Draw();
    void Update();
private:
    void UpdateGameMenu();
    void DrawGameMenu();
    void UpdateCurrentGame();
    void DrawCurrentGame();


    bool m_gameSelected;
    Renderer *m_renderer;
    InputHandler *m_input;
    CurrentGame m_currentGame;
    GUIRect m_testRect;
};