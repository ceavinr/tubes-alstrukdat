#include "stack.h"
#include <stdio.h>

int main()
{
    Stack S;
    boolean succeed;
    int penampung = 0;

    CreateStack(&S);

    if (IsStackEmpty(S))
    {
        printf("Stack kosong!\n");
        printf("Indeks top: %d\n", Top(S));
    }

    printf("Ngepush elemen tapi yang dimasukin elemennya lebih besar daripada InfoTop\n");

    Push(&S, 3, &succeed);
    Push(&S, 4, &succeed);
    if (succeed)
    {
        printf("Sukses!\n");
        printf("Indeks top: %d\n", Top(S));
        printf("Elemen top: %d\n", InfoTop(S));
    }
    else
    {
        printf("Gagal!\n");
    }

    printf("Ngepush elemen yang lebih kecil daripada InfoTop\n");
    Push(&S, 2, &succeed);

    if (succeed)
    {
        printf("Sukses!\n");
    }
    else
    {
        printf("Gagal!\n");
    }

    printf("Percobaan Pop\n");
    printf("Penampung sebelum pop: %d\n", penampung);
    printf("Index top sebelum pop: %d\n", Top(S));
    Pop(&S, &penampung, &succeed);
    printf("Penampung setelah pop: %d\n", penampung);
    printf("Index top setelah pop: %d\n", Top(S));

    printf("Percobaan proses tambahin elemen ke stack sampai full\n");
    CreateStack(&S);

    printf("...proses tambahin elemen ke stack sampai full\n");

    for (int i = MaxEl - 1; i >= 0; i--)
    {
        Push(&S, i, &succeed);
    }

    if (IsStackFull(S))
    {
        printf("Stacknya full gan\n");
    }

    return 0;
}