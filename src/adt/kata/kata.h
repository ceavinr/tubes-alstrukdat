#include <stdio.h>
#include "../../boolean.h"

#ifndef KATA_H
#define KATA_H

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
int panjangString(char *);

boolean isSame(char a[], char b[]);

#endif