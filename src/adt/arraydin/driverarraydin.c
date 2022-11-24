#include "arraydin.h"

int main() {
    printf("\nMake Arraydin\n");
    ArrayDin array = MakeArrayDin();
    PrintArrayDin(array, array.Neff);

    printf("\nInsert First elemen Word = \"AKU\" \n");
    Word satu = stringToWord("AKU");
    InsertFirstArrayDin(&array, satu);
    PrintArrayDin(array, array.Neff);

    printf("\nInsert Last elemen Word = \"BAIK\" \n");
    Word dua = stringToWord("BAIK");
    InsertLastArrayDin(&array, dua);
    PrintArrayDin(array, array.Neff);

    printf("\nInsert At elemen indeks ke-1 Word = \"ANAK\" \n");
    Word tiga = stringToWord("ANAK");
    InsertAtArrayDin(&array, tiga, 1);
    PrintArrayDin(array, array.Neff);

    printf("\nCek IsEmpty dan Length\n");
    if (IsEmptyArrayDin(array)) {
        printf("aku KOSONG\n");
    } else {
        printf("aku TIDAK KOSONG panjangku %d elemen\n", LengthArrayDin(array));
    }

    printf("\nCek IsMember\n");
    if (IsMemberArrayDin(array, satu))
    {
        printf("benar dia adalah bagianku\n");
    } else {
        printf("dia bukan bagianku\n");
    }
    
    Word empat = stringToWord("DI SAYANG");
    InsertLastArrayDin(&array, empat);

    Word lima = stringToWord("MAMA PAPA");
    InsertLastArrayDin(&array, lima);

    printf("\nDelete First elemen\n");
    PrintArrayDin(array, array.Neff);
    printf("jadi ini nih...\n");
    DeleteFirstArrayDin(&array);
    PrintArrayDin(array, array.Neff);
    
    printf("\nDelete At elemen indeks ke-1\n");
    PrintArrayDin(array, array.Neff);
    printf("jadi ini nih...\n");
    DeleteAtArrayDin(&array, 1);
    PrintArrayDin(array, array.Neff);

    printf("\nDelete Last elemen\n");
    PrintArrayDin(array, array.Neff);
    printf("jadi ini nih...\n");
    DeleteLastArrayDin(&array);
    PrintArrayDin(array, array.Neff);

    return 0;
}