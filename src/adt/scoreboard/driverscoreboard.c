#include "scoreboard.h"
#include <stdio.h>

int main()
{
    int jumlah, i, skor;
    char playername[100];
    Word nameWord;

    Scoreboard game;
    CreateScoreboard(&game);

    printf("Masukan jumlah data: ");
    scanf("%d", &jumlah);

    for (i = 0; i < jumlah; i++)
    {
        printf("Masukan player name: ");
        scanf("%s", playername);
        nameWord = stringToWord(playername);

        printf("Masukan skor: ");
        scanf("%d", &skor);

        InsertScoreboard(&game, nameWord, skor);
    }

    printf("**** SCOREBOARD GAME GALAXY ****\n");
    PrintScoreboard(game);

    return 0;
}