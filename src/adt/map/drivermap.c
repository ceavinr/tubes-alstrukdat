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

        key = ToKey(nameWord);
        hashing = Hash(key);

        printf("Key : %d\n", key);
        printf("Hashing : %d\n", hashing);

        InsertInMap(&map, key, skor);
    }

    for (i=0; i<jumlah; i++)
    {
        printf("\nMasukan player name sama kek tadi sesuai urutan: ");
        scanf("%s", playername);
        nameWord = stringToWord(playername);

        int key = ToKey(nameWord);

        printf("Hasil value %d : %d\n", i+1, ValueInMap(map, key));
    }

    printf("\nMasukan player name yang mau didelete: ");
    scanf("%s", playername);
    nameWord = stringToWord(playername);
    DeleteInMap(&map, ToKey(nameWord));

    printf("Ini indexnya : %d\n", IndexInMap(map, ToKey(nameWord)));

    printf("\nHarusnya valuenya -9999 (undefined)\n");
    printf("Ini valuenya: %d\n", ValueInMap(map, ToKey(nameWord)));

    printf("\nCek value IsMemberInmap dari yang didelete: \n");
    if (IsMemberInMap(map, ToKey(nameWord)))
    {
        printf("Ada kok\n");
    } else {
        printf("Gak adaa\n");
    }
    

    return 0;
}