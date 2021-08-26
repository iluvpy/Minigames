#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Renderer.hpp"

class GUIImage {
public:

	void Init(Renderer *renderer, int x, int y, const std::string& path);
	void Draw();
	int GetWidth();
	int GetHeight();
	~GUIImage();
private:
	Renderer *m_renderer;
	SDL_Texture *m_texture;

	Rect m_rect;
};