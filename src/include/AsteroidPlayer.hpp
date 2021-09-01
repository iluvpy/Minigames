#pragma once

#include "Window.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "Timer.hpp"

class AsteroidPlayer {
public:
	void Init(Window *window);
	void Update(Timer *timer);
	void Draw(Rendere *renderer);
private:
	Window *m_window;

};