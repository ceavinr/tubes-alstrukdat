#include <stdio.h>
#include "array.h"
#include <stdlib.h>

void ArMakeEmpty(Array *T)
{
    (*T).Neff = 0;
}

int ArNbElmt(Array T)
{
    return ((T).Neff);
}

int ArMaxNbEl(Array T)
{
    return (IdxMax);
}

IdxType ArGetFirstIdx(Array T)
{
    return (IdxMin);
}

IdxType ArGetLastIdx(Array T)
{
    return ArNbElmt(T);
}

ArElType ArGetElmt(Array T, IdxType i)
{
    return T.TI[i];
}

void ArSetTab(Array Tin, Array *Tout)
{
    int i;
    for (i = IdxMin; i <= IdxMax; i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
    (*Tout).Neff = Tin.Neff;
}

void ArSetEl(Array *T, IdxType i, ArElType v)
{
    (*T).TI[i] = v;
    if (i == ArGetLastIdx(*T) + 1)
    {
        (*T).Neff++;
    }
}

void ArSetNeff(Array *T, IdxType N)
{
    (*T).Neff = N;
}

boolean ArIsIdxValid(Array T, IdxType i)
{
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean ArIsIdxEff(Array T, IdxType i)
{
    return ((i >= ArGetFirstIdx(T)) && (i <= ArGetLastIdx(T)));
}

boolean ArIsEmpty(Array T)
{
    return (ArNbElmt(T) == 0);
}

boolean ArIsFull(Array T)
{
    return (ArNbElmt(T) == ArMaxNbEl(T));
}

void ArTulisIsi(Array T)
{
    if (ArIsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        int i;
        for (i = ArGetFirstIdx(T); i <= ArGetLastIdx(T); i++)
        {
            printf("%d:%d\n", i, T.TI[i]);
        }
    }
}

Array ArPlusTab(Array T1, Array T2)
{
    Array Tsum;
    ArMakeEmpty(&Tsum);
    Tsum.Neff = T1.Neff;
    for (int i = ArGetFirstIdx(T1); i <= ArGetLastIdx(T1); i++)
    {
        ArSetEl(&Tsum, i, ArGetElmt(T1, i) + ArGetElmt(T2, i));
    }
    return Tsum;
}

Array ArMinusTab(Array T1, Array T2)
{
    Array Tmin;
    ArMakeEmpty(&Tmin);
    Tmin.Neff = T1.Neff;
    for (int i = ArGetFirstIdx(T1); i <= ArGetLastIdx(T1); i++)
    {
        ArSetEl(&Tmin, i, ArGetElmt(T1, i) - ArGetElmt(T2, i));
    }
    return Tmin;
}

ArElType ArValMax(Array T)
{
    ArElType max;
    int i;
    max = T.TI[ArGetFirstIdx(T)];
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (max < T.TI[i])
        {
            max = T.TI[i];
        }
    }

    return max;
}

ArElType ArValMin(Array T)
{
    ArElType min;
    int i;
    min = T.TI[ArGetFirstIdx(T)];
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (min > T.TI[i])
        {
            min = T.TI[i];
        }
    }

    return min;
}

IdxType ArIdxMaxTab(Array T)
{
    int i;
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (T.TI[i] == ArValMax(T))
        {
            return i;
        }
    }
}

IdxType ArIdxMinTab(Array T)
{
    int i;
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (T.TI[i] == ArValMin(T))
        {
            return i;
        }
    }
}
