#include "Window.hpp"

Window::Window() {
    m_isOpen = true;
}

void Window::Init(const std::string& name) {
    m_rect = {0, 0, 1920, 1080};
    m_window = SDL_CreateWindow(name.c_str(), m_rect.x, m_rect.y, m_rect.w, m_rect.h, SDL_WINDOW_FULLSCREEN);
}

const SDL_Rect Window::GetWindowRect() const {
    return m_rect;
}


bool Window::isOpen() const { 
    return m_isOpen; 
}
void Window::Close() { 
    m_isOpen = false; 
}
SDL_Event Window::GetEvent() const { 
    return m_events; 
}

SDL_Window *Window::GetWindowPtr() { 
    return m_window; 
} 

ubyte Window::Update() {
    return (ubyte)SDL_PollEvent(&m_events);
}
int Window::GetWidth() const {
    return m_rect.w;
}
int Window::GetHeight() const {
    return m_rect.h;
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
}