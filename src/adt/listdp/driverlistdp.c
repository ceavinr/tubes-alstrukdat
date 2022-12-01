#include <stdio.h>
#include "listdp.h"

int main()
{
    ListDP L;
    CreateEmptyDP(&L);
    addressDP P1 = AlokasiDP(1);
    addressDP P2 = AlokasiDP(2);
    addressDP P3 = AlokasiDP(3);
    addressDP P4 = AlokasiDP(4);
    addressDP P5 = AlokasiDP(5);
    addressDP Q, P;

    P1->Pos = MakePOINT(0, 0);
    P2->Pos = MakePOINT(1, 1);
    P3->Pos = MakePOINT(2, 2);
    P4->Pos = MakePOINT(3, 3);
    P5->Pos = MakePOINT(4, 4);

    InsertFirstDP(&L, P1);
    InsertAfterDP(&L, P2, P1);
    InsertLastDP(&L, P4);
    InsertBeforeDP(&L, P3, P4);
    InsertLastDP(&L, P5);

    Q = SearchPointDP(L, Pos(P3));

    TulisPOINT(Q->Pos);

    printf("\n");

    if (IsEmptyDP(L))
    {
        printf("ListDP L kosong\n");
    }
    else
    {
        printf("ListDP L tidak kosong\n");
    }
    DelBeforeDP(&L, &P, Q);
    printf("%d\n", Info(P));
    DelAfterDP(&L, &P, Q);
    printf("%d\n", Info(P));
    DelFirstDP(&L, &P);
    printf("%d\n", Info(P));
    DelLastDP(&L, &P);
    printf("%d\n", Info(P));

    DelPDP(&L, Pos(P3));
    if (IsEmptyDP(L))
    {
        printf("ListDP L kosong\n");
    }
    else
    {
        printf("ListDP L tidak kosong\n");
    }
    DealokasiDP(&P);
    return 0;
}