cmake_minimum_required(VERSION 3.15)
project(Hangman)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Hangman src/main.cpp
        src/Board/Board.cpp src/Board/Board.h
        src/HangmanIllustration/HangmanIllustration.cpp src/HangmanIllustration/HangmanIllustration.h
)