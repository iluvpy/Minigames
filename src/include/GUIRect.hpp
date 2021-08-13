#pragma once

#include "Structs.hpp"
#include "Color.hpp"
#include "Renderer.hpp"

class GUIRect {
public:
    GUIRect(int x = 0, int y = 0, int w = 0, int h = 0, const Color& color = Color());
    void Init(int x = 0, int y = 0, int w = 0, int h = 0, const Color& color = Color());
    void Draw(Renderer *renderer);
    void SetColor(const Color& color);
    ~GUIRect();
private:
    Rect m_rect;
    Color m_color;
};