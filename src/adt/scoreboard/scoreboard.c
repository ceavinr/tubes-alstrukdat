#include "scoreboard.h"

void InsertScoreboard(Set *setGame, Map *mapGame, Word playerName, valuetype score)
{
    InsertInSet(setGame, playerName);
    InsertInMap(mapGame, ToKey(playerName), score);

    SortScoreboard(setGame, *mapGame);
}

void PrintScoreboard(Set setGame, Map mapGame, Word game)
{
    int i, j, skor;
    address key;
    int spacing;

    printf("**** SCOREBOARD GAME ");
    printWord(game);
    printf(" ****\n");

    printf("| NAMA          | SKOR          |\n");
    printf("|-------------------------------|\n");

    for (i=0; i<setGame.Count; i++)
    {
        printf("| ");
        printWord(setGame.Elements[i]);

        spacing = 14 - setGame.Elements[i].Length;
        for (j=0; j<spacing; j++)
        {
            printf(" ");
        }

        key = ToKey(setGame.Elements[i]);
        skor = ValueInMap(mapGame, key);
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