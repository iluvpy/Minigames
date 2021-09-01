#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Renderer.hpp"

class GUIImage {
public:

	void Init(Renderer *renderer, int x, int y, const std::string& path);
	void Draw();
	void AngleDraw(float angle);
	int GetWidth();
	int GetHeight();
	void SetX(int x);
	void SetY(int y);
	void SetColor(const Color& color);
	~GUIImage();
private:
	Renderer *m_renderer;
	SDL_Texture *m_texture;

	Rect m_rect;
};