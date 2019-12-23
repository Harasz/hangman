cmake_minimum_required(VERSION 3.15)
project(Hangman)

set(Hangman_VERSION "1.0.0")
set(Hangman_HOMEPAGE_URL "https://github.com/Harasz/hangman")
set(IDI_ICON1 ICON DISCARDABLE "Icon.ico")
set(CMAKE_CXX_FLAGS_RELEASE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(
        Hangman src/main.cpp
        src/Board/Board.cpp src/Board/Board.h
        src/HangmanIllustration/HangmanIllustration.cpp src/HangmanIllustration/HangmanIllustration.h
        src/GameLogic/GameHangman.cpp src/GameLogic/GameHangman.h
        src/Words/Words.cpp src/Words/Words.h
        src/GameExceptions/GameExceptions.cpp src/GameExceptions/GameExceptions.h
        src/Helpers/Helpers.cpp src/Helpers/Helpers.h
        Icon.ico
)

file(COPY words.txt DESTINATION /)
