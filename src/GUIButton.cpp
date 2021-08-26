#include "GUIButton.hpp"



void GUIButton::Init(int x, int y, int w, int h, const Color& normalColor, const Color& pressColor) {
    Init(GUIRect(x, y, w, h), normalColor, pressColor);
}

void GUIButton::Init(const GUIRect& rect, const Color& normalColor, const Color& pressColor)  {
    m_rect = rect;
    m_rect.SetColor(normalColor);
    m_normalColor = normalColor;
    m_pressedColor = pressColor;
    m_isPressed = false;
    m_wasReleased = false;
}

void GUIButton::Update(InputHandler *input) {    
    Point mouse = input->GetMousePos();
    m_wasReleased = false;
    if (m_rect.IsOntop(mouse) && input->isMouseButtonPressed(SDL_BUTTON_LEFT)) {
        m_rect.SetColor(m_pressedColor);
        m_isPressed = true;
    } 
    else {
        m_rect.SetColor(m_normalColor);
        if (m_isPressed) m_wasReleased = true;
        m_isPressed = false;
    }
}

bool GUIButton::IsPressed() const {
    return m_isPressed;
}

bool GUIButton::WasReleased() const {
    return m_wasReleased;
}

void GUIButton::Draw(Renderer *renderer) {
    m_rect.Draw(renderer);
}