#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "amogusfight.h"

void sleep(int detik)
{
    // Waktu start
    clock_t start_time = clock();

    while (clock() < start_time + 1000 * detik)
    {
    }
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

void PrintState(int MaxHP1, int HP1, int MaxHP2, int HP2)
{
    PrintHPBar((HP1 * 100) / MaxHP1);
    printf("\t\t\t\t");
    PrintHPBar((HP2 * 100) / MaxHP2);
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

int max2num(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

void DisplayPotions(Array potions)
{
    printf("\n============================== DAFTAR RAMUAN ==============================\n");
    printf("ID\t| Nama\t\t\t| Durasi\t| Ketahanan\t| Harga\t\n");
    printf("---------------------------------------------------------------------------\n");
    for (int i = 0; i <= COUNT(potions) - 1; i++)
    {
        printf("%d\t", NOMOR(ARRELMT(potions, i)));
        if (stringLength(NAMA(ARRELMT(potions, i))) < 14)
        {
            printf("| %s\t\t", NAMA(ARRELMT(potions, i)));
        }
        else
        {
            printf("| %s\t", NAMA(ARRELMT(potions, i)));
        }

        printf("| %d\t\t| %d\t\t| %d\t\n", DURASI(ARRELMT(potions, i)), KETAHANAN(ARRELMT(potions, i)), HARGA(ARRELMT(potions, i)));
    }
}

void DisplayInventory(Array potions)
{
    printf("\n========================= INVENTORY =========================\n");
    printf("ID\t| Nama\t\t\t| Durasi\t| Ketahanan\t\n");
    printf("-------------------------------------------------------------\n");
    if (IsArrayEmpty(potions))
    {
        printf("\t| \t\t\t| \t\t| \t\t\n");
    }
    else
    {
        for (int i = 0; i <= COUNT(potions) - 1; i++)
        {
            printf("%d\t", NOMOR(ARRELMT(potions, i)));
            if (stringLength(NAMA(ARRELMT(potions, i))) < 14)
            {
                printf("| %s\t\t", NAMA(ARRELMT(potions, i)));
            }
            else
            {
                printf("| %s\t", NAMA(ARRELMT(potions, i)));
            }

            printf("| %d\t\t| %d\t\t\n", DURASI(ARRELMT(potions, i)), KETAHANAN(ARRELMT(potions, i)));
        }
    }
}

void DisplayRecipes(List recipes, Array potions)
{
    printf("\n=========================== DAFTAR RESEP ===========================\n");
    for (size_t i = 0; i < NbElmt(recipes); i++)
    {
        BinTree recipe = getElmt(recipes, i);
        Masakan akar = find(potions, Akar(recipe));
        Masakan left = find(potions, Akar(Left(recipe)));
        Masakan right = find(potions, Akar(Right(recipe)));

        if (stringLength(NAMA(akar)) <= 15)
        {
            printf("%s\t\t: %s + %s\n", NAMA(akar), NAMA(left), NAMA(right));
        }
        else
        {
            printf("%s\t: %s + %s\n", NAMA(akar), NAMA(left), NAMA(right));
        }
    }
}

void ReadPotions(Array *potions)
{
    STARTWORD("data/potion.txt");
    int countPotion = wordToInt(currentWord);
    for (int i = 0; i < countPotion; i++)
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

void ReadRecipes(List *recipes)
{
    STARTWORD("data/recipe.txt");
    int countRecipe = wordToInt(currentWord);
    for (int i = 0; i < countRecipe; i++)
    {
        BinTree recipe = NULL;
        int idx = 0;
        ADVWORD();
        BuildTreeFromWord(&recipe, currentWord, &idx);
        InsVLast(recipes, recipe);
    }
}

addrNode Brew(List recipes, int potion1, int potion2)
{
    address P = First(recipes);
    addrNode result = NULL;
    while (Next(P) != NULL && result == NULL)
    {
        result = SearchByChild(Info(P), potion1, potion2);
        if (result == NULL)
        {
            P = Next(P);
        }
    }

    return result;
}

int amogusfight()
{
    int MaxHP1 = 100, HP1 = 100, MaxHP2 = 100, HP2 = 100;
    int damage1 = 20, damage2 = 4;
    int maxEnergy = 100, energy = 0;
    int score = 0;
    boolean gameOn = true;
    Array potions, inventory;
    List recipes;

    CreateArray(&potions);
    CreateArray(&inventory);
    CreateEmpty(&recipes);
    ReadPotions(&potions);
    ReadRecipes(&recipes);

    Insert(&inventory, find(potions, 1));
    Insert(&inventory, find(potions, 2));
    // sleep(100);
    while (gameOn)
    {
        boolean finished = false;

        // Action pemain
        while (!finished)
        {
            system("cls");
            printf("Score: %d\n", score);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);
            DisplayInventory(inventory);

            startInputWord();

            system("cls");
            printf("Score: %d\n", score);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);

            if (stringEQWord(currentWord, "RESEP"))
            {
                DisplayRecipes(recipes, potions);
                sleep(5);
            }
            else if (stringEQWord(currentWord, "BUY"))
            {
                DisplayPotions(potions);
                sleep(5);
            }
            else if (stringEQWord(currentWord, "BREW"))
            {
                DisplayInventory(inventory);
                printf("Potion 1: ");
                startInputWord();
                int potion1 = wordToInt(currentWord);
                if (isMember(inventory, potion1))
                {
                    printf("Potion 2: ");
                    startInputWord();
                    int potion2 = wordToInt(currentWord);
                    if (isMember(inventory, potion2))
                    {
                        if (Brew(recipes, potion1, potion2))
                        {
                            int potion3 = Akar(Brew(recipes, potion1, potion2));
                            Insert(&inventory, find(potions, potion3));
                            finished = true;
                        }
                    }
                }
            }
        }

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