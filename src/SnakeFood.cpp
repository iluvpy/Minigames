#include "SnakeFood.hpp"
#include "Utils.hpp"
#include "SnakeGame.hpp"

SnakeFood::SnakeFood()  {}

void SnakeFood::AddNewRandomFood(SnakeGame *game) {
    Point position;
    do {
        position.x = Util::GetRandomInt(game->GetIndexWidth()-1);
        position.y = Util::GetRandomInt(game->GetIndexHeight()-1);
    } while (game->Get(position.x, position.y) != SnakeRectState::None);
    m_foodPositions.push_back(position);
}

void SnakeFood::AddFoodToGame(SnakeGame *game) {
    for (const auto& pos : m_foodPositions) {
        game->Set(pos.x, pos.y, SnakeRectState::Food);
    }
}

bool SnakeFood::FoodWasEaten(SnakeGame *game) {
    for (const auto& pos : m_foodPositions) {
        if (game->Get(game->XtoXIndex(pos.x), game->YtoYIndex(pos.y)) == SnakeRectState::SnakeSection) {
            std::cout << "heyy \n";
            return true;
        }
    }
    return false;
} 

SnakeFood::~SnakeFood() {

}