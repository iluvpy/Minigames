#pragma once

#include <vector>

#include "Structs.hpp"

class SnakeGame;

class SnakeFood {
public:
    void AddNewRandomFood(SnakeGame *game);
    void AddFoodToGame(SnakeGame *game);
    bool NewFoodIfEaten(SnakeGame *game);

private:
    Point m_foodPosition;
    
};