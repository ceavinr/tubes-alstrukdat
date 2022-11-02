#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>
#include "randomnumber.h"

void rng()
{
    int x,tebakan;
    boolean check;

    check = false;

    srand(time(NULL));

    x = rand()%101;
    printf("%d\n", x);

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    

    while (check == false)
    {
        printf("Tebakan: ");
        scanf("%d", &tebakan);

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