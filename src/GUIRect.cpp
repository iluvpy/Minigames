#include "GUIRect.hpp"
#include "Renderer.hpp"

GUIRect::GUIRect(int x, int y, int w, int h, const Color& color) {
    Init(x, y, w, h, color);
}

void GUIRect::Init(int x, int y, int w, int h, const Color& color) {
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    m_color = color;
}

void GUIRect::Draw(Renderer *renderer) {
    renderer->DrawRect(m_x, m_y, m_w, m_h, m_color);
}

void GUIRect::SetColor(const Color& color) {
    m_color = color;
}

int GUIRect::GetX() const {
    return m_x;
}   

int GUIRect::GetY() const {
    return m_y;
}

int GUIRect::GetW() const {
    return m_w;
}

int GUIRect::GetH() const {
    return m_h;
}

Rect GUIRect::GetRect() const {
	return Rect{m_x, m_y, m_w, m_h};
}


bool GUIRect::IsOntop(const Point& pos) {
    return (pos.x >= m_x &&
            pos.x <= m_x+m_w &&
            pos.y >= m_y &&
            pos.y <= m_y+m_h);
}

Color GUIRect::GetColor() const {
    return m_color;
}

GUIRect::~GUIRect() {

}

