#include <stdio.h>
#include <math.h>
#include "towerofhanoi.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/word/word.h"

void PrintDisk(Stack S, int i, int maxWidth)
{
    if (i <= Top(S))
    {
        int pjgDisk = 4 * S.T[i] + 3;

        for (int k = 0; k < (maxWidth - pjgDisk) / 2; k++)
        {
            printf(" ");
        }
        for (int k = 0; k < pjgDisk; k++)
        {
            printf("*");
        }
        for (int k = 0; k < (maxWidth - pjgDisk) / 2; k++)
        {
            printf(" ");
        }
    }
    else
    {
        for (int k = 0; k < maxWidth / 2; k++)
        {
            printf(" ");
        }
        printf("*");
        for (int k = 0; k < maxWidth / 2; k++)
        {
            printf(" ");
        }
    }
    for (int k = 0; k < 3; k++)
    {
        printf(" ");
    }
}

void DisplayState(Stack S1, Stack S2, Stack S3, int height)
{
    int disk, pjgDisk;

    for (int i = height; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            PrintDisk(S1, i, height * 4 + 3);
            PrintDisk(S2, i, height * 4 + 3);
            PrintDisk(S3, i, height * 4 + 3);

            printf("\n");
        }
    }
    printf("\n");
}

void towerofhanoi()
{
    Word banyak, from, to;
    Stack tower1, tower2, tower3;
    boolean succeed = false;
    boolean gameOn = true;
    boolean inputValid = false;
    int moves = 0, minimumMoves = 0;

    CreateStack(&tower1);
    CreateStack(&tower2);
    CreateStack(&tower3);

    while (!inputValid)
    {
        printf("Banyak disk (3-8): ");
        startInputWord();
        akuisisiCommandWord(&banyak, currentWord, 1);
        if (wordToInt(banyak) >= 3 && wordToInt(banyak) <= 9)
        {
            inputValid = true;
        }
    }

    for (int i = wordToInt(banyak); i > 0; i--)
    {
        Push(&tower1, i, &succeed);
    }

    while (gameOn)
    {
        int diskDel = 0;
        minimumMoves = pow(2, wordToInt(banyak)) - 1;

        inputValid = false;
        printf("\nMoves: %d\n", moves);
        printf("Minimum moves to solve: %d\n", minimumMoves);
        DisplayState(tower1, tower2, tower3, wordToInt(banyak));

        if (Top(tower3) + 1 == wordToInt(banyak))
        {
            gameOn = false;
            printf("Berhasil! Kamu menyelesaikan dalam %d langkah.\n", moves);
            printf("Skor: %d\n", (int)minimumMoves * 100 / moves);
        }

        if (gameOn)
        {
            while (!inputValid)
            {
                Word cek;

                printf("Masukan input!\n");
                printf("Contoh input: 1 3 (Memindahkan disk teratas tower 1 ke tower 3)\n");
                printf(">> ");
                startInputWord();
                akuisisiCommandWord(&from, currentWord, 1);
                akuisisiCommandWord(&to, currentWord, 2);
                akuisisiCommandWord(&cek, currentWord, 3);
                if (cek.Length == 0 && from.Length > 0 && to.Length > 0)
                {
                    if (wordToInt(from) >= 1 && wordToInt(from) <= 3 && wordToInt(to) >= 1 && wordToInt(to) <= 3)
                    {
                        if (wordToInt(from) != wordToInt(to))
                        {
                            inputValid = true;
                        }
                    }
                }
                if (!inputValid)
                {
                    printf("Input tidak valid!\n\n");
                }
            }

            succeed = false;
            if (stringEQWord(from, "1"))
            {
                Pop(&tower1, &diskDel, &succeed);

                if (succeed)
                {
                    succeed = false;
                    if (stringEQWord(to, "2"))
                    {
                        Push(&tower2, diskDel, &succeed);
                    }
                    else if (stringEQWord(to, "3"))
                    {
                        Push(&tower3, diskDel, &succeed);
                    }

                    if (!succeed)
                    {
                        printf("Gagal memindahkan! Ukuran disk harus lebih kecil daripada disk di bawahnya.\n");
                        Push(&tower1, diskDel, &succeed);
                    }
                    else
                    {
                        moves++;
                    }
                }
                else
                {
                    printf("Tower 1 kosong!\n");
                }
            }
            else if (stringEQWord(from, "2"))
            {
                Pop(&tower2, &diskDel, &succeed);

                if (succeed)
                {
                    succeed = false;
                    if (stringEQWord(to, "1"))
                    {
                        Push(&tower1, diskDel, &succeed);
                    }
                    else if (stringEQWord(to, "3"))
                    {
                        Push(&tower3, diskDel, &succeed);
                    }

                    if (!succeed)
                    {
                        printf("Gagal memindahkan! Ukuran disk harus lebih kecil daripada disk di bawahnya.\n");
                        Push(&tower2, diskDel, &succeed);
                    }
                    else
                    {
                        moves++;
                    }
                }
                else
                {
                    printf("Tower 2 kosong!\n");
                }
            }
            else if (stringEQWord(from, "3"))
            {
                Pop(&tower3, &diskDel, &succeed);

                if (succeed)
                {
                    succeed = false;
                    if (stringEQWord(to, "1"))
                    {
                        Push(&tower1, diskDel, &succeed);
                    }
                    else if (stringEQWord(to, "2"))
                    {
                        Push(&tower2, diskDel, &succeed);
                    }

                    if (!succeed)
                    {
                        printf("Gagal memindahkan! Ukuran disk harus lebih kecil daripada disk di bawahnya.\n");
                        Push(&tower3, diskDel, &succeed);
                    }
                    else
                    {
                        moves++;
                    }
                }
                else
                {
                    printf("Tower 3 kosong!\n");
                }
            }
        }
    }
}