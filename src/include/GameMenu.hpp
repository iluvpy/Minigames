#pragma once

#include "Renderer.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"
#include "GUIButton.hpp"
#include "Structs.hpp"
#include "Timer.hpp"

// games
#include "SnakeGame.hpp"
#include "GameButton.hpp"
#include "PongGame.hpp"
#include "AsteroidGame.hpp"
#include "TictactoeGame.hpp"


#define GAME_BUTTON_SPACING 0.1 // % relative to the screen width
#define GAME_BUTTON_STARTX 0.05 // % relative to the screen width
#define GAME_BUTTON_STARTY 0.1 // % relative to the screen width
#define GAME_MENU_BACKGROUND_COLOR Color(50, 50, 50)

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
	GUIRect m_backgroundRect;
    // buttons
    GameButton m_snakeButton;
	GameButton m_pongButton;
	GameButton m_asteroidButton;
    GameButton m_tictactoeButton;
    // games
    SnakeGame m_snakeGame;
	PongGame m_pongGame;
	AsteroidGame m_asteroidGame;
    TictactoeGame m_tictactoeGame;
};