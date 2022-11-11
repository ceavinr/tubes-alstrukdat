#include "mesinkata.h"
#include <stdio.h>

int main()
{
    Word satu, dua;
    printf("Tulis 2 kata kak: ");
    startInputWord();
    printf("Panjang kata total: %d\n", currentWord.Length);
    akuisisiCommandWord(&satu, currentWord, 1);
    akuisisiCommandWord(&dua, currentWord, 2);
    printWord(satu);
    printf("\nPanjang kata pertama: %d\n", satu.Length);
    printWord(dua);
    printf("\nPanjang kata kedua: %d\n", dua.Length);

    return 0;
}