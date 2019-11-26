//
// Created by Jakub Sydor on 25-11-2019.
//

#ifndef HANGMAN_BOARD_H
#define HANGMAN_BOARD_H
#include <string>

class Board {
    public:
        static const int sizeX = 60;
        static const int sizeY = 20;
        static void show(char** rows);
        static void show(char** rows, char** rows1, char** rows2);
};

#endif //HANGMAN_BOARD_H
