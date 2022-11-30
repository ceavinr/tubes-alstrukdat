#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

string kata_random()
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
    string kata = malloc(sizeof(char) * BUFFER(arrKata)[x].Length + 1);
    for (j = 0; j < BUFFER(arrKata)[x].Length; j++)
    {
        kata[j] = BUFFER(arrKata)[x].TabWord[j];
        num++;
    }
    kata[BUFFER(arrKata)[x].Length] = '\0';

    return kata;
}

boolean isWin(string kata)
{
    int i = 0, length = stringLength(kata);
    boolean full = true;

    while (i < length && full)
    {
        if (kata[i] == '_')
        {
            full = false;
        }
        else
        {
            i++;
        }
    }
    return full;
}

void play(int *score)
{
    char history[26];
    string kata;
    int i, j, count;
    int panjang_kata;

    count = 0;

    while (count < 10)
    {
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

        boolean gameOn = true;
        j = 0;

        while (gameOn && count < 10)
        {
            clear();
            if (history[0] == '\0')
            {
                printf("Tebakan sebelumnya: -\n");
            }
            else
            {
                printf("Tebakan sebelumnya: %s\n", history);
            }

            printf("Kata: %s\n", word);
            printf("Kesempatan: %d\n", 10 - count);

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
            else
            {
                count++;
            }

            printf("\n");
            if (isWin(word))
            {
                printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin!\n", word, panjang_kata);
                *score += panjang_kata;
                gameOn = false;
                printf("\nEnter to continue...");
                startInput();
            }
            else
            {
                j++;
            }
        }
    }

    printf("Kesempatan kamu untuk menebak sudah habis. Selamat kamu berhasil mengumpulkan %d poin!\n\n", *score);
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

        clear();
        printf("Masukkan kata baru (DALAM HURUF BESAR): ");
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
    printf("\nKata berhasil ditambahkan.");
    printf("\nEnter to continue...");
    startInput();
    clear();
}

void hangman(int *score)
{
    *score = 0;
    boolean valid = false;
    while (!valid)
    {
        clear();

        printf("======= SELAMAT DATANG DI HANGMAN =======\n");
        printf("=========================================\n");
        printf("\n***************** MENU ******************\n");
        printf(" PLAY        : Bermain game\n");
        printf(" TAMBAH KATA : Menambah kata dalam game\n");
        printf("\nMasukkan pilihan menu: ");
        startInputWord();
        if (stringEQWord(currentWord, "PLAY") || stringEQWord(currentWord, "TAMBAH KATA"))
        {
            valid = true;
        }
        else
        {
            printf("Input anda salah. Silahkan masukan command yang benar.\n");
            sleep(500);
        }
    }

    if (stringEQWord(currentWord, "PLAY"))
    {
        play(score);
    }
    else if (stringEQWord(currentWord, "TAMBAH KATA"))
    {
        tambahKata();
        hangman(score);
    }
}
