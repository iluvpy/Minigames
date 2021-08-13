#include "GUIButton.hpp"



void GUIButton::Init(int x , int y, int w, int h, const Color& normalColor, const Color& pressColor) {
    Init(Rect(x, y, w, h), normalColor, pressColor);
}

void GUIButton::Init(const Rect& rect, const Color& normalColor, const Color& pressColor)  {
    m_rect = rect;
    m_rect.SetColor(normalColor);
    m_normalColor = normalColor;
    m_pressedColor = pressColor;
    m_isPressed = false;
}

void GUIButton::Update(InputHandler *input) {    
    Point mouse = input->GetMousePos();
    if (m_rect.IsOntop(mouse) && input->isMouseButtonPressed(SDL_BUTTON_LEFT)) {
        m_rect.SetColor(m_pressedColor);
        m_isPressed = true;
    } 
    else {
        m_rect.SetColor(m_normalColor);
        m_isPressed = false;
    }
}

bool GUIButton::isPressed() const {
    return m_isPressed;
}

void GUIButton::Draw(Renderer *renderer) {
    m_rect.Draw(renderer);
}