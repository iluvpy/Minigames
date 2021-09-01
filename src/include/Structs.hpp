#pragma once

#include "Types.hpp"

enum CurrentGame : ubyte {
    SNAKEGAME,
    PONGGAME,
	ATEROIDGAME,
	NOGAME
};

enum Direction2d : ubyte {
    up,
    down,
    left,
    right
};

enum SnakeRectState : ubyte {
    Grid, // empty
    Food,
    SnakeSection, // part of snake
    SnakeHead
};

struct Point {
    int x, y;

    bool operator==(const Point& other) noexcept {
        return ((x == other.x) && (y == other.y));
    }

    Point& operator=(const Point& other) noexcept {
        x = other.x;
        y = other.y;
        return *this;
    }

    Point& operator+=(const Point& other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point& operator-=(const Point& other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Point operator+(const Point& other) noexcept {
        return Point{x+other.x, y+other.y}; 
    }

    Point operator-(const Point& other) noexcept {
        return Point{x-other.x, y-other.y}; 
    }
};


struct FPoint {
    float x, y;

    bool operator==(const FPoint& other) noexcept {
        return ((x == other.x) && (y == other.y));
    }

    FPoint& operator=(const FPoint& other) noexcept {
        x = other.x;
        y = other.y;
        return *this;
    }

    FPoint& operator+=(const FPoint& other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }

    FPoint& operator-=(const FPoint& other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    FPoint operator+(const FPoint& other) noexcept {
        return FPoint{x+other.x, y+other.y}; 
    }

    FPoint operator-(const FPoint& other) noexcept {
        return FPoint{x-other.x, y-other.y}; 
    }
};

struct Rect {
    int x, y, w, h;
};


struct FRect {
    float x, y, w, h;
};


struct SnakeGridRect {
    int x, y, w;
    SnakeRectState state;
};
