#include "Utils.hpp"

#include "SnakeGame.hpp"
#include "Snake.hpp"

void Util::Sleep(uint ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int64 Util::GetTimeMs() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


FPoint Util::Rotate(const FPoint& p, const FPoint& origin, float angle) {
	float _sin = sin(angle);
	float _cos = cos(angle);

	float ox = origin.x;
	float oy = origin.y;

	float x = p.x - ox;
	float y = p.y - oy;

	float new_x = x * _cos - y * _sin;
	float new_y = y * _cos + x * _sin;

	new_x += ox;
	new_y += oy;

	return FPoint{new_x, new_y};
}

float Util::toRad(float angle) {
	return M_PI / 180 * angle; 
}



Color Util::GetSnakeGridRectColor(const SnakeGridRect& rect) {
    switch (rect.state) {
        case SnakeRectState::Grid:
            return SNAKE_GRID_GRAY; // gray
        case SnakeRectState::Food:
            return SNAKE_GRID_APPLE_COLOR; // red
        case SnakeRectState::SnakeSection:
            return SNAKE_COLOR; // green
        case SnakeRectState::SnakeHead:
            return SNAKE_HEAD_COLOR;
        default:
            return Color(0, 0, 0);
    }
}

// returns clock1-clock2 in seconds
float Util::GetClockDifference(const Clock_t& clock1, const Clock_t& clock2) {
    return std::chrono::duration<float>(clock1-clock2).count();
}

int Util::GetRandomInt(int max, int min) { 
	return min + (rand() % static_cast<int>(max - min + 1)); 
}