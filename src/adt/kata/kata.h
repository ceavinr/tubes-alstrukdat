#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"

#ifndef KATA_H
#define KATA_H

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
int panjangString(char *);

boolean isSame(char a[], char b[]);

int strlength(char* string);
/*Mengembalikan panjang string*/

char* concat(char* s1, char* s2);
/*Mengembalikan string berupa gabungan dari s1 dan s2*/


#endif