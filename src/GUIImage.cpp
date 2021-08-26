#include "GUIImage.hpp"


void GUIImage::Init(Renderer *renderer, int x, int y, const std::string& path) {
	m_renderer = renderer;
	m_rect = {x, y, 0, 0};

	m_texture = IMG_LoadTexture(m_renderer->GetRendererPtr(), path.c_str());
	int w, h;
	SDL_QueryTexture(m_texture, NULL, NULL, &w, &h);
	m_rect.w = w;
	m_rect.h = h;
}

int GUIImage::GetWidth() {
	return m_rect.w;
}

int GUIImage::GetHeight() {
	return m_rect.h;
}

void GUIImage::Draw() {
	SDL_RenderCopy(m_renderer->GetRendererPtr(), m_texture, NULL, (SDL_Rect*)&m_rect);
}

GUIImage::~GUIImage() {
	SDL_DestroyTexture(m_texture);
}