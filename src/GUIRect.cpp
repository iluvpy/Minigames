#include "GUIRect.hpp"
#include "Renderer.hpp"

GUIRect::GUIRect(float x, float y, float w, float h, const Color& color) {
    Init(x, y, w, h, color);
}

void GUIRect::Init(float x, float y, float w, float h, const Color& color) {
    m_rect = {x, y, w, h};
    m_color = color;
}

void GUIRect::Draw(Renderer *renderer) {
    renderer->DrawRect(m_rect, m_color);
}

void GUIRect::SetColor(const Color& color) {
    m_color = color;
}

float GUIRect::GetX() const {
    return m_rect.x;
}   

float GUIRect::GetY() const {
    return m_rect.y;
}

float GUIRect::GetW() const {
    return m_rect.w;
}

float GUIRect::GetH() const {
    return m_rect.h;
}

FRect GUIRect::GetRect() const {
	return m_rect;
}

void GUIRect::SetX(float x) {
	m_rect.x = x;
}

void GUIRect::SetY(float y) {
	m_rect.y = y;
}

void GUIRect::SetW(float w) {
	m_rect.w = w;
}

void GUIRect::SetH(float h) {
	m_rect.h = h;
}


bool GUIRect::IsOntop(const Point& pos) {
    return (pos.x >= m_rect.x &&
            pos.x <= m_rect.x+m_rect.w &&
            pos.y >= m_rect.y &&
            pos.y <= m_rect.y+m_rect.h);
}

Color GUIRect::GetColor() const {
    return m_color;
}

GUIRect::~GUIRect() {

}

