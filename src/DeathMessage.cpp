#include "DeathMessage.hpp"

#define DEATH_MESSAGE "You died :3"
 
void DeathMessage::Init(Renderer *renderer, const Color& backgroundColor, Window *window) {
    m_renderer = renderer;
    int windowW = window->GetWindowRect().w;
    int windowH = window->GetWindowRect().h;
    int h = windowH * .3f; // 30%
    int w =  windowW * .45f; //  45%
    int x = (int)(windowW / 2 - w / 2); // middle
    int y = (int)(windowH / 2 - h / 2); // middle
    m_rect.Init(x, y, w, h, backgroundColor);

	Rect text_rext = m_renderer->GetTextRect(DEATH_MESSAGE);
	m_textSize = {text_rext.w, text_rext.h};

}

void DeathMessage::Draw() {
    m_renderer->DrawRect(m_rect);
	int x = m_rect.GetX() + m_rect.GetW() / 2 - m_textSize.x / 2;
	int y = m_rect.GetY() + m_rect.GetH() / 2 - m_textSize.y / 2;
	m_renderer->DrawText(Point{x, y}, DEATH_MESSAGE);
}
