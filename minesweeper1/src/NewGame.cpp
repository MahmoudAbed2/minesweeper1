#include "Game.h"
#include <iostream>

Game::Game(int rows, int cols, int mines) : board(rows, cols, mines), gameOver(false) {}

void Game::start() {
    while (!gameOver) {
        board.displayBoard();
        std::string input;
        std::cout << "Ange ruta (t.ex. b2) att avslöja eller 'quit' för att avsluta: ";
        std::cin >> input;

        if (input == "quit") {
            std::cout << "Du har avslutat spelet. Tack för att du spelade!" << std::endl;
            break;
        }

        if (input.length() == 2) {
            int row = input[0] - 'a'; // Adjust as necessary
            int col = input[1] - '1'; // Adjust as necessary
            if (board.isValidCoord(row, col)) { // Use isCellValid if changed
                if (board.isMine(row, col)) {
                    std::cout << "Pang!! Du avslöjade en mina. Game Over!" << std::endl;
                    gameOver = true;
                } else {
                    board.revealCell(row, col);
                    if (board.allSafeCellsRevealed()) {
                        std::cout << "Grattis! Du har avslöjat alla säkra rutor. Du vinner!" << std::endl;
                        gameOver = true;
                    }
                }
            } else {
                std::cout << "Ogiltiga koordinater. Försök igen.\n";
            }
        } else {
            std::cout << "Ogiltig inmatning. Försök igen.\n";
        }
    }

    std::cout << "Spelet är över!\n";
}
