#include <stdio.h>
#include "point.h"
#include <math.h>

POINT MakePOINT(float X, float Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;

    return P;
};

void BacaPOINT(POINT *P)
{
    float x, y;

    scanf("%f %f\n", &x, &y);
    Absis(*P) = x;
    Ordinat(*P) = y;
};

void TulisPOINT(POINT P)
{
    float x, y;

    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
};

boolean EQ(POINT P1, POINT P2)
{
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
};

boolean NEQ(POINT P1, POINT P2)
{
    return !EQ(P1, P2);
};

boolean IsOrigin(POINT P)
{
    return Absis(P) == 0 && Ordinat(P) == 0;
};

boolean IsOnSbX(POINT P)
{
    return Ordinat(P) == 0;
};

boolean IsOnSbY(POINT P)
{
    return Absis(P) == 0;
};

int Kuadran(POINT P)
{
    if (Absis(P) < 0)
    {
        if (Ordinat(P) < 0)
        {
            return 3;
        }
        else if (Ordinat(P) > 0)
        {
            return 2;
        };
    }
    else if (Absis(P) > 0)
    {
        if (Ordinat(P) < 0)
        {
            return 4;
        }
        else if (Ordinat(P) > 0)
        {
            return 1;
        };
    };
};

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    POINT P1 = MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);

    return P1;
};

void Geser(POINT *P, float deltaX, float deltaY)
{
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
};

float Jarak0(POINT P)
{
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
};

float Panjang(POINT P1, POINT P2)
{
    float JarakXkuadrat = pow(Absis(P1) - Absis(P2), 2);
    float JarakYkuadrat = pow(Ordinat(P1) - Ordinat(P2), 2);

    return sqrt(JarakYkuadrat + JarakXkuadrat);
};