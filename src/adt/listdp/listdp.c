#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/****************** TEST LIST KOSONG ******************/

boolean IsEmptyDP(ListDP L)
{
    return (First(L) == NULL && Last(L) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/

void CreateEmptyDP(ListDP *L)
{
    First(*L) = NULL;
    Last(*L) = NULL;
}

/****************** Manajemen Memori ******************/

addressDP AlokasiDP(char X)
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
void DealokasiDP(addressDP P)
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/

addressDP SearchDP(ListDP L, char X)
{
    addressDP P = First(L);
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
        return (P);
    }
    else
    {
        return NULL;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/

void InsVFirstDP(ListDP *L, char X)
{
    addressDP P = AlokasiDP(X);
    if (P != NULL)
    {
        InsertFirstDP(L, P);
    }
}
void InsVLastDP(ListDP *L, char X)
{
    addressDP P = AlokasiDP(X);
    if (P != NULL)
    {
        InsertLastDP(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/

void DelVFirstDP(ListDP *L, char *X)
{
    addressDP P;
    DelFirstDP(L, &P);
    *X = Info(P);
    DealokasiDP(P);
}

void DelVLastDP(ListDP *L, char *X)
{
    addressDP P;
    DelLastDP(L, &P);
    *X = Info(P);
    DealokasiDP(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/

void InsertFirstDP(ListDP *L, addressDP P)
{
    Prev(P) = NULL;
    if (IsEmptyDP(*L))
    {
        Next(P) = NULL;
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
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
    Next(P) = Next(Prec);
    Next(Prec) = P;
    Prev(P) = Prec;
    if (Next(P) == NULL)
    {
        Last(*L) = P;
    }
    else
    {
        Prev(Next(Prec)) = P;
    }
}

void InsertBeforeDP(ListDP *L, addressDP P, addressDP Succ)
{
    Next(P) = Succ;
    Prev(P) = Prev(Succ);
    Prev(Succ) = P;
    if (Prev(P) != NULL)
    {
        Next(Prev(P)) = P;
    }
    else
    {
        First(*L) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/

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

void DelPDP(ListDP *L, char X)
{
    addressDP P = SearchDP(*L, X);
    addressDP Q = Last(*L);
    if (P == First(*L))
    {
        DelFirstDP(L, &P);
    }
    else if (P == Last(*L))
    {
        DelLastDP(L, &P);
    }
    else
    {
        while (Q != P)
        {
            Q->Pos.X = Prev(Q)->Pos.X;
            Q->Pos.Y = Prev(Q)->Pos.Y;
        }
        Next(Prev(P)) = Next(P);
        Prev(Next(P)) = Prev(P);
    }
    DealokasiDP(P);
}

void DelAfterDP(ListDP *L, addressDP *Pdel, addressDP Prec)
{
    *Pdel = Next(Prec);
    if (Next(Prec) != NULL)
    {
        Next(Prec) = Next(Next(Prec));
        if (Next(Prec) == NULL)
        {
            Last(*L) = Prec;
        }
        else
        {
            Prev(Next(Prec)) = Prec;
        }
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

/****************** PROSES SEMUA ELEMEN LIST ******************/

void PrintForwardDP(ListDP L)
{
    printf("[");
    if (!IsEmptyDP(L))
    {
        addressDP P = First(L);
        printf("%c", Info(P));
        P = Next(P);
        while ((P) != NULL)
        {
            printf(",%c", Info(P));
            P = Next(P);
        }
    }
    printf("]");
}

void PrintBackwardDP(ListDP L)
{
    printf("[");
    if (!IsEmptyDP(L))
    {
        addressDP P = Last(L);
        printf("%d", Info(P));
        P = Prev(P);
        while ((P) != NULL)
        {
            printf(",%d", Info(P));
            P = Prev(P);
        }
    }
    printf("]");
}
