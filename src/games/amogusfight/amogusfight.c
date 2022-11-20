#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "../../boolean.h"
#include "amogusfight.h"

void sleep(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void PrintHPBar(int HP)
{
    printf("       [");
    if (HP < 4 && HP > 0)
    {
        HP = 4;
    }
    else if (HP < 0)
    {
        HP = 0;
    }

    for (int i = 0; i < HP / 4; i++)
    {
        printf("=");
    }
    for (int i = 0; i < 25 - HP / 4; i++)
    {
        printf(" ");
    }

    printf("]");
}

void PrintPlayer()
{
    printf("\n\n");
    printf("\t           .@@@@@@@.             \t\t\t          (\\ .@@@@@@@.   /)      \n");
    printf("\t         @@........@@            \t\t\t           \\@@........@@/)       \n");
    printf("\t        @ .....##@@@(@@.         \t\t\t         .@@(@@@##..... @        \n");
    printf("\t       @(.. @#,,,     ,@@        \t\t\t        @@,     ,,,#@ ..(@       \n");
    printf("\t  @@@@@@/..@###,,,,,,,,.@        \t\t\t        @.,,,,,,,,###@../@@@@@@  \n");
    printf("\t @ .//@/....@@#########@@        \t\t\t        @@#########@@..../@//. @ \n");
    printf("\t @////@/...............@         \t\t\t         @.............../@////@ \n");
    printf("\t @////@/ ..............@         \t\t\t         @.............. /@////@ \n");
    printf("\t @///(@/(.............@@         \t\t\t         @@.............(/@(///@ \n");
    printf("\t @@///@////(........//@          \t\t\t          @//........(////@///@@ \n");
    printf("\t      @@/////@  @////@@          \t\t\t          @@////@  @/////@@      \n");
    printf("\t       @@@@@@@  @@@@@@           \t\t\t           @@@@@@  @@@@@@@       \n");
}

int ConvertTo100Scale(int oldScale, int oldNumber)
{
    return (oldNumber * 100) / oldScale;
}

void PrintState(int MaxHP1, int HP1, int MaxHP2, int HP2)
{
    printf("");
    PrintHPBar(ConvertTo100Scale(MaxHP1, HP1));
    printf("\t\t\t\t");
    PrintHPBar(ConvertTo100Scale(MaxHP2, HP2));
    PrintPlayer();
}

int max2num(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int potionwar()
{
    int MaxHP1 = 100, HP1 = 100, MaxHP2 = 100, HP2 = 100;
    int damage1 = 20, damage2 = 4;
    int maxEnergy = 100, energy = 0;
    int score = 0;
    boolean gameOn = true;

    while (gameOn)
    {
        system("cls");
        printf("Score: %d\n", score);
        PrintState(MaxHP1, HP1, MaxHP2, HP2);
        getch(); // Sementara pake getch, ini nanti diganti jadi action pemain

        // Action pemain

        int i = 0;

        while (i < max2num(damage1, damage2) && (HP1 > 0 || HP2 > 0))
        {
            if (i < damage2)
            {
                HP1 -= 4;
            }
            if (i < damage1)
            {
                HP2 -= 4;
            }
            system("cls");
            if (HP1 > 0 || HP2 > 0)
            {
                printf("Score: %d\n", score);
                PrintState(MaxHP1, HP1, MaxHP2, HP2);
            }

            i += 4;
            sleep(0.99);
        }

        if (HP2 <= 0)
        {
            score += MaxHP2;
            MaxHP2 += 12;
            HP2 = MaxHP2;
        }
        if (HP1 <= 0)
        {
            gameOn = false;
            printf("Score: %d\n", score);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);
        }
    }
}