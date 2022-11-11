#include "string.h"
#include <stdio.h>

int main() {
    char kata1[100], kata2[100];
    printf("Masukan kata 1: ");
    scanf("%s", kata1);
    printf("Masukan kata 2: ");
    scanf("%s", kata2);

    printf("\nPanjang kata ke-1 : %d\n", stringLength(kata1));
    printf("Panjang kata ke-2 : %d\n", stringLength(kata2));

    printf("\nHasil CONCAT %s dengan %s : ", kata1, kata2);
    printf("%s\n", concat(kata1, kata2));

    return 0;
}