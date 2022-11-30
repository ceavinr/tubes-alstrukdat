#ifndef HANGMAN_H
#define HANGMAN_H
#include "../../boolean.h"
#include "../../adt/mesin/mesinkarakter.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/arraydin/arraydin.h"
#include "../../adt/word/word.h"
#include "../../adt/string/string.h"

char *kata_random();

int isWin(char *kata);

int play();

void saveDict(ArrayDin arr, FILE *pita);

void tambahKata();

void hangman(int *score);

#endif