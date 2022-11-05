#ifndef __WORD_H__
#define __WORD_H__

#include "../../adt/string/string.h"

#define NMax 50

typedef struct
{
    char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Word;

int wordToInt(Word w);
/*
 I.S word terdefinisi
 F.S dirubah ke integer dan dimasukkan ke dalan integer
*/

void printWord(Word w);
/*
 I.S word terdefinisi
 F.S menampilkan word
*/

Word stringToWord(char *string);

void CopyWord();

boolean stringEQWord(Word w, char *c);
/*Mengembalikan Nilai true jika string dengan tabword bernilai sama*/

#endif