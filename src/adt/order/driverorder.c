#include "order.h"
#include <stdio.h>

int main()
{
    Order o;
    Masakan m;
    CreateOrder(&o);

    if (isEmpty(o))
    {
        printf("o kosong!\n");
    }

    for (int i = 0; i < ORDERCAPACITY; i++)
    {
        CreateMasakan(&m, i);
        addOrder(&o, m);
    }

    if (isFull(o))
    {
        printf("o nya full gan\n");
    }
    else
    {
        printf("o nya blom full gan\n");
    }

    deleteOrder(&o, &m);
    if (!isFull(o))
    {
        printf("o nya blom full gan, soalnya dah didelete\n");
    }

    addOrder(&o, m);

    if (isIn(o, NOMOR(m)))
    {
        printf("Harusnya ini order terakhir (indeks 24)\n");
        if (indexOfOrder(o, NOMOR(m)) == 24)
        {
            printf("Yak betul\n");
        }
    }

    printf("Harusnya ini order terakhir (indeks 24)\n");

    return 0;
}