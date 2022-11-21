#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "../../boolean.h"
#include "amogusfight.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/word/word.h"
#include "../../adt/array/array.h"

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

void DisplayInventory()
{
}

void DisplayIngredients()
{
}

int ConvertTo100Scale(int oldScale, int oldNumber)
{
    return (oldNumber * 100) / oldScale;
}

void PrintState(int MaxHP1, int HP1, int MaxHP2, int HP2)
{
    PrintHPBar(ConvertTo100Scale(MaxHP1, HP1));
    printf("\t\t\t\t");
    PrintHPBar(ConvertTo100Scale(MaxHP2, HP2));
    PrintPlayer();
}

int max2num(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

void displayPotions(Array potions)
{
    printf("\nDaftar ramuan:\n");
    printf("Nama\t\t\t| Durasi\t| Ketahanan\t| Harga\t\n");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i <= COUNT(potions) - 1; i++)
    {
        if (stringLength(NAMA(ARRELMT(potions, i))) <= 15)
        {
            printf("%s\t\t", NAMA(ARRELMT(potions, i)));
        }
        else
        {
            printf("%s\t", NAMA(ARRELMT(potions, i)));
        }

        printf("| %d\t\t| %d\t\t| %d\t\n", DURASI(ARRELMT(potions, i)), KETAHANAN(ARRELMT(potions, i)), HARGA(ARRELMT(potions, i)));
    }
}

void readPotions(Array *potions)
{
    STARTWORD("data/potion.txt");
    int countPotion = wordToInt(currentWord);
    for (int i = 0; i <= countPotion; i++)
    {
        Masakan potion = CreateMasakan();
        ADVWORD();
        NOMOR(potion) = wordToInt(currentWord);

        ADVWORD();
        NAMA(potion) = wordToString(currentWord);

        ADVWORD();
        DURASI(potion) = wordToInt(ambilKataKe(currentWord, 1));
        KETAHANAN(potion) = wordToInt(ambilKataKe(currentWord, 2));
        HARGA(potion) = wordToInt(ambilKataKe(currentWord, 3));
        Insert(potions, potion);
    }
}

int potionwar()
{
    int MaxHP1 = 100, HP1 = 100, MaxHP2 = 100, HP2 = 100;
    int damage1 = 20, damage2 = 4;
    int maxEnergy = 100, energy = 0;
    int score = 0;
    boolean gameOn = true;
    Array potions;

    CreateArray(&potions);
    readPotions(&potions);

    displayPotions(potions);
    sleep(100);

    while (gameOn)
    {
        boolean finished = false;
        system("cls");
        printf("Score: %d\n", score);
        PrintState(MaxHP1, HP1, MaxHP2, HP2);

        // Action pemain

        getch(); // Sementara pake getch, ini nanti diganti jadi action pemain

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