//
// Created by Jakub on 02-12-2019.
//

#include "Words.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <chrono>
#include "../GameExceptions/GameExceptions.h"


void Words::loadWords(std::string &pathToWords) {
    try {
        std::ifstream readFile;
        readFile.open(pathToWords, std::ios::in);
        if (!readFile) {
            throw WordsWrongPathException(pathToWords);
        }

        int wordLength;
        std::string line;

        while (std::getline(readFile, line)) {
            if (line.length() < 4 || line.find(',') == std::string::npos) {
                continue;
            } // Check if line is in correct format -> Category,Word

            wordLength = wordSplit(line).word.length();

            if (wordLength < 8) { // Easy word length in range [1,7]
                this->words[Levels::Easy].push_back(line);
            } else if (wordLength < 16) { // Medium word length in range [8, 15]
                this->words[Levels::Medium].push_back(line);
            } else { // Hard word length in range [15,]
                this->words[Levels::Hard].push_back(line);
            }

            this->wordsCount++; // Increment words count variable
        }

        readFile.close();
        //return this->wordsCount;
    } catch (const WordsWrongPathException &e) {
        std::cout << e.what() << std::endl;
        //return 0;
    }
}

Word Words::wordSplit(std::string word) {
    Word result{};
    std::string temp;

    for (char &it : word) {
        if (it == ' ') it = '-';
        if (it == ',') it = ' ';
    } // Change  character ',' to ' ' in entire &word

    std::stringstream stringStream(word);

    for (int i = 0; i < 2; ++i) {
        stringStream >> temp;
        for (char &it : temp) {
            if (it == '-') it = ' ';
        } // Change  character '-' to ' ' in entire &word
        switch (i) {
            case 0:
                result.category = temp;
                break;
            case 1:
                result.word = temp;
                break;
            default:
                break;
        }
    }

    return result;
}

std::string *Words::getWordByLevel(Levels level) {
    if (level < Levels::Easy || level > Levels::Hard) {
        throw LevelOutOfRange();
    }

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int> distribution(0, this->words[level].size() - 1);

    return &this->words[level][distribution(generator)];
}

Word Words::getRandomWordSplit(Levels levels) {
    std::string word{*this->getWordByLevel(levels)};
    return this->wordSplit(word);
}

char Words::extendAscii(char character) {
    switch (character) {
        case -71:
            return static_cast<char>(165);
        case -65:
            return static_cast<char>(190);
        case -97:
            return static_cast<char>(171);
        case -26:
            return static_cast<char>(134);
        case -15:
            return static_cast<char>(228);
        case -22:
            return static_cast<char>(169);
        case -77:
            return static_cast<char>(136);
        case -13:
            return static_cast<char>(162);
        case -100:
            return static_cast<char>(152);
        case -91:
            return static_cast<char>(164);
        case -81:
            return static_cast<char>(189);
        case -113:
            return static_cast<char>(141);
        case -58:
            return static_cast<char>(143);
        case -47:
            return static_cast<char>(227);
        case -54:
            return static_cast<char>(168);
        case -93:
            return static_cast<char>(157);
        case -45:
            return static_cast<char>(224);
        case -116:
            return static_cast<char>(151);
        default:
            return character;
    }
}
