#include "scoreboard.h"

void CreateScoreboard(scoreboard *game)
{
    CreateEmptyMap(&(*game).mapGame);
    CreateEmptySet(&(*game).setGame);
}

void InsertScoreboard(scoreboard *game, Word playerName, valuetype score)
{
    InsertInSet(&(*game).setGame, playerName);
    InsertInMap(&(*game).mapGame, ToKey(playerName), score);

    SortScoreboard(&(*game).setGame, (*game).mapGame);
}

void PrintScoreboard(scoreboard game)
{
    int i, j, skor;
    address key;
    int spacing;

    printf("| NAMA          | SKOR          |\n");
    printf("|-------------------------------|\n");

    if (IsEmptySet(game.setGame))
    {
        printf("------- SCOREBOARD KOSONG -------\n");
    } else {
        for (i=0; i<game.setGame.Count; i++)
        {
            printf("| ");
            printWord(game.setGame.Elements[i]);

            spacing = 14 - game.setGame.Elements[i].Length;
            for (j=0; j<spacing; j++)
            {
                printf(" ");
            }

            key = ToKey(game.setGame.Elements[i]);
            skor = ValueInMap(game.mapGame, key);
            printf("| %d", skor);

            spacing = 14;
            while (skor != 0)
            {
                skor = skor/10;
                spacing--;
            }

            for (j=0; j<spacing; j++)
            {
                printf(" ");
            }
            printf("|\n");
        }
    }

    printf("\n");
}

void SortScoreboard(Set *setGame, Map mapGame)
{
    int j, idx_a, idx_b;
    Word temp;  

    boolean flag = true;  
    while (flag) { 
        flag = false;
        for(j=0; j<(*setGame).Count-1; j++) {
            idx_a = IndexInMap(mapGame, ToKey((*setGame).Elements[j]));
            idx_b = IndexInMap(mapGame, ToKey((*setGame).Elements[j+1]));

            if (mapGame.Elements[idx_a].Value < mapGame.Elements[idx_b].Value)   
            {
                CopyWord(&temp, (*setGame).Elements[j]);
                CopyWord(&(*setGame).Elements[j], (*setGame).Elements[j+1]);                
                CopyWord(&(*setGame).Elements[j+1], temp);
                flag = true;
            }
        }
    }
}