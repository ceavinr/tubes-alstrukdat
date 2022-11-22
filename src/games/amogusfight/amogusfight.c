#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "amogusfight.h"

// To do:
// - Potion effect
// - Reject input
// - Help
// - Easter egg

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
    printf("ID\t| Nama\t\t\t| Ketahanan\t| Harga\t\n");
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

        printf("| %d\t\t| %d\t\n", KETAHANAN(ARRELMT(potions, i)), HARGA(ARRELMT(potions, i)));
    }
}

void DisplayInventory(Array potions)
{
    printf("\n========================= INVENTORY =========================\n");
    printf("ID\t| Nama\t\t\t| Ketahanan\t\n");
    printf("-------------------------------------------------------------\n");
    if (IsArrayEmpty(potions))
    {
        printf("\t| \t\t\t| \t\t\n");
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

            printf("| %d\t\t\n", KETAHANAN(ARRELMT(potions, i)));
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
        KETAHANAN(potion) = wordToInt(ambilKataKe(currentWord, 1));
        HARGA(potion) = wordToInt(ambilKataKe(currentWord, 2));
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

addrNode Brew(List recipes, Masakan potion1, Masakan potion2)
{
    addrNode result = NULL;

    if (!IsListEmpty(recipes))
    {
        address P = First(recipes);
        while (P != NULL && result == NULL)
        {
            result = SearchByChild(Info(P), NOMOR(potion1), NOMOR(potion2));
            if (result == NULL)
            {
                P = Next(P);
            }
        }
    }
    return result;
}

int amogusfight()
{
    int potionID;
    int MaxHP1 = 100, HP1 = 100, MaxHP2 = 40, HP2 = 40;
    int damage1 = 20, damage2 = 4;
    int score = 0, elixir = 0;
    boolean gameOn = true;
    Array potions, inventory, using;
    List recipes;

    CreateArray(&potions);
    CreateArray(&inventory);
    CreateArray(&using);
    CreateEmpty(&recipes);
    ReadPotions(&potions);
    ReadRecipes(&recipes);

    Insert(&inventory, find(potions, 1));

    while (gameOn)
    {
        Masakan m_del = CreateMasakan();
        boolean finished = false;

        // Action pemain
        while (!finished)
        {
            boolean inputValid = false;
            Word command;

            system("cls");
            printf("Score: %d\n", score);
            printf("Elixir: %d\n", elixir);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);
            DisplayInventory(inventory);

            printf("\nMasukkan perintah! (RESEP/BUY/BREW/USE/SKIP/USED)");
            printf("\n>> ");
            startInputWord();
            akuisisiCommandWord(&command, currentWord, 1);

            system("cls");
            printf("Score: %d\n", score);
            printf("Elixir: %d\n", elixir);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);

            if (stringEQWord(currentWord, "RESEP"))
            {
                DisplayRecipes(recipes, potions);
                sleep(5);
            }
            else if (stringEQWord(command, "USED"))
            {
                DisplayInventory(using);
                sleep(5);
            }
            else if (stringEQWord(command, "USE"))
            {
                akuisisiCommandWord(&command, currentWord, 2);
                potionID = wordToInt(command);
                DeleteArrayAt(&inventory, &m_del, indexOf(inventory, potionID));
                Insert(&using, m_del);
                finished = true;
            }
            else if (stringEQWord(currentWord, "BUY"))
            {
                DisplayPotions(potions);
                printf("Enter potion ID (Enter 0 to cancel buy): ");

                while (!inputValid)
                {
                    startInputWord();
                    if (wordToInt(currentWord) >= 0 && wordToInt(currentWord) <= 18)
                    {
                        inputValid = true;
                    }
                }

                if (!stringEQWord(currentWord, "0"))
                {
                    if (elixir >= HARGA(find(potions, wordToInt(currentWord))))
                    {
                        Insert(&inventory, find(potions, wordToInt(currentWord)));
                        elixir -= HARGA(find(potions, wordToInt(currentWord)));
                        finished = true;
                    }
                    else
                    {
                    }
                }
            }
            else if (stringEQWord(currentWord, "BREW"))
            {
                Masakan potion1, potion2;

                DisplayInventory(inventory);
                printf("\nPotion 1: ");
                startInputWord();
                if (isMember(inventory, wordToInt(currentWord)))
                {
                    DeleteArrayAt(&inventory, &potion1, indexOf(inventory, wordToInt(currentWord)));
                    printf("Potion 2: ");
                    startInputWord();
                    if (isMember(inventory, wordToInt(currentWord)))
                    {
                        DeleteArrayAt(&inventory, &potion2, indexOf(inventory, wordToInt(currentWord)));
                        if (Brew(recipes, potion1, potion2) != NULL)
                        {
                            printf("Brewing...\n");
                            sleep(1);
                            int potion3 = Akar(Brew(recipes, potion1, potion2));
                            Insert(&inventory, find(potions, potion3));
                            finished = true;
                        }
                        else
                        {
                            printf("Tidak bisa mencampur %s dengan %s!", NAMA(potion1), NAMA(potion2));
                            sleep(2);
                            Insert(&inventory, potion1);
                            Insert(&inventory, potion2);
                        }
                    }
                    else
                    {
                        Insert(&inventory, potion1);
                    }
                }
            }
            else if (stringEQWord(currentWord, "SKIP"))
            {
                finished = true;
            }
        }

        int i = 0;
        while (i < COUNT(using))
        {
            switch (NOMOR(ARRELMT(using, i)))
            {
            case 11:
                damage1 *= 2;
                break;
            case 12:
                damage2 = damage2 * 3 / 4;
                break;
            case 13:
                HP1 -= MaxHP1 / 10;
                break;
            case 14:
                HP1 -= MaxHP1 / 2;
                break;
            case 15:
                HP1 += MaxHP1 / 10;
                break;
            case 16:
                MaxHP1 = MaxHP1 * 5 / 4;
                break;
            case 17:
                damage1 = damage1 * 5 / 4;
                break;
            }

            KETAHANAN(ARRELMT(using, i)) -= 1;
            if (KETAHANAN(ARRELMT(using, i)) == 0)
            {
                DeleteArrayAt(&using, &m_del, i);
            }
            else
            {
                i++;
            }
        }

        i = 0;

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
                printf("Elixir: %d\n", elixir);
                PrintState(MaxHP1, HP1, MaxHP2, HP2);
            }

            i += 4;
            sleep(0.99);
        }

        if (HP2 <= 0)
        {
            score += MaxHP2;
            elixir += MaxHP2;
            MaxHP2 += 20;
            damage2 += 4;
            HP2 = MaxHP2;
        }
        if (HP1 <= 0)
        {
            gameOn = false;
            system("cls");
            printf("Score: %d\n", score);
            printf("Elixir: %d\n", elixir);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);
        }
        srand(time(NULL));
        int x = rand() % 9 + 1;
        Insert(&inventory, find(potions, x));
    }

    return score;
}