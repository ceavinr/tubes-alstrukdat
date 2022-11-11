#include "mesinkata.h"
#include <stdio.h>

int main()
{
    Word satu;
    printf("CEK BERDASARKAN INPUT: \n");
    startInputWord();
    printf("\nTes cek panjang WORD\n");
    printf("%d\n", currentWord.Length);
    printf("\nAkuisisi kata ke-1\n");
    akuisisiCommandWord(&satu, currentWord, 1);
    printf("Tes printWord\n");
    printWord(satu);
    printf("\n");

    printf("\nCEK BERDASARKAN FILE\n");
    STARTWORD("../data/default.txt");
    printWord(currentWord);
    while (!EOP)
    {
        ADVWORD();
        printf("\nCetak Current Word\n");
        printWord(currentWord);
    }
    
}