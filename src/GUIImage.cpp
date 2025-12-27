#include "GUIImage.hpp"


void GUIImage::Init(Renderer *renderer, float x, float y, const std::string& path) {
	m_renderer = renderer;
	m_rect = {x, y, 0, 0};

	m_texture = IMG_LoadTexture(m_renderer->GetRendererPtr(), path.c_str());
	int w, h;
	SDL_QueryTexture(m_texture, NULL, NULL, &w, &h);
	m_rect.w = w;
	m_rect.h = h;
}

SDL_Texture* GUIImage::GetTexture() const {
	return m_texture;
}

float GUIImage::GetWidth() {
	return m_rect.w;
}

float GUIImage::GetHeight() {
	return m_rect.h;
}

float GUIImage::GetX() {
	return m_rect.x;
}
float GUIImage::GetY() {
	return m_rect.y;
}

void GUIImage::SetX(float x) {
	m_rect.x = x;
}
void GUIImage::SetY(float y) {
	m_rect.y = y;
}

void GUIImage::SetColor(const Color& color) {
	if (SDL_SetTextureColorMod(m_texture, color.GetR(), color.getG(), color.getB())) {
		std::cerr << "could not modify color of texture!\n";
	}
}

void GUIImage::Draw() {
	SDL_RenderCopyF(m_renderer->GetRendererPtr(), m_texture, NULL, (SDL_FRect*)&m_rect);
}


void GUIImage::AngleDraw(float angle) {
	SDL_RenderCopyExF(m_renderer->GetRendererPtr(), m_texture, NULL, (SDL_FRect*)&m_rect, angle, NULL, SDL_FLIP_NONE);
}

GUIImage::~GUIImage() {
	SDL_DestroyTexture(m_texture);
}