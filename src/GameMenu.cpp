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
	Color backgroundColor(100, 100, 100);
	Color outlineColor(60, 60, 60);
	int outlineWidth = 5;

	int x = m_window->GetWidth() * GAME_BUTTON_STARTX;
	int y = m_window->GetHeight() * GAME_BUTTON_STARTY;
	int spacing = m_window->GetWidth() * GAME_BUTTON_SPACING;

	m_snakeButton.Init(m_renderer, x, y, "./res/icons/snake.png", outlineWidth, backgroundColor, outlineColor);
	m_pongButton.Init(m_renderer, x+=spacing, y, "./res/icons/pong.png", outlineWidth, backgroundColor, outlineColor);
	m_asteroidButton.Init(m_renderer, x+=spacing, y, "./res/icons/asteroid.png", outlineWidth, backgroundColor, outlineColor);
}

void GameMenu::InitGames() {
    m_snakeGame.Init(m_renderer, m_window, m_input, SNAKE_GAME_RECT_WIDTH);
	m_pongGame.Init(m_renderer, m_window, m_input);
	m_asteroidGame.Init(m_renderer, m_window, m_input);
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
			m_pongGame.Update(m_timer->GetDeltaTime());
			break;
		case CurrentGame::ATEROIDGAME:
			m_asteroidGame.Update(m_timer->GetDeltaTime());
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

	m_asteroidButton.Update(m_input);
	if (m_asteroidButton.GetButton().WasReleased()) m_currentGame = CurrentGame::ATEROIDGAME;
}

void GameMenu::DrawCurrentGame() {
    switch (m_currentGame) {
        case CurrentGame::SNAKEGAME:
            m_snakeGame.Draw();
            break;
		case CurrentGame::PONGGAME:
			m_pongGame.Draw();
			break;
		case CurrentGame::ATEROIDGAME:
			m_asteroidGame.Draw();
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
	m_asteroidButton.Draw();
}


bool GameMenu::GameActive() { 
    return m_currentGame != CurrentGame::NOGAME; 
}

