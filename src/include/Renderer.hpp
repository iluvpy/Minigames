#pragma once

#include <iostream>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "Color.hpp"
#include "Window.hpp"
#include "Rect.hpp"
#include "GUIText.hpp"

class Renderer {
public:
    Renderer();
    void Init(SDL_Window *window);
    void Fill(const Color& color, const Window *window);
    void DrawRect(const Rect& rect);
	void DrawText(const Point& pos, 
				  const std::string& text, 
				  int fontSize=28, 
				  const Color& color=Color(0, 0, 0));
    void SetColor(const Color& color);
    void DrawRect(int x, int y, int w, int h, const Color& color=Color());
    void Start();
    void End();
    SDL_Renderer *GetRendererPtr();
    ~Renderer();
private:

    SDL_Renderer *m_renderer;
	std::unordered_map<std::string, GUIText*> m_textCache;

};