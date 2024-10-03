#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Board::Board(int r, int c, int m) : rows(r), cols(c), mines(m) {
    cells = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols));
    placeMines();
    calculateAdjacentMines();
}

void Board::placeMines() {
    srand(static_cast<unsigned int>(time(0)));
    int placedMines = 0;
    while (placedMines < mines) {
        int row = rand() % rows;
        int col = rand() % cols;
        if (cells[row][col].hasMine) continue;
        cells[row][col].hasMine = true;
        placedMines++;
    }
}

void Board::calculateAdjacentMines() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (cells[r][c].hasMine) continue;
            int mineCount = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int newRow = r + i;
                    int newCol = c + j;
                    if (isValidCoord(newRow, newCol) && cells[newRow][newCol].hasMine) {
                        mineCount++;
                    }
                }
            }
            cells[r][c].adjacentMines = mineCount;
        }
    }
}

bool Board::isMine(int row, int col) const {
    return cells[row][col].hasMine;
}

int Board::getAdjacentMines(int row, int col) const {
    return cells[row][col].adjacentMines;
}

void Board::revealCell(int row, int col) {
    cells[row][col].revealed = true;
}

bool Board::isRevealed(int row, int col) const {
    return cells[row][col].revealed;
}

void Board::displayBoard() const {
    std::cout << "   ";
    for (int i = 0; i < cols; i++) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        std::cout << char('a' + i) << " ";
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].revealed) {
                if (cells[i][j].hasMine) {
                    std::cout << "* ";
                } else {
                    std::cout << cells[i][j].adjacentMines << " ";
                }
            } else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
}

bool Board::allSafeCellsRevealed() const {
    int revealedCount = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (cells[r][c].revealed && !cells[r][c].hasMine) {
                revealedCount++;
            }
        }
    }
    return revealedCount == (rows * cols - mines);
}

bool Board::isValidCoord(int row, int col) const {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}
