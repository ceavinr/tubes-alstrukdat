#include <stdlib.h>
#include "primitif.h"

boolean stringEQ(char* c1, char* c2) {
/*Mengembalikan Nilai true jika string bernilai sama*/
    boolean eq = true;
    while (*c2 != '\0' && eq) {
        if (*c1 != *c2) {
            eq = false;
        } else {
            c1++;
            c2++;
        }
    }
    return eq;
}

int strlength(char* string) {
/*Mengembalikan panjang string*/
    int length = 0;
    while (*string != '\0') {
        length++;
        *string++;
    }
    return length;
}

char* concat(char* s1, char* s2) {
/*Mengembalikan string berupa gabungan dari s1 dan s2*/
    char* ret = malloc((strlength(s1) + strlength(s2) + 1) * sizeof(char));
    char* p = ret;
    while (*s1 != '\0') {
        *p++ = *s1++;
    }
    while (*s2 != '\0') {
        *p++ = *s2++;
    }
    *p = '\0';
    return ret;
}