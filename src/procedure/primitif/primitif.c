#include "primitif.h"

boolean stringEQ(char* c1, char* c2) {
/*Mengembalikan Nilai true jika string bernilai sama*/
    boolean eq = true;
    while (*c1 != '\0' && eq) {
        if (*c1 != *c2) {
            eq = false;
        } else {
            c1++;
            c2++;
        }
    }
    return eq;
}