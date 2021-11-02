#include "Window.hpp"

Window::Window() {
    m_isOpen = true;
}

void Window::Init(const std::string& name) {
    m_rect = {0, 0, 1280, 720};
    m_window = SDL_CreateWindow(name.c_str(), m_rect.x, m_rect.y, m_rect.w, m_rect.h, 0);
	SDL_GetWindowSize(m_window, &m_rect.x, &m_rect.y);
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

bool Window::IsOnWindow(const FPoint& point) {
	return point.x <= m_rect.w &&
		   point.x >= 0 &&
		   point.y <= m_rect.h &&
		   point.y >= 0;
}

bool Window::IsOnWindow(const Point& point) {
	return point.x <= m_rect.w &&
		   point.x >= 0 &&
		   point.y <= m_rect.h &&
		   point.y >= 0;
}


Window::~Window() {
    SDL_DestroyWindow(m_window);
}