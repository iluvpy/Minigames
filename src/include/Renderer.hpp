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
    void DrawRect(const SDL_Rect& rect, const Color& color=Color());
    void SetColor(const Color& color);
    void DrawRect(int x, int y, int w, int h, const Color& color=Color());
    void Start();
    void End();
    ~Renderer();

private:

    SDL_Renderer *m_renderer;

};