#include <iostream>
#include <SDL2/SDL.h>

#include "Window.hpp"
#include "Program.hpp"


int main(int argc, char **argv) {
    Program p;
    p.Init("Minigames");
    p.Start();

    return 0;
}