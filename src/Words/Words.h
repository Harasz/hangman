//
// Created by Jakub on 02-12-2019.
//

#ifndef HANGMAN_WORDS_H
#define HANGMAN_WORDS_H

#include <string>
#include <vector>

enum Levels {
    Easy = 0,
    Medium = 1,
    Hard = 2,
};

struct Word {
    std::string word;
    std::string category;
};

class Words {
public:
    unsigned int wordsCount{0};

    // Functions
    std::string *getWordByLevel(Levels levels);

    Word getRandomWordSplit(Levels levels);

    static Word wordSplit(std::string word);

    void loadWords(std::string &pathToWords);

    static char extendAscii(char character);

private:
    // Vars
    std::vector<std::string> words[3];
};

#endif //HANGMAN_WORDS_H
