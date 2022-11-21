#include "masakan.h"
#include "../mesin/mesinkata.h"
#include <stdio.h>

int main()
{
    Masakan m, m1;

    printf("Masukan nama masakan 1: ");
    startInputWord();
    CreateMasakanRandom(&m, 0);
    NAMA(m) = wordToString(currentWord);

    printf("Harusnya sih nomor 0\n");
    printf("Nomor masakan: %d\n", NOMOR(m));

    m1 = CreateMasakan();
    printf("Masukan nama masakan 2: ");
    startInputWord();
    NAMA(m1) = wordToString(currentWord);

    printf("\nSebelum dicopy:\n");
    DisplayMasakan(m);
    printf("\n");
    DisplayMasakan(m1);

    copyMasakan(&m1, m);
    printf("\nSetelah dicopy:\n");
    DisplayMasakan(m);
    printf("\n");
    DisplayMasakan(m1);
    printf("\n");

    return 0;
}