#include "matrix.h"
#include <stdio.h>

int main()
{
    Matrix m;
    char huruf = 'a';
    CreateMatrix(&m, 1, 3);
    printf("Jumlah row: %d\n", ROWS(m));
    printf("Jumlah col: %d\n", COLS(m));

    for (int i = 0; i < count(m); i++)
    {
        if (i % COLS(m) == 0)
        {
            printf("\n");
        }
        printf("%c, ", huruf);
        MATRIXELMT(m, i / COLS(m), i % COLS(m)) = huruf;
        huruf++;
    }

    printf("\n\n");

    for (int i = 0; i < ROWS(m); i++)
    {
        for (int j = 0; j < COLS(m); j++)
        {
            printf("%c, ", MATRIXELMT(m, i, j));
        }
        printf("\n");
    }

    return 0;
}