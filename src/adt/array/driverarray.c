#include "array.h"
#include <stdio.h>

int main()
{
    Array arr;
    Masakan m;

    CreateArray(&arr);

    if (IsArrayEmpty(arr))
    {
        printf("arr kosong!\n");
    }

    for (int i = 0; i < MaxArrayEl; i++)
    {
        CreateMasakan(&m, i);
        Insert(&arr, m);
    }

    if (IsArrayFull(arr))
    {
        printf("arr nya full gan\n");
    }
    else
    {
        printf("arr nya blom full gan\n");
    }

    DeleteArrayAt(&arr, &m, 0);
    if (!IsArrayFull(arr))
    {
        printf("arr nya blom full gan, soalnya dah didelete\n");
    }

    Insert(&arr, m);

    if (isMember(arr, NOMOR(m)))
    {
        printf("Indeks dari M%d adalah %d\n", NOMOR(m), indexOf(arr, NOMOR(m)));
    }
    if (isMember(arr, 2))
    {
        Masakan m_cari = find(arr, 2);
        printf("Indeks dari masakan yang dicari (M2) adalah %d\n", indexOf(arr, NOMOR(m_cari)));
    }

    return 0;
}