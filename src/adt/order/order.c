#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "order.h"

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

boolean isEmpty(Order o)
{
    return (IDX_HEAD(o) == IDX_UNDEF) && (IDX_TAIL(o) == IDX_UNDEF);
}

boolean isFull(Order o)
{
    return (IDX_TAIL(o) == ORDERCAPACITY - 1);
}

int orderLength(Order o)
{
    return IDX_TAIL(o) + 1;
}

/* *** Primitif Add/Delete *** */
void addOrder(Order *o, Masakan val)
{
    int i = orderLength(*o);
    boolean stop = false;

    if (isEmpty(*o))
    {
        IDX_HEAD(*o) = 0;
    }
    else
    {
        while (i != IDX_HEAD(*o) && !stop)
        {
            if (NOMOR(val) >= NOMOR(ORDERELMT(*o, i - 1)))
            {
                stop = true;
            }
            else
            {
                copyMasakan(&ORDERELMT(*o, i), ORDERELMT(*o, i - 1));
                i--;
            }
        }
    }
    copyMasakan(&ORDERELMT(*o, i), val);
    IDX_TAIL(*o) += 1;
}

void deleteOrderAt(Order *o, Masakan *val, KeyType key)
{
    copyMasakan(val, find(*o, key));
    if (orderLength(*o) == 1)
    {
        IDX_HEAD(*o) = IDX_UNDEF;
        IDX_TAIL(*o) = IDX_UNDEF;
    }
    else
    {
        for (int i = indexOf(*o, key); i < IDX_TAIL(*o); i++)
        {
            copyMasakan(&ORDERELMT(*o, i), ORDERELMT(*o, i + 1));
        }
        IDX_TAIL(*o) -= 1;
    }
}

int indexOf(Order o, KeyType key)
{
    int i = 0;
    boolean found = false;
    while (i <= IDX_TAIL(o) && !found)
    {
        if (NOMOR(ORDERELMT(o, i)) == key)
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

Masakan find(Order o, KeyType key)
{
    return ORDERELMT(o, indexOf(o, key));
}

boolean isIn(Order o, KeyType key)
{
    return indexOf(o, key) != IDX_UNDEF;
}

void copyMasakan(Masakan *m, Masakan val)
{
    NOMOR(*m) = NOMOR(val);
    DURASI(*m) = DURASI(val);
    KETAHANAN(*m) = KETAHANAN(val);
    HARGA(*m) = HARGA(val);
}
