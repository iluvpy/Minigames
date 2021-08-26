#pragma once

#include <iostream>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "Color.hpp"
#include "Window.hpp"
#include "GUIRect.hpp"
#include "GUIText.hpp"

class Renderer {
public:
    Renderer();
    void Init(SDL_Window *window);
    void Fill(const Color& color, const Window *window);
    void DrawRect(const GUIRect& rect);
	void DrawText(const Point& pos, const std::string& text, int fontSize=28, const Color& color=Color(0, 0, 0));
	void DrawText(int x, int y,const std::string& text, int fontSize=28, const Color& color=Color(0, 0, 0));
	Rect GetTextRect(const std::string& text, int fontSize=28);
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