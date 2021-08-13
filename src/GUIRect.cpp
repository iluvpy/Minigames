#include "GUIRect.hpp"

GUIRect::GUIRect(int x, int y, int w, int h, const Color& color) {
    Init(x, y, w, h, color);
}

void GUIRect::Init(int x, int y, int w, int h, const Color& color) {
    m_rect = Rect{x, y, w, h};
    m_color = color;
}

void GUIRect::Draw(Renderer *renderer) {
    renderer->DrawRect(m_rect.x, m_rect.y, m_rect.w, m_rect.h, m_color);
}

void GUIRect::SetColor(const Color& color) {
    m_color = color;
}

GUIRect::~GUIRect() {

}

