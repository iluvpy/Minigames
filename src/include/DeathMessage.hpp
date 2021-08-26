#pragma once

#include "GUIRect.hpp"
#include "Color.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include "GUIText.hpp"

class DeathMessage {
public:
    void Init(Renderer *renderer, const Color& backgroundColor, Window *window);
    void Draw();
private:
    GUIRect m_rect;
	Point m_textSize;
    Renderer *m_renderer;
};