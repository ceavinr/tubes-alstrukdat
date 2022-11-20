#include "set.h"

int main() {
    int jumlah, i;
    char playername[100];
    Word nameWord;
    Set set;

    printf("Inisialisasi Set\n");
    CreateEmptySet(&set);
    printf("Cek set kosong and not full: \n");
    if (!IsFullSet(set) && IsEmptySet(set))
    {
        printf("Ini setnya kosong dan tidak full\n");
        printf("Panjangnya %d\n", set.Count);
    }

    printf("\nMasukin data");
    printf("\nMasukan jumlah data: ");
    scanf("%d", &jumlah);

    for (i=0; i<jumlah; i++)
    {
        printf("\nMasukan player name: ");
        scanf("%s", playername);
        nameWord = stringToWord(playername);

        InsertInSet(&set, nameWord);
    }

    printf("\nTampilin isi Set\n");
    for (i=0; i<set.Count; i++)
    {
        printWord(set.Elements[i]);
        printf("\n");
    }

    printf("\nMasukan player name yang mau didelete: ");
    scanf("%s", playername);
    nameWord = stringToWord(playername);
    DeleteInSet(&set, nameWord);

    printf("\nTampilin isi Set\n");
    for (i=0; i<set.Count; i++)
    {
        printWord(set.Elements[i]);
        printf("\n");
    }

    printf("\nCek value IsMemberInmap masukan playername: ");
    scanf("%s", playername);
    nameWord = stringToWord(playername);
    if (IsMemberInSet(set, nameWord))
    {
        printf("Ada kok\n");
    } else {
        printf("Gak adaa\n");
    }
    

    return 0;
}