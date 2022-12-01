#include <stdio.h>
#include "point.h"
#include <math.h>

POINT MakePOINT(int X, int Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;

    return P;
};

void TulisPOINT(POINT P)
{
    int x, y;

    printf("(%d,%d)", Absis(P), Ordinat(P));
};

boolean EQ(POINT P1, POINT P2)
{
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
};
