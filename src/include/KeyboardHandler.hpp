#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>


class KeyboardHandler {
public:
    KeyboardHandler();
    void Press(SDL_Event e);
    void Release(SDL_Event e);
    void isPressed(SDL_Event e);
    ~KeyboardHandler();
private:
    std::unordered_map<SDL_KeyCode, bool> pressed;
};