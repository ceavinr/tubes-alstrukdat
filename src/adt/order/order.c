#include <stdio.h>
#include <stdlib.h>
#include "order.h"

void CreateOrder(Order *o)
{
    IDX_HEAD(*o) = IDX_UNDEF;
    IDX_TAIL(*o) = IDX_UNDEF;
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

void addOrder(Order *o, Masakan val)
{
    if (isEmpty(*o))
    {
        IDX_HEAD(*o) = 0;
    }

    IDX_TAIL(*o) += 1;
    copyMasakan(&TAIL(*o), val);
}

void deleteOrder(Order *o, Masakan *val)
{
    copyMasakan(val, HEAD(*o));
    if (orderLength(*o) == 1)
    {
        IDX_HEAD(*o) = IDX_UNDEF;
    }
    else
    {
        for (int i = IDX_HEAD(*o); i < IDX_TAIL(*o); i++)
        {
            copyMasakan(&ORDERELMT(*o, i), ORDERELMT(*o, i + 1));
        }
    }
    IDX_TAIL(*o) -= 1;
}

int indexOfOrder(Order o, KeyType key)
{
    Masakan m_del;
    int i = 0;
    boolean found = false;

    while (!isEmpty(o) && !found)
    {
        deleteOrder(&o, &m_del);
        if (NOMOR(m_del) == key)
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

Masakan findOrder(Order o, KeyType key)
{
    return ORDERELMT(o, indexOfOrder(o, key));
}

boolean isIn(Order o, KeyType key)
{
    return indexOfOrder(o, key) != IDX_UNDEF;
}
