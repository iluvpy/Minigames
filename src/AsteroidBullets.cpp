#include "AsteroidBullets.hpp"


void AsteroidBullets::Init(Window *window) {
	m_window = window;
}

void AsteroidBullets::AddBullet(const FPoint& pos, float angle) {
	Bullet bullet(pos, angle);
	m_bullets.push_back(bullet);
}

void AsteroidBullets::Update(float deltaTime) {
	auto it = m_bullets.begin();
	for (auto& bullet : m_bullets) {
		bullet.Update(m_window, deltaTime);
		if (bullet.ShouldDelete()) {
			m_bullets.erase(it);
			std::cout << "deleted bullet!!\n";
		}
		it++;
	}
}

void AsteroidBullets::Draw(Renderer *renderer) {
	for (auto& bullet : m_bullets) {
		bullet.Draw(renderer);
	}
}


Bullet::Bullet(const FPoint& pos, float angle) {
	Init(pos, angle);
}
void Bullet::Init(const FPoint& pos, float angle) {
	m_pos = pos;
	m_angle = angle;
	m_shouldDelete = false;
}
void Bullet::Update(Window *window, float deltaTime) {
	FPoint origin = m_pos;
	m_pos.x += deltaTime * ASTEROID_BULLET_SPEED;
	m_pos = Util::Rotate(m_pos, origin, Util::toRad(m_angle));

	m_shouldDelete = !window->IsOnWindow(m_pos);
}

void Bullet::Draw(Renderer *renderer) {
	renderer->DrawCircle(m_pos.x, m_pos.y, ASTEROID_BULLET_WIDTH);
}

bool Bullet::ShouldDelete() {
	return m_shouldDelete;
}