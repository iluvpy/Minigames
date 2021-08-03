#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Renderer.hpp"
#include "Window.hpp"
#include "Utils.hpp"
#include "SnakeGame.hpp"
#include "KeyboardHandler.hpp"

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
    
    std::string m_window_name;
    Window m_window;
    Renderer m_renderer;
    KeyboardHandler m_keyboard;


    // games
    SnakeGame m_snake;
};