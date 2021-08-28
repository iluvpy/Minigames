#pragma once

#include "Structs.hpp"
#include "Color.hpp"

// forward declaration
class Renderer;

class GUIRect {
public:
    GUIRect(float x = 0, float y = 0, float w = 0, float h = 0, const Color& color = Color());
    void Init(float x = 0, float y = 0, float w = 0, float h = 0, const Color& color = Color());
    void Draw(Renderer *renderer);
    void SetColor(const Color& color);
    float GetX() const;   
    float GetY() const;
    float GetW() const;
    float GetH() const;
	void SetX(float x);   
    void SetY(float y);
    void SetW(float w);
    void SetH(float h);
	FRect GetRect() const;
    bool IsOntop(const Point& pos);
    Color GetColor() const;
    ~GUIRect();
private:
    FRect m_rect;
    Color m_color;
};