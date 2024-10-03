#ifndef CELL_H
#define CELL_H

struct Cell {
    bool hasMine = false;
    int adjacentMines = 0;
    bool revealed = false;
};

#endif
