#include "SnakeFood.hpp"
#include "Utils.hpp"
#include "SnakeGame.hpp"

void SnakeFood::AddNewRandomFood(SnakeGame *game) {
    Point position;
    ubyte tries = 0; // avoid getting trapped in an infinite loop
    do {
        position.x = Util::GetRandomInt(game->GetIndexWidth());
        position.y = Util::GetRandomInt(game->GetIndexHeight());
        tries++;
    } while (game->Get(position.x, position.y) != SnakeRectState::Grid && tries < 10);
    m_foodPosition = position;
}

void SnakeFood::AddFoodToGame(SnakeGame *game) {
    game->Set(m_foodPosition.x, m_foodPosition.y, SnakeRectState::Food);
}

bool SnakeFood::NewFoodIfEaten(SnakeGame *game) {
    if (game->Get(m_foodPosition.x, m_foodPosition.y) != SnakeRectState::Food) {
		AddNewRandomFood(game);
		return true;
	}
	return false;
} 
