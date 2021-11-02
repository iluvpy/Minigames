#pragma once

#include <vector>
#include "Window.hpp"
#include "Renderer.hpp"
#include "Structs.hpp"

#define ASTEROID_BULLET_SPEED 350
#define ASTEROID_BULLET_WIDTH 5

class Bullet{
public: 
	Bullet(const FPoint& pos, float angle);
	void Init(const FPoint& pos, float angle);
	void Update(Window *window, float deltaTime);
	void Draw(Renderer *renderer);
	bool ShouldDelete(); 
private:
	FPoint m_pos;
	float m_angle; // the direction it flies
	bool m_shouldDelete;
};

class AsteroidBullets {
public:

	void Init(Window *window);
	void AddBullet(const FPoint& pos, float angle);
	void Update(float deltaTime);
	void Draw(Renderer *renderer);

private:
	Window *m_window;
	std::vector<Bullet> m_bullets;
};