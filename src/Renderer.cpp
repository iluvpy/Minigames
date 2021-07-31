#include "Renderer.hpp"

Renderer::Renderer() {}

void Renderer::Init(SDL_Window *window) {
    m_renderer = SDL_CreateRenderer(window, 0, 0);
}

void Renderer::Start() {
    SDL_RenderClear(m_renderer);
}

void Renderer::Fill(const Color& color, const Window *window) {
    SDL_SetRenderDrawColor(m_renderer, color.getR(), color.getG(), color.getB(), color.getA());
    SDL_Rect r = window->getWindowRect();
    SDL_RenderFillRect(m_renderer, &r);
}

void Renderer::SetColor(const Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.getR(), color.getG(), color.getB(), color.getA());
}

void Renderer::DrawRect(int x, int y, int w, int h) {

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