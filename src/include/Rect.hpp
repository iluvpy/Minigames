#pragma once

#include "Structs.hpp"
#include "Color.hpp"

// forward declaration
class Renderer;

class Rect {
public:
    Rect(int x = 0, int y = 0, int w = 0, int h = 0, const Color& color = Color());
    void Init(int x = 0, int y = 0, int w = 0, int h = 0, const Color& color = Color());
    void Draw(Renderer *renderer);
    void SetColor(const Color& color);
    int GetX() const;   
    int GetY() const;
    int GetW() const;
    int GetH() const;
    bool IsOntop(const Point& pos);
    Color GetColor() const;
    ~Rect();
private:
    int m_x, m_y, m_w, m_h;
    Color m_color;
};