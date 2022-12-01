#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsListEmpty(List L)
{
    return First(L) == NULL;
}

void CreateEmpty(List *L)
{
    First(*L) = NULL;
}

address Alokasi(infotype X)
{
    address P;
    P = (ElmtList *)malloc(sizeof(ElmtList));
    if (P != NULL)
    {
        Info(P) = X;
        Next(P) = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}

void Dealokasi(address *P)
{
    free(*P);
}

address Search(List L, infotype X)
{
    address P = First(L);
    boolean found = false;

    while (P != NULL && !found)
    {
        if (Info(P) == X)
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
        return P;
    }
    else
    {
        return NULL;
    }
}

void InsVFirst(List *L, infotype X)
{
    address P = Alokasi(X);

    if (P != NULL)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List *L, infotype X)
{
    address P = Alokasi(X);

    if (P != NULL)
    {
        InsertLast(L, P);
    }
}

void DelVFirst(List *L, infotype *X)
{
    address P;
    DelFirst(L, &P);

    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{
    address P;

    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void InsertFirst(List *L, address P)
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, address P)
{

    if (IsListEmpty(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        address last = First(*L);
        while (Next(last) != NULL)
        {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}

void DelFirst(List *L, address *P)
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = NULL;
}

void DelP(List *L, infotype X)
{
    address P = Search(*L, X);

    if (P != NULL)
    {
        if (P == First(*L))
        {
            DelFirst(L, &P);
        }
        else
        {
            address prec = First(*L);
            while (Next(prec) != P)
            {
                prec = Next(prec);
            }
            DelAfter(L, &P, prec);
        }
    }
}

void DelLast(List *L, address *P)
{
    address last = First(*L);
    address prec = NULL;

    while (Next(last) != NULL)
    {
        prec = last;
        last = Next(last);
    }

    *P = last;
    if (prec == NULL)
    {
        First(*L) = NULL;
    }
    else
    {
        Next(prec) = NULL;
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    *Pdel = Next(Prec);
    if (Next(Prec) != NULL)
    {
        Next(Prec) = Next(Next(Prec));
        Next(*Pdel) = NULL;
    }
}

int NbElmt(List L)
{
    int banyak = 0;

    address P = First(L);

    while (P != NULL)
    {
        P = Next(P);
        banyak++;
    }
    return banyak;
}

infotype getElmt(List L, int idx)
{
    int ctr = 0;
    address p = First(L);

    while (ctr < idx)
    {
        p = Next(p);
        ctr++;
    }
    return Info(p);
}