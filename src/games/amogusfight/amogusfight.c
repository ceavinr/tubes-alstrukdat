#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "amogusfight.h"
#include "../../interface.h"

void PrintHPBar(int HP)
{
    printf("[");
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
    printf("\t");
    PrintHPBar((HP1 * 100) / MaxHP1);
    printf("\t\t\t\t      ");
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
    printf("\t\n");
    printf("\t            AMOGUS               \t\t\t              IMPOSTOR           \n");
}

int max2num(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

void CommandList()
{
    printf("\n=============================== COMMAND LIST =============================== \n");
    printf("RESEP\t\t\t\t : Melihat resep untuk membuat potion\n");
    printf("BUY\t\t\t\t : Membeli bahan/potion\n");
    printf("BREW <ID potion 1> <ID potion 2> : Membuat potion\n");
    printf("USE <ID potion>\t\t\t : Menggunakan potion\n");
    printf("SKIP\t\t\t\t : Melewatkan 1 turn tanpa melakukan action\n");
    printf("USED\t\t\t\t : Melihat potion yang sedang digunakan\n");
    printf("STATUS\t\t\t\t : Melihat status dari Amogus dan Impostor\n");
    printf("INGFO\t\t\t\t : Melihat info dari potion-potion pada game\n");
    printf("HELP\t\t\t\t : Melihat list command yang dapat digunakan\n");

    printf("\nEnter to continue...");
    startInput();
}

void DisplayInfo()
{
    printf("\n=================================== INFO RAMUAN ===================================\n");
    STARTWORD("data/amogusdata/ingfo.txt");
    int countPotion = wordToInt(currentWord);
    for (int i = 0; i < countPotion; i++)
    {
        ADVWORD();
        int id = wordToInt(currentWord);
        if (id >= 10 && id <= 29 && id != 19 && id != 20)
        {
            ADVWORD();

            printf(" %s\t:", wordToString(currentWord));

            ADVWORD();
            printf(" %s\t \n", wordToString(currentWord));
        }
        else
        {
            ADVWORD();
            ADVWORD();
        }
    }
    printf("\nEnter to continue...");
    startInput();
}

void DisplayPotions(Array potions)
{
    printf("\n============================== DAFTAR RAMUAN ==============================\n");
    printf("ID\t| Nama\t\t\t| Durasi | Harga\t\n");
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

        printf("| %d\t | %d\t\n", DURASI(ARRELMT(potions, i)), HARGA(ARRELMT(potions, i)));
    }
}

void DisplayInventory(Array potions)
{
    printf("\n================== INVENTORY ==================\n");
    printf("ID\t| Nama\t\t\t| Durasi\n");
    printf("-----------------------------------------------\n");
    if (IsArrayEmpty(potions))
    {
        printf("\t| \t\t\t| \t\n");
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

            printf("| %d\t\t\n", DURASI(ARRELMT(potions, i)));
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
    STARTWORD("data/amogusdata/potion.txt");
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
        HARGA(potion) = wordToInt(ambilKataKe(currentWord, 2));
        Insert(potions, potion);
    }
}

void ReadRecipes(List *recipes)
{
    STARTWORD("data/amogusdata/recipe.txt");
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

void amogusfight(int *score)
{
    *score = 0;
    int potionID;
    int MaxHP1 = 200, MaxHP2 = 40;
    int HP1 = MaxHP1, HP2 = MaxHP2;
    int baseDamage1 = 20, baseDamage2 = 4;
    int damage1 = baseDamage1, damage2 = baseDamage2;
    int elixir = 0;
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
    Insert(&inventory, find(potions, 2));
    Insert(&inventory, find(potions, 9));

    CommandList();

    while (gameOn)
    {
        Masakan m_del = CreateMasakan();
        boolean finished = false;
        int i;

        // Action pemain
        while (!finished)
        {
            boolean inputValid = false;
            Word command;

            clear();
            printf("Score: %d\n", *score);
            printf("Elixir: %d\n", elixir);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);
            DisplayInventory(inventory);

            printf("\nMasukkan perintah!");
            printf("\n>> ");
            startInputWord();
            akuisisiCommandWord(&command, currentWord, 1);

            clear();
            printf("Score: %d\n", *score);
            printf("Elixir: %d\n", elixir);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);

            if (stringEQWord(currentWord, "RESEP"))
            {
                DisplayRecipes(recipes, potions);
                printf("\nEnter to continue...");
                startInput();
            }
            else if (stringEQWord(command, "USED"))
            {
                DisplayInventory(using);
                printf("\nEnter to continue...");
                startInput();
            }
            else if (stringEQWord(command, "STATUS"))
            {
                printf("\n======== AMOGUS ========\n");
                printf("Damage: %d\n", damage1);
                printf("HP: %d\n", HP1);
                printf("Max HP: %d\n", MaxHP1);

                printf("\n======= OPPONENT =======\n");
                printf("Damage: %d\n", damage2);
                printf("HP: %d\n", HP2);
                printf("Max HP: %d\n", MaxHP2);

                printf("\nEnter to continue...");
                startInput();
            }
            else if (stringEQWord(command, "USE"))
            {
                DisplayInventory(inventory);
                akuisisiCommandWord(&command, currentWord, 2);
                potionID = wordToInt(command);

                if (isMember(potions, potionID))
                {
                    if (isMember(inventory, potionID))
                    {
                        switch (potionID)
                        {
                        case 10:
                        case 21:
                            damage1 -= baseDamage1 * 0.1;
                            break;
                        case 11:
                        case 23:
                            damage1 += baseDamage1 * 0.5;
                            break;
                        case 12:
                        case 25:
                            damage2 -= baseDamage2 * 0.5;
                            break;
                        }

                        DeleteArrayAt(&inventory, &m_del, indexOf(inventory, potionID));
                        Insert(&using, m_del);
                        finished = true;
                    }
                    else
                    {
                        printf("\n%s tidak ada dalam inventory!", NAMA(find(potions, potionID)));
                        sleep(500);
                    }
                }
                else
                {
                    printf("\nInput tidak valid!");
                    sleep(500);
                }
            }
            else if (stringEQWord(currentWord, "BUY"))
            {
                if (COUNT(inventory) < 12)
                {
                    while (!inputValid)
                    {
                        DisplayPotions(potions);
                        printf("\nEnter potion ID (Enter 0 to cancel buy): ");
                        startInputWord();
                        if (wordToInt(currentWord) >= 0 && wordToInt(currentWord) <= 20)
                        {
                            if (!stringEQWord(currentWord, "0"))
                            {
                                if (elixir >= HARGA(find(potions, wordToInt(currentWord))))
                                {
                                    Insert(&inventory, find(potions, wordToInt(currentWord)));
                                    elixir -= HARGA(find(potions, wordToInt(currentWord)));
                                    finished = true;
                                    inputValid = true;
                                }
                                else
                                {
                                    printf("Elixir tidak mencukupi!");
                                    sleep(500);
                                }
                            }
                            else
                            {
                                inputValid = true;
                            }
                        }
                        else
                        {
                            printf("Input tidak valid!\n");
                            sleep(500);
                            clear();
                        }
                    }
                }
                else
                {
                    printf("Inventory penuh!");
                }
            }
            else if (stringEQWord(command, "BREW"))
            {
                Masakan potion1, potion2;
                DisplayInventory(inventory);

                if (ambilKataKe(currentWord, 2).Length > 0 && ambilKataKe(currentWord, 3).Length > 0)
                {
                    akuisisiCommandWord(&command, currentWord, 2);
                    if (isMember(inventory, wordToInt(command)))
                    {
                        DeleteArrayAt(&inventory, &potion1, indexOf(inventory, wordToInt(command)));

                        akuisisiCommandWord(&command, currentWord, 3);
                        if (isMember(inventory, wordToInt(command)))
                        {
                            DeleteArrayAt(&inventory, &potion2, indexOf(inventory, wordToInt(command)));

                            if (Brew(recipes, potion1, potion2) != NULL)
                            {
                                printf("\nBrewing...\n");
                                sleep(500);
                                int potion3 = Akar(Brew(recipes, potion1, potion2));
                                Insert(&inventory, find(potions, potion3));
                                finished = true;
                            }
                            else
                            {
                                printf("\nTidak bisa mencampur %s dengan %s!", NAMA(potion1), NAMA(potion2));
                                sleep(500);
                                Insert(&inventory, potion1);
                                Insert(&inventory, potion2);
                            }
                        }
                        else
                        {
                            if (wordToInt(command) >= 1 && wordToInt(command) <= 20)
                            {
                                printf("\nTidak ada %s dalam inventory!", NAMA(find(potions, wordToInt(command))));
                                Insert(&inventory, potion1);
                                sleep(500);
                            }
                            else
                            {
                                printf("\nInput tidak valid!");
                                sleep(500);
                            }
                        }
                    }
                    else
                    {
                        if (wordToInt(command) >= 1 && wordToInt(command) <= 20)
                        {
                            printf("\nTidak ada %s dalam inventory!", NAMA(find(potions, wordToInt(command))));
                            sleep(500);
                        }
                        else
                        {
                            printf("\nInput tidak valid!");
                            sleep(500);
                        }
                    }
                }
                else
                {
                    printf("\nInput tidak valid!");
                    sleep(500);
                }
            }
            else if (stringEQWord(currentWord, "SKIP"))
            {
                finished = true;
            }
            else if (stringEQWord(currentWord, "HELP"))
            {
                CommandList();
            }
            else if (stringEQWord(currentWord, "INGFO"))
            {
                DisplayInfo();
            }
            else
            {
                printf("\nInput tidak valid!");
                sleep(500);
            }
        }

        // Potion effect
        i = 0;
        while (i < COUNT(using))
        {
            switch (NOMOR(ARRELMT(using, i)))
            {
            case 13:
            case 27:
                HP1 -= MaxHP1 * 0.1;
                break;
            case 14:
            case 29:
                HP1 += MaxHP1 * 0.1;
                break;
            case 15:
                HP1 -= MaxHP1 * 0.5;
                break;
            case 16:
                MaxHP1 = MaxHP1 * 1.25;
                break;
            case 17:
                damage1 = damage1 * 1.25;
                break;
            case 18:
                HP1 = MaxHP1;
                break;
            }

            DURASI(ARRELMT(using, i)) -= 1;
            if (DURASI(ARRELMT(using, i)) == 0)
            {
                DeleteArrayAt(&using, &m_del, i);
                switch (NOMOR(m_del))
                {
                case 10:
                case 21:
                    damage1 += baseDamage1 * 0.1;
                    break;
                case 11:
                case 23:
                    damage1 -= baseDamage1 * 0.5;
                    break;
                case 12:
                case 25:
                    damage2 += baseDamage2 * 0.5;
                    break;
                }
            }
            else
            {
                i++;
            }
        }

        // Animasi HP bar
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
            clear();
            if (HP1 > 0 || HP2 > 0)
            {
                printf("Score: %d\n", *score);
                printf("Elixir: %d\n", elixir);
                PrintState(MaxHP1, HP1, MaxHP2, HP2);
            }

            i += 4;
        }

        // Ganti musuh
        if (HP2 <= 0)
        {
            *score += MaxHP2;
            elixir += MaxHP2;
            MaxHP2 += 20;
            damage2 += 4;
            HP2 = MaxHP2;
        }

        // End game
        if (HP1 <= 0)
        {
            gameOn = false;
            clear();
            printf("Score: %d\n", *score);
            printf("Elixir: %d\n", elixir);
            PrintState(MaxHP1, HP1, MaxHP2, HP2);
        }

        // Add random ingredients
        if (COUNT(inventory) < 12)
        {
            srand(time(NULL));
            int x = rand() % 15 + 1;
            if (x > 9) // Biar lebih sering keluar Water Bottle atau Nether Wart
            {
                x = x % 2 + 1;
            }

            Insert(&inventory, find(potions, x));
        }
    }
}