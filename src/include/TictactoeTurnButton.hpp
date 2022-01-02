#pragma once

#include "InputHandler.hpp"
#include "Renderer.hpp"
#include "GUIImage.hpp"

#define TTTT_BUTTON_OUTLINE_WIDTH 10
#define TTTT_BUTTON_OUTLINE_COLOR Color(81, 82, 84)
enum TurnButton : char {
    CIRLCE,
    X
};

class TictactoeTurnButton {
public:
    void Init(int x, int y, TurnButton button_type, Renderer *renderer, Color backgroundColor);
    void Update(InputHandler *input);
    void Draw();

private:

    GUIImage m_image;
    GUIRect m_outlineRect;
    GUIRect m_backgroundRect;
    Renderer *m_renderer;
    bool m_focused;

};