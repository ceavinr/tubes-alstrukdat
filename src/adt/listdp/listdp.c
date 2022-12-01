#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

boolean IsEmptyDP(ListDP L)
{
    return (First(L) == NULL && Last(L) == NULL);
}

void CreateEmptyDP(ListDP *L)
{
    First(*L) = NULL;
    Last(*L) = NULL;
}

addressDP AlokasiDP(int X)
{
    ElmtListDP *P = NULL;
    P = (ElmtListDP *)malloc(sizeof(ElmtListDP));
    if (P != NULL)
    {
        Info(P) = X;
        Next(P) = NULL;
        Prev(P) = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}

void DealokasiDP(addressDP *P)
{
    free(*P);
}

addressDP SearchPointDP(ListDP L, POINT X)
{
    addressDP P = First(L);
    boolean found = false;
    while (P != NULL && !found)
    {
        if (EQ(Pos(P), X))
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    if (found)
    {
        return (P);
    }
    else
    {
        return NULL;
    }
}

void InsertFirstDP(ListDP *L, addressDP P)
{
    Next(P) = First(*L);
    if (!IsEmptyDP(*L))
    {
        Prev(Next(P)) = P;
    }
    else
    {
        Last(*L) = P;
    }
    First(*L) = P;
}

void InsertLastDP(ListDP *L, addressDP P)
{
    Next(P) = NULL;
    if (IsEmptyDP(*L))
    {
        First(*L) = P;
        Prev(P) = NULL;
        Last(*L) = P;
    }
    else
    {
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}

void InsertAfterDP(ListDP *L, addressDP P, addressDP Prec)
{
    if (Prec == Last(*L))
    {
        InsertLastDP(L, P);
    }
    else
    {
        Next(P) = Next(Prec);
        Prev(Next(P)) = P;
        Next(Prec) = P;
        Prev(P) = Prec;
    }
}

void InsertBeforeDP(ListDP *L, addressDP P, addressDP Succ)
{
    if (Succ == First(*L))
    {
        InsertFirstDP(L, P);
    }
    else
    {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
        Next(P) = Succ;
    }
}

void DelFirstDP(ListDP *L, addressDP *P)
{
    addressDP q = First(*L);
    *P = q;
    if (Next(q) == NULL)
    {
        CreateEmptyDP(L);
    }
    else
    {
        First(*L) = Next(q);
        Prev(First(*L)) = NULL;
    }
}

void DelLastDP(ListDP *L, addressDP *P)
{
    addressDP q = Last(*L);
    *P = q;
    if (Prev(q) == NULL)
    {
        CreateEmptyDP(L);
    }
    else
    {
        Next(Prev(q)) = NULL;
        Last(*L) = Prev(q);
    }
}

void DelPDP(ListDP *L, POINT X)
{
    addressDP P = SearchPointDP(*L, X);

    if (P != NULL)
    {
        if (P == First(*L))
        {
            DelFirstDP(L, &P);
        }
        else
        {
            addressDP prec = First(*L);
            while (Next(prec) != P)
            {
                prec = Next(prec);
            }
            DelAfterDP(L, &P, prec);
        }
        DealokasiDP(&P);
    }
}

void DelAfterDP(ListDP *L, addressDP *Pdel, addressDP Prec)
{
    *Pdel = Next(Prec);
    if (Next(Prec) != NULL)
    {
        if (Next(Next(Prec)) == NULL)
        {
            Last(*L) = Prec;
        }
        else
        {
            Prev(Next(*Pdel)) = Prec;
        }
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = NULL;
        Prev(*Pdel) = NULL;
    }
}

void DelBeforeDP(ListDP *L, addressDP *Pdel, addressDP Succ)
{
    *Pdel = Prev(Succ);
    addressDP Q = Last(*L);
    if (Prev(Succ) != NULL)
    {
        Prev(Succ) = Prev(Prev(Succ));
        if (Prev(Succ) == NULL)
        {
            First(*L) = Succ;
        }
        else
        {
            Next(Prev(Succ)) = Succ;
        }
    }
}
