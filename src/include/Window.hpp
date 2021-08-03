#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Types.hpp"

class Window {
public:
    Window();
    void Init(const std::string& name);
    ubyte Update();
    const SDL_Rect getWindowRect() const;
    bool isOpen() const;
    void Close();
    SDL_Event getEvent() const;
    SDL_Window *getWindowPtr();
    ~Window();
private:

    SDL_Window *m_window;
    SDL_Event m_events;
    bool m_isOpen;
    SDL_Rect m_rect;
};