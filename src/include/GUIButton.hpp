#pragma once

#include "Color.hpp"
#include "InputHandler.hpp"
#include "Renderer.hpp"
#include "GUIRect.hpp"

class GUIButton {
public:
    void Init(const GUIRect& rect, const Color& normalColor=Color(), const Color& pressedColor=Color(150, 150, 150));
    void Init(int x, int y, int w, int h, const Color& normalColor=Color(), const Color&  pressedColor=Color(150, 150, 150));
    void Draw(Renderer *renderer);
    void Update(InputHandler *input);
    bool IsPressed() const;
    bool WasReleased() const;
private:
    Color m_normalColor;
    Color m_pressedColor;
    GUIRect m_rect;
    bool m_isPressed;
    bool m_wasReleased;
};