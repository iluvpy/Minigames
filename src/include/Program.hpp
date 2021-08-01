#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "Renderer.hpp"
#include "Window.hpp"
#include "Utils.hpp"
#include "SnakeGrid.hpp"

class Program {
public:
    Program();
    void Init(const std::string& name); // inits all libraries
    void Start();
    ~Program();
private:

    void InitSDL();
    void HandleEvents();
    
    std::string m_window_name;
    Window m_window;
    Renderer m_renderer;
};