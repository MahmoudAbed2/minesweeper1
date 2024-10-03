#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
private:
    Board board;
    bool gameOver;

public:
    Game(int rows, int cols, int mines);
    void start();
};

#endif
