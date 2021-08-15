#include "Color.hpp"

Color::Color(ubyte r, ubyte g, ubyte b, ubyte a) 
: m_r(r), m_g(g), m_b(b), m_a(a)
{}

ubyte Color::GetR() const { return m_r; }
ubyte Color::getG() const { return m_g; }
ubyte Color::getB() const { return m_b; }
ubyte Color::getA() const { return m_a; } 
SDL_Color Color::GetSdlColor() const { return SDL_Color{m_r, m_g, m_b}; };
Color::~Color() {}