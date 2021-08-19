#include "DeathMessage.hpp"


void DeathMessage::Init(Renderer *renderer, const Color& backgroundColor, Window *window) {
    m_renderer = renderer;
    int windowW = window->GetWindowRect().w;
    int windowH = window->GetWindowRect().h;
    int h = windowH*.3f; // 30%
    int w =  windowW*.45f; //  45%
    int x = (int)(windowW/2-w/2);
    int y = (int)(windowH/2-h/2);
    m_rect.Init(x, y, w, h, backgroundColor);

    // init text
    m_text.Init(m_renderer, x, y, "You Died :(", nullptr);
}

void DeathMessage::Draw() {
    m_renderer->DrawRect(m_rect);
    m_text.DrawText();
}
