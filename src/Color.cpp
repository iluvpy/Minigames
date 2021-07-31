#include "Color.hpp"

Color::Color(ubyte r, ubyte g, ubyte b, ubyte a) 
: m_r(r), m_g(g), m_b(b), m_a(a)
{}

ubyte Color::getR() const { return m_r; }
ubyte Color::getG() const { return m_g; }
ubyte Color::getB() const { return m_b; }
ubyte Color::getA() const { return m_a; } 

Color::~Color() {}