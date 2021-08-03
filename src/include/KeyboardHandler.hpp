#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>


class KeyboardHandler {
public:
    KeyboardHandler();
    void Press(SDL_Event e);
    void Release(SDL_Event e);
    bool isPressed(SDL_KeyCode code);
    bool isReleased(SDL_KeyCode code);
    ~KeyboardHandler();
private:
    std::unordered_map<int, bool> m_keys;
};