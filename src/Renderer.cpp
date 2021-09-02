#include "Renderer.hpp"

#define DEFAULT_FONT_PATH "./res/fonts/default.ttf"

Renderer::Renderer() {}

void Renderer::Init(SDL_Window *window) {
    m_renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC);
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

void Renderer::DrawRect(const Rect& rect, const Color& color) {
	DrawRect(rect.x, rect.y, rect.w, rect.h, color);
}

void Renderer::DrawRect(const FRect& rect, const Color& color) {
	SetColor(color);
    SDL_RenderFillRectF(m_renderer, (SDL_FRect*)&rect);
}


void Renderer::DrawRect(const GUIRect& rect) {
    DrawRect(rect.GetRect(), rect.GetColor());
}

void Renderer::DrawCircle(float x, float y, float radius, const Color& color) {
	SetColor(color);

	for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(m_renderer, x + dx, y + dy);
            }
        }
    }

}

void Renderer::DrawText(const Point& pos, const std::string& text, int fontSize, const Color& color) {
	DrawText(pos.x, pos.y, text, fontSize, color);
}

void Renderer::DrawText(int x, int y, const std::string& text, int fontSize, const Color& color) 
{
	auto it = m_textCache.find(text);
	if (it != m_textCache.end()) 
		it->second->DrawText();
	else {
		// need to use 'new' causes segfault if i dont (and does not draw text)
		GUIText *gui_text = new GUIText;
		gui_text->Init(this, x, y, text, DEFAULT_FONT_PATH, fontSize, color);
		m_textCache[text] = gui_text;
	}
	if (m_textCache.size() > 50) 
		m_textCache.clear();
}

Rect Renderer::GetTextRect(const std::string& text, int fontSize) {
	GUIText *text__;
	// check cache
	auto it = m_textCache.find(text);
	if (it != m_textCache.end()) text__ = it->second;
	else {
		text__ = new GUIText;
		text__->Init(this, 0, 0, text, DEFAULT_FONT_PATH, fontSize, Color(0, 0, 0));
	}
	return text__->GetRect();
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