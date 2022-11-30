#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

char *kata_random()
{
    int x, total, count;
    ArrayDin arrKata;

    arrKata = MakeArrayDin();
    STARTWORD("data/kata.txt");

    if (!EOP)
    {
        count = wordToInt(currentWord);
        int i;
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAtArrayDin(&arrKata, currentWord, i);
        }
        ADVWORD();
    }

    total = count + 1;
    srand(time(NULL));
    x = rand() % total;

    int j, num;
    num = 0;
    char *kata = malloc(sizeof(char) * BUFFER(arrKata)[x].Length + 1);
    for (j = 0; j < BUFFER(arrKata)[x].Length; j++)
    {
        kata[j] = BUFFER(arrKata)[x].TabWord[j];
        num++;
    }
    kata[BUFFER(arrKata)[x].Length] = '\0';

    return kata;
}

int isWin(char *kata)
{
    int i, length;
    length = stringLength(kata);

    for (i = 0; i < length; i++)
    {
        if (kata[i] == '_')
        {
            return 0;
        }
    }
    return 1;
}

int play()
{
    char history[11];
    string kata;
    int i, j, count;
    int panjang_kata, score, win;

    score = 0;
    count = 0;

    while (count <= 10)
    {
        count++;
        kata = kata_random();
        panjang_kata = stringLength(kata);

        string word = copyString(kata);

        for (i = 0; i < panjang_kata; i++)
        {
            word[i] = '_';
        }
        word[panjang_kata] = '\0';

        history[0] = '\0';

        char tebakan;

        win = 0;
        j = 0;

        while (win == 0)
        {

            if (history[0] == '\0')
            {
                printf("Tebakan sebelumnya: -\n");
            }
            else
            {
                printf("Tebakan sebelumnya: %s\n", history);
            }

            printf("Kata: %s\n", word);

            printf("Kesempatan: %d\n", 10 - count + 1);

            do
            {
                printf("Masukkan tebakan (DALAM HURUF KAPITAL): ");
                startInputWord();
                tebakan = ambilKataKe(currentWord, 1).TabWord[0];
            } while (isCharInString(history, tebakan) || (tebakan >= 'a' && tebakan <= 'z'));

            history[j] = tebakan;
            history[j + 1] = '\0';

            if (isCharInString(kata, tebakan))
            {
                for (i = 0; i < panjang_kata; i++)
                {
                    if (kata[i] == tebakan)
                    {
                        word[i] = tebakan;
                    }
                }
            }

            win = isWin(word);
            printf("\n");
            if (win == 1)
            {
                printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin!\n\n", word, panjang_kata);
                score = score + panjang_kata;
                win = 0;
                break;
            }
            if (count == 10)
            {
                break;
            }
            count++;
            j++;
        }

        if (count == 10)
        {
            break;
        }
    }

    printf("Kesempatan kamu untuk menebak sudah habis. Selamat kamu berhasil mengumpulkan %d poin!\n\n", score);

    return score;
}

void saveDict(ArrayDin arr, FILE *pita)
{
    int i, j;
    Word count;
    count = intToWord(arr.Neff);
    for (i = 0; i < count.Length; i++)
    {
        fprintf(pita, "%c", count.TabWord[i]);
    }
    if (arr.Neff != 0)
    {
        fprintf(pita, "\n");
    }

    for (i = 0; i < arr.Neff; i++)
    {
        for (j = 0; j < arr.A[i].Length; j++)
        {
            fprintf(pita, "%c", arr.A[i].TabWord[j]);
        }
        if (i < arr.Neff - 1)
        {
            fprintf(pita, "\n");
        }
    }
}

void tambahKata()
{
    Word wordBaru, eop, total;
    string kataBaru;
    boolean found = true;
    do
    {
        int i = 0;
        found = false;
        printf("\nMasukkan kata baru (DALAM HURUF BESAR): ");
        startInputWord();
        akuisisiCommandWord(&wordBaru, currentWord, 1);
        kataBaru = wordToString(wordBaru);

        while (i < stringLength(kataBaru) && !found)
        {
            if ((kataBaru[i] >= 'a' && kataBaru[i] <= 'z'))
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
    } while (found);

    int count;
    ArrayDin arrKata;

    arrKata = MakeArrayDin();
    STARTWORD("data/kata.txt");

    if (!EOP)
    {
        count = wordToInt(currentWord);
        int i;
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAtArrayDin(&arrKata, currentWord, i);
        }
        ADVWORD();
    }

    InsertAtArrayDin(&arrKata, wordBaru, count);

    FILE *pita;
    pita = fopen("data/kata.txt", "w");

    saveDict(arrKata, pita);

    fclose(pita);
    printf("\nKata berhasil ditambahkan.\n");
}

void hangman(int *score)
{
    printf("======= SELAMAT DATANG DI HANGMAN =======\n");
    printf("=========================================\n");
    printf("\n***************** MENU ******************\n");
    printf("   PLAY        : Bermain game\n");
    printf("   TAMBAH KATA : Menambah kata dalam game\n");
    boolean valid = false;
    while (!valid)
    {
        printf("Masukan opsi Anda :");
        startInputWord();
        if (stringEQWord(currentWord, "PLAY") || stringEQWord(currentWord, "TAMBAH KATA"))
        {
            valid = true;
        }
        else
        {
            printf("Input anda salah. Silahkan masukan command yang benar.\n");
        }
    }

    if (stringEQWord(currentWord, "PLAY"))
    {
        *score = play();
    }
    else if (stringEQWord(currentWord, "TAMBAH KATA"))
    {
        tambahKata();
        hangman(score);
    }
}
