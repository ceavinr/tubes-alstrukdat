#include <stdio.h>
#include "point.h"

int main(){
    POINT P=MakePOINT(0,1);
    TulisPOINT(P);
    POINT Q=MakePOINT(1,0);
    TulisPOINT(Q);
    printf("Point P dan Q");
    if (EQ(P,Q)){
        printf("sama\n");
    }else{
        printf("tidak sama\n");
    }
    return 0;
}