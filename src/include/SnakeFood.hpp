#pragma once

#include <vector>

#include "Structs.hpp"

class SnakeGame;

class SnakeFood {
public:
    SnakeFood();
    void AddNewRandomFood(SnakeGame *game);
    void AddFoodToGame(SnakeGame *game);
    bool FoodWasEaten(SnakeGame *game);
    ~SnakeFood();

private:
    std::vector<Point> m_foodPositions;
    
};