#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "masakan.h"
#include "../string/string.h"

void CreateMasakanRandom(Masakan *m, int nomor)
{
    srand(time(NULL));

    NOMOR(*m) = nomor;
    NAMA(*m) = "";
    DURASI(*m) = rand() % 5 + 1;
    KETAHANAN(*m) = rand() % 5 + 1;
    HARGA(*m) = rand() % 50001;
    if (HARGA(*m) < 10000)
    {
        HARGA(*m) += 10000;
    }
}

Masakan CreateMasakan()
{
    Masakan m;
    NOMOR(m) = 0;
    NAMA(m) = "";
    DURASI(m) = 0;
    KETAHANAN(m) = 0;
    HARGA(m) = 0;

    return m;
}

void copyMasakan(Masakan *m, Masakan val)
{
    NOMOR(*m) = NOMOR(val);
    NAMA(*m) = NAMA(val);
    DURASI(*m) = DURASI(val);
    KETAHANAN(*m) = KETAHANAN(val);
    HARGA(*m) = HARGA(val);
}

void DisplayMasakan(Masakan m)
{
    printf("Nomor\t| Nama\t\t\t| Durasi\t| Ketahanan\t| Harga\t\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("%d\t|", NOMOR(m));
    if (stringLength(NAMA(m)) > 0)
    {
        if (stringLength(NAMA(m)) <= 8)
        {
            printf(" %s\t\t\t", NAMA(m));
        }
        else if (stringLength(NAMA(m)) <= 15)
        {
            printf(" %s\t\t", NAMA(m));
        }
        else
        {
            printf(" %s\t", NAMA(m));
        }
    }
    else
    {
        printf(" (Unknown)\t\t");
    }

    printf("| %d\t\t| %d\t\t| %d\t\n", DURASI(m), KETAHANAN(m), HARGA(m));
}