#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Renderer.hpp"
#include "Window.hpp"
#include "SnakeGame.hpp"
#include "InputHandler.hpp"
#include "GameMenu.hpp"

class Program {
public:
    Program();
    void Init(const std::string& name); // inits all libraries
    void Start();
    ~Program();
private:

    void InitSDL();
    void HandleEvents();
    void Update();

    Window m_window;
    Renderer m_renderer;
    InputHandler m_input;
    GameMenu m_gameMenu;
};