#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>


class InputHandler {
public:
    InputHandler();
    void Press(SDL_Event e);
    void Release(SDL_Event e);
    bool isPressed(SDL_KeyCode code);
    bool isReleased(SDL_KeyCode code);
    ~InputHandler();
private:
    std::unordered_map<int, bool> m_keys;
    std::unordered_map<int, bool> m_buttons; // mouse
};