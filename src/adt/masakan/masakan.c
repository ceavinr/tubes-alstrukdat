#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "masakan.h"

void CreateMasakanRandom(Masakan *m, int nomor)
{
    srand(time(NULL));

    NOMOR(*m) = nomor;
    DURASI(*m) = rand() % 5 + 1;
    KETAHANAN(*m) = rand() % 5 + 1;
    HARGA(*m) = rand() % 50001;
    if (HARGA(*m) < 10000)
    {
        HARGA(*m) += 10000;
    }
}

void copyMasakan(Masakan *m, Masakan val)
{
    NOMOR(*m) = NOMOR(val);
    DURASI(*m) = DURASI(val);
    KETAHANAN(*m) = KETAHANAN(val);
    HARGA(*m) = HARGA(val);
}
