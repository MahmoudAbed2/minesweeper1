#include "Game.h"

int main() {
    Game game(6, 6, 5);  // Create a Minesweeper game with a 6x6 board and 5 mines
    game.start();        // Start the game
    return 0;
}
