#include "Renderer.hpp"

Renderer::Renderer() {}

void Renderer::Init(SDL_Window *window) {
    m_renderer = SDL_CreateRenderer(window, 0, 0);
}

void Renderer::Start() {
    SDL_RenderClear(m_renderer);
}

void Renderer::Fill(const Color& color, const Window *window) {
    SDL_Rect r = window->getWindowRect();
    DrawRect(r, color);
}

void Renderer::SetColor(const Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.getR(), color.getG(), color.getB(), color.getA());
}

void Renderer::DrawRect(int x, int y, int w, int h, const Color& color) {
    SetColor(color);
    SDL_Rect r{x, y, w, h};
    SDL_RenderFillRect(m_renderer, &r);
}

void Renderer::DrawRect(const SDL_Rect& rect, const Color& color) {
    DrawRect(rect.x, rect.y, rect.w, rect.h, color);
}

void Renderer::End() {
    SDL_RenderPresent(m_renderer);
}

void Renderer::Quit() {
    this->~Renderer();
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}