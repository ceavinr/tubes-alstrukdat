#include <stdio.h>
#include "listdp.h"

int main(){
    ListDP L;
    CreateEmptyDP (&L);
    addressDP P1=AlokasiDP (1);
    addressDP P2=AlokasiDP (2);
    addressDP P3=AlokasiDP (3);
    addressDP Q,P;
    P1->Pos=MakePOINT(0,0);
    P2->Pos=MakePOINT(1,1);
    P3->Pos=MakePOINT(2,2);
    InsertLastDP(&L,P1);
    InsertLastDP(&L,P2);
    InsertLastDP(&L,P3);
    Q=SearchPointDP(L,2,2);
    TulisPOINT(Q->Pos);
    DelBeforeDP(&L,P,Q);
    DelFirstDP(&L,P);
    DelLastDP(&L,P);
    if (IsEmptyDP(L)){
        printf("ListDP L kosong\n");
    }else{
        printf("ListDP L tidak kosong\n");
    }
    return 0;
}