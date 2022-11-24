#include "map.h"

int main() {
    int jumlah, skor, i, key, hashing;
    char playername[100];
    Word nameWord;
    Map map;

    printf("Inisialisasi Map\n");
    CreateEmptyMap(&map);
    printf("Cek map kosong and not full: \n");
    if (!IsFullMap(map) && IsEmptyMap(map))
    {
        printf("Ini mapnya kosong dan tidak full\n");
        printf("Panjangnya %d\n", map.Count);
    }

    printf("\nMasukin data");
    printf("\nMasukan jumlah data: ");
    scanf("%d", &jumlah);

    for (i=0; i<jumlah; i++)
    {
        printf("\nMasukan player name: ");
        scanf("%s", playername);
        nameWord = stringToWord(playername);

        printf("Masukan skor: ");
        scanf("%d", &skor);

        InsertInMap(&map, nameWord, skor);
    }

    PrintMap(map);

    for (i=0; i<jumlah; i++)
    {
        printf("\nMasukan player name sama kek tadi sesuai urutan: ");
        scanf("%s", playername);
        nameWord = stringToWord(playername);

        printf("Hasil value %d : %d\n", i+1, ValueInMap(map, nameWord));
    }

    printf("\nMasukan player name yang mau didelete: ");
    scanf("%s", playername);
    nameWord = stringToWord(playername);
    DeleteInMap(&map, nameWord);

    PrintMap(map);

    printf("\nCek value IsMemberInmap masukan playername: ");
    scanf("%s", playername);
    nameWord = stringToWord(playername);
    if (IsMemberInMap(map, nameWord))
    {
        printf("Ada kok\n");
    } else {
        printf("Gak adaa\n");
    }
    

    return 0;
}