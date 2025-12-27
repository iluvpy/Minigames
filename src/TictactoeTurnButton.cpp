#include "TictactoeTurnButton.hpp"

void TictactoeTurnButton::Init(int x, int y, TurnButton button_type, Renderer *renderer, Color backgroundColor) {
    m_renderer = renderer;
    std::string img_path = "./res/icons/";
    if (button_type == TurnButton::CIRLCE) 
        img_path += "turnO.png";
    else 
        img_path += "turnX.png";
    m_image.Init(m_renderer, x, y, img_path);
    m_backgroundRect.Init(x, y, m_image.GetWidth(), m_image.GetHeight(), backgroundColor);
    m_button.Init(m_backgroundRect);
    m_outlineRect.Init(x-TTTT_BUTTON_OUTLINE_WIDTH, 
                       y-TTTT_BUTTON_OUTLINE_WIDTH, 
                       m_image.GetWidth()+TTTT_BUTTON_OUTLINE_WIDTH*2,
                       m_image.GetHeight()+TTTT_BUTTON_OUTLINE_WIDTH*2, 
                       TTTT_BUTTON_OUTLINE_COLOR);
    m_focused = false;
}

void TictactoeTurnButton::Update(InputHandler *input) {
    m_button.Update(input);
    if (m_button.WasReleased()) {
        m_focused = !m_focused;
    }
    
}

void TictactoeTurnButton::Draw() {
    if (m_focused) 
        m_outlineRect.Draw(m_renderer);
    m_backgroundRect.Draw(m_renderer);
    m_image.Draw();
}

bool TictactoeTurnButton::IsFocused() const {
    return m_focused; 
}


