#include "arraydin.h"

int main() {
    printf("\nMake Arraydin\n");
    ArrayDin array = MakeArrayDin();
    PrintArrayDin(array);

    printf("\nInsert First elemen Word = \"AKU\" \n");
    Word satu = stringToWord("AKU");
    InsertFirst(&array, satu);
    PrintArrayDin(array);

    printf("\nInsert Last elemen Word = \"BAIK\" \n");
    Word dua = stringToWord("BAIK");
    InsertLast(&array, dua);
    PrintArrayDin(array);

    printf("\nInsert At elemen indeks ke-1 Word = \"ANAK\" \n");
    Word tiga = stringToWord("ANAK");
    InsertAt(&array, tiga, 1);
    PrintArrayDin(array);

    printf("\nCek IsEmpty dan Length\n");
    if (IsEmpty(array)) {
        printf("aku KOSONG\n");
    } else {
        printf("aku TIDAK KOSONG panjangku %d elemen\n", Length(array));
    }

    printf("\nCek IsMember\n");
    if (IsMember(array, satu))
    {
        printf("benar dia adalah bagianku\n");
    } else {
        printf("dia bukan bagianku\n");
    }
    
    Word empat = stringToWord("DI SAYANG");
    InsertLast(&array, empat);

    Word lima = stringToWord("MAMA PAPA");
    InsertLast(&array, lima);

    printf("\nDelete First elemen\n");
    PrintArrayDin(array);
    printf("jadi ini nih...\n");
    DeleteFirst(&array);
    PrintArrayDin(array);
    
    printf("\nDelete At elemen indeks ke-1\n");
    PrintArrayDin(array);
    printf("jadi ini nih...\n");
    DeleteAt(&array, 1);
    PrintArrayDin(array);

    printf("\nDelete Last elemen\n");
    PrintArrayDin(array);
    printf("jadi ini nih...\n");
    DeleteLast(&array);
    PrintArrayDin(array);

    return 0;
}