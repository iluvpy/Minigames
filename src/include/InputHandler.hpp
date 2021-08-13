#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>

#include "Types.hpp"
#include "Structs.hpp"

class InputHandler {
public:
    void PressKey(const SDL_Event& e);
    void ReleaseKey(const SDL_Event& e);
    void PressMouseButton(const SDL_Event& e);
    void ReleaseMouseButton(const SDL_Event& e);
    bool isPressed(const SDL_KeyCode& code);
    bool isReleased(const SDL_KeyCode& code);
    bool isMouseButtonPressed(ubyte button);
    bool isMouseButtonReleased(ubyte button);
    void SetMousePos(const Point& pos);
    Point GetMousePos();
private:
    std::unordered_map<int, bool> m_keys;
    std::unordered_map<ubyte, bool> m_buttons; // mouse
    Point m_mousePos;
};