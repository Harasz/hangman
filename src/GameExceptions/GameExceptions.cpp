//
// Created by Jakub on 02-12-2019.
//

#include "GameExceptions.h"
#include <string>
#include <exception>

// WordsWrongPathException
WordsWrongPathException::WordsWrongPathException(const std::string &path) : path(path) {}

const char *WordsWrongPathException::what() const noexcept {
    std::string info{"Nie można odczytać pliku zawierającego słowa. Plik: "};
    info.append(this->path);
    return info.c_str();
}


const char *LevelOutOfRange::what() const noexcept {
    return "Poziomy gry spoza zakresu. Poziom gry -> [0,2]";
}

const char *UnexpectedInput::what() const noexcept {
    return "Nie można obsłużyć znaku wejścia.";
}

const char *AttemptOutOfRange::what() const noexcept {
    return "Ilość prób gry spoza zakresu.";
}
