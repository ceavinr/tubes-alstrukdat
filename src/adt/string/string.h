#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"

#ifndef KATA_H
#define KATA_H

typedef char *string;

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
int stringLength(string s);

/*Mengembalikan string berupa gabungan dari s1 dan s2*/
string concat(string s1, string s2);

/* Mengembalikan sebuah string hasil salinan dari s2 */
string copyString(string s2);

/* Mereturn apakah c terdapat di dalam s */
boolean isCharInString(string s, char c);

#endif