#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Structs.hpp"
#include "Types.hpp"

class Window {
public:
    Window();
    void Init(const std::string& name);
    ubyte Update();
    const SDL_Rect GetWindowRect() const;
    bool isOpen() const;
    void Close();
    int GetWidth() const;
    int GetHeight() const;
    SDL_Event GetEvent() const;
    SDL_Window *GetWindowPtr();
	bool IsOnWindow(const FPoint& point);
	bool IsOnWindow(const Point& point);
    ~Window();
private:

    SDL_Window *m_window;
    SDL_Event m_events;
    bool m_isOpen;
    SDL_Rect m_rect;
};