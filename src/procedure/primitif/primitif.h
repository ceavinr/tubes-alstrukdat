#ifndef __PRIMITIF__
#define __PRIMITIF__

#include "../../boolean.h"

boolean stringEQ(char* c1, char* c2);
/*Mengembalikan Nilai true jika string bernilai sama*/

int strlength(char* string);
/*Mengembalikan panjang string*/

char* concat(char* s1, char* s2);
/*Mengembalikan string berupa gabungan dari s1 dan s2*/

#endif