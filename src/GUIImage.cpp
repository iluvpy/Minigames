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

void GUIImage::SetX(int x) {
	m_rect.x = x;
}
void GUIImage::SetY(int y) {
	m_rect.y = y;
}

void GUIImage::SetColor(const Color& color) {
	if (SDL_SetTextureColorMod(m_texture, color.GetR(), color.getG(), color.getB())) {
		std::cerr << "could not modify color of texture!\n";
	}
}

void GUIImage::Draw() {
	SDL_RenderCopy(m_renderer->GetRendererPtr(), m_texture, NULL, (SDL_Rect*)&m_rect);
}


void GUIImage::AngleDraw(float angle) {
	SDL_RenderCopyEx(m_renderer->GetRendererPtr(), m_texture, NULL, (SDL_Rect*)&m_rect, angle, NULL, SDL_FLIP_NONE);
}

GUIImage::~GUIImage() {
	SDL_DestroyTexture(m_texture);
}