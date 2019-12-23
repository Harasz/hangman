//
// Created by Jakub on 02-12-2019.
//

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "Words.h"
#include "../GameExceptions/GameExceptions.h"


void Words::loadWords(std::string &pathToWords) {
    try {
        std::ifstream readFile;
        readFile.open(pathToWords, std::ios::in);
        if (!readFile) {
            throw WordsWrongPathException(pathToWords);
        }

        Word word;
        std::string line;

        while (std::getline(readFile, line)) {
            if (line.length() < 4 || line.length() > 100 || line.find(',') == std::string::npos) {
                continue;
            } // Check if line is in correct format -> Category,Word

            word = wordSplit(line);

            if (word.word.length() > 55 || word.category.length() > 44) continue; // Check restriction for word and category length
            if (std::count(line.begin(), line.end(), ',') > 1) continue; // Check restriction for word and category allowed characters

            for (char i : word.word) {
                if (i > 122 || i < 32) goto next;
            } // Check restriction for word allowed characters

            for (char i : word.category) {
                if (i > 122 || i < 32) goto next;
            }  // Check restriction for category allowed characters

            if (word.word.length() < 8) { // Easy word length in range [1,7]
                this->words[Levels::Easy].push_back(line);
            } else if (word.word.length() < 16) { // Medium word length in range [8, 15]
                this->words[Levels::Medium].push_back(line);
            } else { // Hard word length in range [15,]
                this->words[Levels::Hard].push_back(line);
            }

            this->wordsCount++; // Increment words count variable
            next:;
        }

        readFile.close();
    } catch (const WordsWrongPathException &e) {
        std::cout << e.what() << std::endl;
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
