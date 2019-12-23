//
// Created by Jakub Sydor on 28-11-2019.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <conio.h>
#include <string>
#include "GameHangman.h"
#include "../GameExceptions/GameExceptions.h"
#include "../Helpers/Helpers.h"

GameHangman::GameHangman(std::string &wordListPath) {
    GameHangman::welcomeScreen();
    this->words.loadWords(wordListPath);
}

void GameHangman::welcomeScreen() {
    // Clear screen
    system("cls");

    // Welcome message
    std::cout << "                         *                           *      " << std::endl;
    std::cout << "                         *                           *      " << std::endl;
    std::cout << "                         *                           *      " << std::endl;
    std::cout << "                         *                           *      " << std::endl;
    std::cout << "          *                                                 " << std::endl;
    std::cout << "       _   _            *               *                   " << std::endl;
    std::cout << "      | | | |                    *                          " << std::endl;
    std::cout << "      | |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __         " << std::endl;
    std::cout << R"(      |  _  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \     )" << std::endl;
    std::cout << "      | | | | (_| | | | | (_| | | | | | | (_| | | | |       " << std::endl;
    std::cout << R"(      \_| |_/\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|    )" << std::endl;
    std::cout << "                          __/ |                             " << std::endl;
    std::cout << "      *                  |___/    by Jakub Sydor            " << std::endl;
    std::cout << "               *                  (c) 2019           *      " << std::endl;
    std::cout << "                                            *               " << std::endl;
    std::cout << "                                            *               " << std::endl;
    std::cout << "                                            *               " << std::endl;
    std::cout << "                                            *               " << std::endl;
    std::cout << "                                            *               " << std::endl;
    std::cout << "                                            *               " << std::endl;

    std::cout << static_cast<char>(157) << "adowanie zasob" << static_cast<char>(162) << "w";
    std::cout << std::endl;

    // Sleep thread for 2s
    std::this_thread::sleep_for(std::chrono_literals::operator ""s(.3));
}

void GameHangman::startMenu() {
    // AddSome color to console
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clear console
    system("cls");

    SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < 60; ++i) {
        std::cout << static_cast<char>(177);
    }
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "       _   _                                              ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | | | |                                             ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __       ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << R"(      |  _  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \      )";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | | | | (_| | | | | (_| | | | | | | (_| | | | |     ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << R"(      \_| |_/\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|     )";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                          __/ |                           ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                         |___/    by Jakub Sydor          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                  (c) 2019                ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                                          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                 ";
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << " Game Menu ";
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << "                  ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                                          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                  [P] - Start Game                        ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                  [Q] - Quit                              ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    for (int i = 0; i < 60; ++i) {
        std::cout << static_cast<char>(177);
    }
    SetConsoleTextAttribute(hConsole, 15);

    const char allowedInput[]{'p', 'q'};
    char userInput = GameHangman::getUserInput(&allowedInput[0]);

    switch (userInput) {
        case 'p':
            return this->getLevel();
        case 'q':
            return;
        default:
            throw UnexpectedInput();
    }
}

void GameHangman::getLevel() {
    // AddSome color to console
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clear console
    system("cls");

    SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < 60; ++i) {
        std::cout << static_cast<char>(177);
    }
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "       _   _                                              ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | | | |                                             ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __       ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << R"(      |  _  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \      )";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | | | | (_| | | | | (_| | | | | | | (_| | | | |     ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << R"(      \_| |_/\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|     )";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                          __/ |                           ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                         |___/    by Jakub Sydor          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                  (c) 2019                ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                                          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                ";
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << " Choose level ";
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << "                ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                                          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                  [1] - Easy                              ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                  [2] - Medium                            ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                  [3] - Hard                              ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                  [B] - Back to main menu                 ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    for (int i = 0; i < 60; ++i) {
        std::cout << static_cast<char>(177);
    }
    SetConsoleTextAttribute(hConsole, 15);

    const char allowedInput[]{'1', '2', '3', 'b'};
    char userInput = GameHangman::getUserInput(&allowedInput[0]);

    switch (userInput) {
        case '1':
            this->level = Levels::Easy;
            break;
        case '2':
            this->level = Levels::Medium;
            break;
        case '3':
            this->level = Levels::Hard;
            break;
        case 'b':
            return this->startMenu();
        default:
            throw UnexpectedInput();
    }

    return this->startGame();
}

char GameHangman::getUserInput(const char *allowedChars) {
    int keyboardInput{0}, i{0};

    while (true) {
        keyboardInput = _getch();

        if (keyboardInput >= 'A' && keyboardInput <= 'Z') {
            keyboardInput += 'a' - 'A';
        }

        while (*(allowedChars + i)) {
            if (*(allowedChars + i) == keyboardInput) {
                return *(allowedChars + i);
            }
            i++;
        }
        i = 0;
    }
}

char GameHangman::getUserInput(int from, int to, const char *allowedChars) {
    int keyboardInput{0}, i{0};

    while (true) {
        keyboardInput = _getch();

        if (keyboardInput >= 'A' && keyboardInput <= 'Z') {
            keyboardInput += 'a' - 'A';
        }

        if (keyboardInput >= from && keyboardInput <= to) {
            return static_cast<char>(keyboardInput);
        }

        while (*(allowedChars + i)) {
            if (*(allowedChars + i) == keyboardInput) {
                return *(allowedChars + i);
            }
            i++;
        }
        i = 0;
    }
}

void GameHangman::startGame() {
    int chosenLetterCount{0};
    Word drawnWord = this->words.getRandomWordSplit(this->level);
    const char allowedInput[]{static_cast<char>(134), static_cast<char>(136), static_cast<char>(162),
                              static_cast<char>(165), static_cast<char>(169), static_cast<char>(243),
                              static_cast<char>(190), static_cast<char>(228), static_cast<char>(152)};
    char chosenLetter[32]{};
    char **boardChosenLetter, **boardInputPanel, *drawnWordCstr, guessedCurrent;

    drawnWordCstr = const_cast<char *>(drawnWord.word.c_str());
    boardChosenLetter = GameHangman::showChosen(chosenLetter, chosenLetterCount);
    boardInputPanel = this->showInputPanel(&drawnWord, chosenLetter);
    Board::show(this->illustration.getIllustration(), boardChosenLetter, boardInputPanel);

    while (true) {
        guessedCurrent = getUserInput(97, 122, allowedInput);

        if (!Helpers::isInArray(chosenLetter, guessedCurrent, chosenLetterCount)) {
            chosenLetter[chosenLetterCount] = guessedCurrent;
            chosenLetterCount++;
        }

        this->attempts++;
        if (!Helpers::isInArray(drawnWordCstr, guessedCurrent, drawnWord.word.length())) {
            this->illustration.increaseAttempt();
        }

        if (this->checkIfEnd(chosenLetter, drawnWordCstr)) {
            break;
        }

        boardChosenLetter = GameHangman::showChosen(chosenLetter, chosenLetterCount);
        boardInputPanel = this->showInputPanel(&drawnWord, chosenLetter);
        Board::show(this->illustration.getIllustration(), boardChosenLetter, boardInputPanel);
    }

    boardChosenLetter = GameHangman::showChosen(chosenLetter, chosenLetterCount);
    boardInputPanel = this->showInputPanel(&drawnWord, chosenLetter, true, this->illustration.getAttempt() < 7);
    Board::show(this->illustration.getIllustration(), boardChosenLetter, boardInputPanel);

    delete[] boardChosenLetter;
    delete[] boardInputPanel;

    this->endGame();
}

char **GameHangman::showChosen(const char letters[32], int lettersCount) {
    int letterIncrement{0};
    char **result = new char *[Board::sizeY / 2];
    result[0] = new char[Board::sizeX / 3]{'U', static_cast<char>(190), 'y', 't', 'e', ' ', 'l', 'i', 't', 'e', 'r',
                                           'y', ':', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    for (int i = 1; i < (Board::sizeY / 2); ++i) {
        result[i] = new char[Board::sizeX / 3];
        for (int j = 0; j < Board::sizeX / 3; j += 3) {
            if (letterIncrement <= lettersCount) {
                result[i][j] = letters[letterIncrement];
                if (letterIncrement == lettersCount) {
                    result[i][j + 1] = ' ';
                } else {
                    result[i][j + 1] = ',';
                }
                result[i][j + 2] = ' ';
                letterIncrement++;
            } else {
                result[i][j] = ' ';
                result[i][j + 1] = ' ';
                result[i][j + 2] = ' ';
            }
        }
    }
    return result;
}

char **GameHangman::showInputPanel(Word *word, char chosenLetter[32], bool end, bool winner) {
    char **result = new char *[Board::sizeY / 2];
    for (unsigned int i = 1; i < (Board::sizeY / 2) - 1; ++i) {
        result[i] = new char[Board::sizeX];
    }

    // Print Category Name
    const unsigned int categoryTitleLength{11};
    result[0] = new char[Board::sizeX]{'K', 'a', 't', 'e', 'g', 'o', 'r', 'i', 'a', ':', ' '};
    for (unsigned int j = categoryTitleLength; j < Board::sizeX - categoryTitleLength; ++j) {
        if (j - categoryTitleLength < word->category.length()) {
            result[0][j] = word->category[j - categoryTitleLength];
        } else {
            result[0][j] = ' ';
        }
    }

    // Print Word
    unsigned int yBoundary{((Board::sizeY - 2) / 2) / 2};
    unsigned int xBoundary{(Board::sizeX) / 2};
    unsigned int wordIterator{0};

    for (unsigned int k = 1; k < (Board::sizeY / 2) - 1; ++k) {
        for (unsigned int i = 0; i < Board::sizeX; i += 2) {
            if (yBoundary == k) {
                if (wordIterator < word->word.length() && i >= xBoundary - (word->word.length()) &&
                    i <= xBoundary + (word->word.length())) {
                    if (Helpers::isInArray(chosenLetter, word->word[wordIterator])) {
                        result[k][i] = word->word[wordIterator];
                    } else {
                        result[k][i] = word->word[wordIterator] == ' ' ? ' ' : '_';
                    }
                    wordIterator++;
                } else {
                    result[k][i] = ' ';
                }
            } else {
                result[k][i] = ' ';
            }
            result[k][i + 1] = ' ';
        }
    }


    if (end) {
        int posY{0};
        int posX{(Board::sizeY / 4) + 1};

        if (winner) {
            posY = 25;
            result[posX][++posY] = 'W';
            result[posX][++posY] = 'Y';
            result[posX][++posY] = 'G';
            result[posX][++posY] = 'R';
            result[posX][++posY] = 'A';
            result[posX][++posY] = 'N';
            result[posX][++posY] = 'A';
            result[posX][++posY] = '!';
        } else {
            posY = 24;
            result[posX][++posY] = 'P';
            result[posX][++posY] = 'R';
            result[posX][++posY] = 'Z';
            result[posX][++posY] = 'E';
            result[posX][++posY] = 'G';
            result[posX][++posY] = 'R';
            result[posX][++posY] = 'A';
            result[posX][++posY] = 'N';
            result[posX][++posY] = 'A';
            result[posX][++posY] = '!';
        }

        posX += 1;
        posY = 17;

        result[posX][++posY] = 'E';
        result[posX][++posY] = 'N';
        result[posX][++posY] = 'T';
        result[posX][++posY] = 'E';
        result[posX][++posY] = 'R';
        result[posX][++posY] = ',';
        result[posX][++posY] = ' ';
        result[posX][++posY] = 'a';
        result[posX][++posY] = 'b';
        result[posX][++posY] = 'y';
        result[posX][++posY] = ' ';
        result[posX][++posY] = 'p';
        result[posX][++posY] = 'r';
        result[posX][++posY] = 'z';
        result[posX][++posY] = 'e';
        result[posX][++posY] = 'j';
        result[posX][++posY] = static_cast<char>(152);
        result[posX][++posY] = static_cast<char>(134);
        result[posX][++posY] = ' ';
        result[posX][++posY] = 'd';
        result[posX][++posY] = 'a';
        result[posX][++posY] = 'l';
        result[posX][++posY] = 'e';
        result[posX][++posY] = 'j';
    }

    // Print Attempts count
    const char *tempAttempt = std::to_string(this->attempts).c_str();
    result[(Board::sizeY / 2) - 1] = new char[Board::sizeX]{'P', 'r', static_cast<char>(162), 'b', 'a', ':', ' '};
    for (unsigned int l = 0; l < std::to_string(this->attempts).length(); ++l) {
        result[(Board::sizeY / 2) - 1][7 + l] = tempAttempt[l];
    }

    return result;
}

bool GameHangman::checkIfEnd(const char *chosenLetters, const char *wordLetters) {
    if (this->illustration.getAttempt() >= 7) {
        return true;
    }

    int i{0};
    while (*(wordLetters + i)) {
        if (!Helpers::isInArray(chosenLetters, *(wordLetters + i)) && *(wordLetters + i) != ' ') return false;
        i++;
    }
    return true;
}

void GameHangman::endGame() {
    _getch();

    // AddSome color to console
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clear console
    system("cls");

    SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < 60; ++i) {
        std::cout << static_cast<char>(177);
    }
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "       _   _                                              ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | | | |                                             ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __       ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << R"(      |  _  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \      )";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "      | | | | (_| | | | | (_| | | | | | | (_| | | | |     ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << R"(      \_| |_/\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|     )";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                          __/ |                           ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                         |___/    by Jakub Sydor          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                  (c) 2019                ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                                          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                 ";
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << " Tw";
    std::cout << static_cast<char>(162);
    std::cout << "j wynik ";
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << static_cast<char>(177);
    std::cout << "                 ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                                                          ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                       Ilo";
    std::cout << static_cast<char>(152);
    std::cout << static_cast<char>(134);
    std::cout << " pr";
    std::cout << static_cast<char>(162);
    std::cout << "b: ";
    std::cout << this->attempts;
    std::cout << "                     ";
    if (this->attempts < 10) {
        std::cout << " ";
    }
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                      Ilo";
    std::cout << static_cast<char>(152);
    std::cout << static_cast<char>(134);
    std::cout << " b";
    std::cout << static_cast<char>(136);
    std::cout << static_cast<char>(169);
    std::cout << "d";
    std::cout << static_cast<char>(162);
    std::cout << "w: ";
    std::cout << this->illustration.getAttempt();
    std::cout << "                     ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "                  [B] - Back to main menu                 ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << static_cast<char>(177) << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    std::cout << static_cast<char>(177);
    std::cout << "                                                          ";
    std::cout << static_cast<char>(177);
    std::cout << std::endl;
    for (int i = 0; i < 60; ++i) {
        std::cout << static_cast<char>(177);
    }
    SetConsoleTextAttribute(hConsole, 15);

    this->resetGame();

    const char allowedInput[]{'b'};
    char userInput = GameHangman::getUserInput(&allowedInput[0]);

    if (userInput == 'b') {
        this->startMenu();
        return;
    } else {
        throw UnexpectedInput();
    }
}

void GameHangman::resetGame() {
    this->attempts = 0;
    this->illustration.resetAttempt();
}
