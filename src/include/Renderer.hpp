#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Color.hpp"
#include "Window.hpp"

class Renderer {
public:
    Renderer();
    void Init(SDL_Window *window);
    void Fill(const Color& color, const Window *window);
    void DrawRect(const SDL_Rect& rect);
    void SetColor(const Color& color);
    void DrawRect(int x, int y, int w, int h);
    void Start();
    void End();
    void Quit();
    ~Renderer();

private:

    SDL_Renderer *m_renderer;

};