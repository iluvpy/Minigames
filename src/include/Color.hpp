#pragma once

#include <SDL2/SDL.h>
#include "Types.hpp"

class Color {
public:
    Color(ubyte r=255, ubyte g=255, ubyte b=255, ubyte a=255);
    inline SDL_Color getColor() const noexcept {return SDL_Color{m_r, m_g, m_b, m_a}; }
    inline ubyte getR() const { return m_r; }
    inline ubyte getG() const { return m_g; }
    inline ubyte getB() const { return m_b; }
    inline ubyte getA() const { return m_a; } 
    ~Color();

private:
    ubyte m_r, m_g, m_b, m_a;
};