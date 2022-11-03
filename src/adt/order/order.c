#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "order.h"

/* *** Kreator *** */
void CreateOrder(Order *o)
{
    IDX_HEAD(*o) = IDX_UNDEF;
    IDX_TAIL(*o) = IDX_UNDEF;
}
void CreateMasakan(Masakan *m, int nomor)
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

/* ********* Prototype ********* */
boolean isEmpty(Order o)
{
    return (IDX_HEAD(o) == IDX_UNDEF) && (IDX_TAIL(o) == IDX_UNDEF);
}

boolean isFull(Order o)
{
    return (IDX_TAIL(o) == CAPACITY - 1);
}

int length(Order o)
{
    return IDX_TAIL(o) + 1;
}

/* *** Primitif Add/Delete *** */
void addOrder(Order *o, Masakan val)
{
    int i = length(*o);
    boolean stop = false;

    if (isEmpty(*o))
    {
        IDX_HEAD(*o) = 0;
    }
    else
    {
        while (i != IDX_HEAD(*o) && !stop)
        {
            if (NOMOR(val) >= NOMOR(ELMT(*o, i - 1)))
            {
                stop = true;
            }
            else
            {
                copyMasakan(&ELMT(*o, i), ELMT(*o, i - 1));
                i--;
            }
        }
    }
    copyMasakan(&ELMT(*o, i), val);
    IDX_TAIL(*o) += 1;
}

void deleteOrderAt(Order *o, Masakan *val, KeyType idx)
{
    copyMasakan(val, HEAD(*o));
    if (length(*o) == 1)
    {
        IDX_HEAD(*o) = IDX_UNDEF;
        IDX_TAIL(*o) = IDX_UNDEF;
    }
    else
    {
        for (int i = indexOf(*o, idx); i < IDX_TAIL(*o); i++)
        {
            copyMasakan(&ELMT(*o, i), ELMT(*o, i + 1));
        }
        IDX_TAIL(*o) -= 1;
    }
}

int indexOf(Order o, int val)
{
    int i = 0;
    boolean found = false;
    while (i <= IDX_TAIL(o) && !found)
    {
        if (NOMOR(ELMT(o, i)) == val)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (found)
    {
        return i;
    }
    else
    {
        return IDX_UNDEF;
    }
}

Masakan find(Order o, int val)
{
    return ELMT(o, indexOf(o, val));
}

boolean isIn(Order o, int val)
{
    return indexOf(o, val) != IDX_UNDEF;
}

void copyMasakan(Masakan *m, Masakan val)
{
    NOMOR(*m) = NOMOR(val);
    DURASI(*m) = DURASI(val);
    KETAHANAN(*m) = KETAHANAN(val);
    HARGA(*m) = HARGA(val);
}

void displayOrder(Order o)
{
    printf("Daftar Pesanan\n");
    printf("Makanan         | Durasi memasak        | Ketahanan     | Harga\n");
    printf("-----------------------------------------------------------------------\n");
    if (IDX_TAIL(o) != IDX_UNDEF)
    {
        for (int i = 0; i <= IDX_TAIL(o); i++)
        {
            printf("M%d              | %d                     | %d             | %d        \n", NOMOR(ELMT(o, i)), DURASI(ELMT(o, i)), KETAHANAN(ELMT(o, i)), HARGA(ELMT(o, i)));
        }
    }
    else
    {
        printf("                |                       |               |            ");
    }
}

void displayCooking(Order o)
{
    int count = 0;
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan         | Sisa durasi memasak\n");
    printf("-------------------------------------\n");

    for (int i = 0; i <= IDX_TAIL(o); i++)
    {
        if (DURASI(ELMT(o, i)) > 0)
        {
            printf("M%d              | %d           \n", NOMOR(ELMT(o, i)), DURASI(ELMT(o, i)));
            count++;
        }
    }
    if (count == 0)
    {
        printf("                |              \n");
    }
}

void displayReady(Order o)
{
    int count = 0;
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan         | Sisa ketahanan makanan\n");
    printf("----------------------------------------\n");

    for (int i = 0; i <= IDX_TAIL(o); i++)
    {
        if (DURASI(ELMT(o, i)) == 0 && KETAHANAN(ELMT(o, i)) > 0)
        {
            printf("M%d              | %d            \n", NOMOR(ELMT(o, i)), KETAHANAN(ELMT(o, i)));
            count++;
        }
    }

    if (count == 0)
    {
        printf("                |              \n");
    }
}