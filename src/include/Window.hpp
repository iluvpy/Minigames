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
    inline bool isOpen() const { return m_isOpen; }
    inline void Close() { m_isOpen = false; }
    inline uint getEvent() const { return m_events.type; }
    inline SDL_Window *getWindowPtr() { return m_window; } 
    void Quit();
    ~Window();
private:

    SDL_Window *m_window;
    SDL_Event m_events;
    bool m_isOpen;
    SDL_Rect m_rect;
};