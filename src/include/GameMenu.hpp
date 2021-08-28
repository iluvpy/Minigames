#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"
#include "GUIButton.hpp"
#include "Structs.hpp"
#include "SnakeGame.hpp"
#include "GameButton.hpp"
#include "PongGame.hpp"
#include "Timer.hpp"

#define GAME_BUTTON_SPACING 0.1 // % relative to the screen width
#define GAME_BUTTON_STARTX 0.1 // % relative to the screen width
#define GAME_BUTTON_STARTY 0.2 // % relative to the screen width
class GameMenu {
public:
    void Init(Window *window, Renderer *renderer, InputHandler *input, Timer *timer);
    void Draw();
    void Update();
private:
    void InitGames();
	void InitButtons();
    void UpdateGameMenu();
    void DrawGameMenu();
    void UpdateCurrentGame();
    void DrawCurrentGame();
    bool GameActive();

    Window *m_window;
    Renderer *m_renderer;
    InputHandler *m_input;
    CurrentGame m_currentGame;
	Timer *m_timer;

    // buttons
    GameButton m_snakeButton;
	GameButton m_pongButton;
    // games
    SnakeGame m_snakeGame;
	PongGame m_pongGame;


};