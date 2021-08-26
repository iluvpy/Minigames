#include "Renderer.hpp"

#define DEFAULT_FONT_PATH "./res/fonts/default.ttf"

Renderer::Renderer() {}

void Renderer::Init(SDL_Window *window) {
    m_renderer = SDL_CreateRenderer(window, 0, 0);
}

void Renderer::Start() {
    SDL_RenderClear(m_renderer);
}

void Renderer::Fill(const Color& color, const Window *window) {
    SDL_Rect r = window->GetWindowRect();
    DrawRect(r.x, r.y, r.w, r.h, color);
}

void Renderer::SetColor(const Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.GetR(), color.getG(), color.getB(), color.getA());
}

void Renderer::DrawRect(int x, int y, int w, int h, const Color& color) {
    SetColor(color);
    SDL_Rect r{x, y, w, h};
    SDL_RenderFillRect(m_renderer, &r);
}

void Renderer::DrawRect(const Rect& rect) {
    DrawRect(rect.GetX(), rect.GetY(), rect.GetW(), rect.GetH(), rect.GetColor());
}

void Renderer::DrawText(const Point& pos, 
				        const std::string& text, 
						int fontSize, 
						const Color& color) {

	auto it = m_textCache.find(text);
	if (it != m_textCache.end()) it->second->DrawText();
	else {
		// need to use 'new' causes segfault if i dont (and does not draw text)
		GUIText *gui_text = new GUIText;
		gui_text->Init(this, pos.x, pos.y, text, DEFAULT_FONT_PATH, fontSize, color);
		m_textCache[text] = gui_text;
	}

}


void Renderer::End() {
    SDL_RenderPresent(m_renderer);
}

SDL_Renderer *Renderer::GetRendererPtr() {
    return m_renderer;
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
	for (auto ptr = m_textCache.begin(); ptr != m_textCache.end(); ptr++) {
		delete ptr->second;
	}
}