//
// Created by Jakub Sydor on 25-11-2019.
//

#include "Board.h"
#include <iostream>

void Board::show(char** rows) {
    /*
     * Create boundary for bord ratio:
     * A A A A A
     * A A A A A
     * A A A A A
     * A A A A A
     * */

    // Clear old screen
    std::system("cls");

    for (int y = 0; y < Board::sizeY; ++y) {
        for (int x = 0; x < Board::sizeX; ++x) {
            std::cout << rows[y][x];
        }
        std::cout << std::endl;
    }
}

void Board::show(char** rows, char** rows1, char** rows2) {
    /*
     * Create boundary for bord ratio:
     * A A A B B
     * A A A B B
     * C C C C C
     * C C C C C
     * */
    int boundaryX{((2 * Board::sizeX) / 3) - 1};
    int boundaryY{(Board::sizeY / 2) - 1};

    // Clear old screen
    std::system("cls");

    // Generate and print new screen
    for (int y = 0; y < Board::sizeY; ++y) {
        for (int x = 0; x < Board::sizeX; ++x) {
            if (x <= boundaryX && y <= boundaryY) { // Check if match A part
                std::cout << rows[y][x];
            } else if (x >= boundaryX && y <= boundaryY) { // Check if match B part
                std::cout << rows1[y][x - ((2 * Board::sizeX) / 3)];
            } else { // else for C part
                std::cout << rows2[y - (Board::sizeY / 2)][x];
            }
        }
        std::cout << std::endl;
    }
}
