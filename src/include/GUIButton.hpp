#pragma once

#include "Color.hpp"
#include "InputHandler.hpp"
#include "Renderer.hpp"

class GUIButton {
public:
    void Init(int x, int y, int w, int h);
    void Draw(Renderer *renderer);
    void Update(InputHandler *input);
private:

};