#pragma once

#include <string>
#include <SDL2/SDL_ttf.h>

#include "Color.hpp"
#include "Structs.hpp"

// forward declaration
class Renderer;

class GUIText {
public:
    GUIText();
    GUIText(Renderer *renderer, int x, int y, const std::string& text, const std::string& fontPath="./res/fonts/default.ttf", int fontSize=28, const Color& color=Color(0,0,0));
    void Init(Renderer *renderer, int x, int y, const std::string& text, const std::string& fontPath="./res/fonts/default.ttf", int fontSize=28, const Color& color=Color(0,0,0));
    void DrawText();
    void SetText(const std::string& text);
    int GetWidth();
    int GetHeight();
    Rect GetRect() const;
    void SetRect(const Rect& rect);
    ~GUIText();
private:

    TTF_Font *m_font=nullptr;
    SDL_Surface *m_surface=nullptr;
    SDL_Texture *m_texture=nullptr;
    Renderer *m_renderer;

    Color m_color;
    Rect m_rect;
    std::string m_text;
};