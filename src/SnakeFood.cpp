#include "SnakeFood.hpp"
#include "Utils.hpp"
#include "SnakeGame.hpp"

SnakeFood::SnakeFood()  {}

void SnakeFood::AddNewRandomFood(SnakeGame *game) {
    Point position;
    ubyte tries = 0; // avoid getting trapped in an infinite loop
    do {
        position.x = Util::GetRandomInt(game->GetIndexWidth());
        position.y = Util::GetRandomInt(game->GetIndexHeight());
        tries++;
    } while (game->Get(position.x, position.y) != SnakeRectState::None && tries < 10);
    m_foodPositions.push_back(position);
}

void SnakeFood::AddFoodToGame(SnakeGame *game) {
    for (const auto& pos : m_foodPositions) {
        game->Set(pos.x, pos.y, SnakeRectState::Food);
    }
}

bool SnakeFood::FoodWasEaten(SnakeGame *game) {
    for (auto it = m_foodPositions.begin(); it != m_foodPositions.end(); it++) {
        if (game->Get(it->x, it->y) == SnakeRectState::SnakeSection) {
            m_foodPositions.erase(it);
            return true;
        }
    }
    return false;
} 

SnakeFood::~SnakeFood() {

}