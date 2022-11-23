#ifndef HANGMAN_H
#define HANGMAN_H
#include "../../boolean.h"
#include "../../adt/mesin/mesinkarakter.c"
#include "../../adt/mesin/mesinkata.c"
#include "../../adt/arraydin/arraydin.c"
#include "../../adt/word/word.c"
#include "../../adt/string/string.c"

char* kata_random();

int check(char* kata, char huruf);

int isWin(char* kata);

int play();

#endif