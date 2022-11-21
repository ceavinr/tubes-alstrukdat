#include <stdio.h>
#include <math.h>
#include "towerofhanoi.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/word/word.h"

/* I.S. S, i, dan maxWidth terdefinisi */
/* F.S. Menampilkan gambar disk ke i dari tower S */
void PrintDisk(Stack S, int i, int maxWidth)
{
    if (i <= Top(S))
    {
        int pjgDisk = 2 * S.T[i] + 1;

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
        printf("|");
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

/* I.S. S1, S2, S3, dan height terdefinisi */
/* F.S. Menampilkan state dari ketiga tower */
void DisplayState(Stack S1, Stack S2, Stack S3, int height)
{
    int disk, pjgDisk, tebal = 1;

    for (int i = height; i >= 0; i--)
    {
        for (int j = 0; j < tebal; j++)
        {
            PrintDisk(S1, i, height * 2 + 1);
            PrintDisk(S2, i, height * 2 + 1);
            PrintDisk(S3, i, height * 2 + 1);

            printf("\n");
        }
    }
    for (int i = 0; i < height * 6 + 9; i++)
    {
        if (i == height)
        {
            printf("A");
        }
        else if (i == height * 3 + 4)
        {
            printf("B");
        }
        else if (i == height * 5 + 8)
        {
            printf("C");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n\n");
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
        printf("Banyak disk (3-9): ");
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
            printf("Skor: %.1f\n", (float)minimumMoves * 10 / moves - 0.5 * (9 - wordToInt(banyak)));
        }

        if (gameOn)
        {
            while (!inputValid)
            {
                Word cek;

                printf("Tiang asal: ");
                startInputWord();
                akuisisiCommandWord(&from, currentWord, 1);
                akuisisiCommandWord(&cek, currentWord, 2);
                printf("Tiang tujuan: ");
                startInputWord();
                akuisisiCommandWord(&to, currentWord, 1);
                if (cek.Length < currentWord.Length)
                {
                    akuisisiCommandWord(&cek, currentWord, 2);
                }

                if (cek.Length == 0 && from.Length == 1 && to.Length == 1)
                {
                    if (from.TabWord[0] >= 'A' && from.TabWord[0] <= 'C' && to.TabWord[0] >= 'A' && to.TabWord[0] <= 'C')
                    {
                        if (!IsEQWord(from, to))
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
            if (stringEQWord(from, "A"))
            {
                Pop(&tower1, &diskDel, &succeed);

                if (succeed)
                {
                    succeed = false;
                    if (stringEQWord(to, "B"))
                    {
                        Push(&tower2, diskDel, &succeed);
                    }
                    else if (stringEQWord(to, "C"))
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
                    printf("Tower A kosong!\n");
                }
            }
            else if (stringEQWord(from, "B"))
            {
                Pop(&tower2, &diskDel, &succeed);

                if (succeed)
                {
                    succeed = false;
                    if (stringEQWord(to, "A"))
                    {
                        Push(&tower1, diskDel, &succeed);
                    }
                    else if (stringEQWord(to, "C"))
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
                    printf("Tower B kosong!\n");
                }
            }
            else if (stringEQWord(from, "C"))
            {
                Pop(&tower3, &diskDel, &succeed);

                if (succeed)
                {
                    succeed = false;
                    if (stringEQWord(to, "A"))
                    {
                        Push(&tower1, diskDel, &succeed);
                    }
                    else if (stringEQWord(to, "B"))
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
                    printf("Tower C kosong!\n");
                }
            }
        }
    }
}