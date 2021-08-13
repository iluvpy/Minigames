#include "Rect.hpp"
#include "Renderer.hpp"

Rect::Rect(int x, int y, int w, int h, const Color& color) {
    Init(x, y, w, h, color);
}

void Rect::Init(int x, int y, int w, int h, const Color& color) {
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    m_color = color;
}

void Rect::Draw(Renderer *renderer) {
    renderer->DrawRect(m_x, m_y, m_w, m_h, m_color);
}

void Rect::SetColor(const Color& color) {
    m_color = color;
}

int Rect::GetX() const {
    return m_x;
}   

int Rect::GetY() const {
    return m_y;
}

int Rect::GetW() const {
    return m_w;
}

int Rect::GetH() const {
    return m_h;
}

bool Rect::IsOntop(const Point& pos) {
    return (pos.x >= m_x &&
            pos.x <= m_x+m_w &&
            pos.y >= m_y &&
            pos.y <= m_y+m_h);
}

Color Rect::GetColor() const {
    return m_color;
}

Rect::~Rect() {

}

