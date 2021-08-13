#pragma once

#include "Color.hpp"
#include "InputHandler.hpp"
#include "Renderer.hpp"
#include "Rect.hpp"

class GUIButton {
public:
    void Init(const Rect& rect, const Color& normalColor=Color(), const Color& pressedColor=Color(150, 150, 150));
    void Init(int x, int y, int w, int h, const Color& normalColor=Color(), const Color&  pressedColor=Color(150, 150, 150));
    void Draw(Renderer *renderer);
    void Update(InputHandler *input);
    bool isPressed() const;
private:
    Color m_normalColor;
    Color m_pressedColor;
    Rect m_rect;
    bool m_isPressed;
};