#include "listscore.h"

int main() {
    ListScore scoreboard;
    int i, j, score, index;
    Word name, game;

    MakeListScore(&scoreboard);
    printf("Cek apakah kosong?\n");
    if (IsEmptyScoreboard(&scoreboard))
    {
        printf("Yaa kosong\n\n");
    } else
    {
        printf("Udah terisi nihh\n\n");
    }

    printf("Masukan banyak game: ");
    startInputWord();
    int banyak_game = wordToInt(currentWord);
    for (i=0; i<banyak_game; i++)
    {
        printf("\nMasukan Nama game %d : ", i+1);
        startInputWord();
        InsertLastScoreboard(&scoreboard, currentWord);
        index = SearchScoreboard(&scoreboard, currentWord);

        printf("Masukan banyak pemain : ");
        startInputWord();
        int banyak_pemain = wordToInt(currentWord);
        for (j=0; j<banyak_pemain; j++)
        {
            score = rand()%101;
            printf("\n===== SCORE ANDA %d =====\n", score);
            printf("Masukan nama pemain %d : ", j+1);
            startInputWord();
            InsertInMap(&scoreboard.A[index].MapScoreboard, currentWord, score);
        }    
    }

    printf("\n Ini hasil print scoreboard\n\n");
    for (i = 0; i < (scoreboard).Neff; i++)
    {
        printf("**** SCOREBOARD GAME ");
        printWord((scoreboard).A[i].GameTitle);
        printf(" ****\n");
        PrintMap((scoreboard).A[i].MapScoreboard);
    }

    printf("\nCoba masukan masukan nama game yang akan dihapus: ");
    startInputWord();
    index = SearchScoreboard(&scoreboard, currentWord);
    DeleteAtScoreboard(&scoreboard, index);
    printf("\nIni hasilnya\n");
    for (i = 0; i < (scoreboard).Neff; i++)
    {
        printf("**** SCOREBOARD GAME ");
        printWord((scoreboard).A[i].GameTitle);
        printf(" ****\n");
        PrintMap((scoreboard).A[i].MapScoreboard);
    }
    

    return 0;
}