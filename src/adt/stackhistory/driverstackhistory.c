#include "stackhistory.h"
#include <stdio.h>

int main()
{
    StackHistory S;
    Word elemen;

    CreateStackHistory(&S);

    if (IsStackHistoryEmpty(S))
    {
        printf("Stack kosong!\n");
        printf("Indeks top: %d\n", Top(S));
    }

    printf("\nNgepush elemen :\n");
    startInputWord();
    PushHistory(&S, currentWord);

    printf("\nNgepush elemen :\n");
    startInputWord();
    PushHistory(&S, currentWord);
    PrintStackHistory(S, Top(S)+1);

    printf("\nInverse stack :\n");
    InverseStackHistory(&S);
    PrintStackHistory(S, Top(S)+1);

    printf("Percobaan Pop\n");
    printf("Index top sebelum pop: %d\n", Top(S));
    PopHistory(&S, &elemen);
    printf("Penampung setelah pop: ");
    printWord(elemen);
    printf("\n");
    printf("Index top setelah pop: %d\n", Top(S));

    printf("\nPercobaan proses tambahin elemen ke stack sampai full\n");
    CreateStackHistory(&S);

    printf("...proses tambahin elemen ke stack sampai full\n");

    for (int i = MaxElHistory - 1; i >= 0; i--)
    {
        elemen = stringToWord("HALO!");
        PushHistory(&S, elemen);
    }

    if (IsStackHistoryFull(S))
    {
        printf("Stacknya full gan\n");
    }

    return 0;
}