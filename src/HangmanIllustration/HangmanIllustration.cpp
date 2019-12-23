//
// Created by Jakub Sydor on 25-11-2019.
//

#include <stdexcept>
#include <string>
#include "HangmanIllustration.h"


HangmanIllustration::HangmanIllustration(unsigned short attempt) {
    if (attempt > HangmanIllustration::illustrationCount) {
        throw std::invalid_argument("Number of attempts is out of range");
    }
    this->attempt = attempt;
    this->illustrations = HangmanIllustration::loadIllustration();
}

void HangmanIllustration::increaseAttempt() {
    this->attempt++;
    if (this->attempt > HangmanIllustration::illustrationCount) {
        this->attempt = 0;
    }
}

char ***HangmanIllustration::loadIllustration() {
    // Initialize array from future illustrations
    char ***illustration = new char **[HangmanIllustration::illustrationCount];
    for (int i = 0; i < HangmanIllustration::illustrationCount; ++i) {
        illustration[i] = new char *[Board::sizeY / 2];
    }

    // Illustration #0 from file
    for (int j = 0; j < 9; ++j) {
        // Generate empty space
        illustration[0][j] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    }
    // Add some grass at bottom
    illustration[0][9] = new char[(2 * Board::sizeX) / 3]{static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177),
                                                          static_cast<char>(177), static_cast<char>(177)};


    // Illustration #1 from file
    for (int j = 0; j < 8; ++j) {
        // Generate empty space
        illustration[1][j] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    }
    // Add some grass at bottom
    illustration[1][8] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(205), static_cast<char>(202),
                                                          static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(205), static_cast<char>(205), ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' '};
    // Add some grass at bottom
    illustration[1][9] = illustration[0][9];


    // Illustration #2 from file
    illustration[2][0] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(201), ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int j = 1; j < 8; ++j) {
        // Generate empty space
        illustration[2][j] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(186), ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    }
    // Add some grass at bottom
    illustration[2][8] = illustration[1][8];
    // Add some grass at bottom
    illustration[2][9] = illustration[1][9];


    // Illustration #3 from file
    illustration[3][0] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(201),
                                                          static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(205), static_cast<char>(205),
                                                          static_cast<char>(187), ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' '};
    for (int j = 1; j < 8; ++j) {
        // Generate empty space
        illustration[3][j] = illustration[2][j];
    }
    // Add some grass at bottom
    illustration[3][8] = illustration[2][8];
    // Add some grass at bottom
    illustration[3][9] = illustration[2][9];


    // Illustration #4 from file
    illustration[4][0] = illustration[3][0];
    illustration[4][1] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(186), ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          static_cast<char>(194), ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' '};
    illustration[4][2] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(186), ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          static_cast<char>(218), static_cast<char>(179),
                                                          static_cast<char>(191), ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int j = 3; j < 8; ++j) {
        // Generate empty space
        illustration[4][j] = illustration[3][j];
    }
    // Add some grass at bottom
    illustration[4][8] = illustration[2][8];
    // Add some grass at bottom
    illustration[4][9] = illustration[2][9];

    // Illustration #5 from file
    illustration[5][0] = illustration[4][0];
    illustration[5][1] = illustration[4][1];
    illustration[5][2] = illustration[4][2];
    illustration[5][3] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(186), ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          static_cast<char>(192), static_cast<char>(153),
                                                          static_cast<char>(217), ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    illustration[5][4] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(186), ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          static_cast<char>(47), static_cast<char>(179),
                                                          static_cast<char>(92), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int j = 5; j < 8; ++j) {
        // Generate empty space
        illustration[5][j] = illustration[3][j];
    }
    // Add some grass at bottom
    illustration[5][8] = illustration[2][8];
    // Add some grass at bottom
    illustration[5][9] = illustration[2][9];

    // Illustration #6 from file
    illustration[6][0] = illustration[4][0];
    illustration[6][1] = illustration[4][1];
    illustration[6][2] = illustration[4][2];
    illustration[6][3] = illustration[5][3];
    illustration[6][4] = illustration[5][4];
    illustration[6][5] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(186), ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          static_cast<char>(47), ' ', static_cast<char>(179), ' ',
                                                          static_cast<char>(92), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    illustration[6][6] = new char[(2 * Board::sizeX) / 3]{' ', ' ', ' ', ' ', ' ', ' ', static_cast<char>(186), ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          static_cast<char>(47), ' ', static_cast<char>(92), ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                                          ' ', ' ', ' ', ' ', ' '};
    illustration[6][7] = illustration[3][7];
    // Add some grass at bottom
    illustration[6][8] = illustration[2][8];
    // Add some grass at bottom
    illustration[6][9] = illustration[2][9];

    return illustration;
}

char **HangmanIllustration::getIllustration() {
    return this->illustrations[this->attempt];
}

char **HangmanIllustration::getIllustration(unsigned short attemptCustom) {
    if (attemptCustom > HangmanIllustration::illustrationCount) {
        throw std::invalid_argument("Number of attempts is out of range");
    }
    return this->illustrations[attemptCustom];
}

unsigned short HangmanIllustration::getAttempt() {
    return this->attempt;
}

void HangmanIllustration::resetAttempt() {
    this->attempt = 0;
}
