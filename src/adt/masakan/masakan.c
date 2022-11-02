#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "masakan.h"

/* *** Kreator *** */
void CreateMasakan(Masakan *m, int nomor)
{
    srand(time(NULL));

    NOMOR(*m) = nomor;
    DURASI(*m) = rand() % 5 + 1;
    KETAHANAN(*m) = rand() % 5 + 1;
    HARGA(*m) = rand() % 5001 + 10000;
}

/* ********* Prototype ********* */
boolean isFinished(Masakan m)
{
    return (DURASI(m) == 0);
}

/* *** Set *** */
void copyMasakan(Masakan *m, Masakan val)
{
    NOMOR(*m) = NOMOR(val);
    DURASI(*m) = DURASI(val);
    KETAHANAN(*m) = KETAHANAN(val);
    HARGA(*m) = HARGA(val);
}
