#include "scoreboard.h"
#include <stdio.h>

int main() {
    int jumlah, i, skor;
    char playername[100];
    Word nameWord;

    Set setGame;
    Map mapGame;

    CreateEmptySet(&setGame);
    CreateEmptyMap(&mapGame);

    printf("Masukan jumlah data: ");
    scanf("%d", &jumlah);

    for (i=0; i<jumlah; i++)
    {
        printf("Masukan player name: ");
        scanf("%s", playername);
        nameWord = stringToWord(playername);

        printf("Masukan skor: ");
        scanf("%d", &skor);

        InsertScoreboard(&setGame, &mapGame, nameWord, skor);

    }
    
    Word game = stringToWord("GALAXY");
    PrintScoreboard(setGame, mapGame, game);

    return 0;
}