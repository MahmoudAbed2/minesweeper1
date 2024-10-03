#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"

class Board {
private:
    int rows, cols, mines;
    std::vector<std::vector<Cell>> cells;

public:
    Board(int r, int c, int m);
    void placeMines();
    void calculateAdjacentMines();
    bool isMine(int row, int col) const;
    int getAdjacentMines(int row, int col) const;
    void revealCell(int row, int col);
    bool isRevealed(int row, int col) const;
    void displayBoard() const;
    bool allSafeCellsRevealed() const;
    
    // Make isValidCoord public
    bool isValidCoord(int row, int col) const; 
};

#endif
