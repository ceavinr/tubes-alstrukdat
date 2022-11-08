#include <stdio.h>
#include "tictactoe.h"
#include "../../adt/array/array.h"

/*Fungsi untuk mengecek apakah game sudah ada pemenang atau belum*/
int isWin(Papan papan)
{
    if (papan.TI[1] == papan.TI[2] && papan.TI[2] == papan.TI[3])
        return 1;

    else if (papan.TI[4] == papan.TI[5] && papan.TI[5] == papan.TI[6])
        return 1;

    else if (papan.TI[7] == papan.TI[8] && papan.TI[8] == papan.TI[9])
        return 1;

    else if (papan.TI[1] == papan.TI[4] && papan.TI[4] == papan.TI[7])
        return 1;

    else if (papan.TI[2] == papan.TI[5] && papan.TI[5] == papan.TI[8])
        return 1;

    else if (papan.TI[3] == papan.TI[6] && papan.TI[6] == papan.TI[9])
        return 1;

    else if (papan.TI[1] == papan.TI[5] && papan.TI[5] == papan.TI[9])
        return 1;

    else if (papan.TI[3] == papan.TI[5] && papan.TI[5] == papan.TI[7])
        return 1;

    else if (papan.TI[1] != '1' && papan.TI[2] != '2' && papan.TI[3] != '3' && papan.TI[4] != '4' && papan.TI[5] != '5' && papan.TI[6] != '6' && papan.TI[7] != '7' && papan.TI[8] != '8' && papan.TI[9] != '9')
        return 0;
    else
        return -1;
}

/*Prosedur untuk melakukan print tampilan papan kepada user*/
void board(Papan papan)
{
    printf("\nTic Tac Toe\n");

    printf("Pemain 1 (X)  -  Pemain 2 (O)\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", papan.TI[1], papan.TI[2], papan.TI[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", papan.TI[4], papan.TI[5], papan.TI[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", papan.TI[7], papan.TI[8], papan.TI[9]);
    printf("     |     |     \n\n");
}

/*Prosedur untuk menjalankan game Tic Tac Toe*/
void tictactoe()
{
    int player, i, j, tebakan;
    char mark;
    Word input;
    Papan papan;

    ArMakeEmpty(&papan);
    ArSetEl(&papan, 1, '1');
    ArSetEl(&papan, 2, '2');
    ArSetEl(&papan, 3, '3');
    ArSetEl(&papan, 4, '4');
    ArSetEl(&papan, 5, '5');
    ArSetEl(&papan, 6, '6');
    ArSetEl(&papan, 7, '7');
    ArSetEl(&papan, 8, '8');
    ArSetEl(&papan, 9, '9');

    player = 1;

    do
    {
        board(papan);
        if (player % 2 == 1)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }

        printf("Player %d, silakan memilih angka:  ", player);

        startInputWord();
        akuisisiCommandWord(&input, currentWord, 1);
        tebakan = wordToInt(input);

        if (player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        if (tebakan == 1 && papan.TI[1] == '1')
        {
            papan.TI[1] = mark;
        }          
        else if (tebakan == 2 && papan.TI[2] == '2')
        {
            papan.TI[2] = mark;
        }
            
        else if (tebakan == 3 && papan.TI[3] == '3')
        {
            papan.TI[3] = mark;
        }

        else if (tebakan == 4 && papan.TI[4] == '4')
        {
            papan.TI[4] = mark;
        }

        else if (tebakan == 5 && papan.TI[5] == '5')
        {
            papan.TI[5] = mark;
        }

        else if (tebakan == 6 && papan.TI[6] == '6')
        {
            papan.TI[6] = mark;
        }

        else if (tebakan == 7 && papan.TI[7] == '7')
        {
            papan.TI[7] = mark;
        }

        else if (tebakan == 8 && papan.TI[8] == '8')
        {
            papan.TI[8] = mark;
        }

        else if (tebakan == 9 && papan.TI[9] == '9')
        {
            papan.TI[9] = mark;
        }

        else
        {
            printf("Input tidak valid\n");
            j = 0;

            while (j == 0)
            {
                printf("Player %d, silakan memilih ulang angka:  ", player);

                startInputWord();
                akuisisiCommandWord(&input, currentWord, 1);
                tebakan = wordToInt(input);

                if (player == 1)
                {
                    mark = 'X';
                }
                else
                {
                    mark = 'O';
                }

                if (tebakan == 1 && papan.TI[1] == '1')
                {
                    papan.TI[1] = mark;
                    j = 1;
                }          
                else if (tebakan == 2 && papan.TI[2] == '2')
                {
                    papan.TI[2] = mark;
                    j = 1;
                }
                    
                else if (tebakan == 3 && papan.TI[3] == '3')
                {
                    papan.TI[3] = mark;
                    j = 1;
                }

                else if (tebakan == 4 && papan.TI[4] == '4')
                {
                    papan.TI[4] = mark;
                    j = 1;
                }

                else if (tebakan == 5 && papan.TI[5] == '5')
                {
                    papan.TI[5] = mark;
                    j = 1;
                }

                else if (tebakan == 6 && papan.TI[6] == '6')
                {
                    papan.TI[6] = mark;
                    j = 1;
                }

                else if (tebakan == 7 && papan.TI[7] == '7')
                {
                    papan.TI[7] = mark;
                    j = 1;
                }

                else if (tebakan == 8 && papan.TI[8] == '8')
                {
                    papan.TI[8] = mark;
                    j = 1;
                }

                else if (tebakan == 9 && papan.TI[9] == '9')
                {
                    papan.TI[9] = mark;
                    j = 1;
                }

                else
                {
                    printf("Input tidak valid\n");
                    j = 0;
                }
            }
        }

        i = isWin(papan);

        player++;

    } while (i == -1);

    board(papan);

    if (i == 1)
        printf("==> \aPlayer %d menang \n", --player);
    else
        printf("==> \aDraw");
}
