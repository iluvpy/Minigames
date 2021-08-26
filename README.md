# Minigames
some simple minigames written in C++ with sdl2

## State
in development <br>
![Markdown Logo](https://img.shields.io/badge/state-development-red)
![Markdown Logo](https://img.shields.io/badge/build-unstable-red)
![Markdown Logo](https://tokei.rs/b1/github/iluvpy/Minigames)

## Dependencies
- sdl2
- sdl2_ttf
- sdl2_image
- ninja (only linux  and mac)
- clang (only linux and mac)

## Compilation

### Arch based OS
run `sudo pacman -S sdl2 sdl2_ttf sdl2_image ninja clang`

### Debian based OS
run `sudo apt install libsdl2-dev libsdl2-ttf-dev libsdl2-image-2.0-0-dev ninja clang`

### Windows (NOT WORKING)
install Mingw on your windows machine. Then download the static .lib files of the needed libraries <br>
from their websites: <br>
- Download the development libraries from https://www.libsdl.org/download-2.0.php for sdl2 
- Download the development libraries from https://www.libsdl.org/projects/SDL_ttf/ for sdl2-ttf 
- Download the development libraries from https://www.libsdl.org/projects/SDL_image/ for sdl2-image 
then place the .lib files into `Minigames/lib/` and the .h files into `Minigames/src/include/SDL/`
after that you should be able to run this command: <br>
`g++ ./src/*.cpp -o client -std=c++17 -O2 -Werror -Wall -I./src/include/ -L./lib/ -lSDL2 -lSDL2_image -lSDL2_ttf`