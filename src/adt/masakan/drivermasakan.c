#include "masakan.h"
#include <stdio.h>

int main()
{
    Masakan m, m1;

    CreateMasakanRandom(&m, 0);
    printf("Harusnya sih nomor 0\n");
    printf("%d\n", NOMOR(m));

    CreateMasakanRandom(&m1, 2);
    printf("Harusnya sih nomor 2\n");
    printf("%d\n", NOMOR(m1));

    copyMasakan(&m1, m);
    printf("Habis dicopy m ke m1 harusnya mereka jadi sama\n");
    if (NOMOR(m1) == NOMOR(m))
    {
        printf("Tuh kan sama\n");
    }

    return 0;
}