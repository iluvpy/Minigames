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
    DrawRect(r.x, r.y, r.w, r.h, color);
}

void Renderer::SetColor(const Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.getR(), color.getG(), color.getB(), color.getA());
}

void Renderer::DrawRect(int x, int y, int w, int h, const Color& color) {
    SetColor(color);
    SDL_Rect r{x, y, w, h};
    SDL_RenderFillRect(m_renderer, &r);
}

void Renderer::DrawRect(const Rect& rect) {
    DrawRect(rect.GetX(), rect.GetY(), rect.GetW(), rect.GetH(), rect.GetColor());
}

void Renderer::End() {
    SDL_RenderPresent(m_renderer);
}


Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}