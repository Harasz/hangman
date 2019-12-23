//
// Created by Jakub on 02-12-2019.
//

#ifndef HANGMAN_GAMEEXCEPTIONS_H
#define HANGMAN_GAMEEXCEPTIONS_H

#include <exception>
#include <string>

// WordsWrongPathException
class WordsWrongPathException : public std::exception {
private:
    const std::string &path;
public:
    explicit WordsWrongPathException(const std::string &path);

    const char *what() const noexcept override;
};

// LevelOutOfRange
class LevelOutOfRange : public std::exception {
public:
    const char *what() const noexcept override;
};

// BadInput
class UnexpectedInput : public std::exception {
public:
    const char *what() const noexcept override;
};


#endif //HANGMAN_GAMEEXCEPTIONS_H
