#include "order.h"
#include <stdio.h>

int main()
{
    Order o;
    Masakan m;
    CreateOrder(&o);
    for (int i = 2; i >= 0; i--)
    {
        CreateMasakan(&m, i);
        addOrder(&o, m);
    }
    displayOrder(o);

    printf("%d\n", DURASI(ELMT(o, find(o, 1))));

    return 0;
}