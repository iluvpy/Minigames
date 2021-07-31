#include "Window.hpp"

Window::Window() {
    m_isOpen = true;
}

void Window::Init(const std::string& name) {
    m_rect = {0, 0, 1920, 1080};
    m_window = SDL_CreateWindow(name.c_str(), m_rect.x, m_rect.y, m_rect.w, m_rect.h, SDL_WINDOW_FULLSCREEN);
}

const SDL_Rect Window::getWindowRect() const {
    return m_rect;
}

ubyte Window::Update() {
    return (ubyte)SDL_PollEvent(&m_events);
}

void Window::Quit() {
    this->~Window();
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
}