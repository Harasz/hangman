# Hangman
Hangman Game in console. To start we need a text file with categories and words.
File should look like this:

##### Words file
```text
Category,Word1
Category,Word2
Category2,Word3
...
```
We can enter as much word as we like, but we have some restrictions:
+ Allowed only character with ASCII decimal code between 32 and 122, excluded ',' character,
+ Maximum length of word is 55 characters,
+ Maximum length of category is 44 characters.

In repository, we have sample words file called “words.txt”, and this file name is used as default to use if we don't set other file name as first parameter.

##### Usage

```shell script
Hangman.exe
```

This will start the game with words from file "words.txt".


```shell script
Hangman.exe /path/to/other/new_words.txt
```
This will start the game with words from file "/path/to/other/new_words.txt".
