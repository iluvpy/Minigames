#include "GUIText.hpp"
#include <iostream>

GUIText::GUIText() {

}

GUIText::GUIText(Renderer *renderer, int x, int y, const std::string& text, const std::string& fontPath, int fontSize, const Color& color) {
    Init(renderer, x, y, text, fontPath, fontSize, color);
}

void GUIText::Init(Renderer *renderer, int x, int y, const std::string& text, const std::string& fontPath, int fontSize, const Color& color) {
    m_font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!m_font) std::cout << "could not open font\n";
    m_color = color;
    m_text = text;
    m_renderer = renderer;
    m_rect = {x, y, 0, 0};
    SetText(m_text);
}


void GUIText::SetText(const std::string& text) {
    if (m_surface) SDL_FreeSurface(m_surface);
    if (m_texture) SDL_DestroyTexture(m_texture);
    
    m_surface = TTF_RenderText_Solid(m_font, text.c_str(), m_color.GetSdlColor()); 
    m_texture = SDL_CreateTextureFromSurface(m_renderer->GetRendererPtr(), m_surface); 

    // update width and height
    int w, h;
    TTF_SizeText(m_font, text.c_str(), &w, &h);  
    m_rect.w = w;
    m_rect.h = h;
}

void GUIText::DrawText() {
    SDL_RenderCopy(m_renderer->GetRendererPtr(), m_texture, NULL, (SDL_Rect*)&m_rect);
}

int GUIText::GetWidth() {
    return m_rect.h;
}

int GUIText::GetHeight() {
    return m_rect.w;
}

GUIText::~GUIText() {
    if (m_surface) SDL_FreeSurface(m_surface);
    if (m_texture) SDL_DestroyTexture(m_texture);
    if (m_font) TTF_CloseFont(m_font);
}
