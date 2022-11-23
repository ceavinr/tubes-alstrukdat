#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rng.h"

/*Fungsi untuk memulai game rng*/
int rng()
{
    int x, tebakan, count;
    Word input;
    boolean check;

    count = 0;
    check = false;

    srand(time(NULL));

    x = rand() % 101;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");

    while (check == false)
    {
        printf("Tebakan: ");

        startInputWord();
        akuisisiCommandWord(&input, currentWord, 1);
        tebakan = wordToInt(input);

        if (tebakan == x)
        {
            check = true;
        }
        else if (tebakan < x)
        {
            printf("Lebih besar\n");
        }
        else if (tebakan > x)
        {
            printf("Lebih kecil\n");
        }
        count++;
    }

    int score = 100 - count;

    printf("\nYa, X adalah %d.\n", x);
    return score;
}