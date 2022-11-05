#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rng.h"

/*Fungsi untuk memulai game rng*/
void rng()
{
    int x, tebakan;
    Word input;
    boolean check;

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
    }

    printf("\nYa, X adalah %d.\n", x);
}