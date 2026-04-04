#include "Game.h"
#include "game_title.h"
#include <iostream>

int main() {
    std::cout << GAME_TITLE << std::endl;
    Game game;
    game.startGame();
    return 0;
}