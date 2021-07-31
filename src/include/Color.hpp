#pragma once

#include <SDL2/SDL.h>
#include "Types.hpp"

class Color {
public:
    Color(ubyte r=255, ubyte g=255, ubyte b=255, ubyte a=255);
    ubyte getR() const;
    ubyte getG() const;
    ubyte getB() const;
    ubyte getA() const;
    ~Color();

private:
    ubyte m_r, m_g, m_b, m_a;
};