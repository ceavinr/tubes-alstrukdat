#include "mesinkata.h"
#include <stdio.h>

int main()
{
    Word masakan, command, satu;
    startInputWord();
    printf("%d\n", currentWord.Length);
    // akuisisiCommandWord(&command, currentWord, 1);
    // akuisisiCommandWord(&masakan, currentWord, 2);
    akuisisiCommandWord(&satu, currentWord, 3);
    // printWord(command);
    // printf("\n%d\n", command.Length);
    // printWord(masakan);
    // printf("\n%d\n", masakan.Length);
    printWord(satu);
    printf("\n%d\n", satu.Length);
}