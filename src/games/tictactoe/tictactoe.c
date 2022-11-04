#include <stdio.h>
#include "tictactoe.h"

char papan[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int isWin()
{
    if (papan[0] == papan[1] && papan[1] == papan[2])
        return 1;
        
    else if (papan[3] == papan[4] && papan[4] == papan[5])
        return 1;
        
    else if (papan[6] == papan[7] && papan[7] == papan[8])
        return 1;
        
    else if (papan[0] == papan[3] && papan[3] == papan[6])
        return 1;
        
    else if (papan[1] == papan[4] && papan[4] == papan[7])
        return 1;
        
    else if (papan[2] == papan[5] && papan[5] == papan[8])
        return 1;
        
    else if (papan[0] == papan[4] && papan[4] == papan[8])
        return 1;
        
    else if (papan[2] == papan[4] && papan[4] == papan[6])
        return 1;
        
    else if (papan[0] != '1' && papan[1] != '2' && papan[2] != '3' && papan[3] != '4' && papan[4] != '5' && papan[5] != '6' && papan[6] != '7' && papan[7] != '8' && papan[8] != '9')
        return 0;
    else
        return  - 1;
}

void board()
{
    printf("\nTic Tac Toe\n");

    printf("Pemain 1 (X)  -  Pemain 2 (O)\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", papan[0], papan[1], papan[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", papan[3], papan[4], papan[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", papan[6], papan[7], papan[8]);
    printf("     |     |     \n\n");
}

void tictactoe()
{
    int player, i, choice;
    char mark;

    player = 1;

    do
    {
        board();
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

        if (choice == 1 && papan[0] == '1')
            papan[0] = mark;
            
        else if (choice == 2 && papan[1] == '2')
            papan[1] = mark;
            
        else if (choice == 3 && papan[2] == '3')
            papan[2] = mark;
            
        else if (choice == 4 && papan[3] == '4')
            papan[3] = mark;
            
        else if (choice == 5 && papan[4] == '5')
            papan[4] = mark;
            
        else if (choice == 6 && papan[5] == '6')
            papan[5] = mark;
            
        else if (choice == 7 && papan[6] == '7')
            papan[6] = mark;
            
        else if (choice == 8 && papan[7] == '8')
            papan[7] = mark;
            
        else if (choice == 9 && papan[8] == '9')
            papan[8] = mark;
            
        else
        {
            printf("Input tidak valid");
            
            player--;
            printf("Player %d, silakan memilih angka:  ", player);
            scanf("%d", &choice);
        }

        i = isWin();

        player++;

    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d menang \n", --player);
    else
        printf("==>\aDraw");
}



