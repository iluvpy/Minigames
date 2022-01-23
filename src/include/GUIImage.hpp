#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Renderer.hpp"

class GUIImage {
public:
	void Init(Renderer *renderer, float x, float y, const std::string& path);
	void Draw();
	void AngleDraw(float angle);
	float GetWidth();
	float GetHeight();
	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);
	void SetColor(const Color& color);
	SDL_Texture* GetTexture() const;

	~GUIImage();
private:
	Renderer *m_renderer;
	SDL_Texture *m_texture;
	FRect m_rect;
};