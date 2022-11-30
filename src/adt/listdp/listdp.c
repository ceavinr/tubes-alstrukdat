#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/****************** TEST LIST KOSONG ******************/

boolean IsEmptyDP(ListDP L)
{
    return (First(L)==NilDP && Last(L)==NilDP);
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/

addressDP SearchPointDP(ListDP L, int X,int Y)
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


/*** PENGHAPUSAN ELEMEN ***/



/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/


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

