#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rng.h"

/*I.S. Sembarang*/
/*F.S. RNG dijalankan dan menerima parameter output score*/
void rng(int *score)
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

    *score = 100 - count;

    printf("\nYa, X adalah %d.\n", x);
    printf("\nScore anda : %d.\n", *score);

}