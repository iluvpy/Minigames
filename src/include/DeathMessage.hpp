#pragma once

#include "Rect.hpp"
#include "Color.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

class DeathMessage {
public:
    void Init(const Color& backgroundColor, Window *window);
    void Draw(Renderer *renderer);
private:
    Rect m_rect;
};