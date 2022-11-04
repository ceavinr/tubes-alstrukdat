#include <stdio.h>
#include "tictactoe.h"
#include "../../adt/array/array.c"


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
        return  - 1;
}

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

void tictactoe()
{
    int player, i, choice;
    char mark;
    Papan papan;

    MakeEmpty(&papan);
    SetEl(&papan, 1, '1');
    SetEl(&papan, 2, '2');
    SetEl(&papan, 3, '3');
    SetEl(&papan, 4, '4');
    SetEl(&papan, 5, '5');
    SetEl(&papan, 6, '6');
    SetEl(&papan, 7, '7');
    SetEl(&papan, 8, '8');
    SetEl(&papan, 9, '9');

    player = 1;

    do
    {
        board(papan);
        if (player % 2)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }

        printf("Player %d, silakan memilih angka:  ", player);
        scanf("%d", &choice);

        if (player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        if (choice == 1 && papan.TI[1] == '1')
            papan.TI[1] = mark;
            
        else if (choice == 2 && papan.TI[2] == '2')
            papan.TI[2] = mark;
            
        else if (choice == 3 && papan.TI[3] == '3')
            papan.TI[3] = mark;
            
        else if (choice == 4 && papan.TI[4] == '4')
            papan.TI[4] = mark;
            
        else if (choice == 5 && papan.TI[5] == '5')
            papan.TI[5] = mark;
            
        else if (choice == 6 && papan.TI[6] == '6')
            papan.TI[6] = mark;
            
        else if (choice == 7 && papan.TI[7] == '7')
            papan.TI[7] = mark;
            
        else if (choice == 8 && papan.TI[8] == '8')
            papan.TI[8] = mark;
            
        else if (choice == 9 && papan.TI[9] == '9')
            papan.TI[9] = mark;
            
        else
        {
            printf("Input tidak valid");
            
            player--;
            printf("Player %d, silakan memilih angka:  ", player);
            scanf("%d", &choice);
        }

        i = isWin(papan);

        player++;

    }while (i ==  - 1);
    
    board(papan);
    
    if (i == 1)
        printf("==>\aPlayer %d menang \n", --player);
    else
        printf("==>\aDraw");
}



