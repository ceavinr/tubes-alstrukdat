#include <stdio.h>
#include "tictactoe.h"

/* Mengembalikan true jika semua elemen pada salah satu diagonal papan berisi mark */
boolean isDiagonalWin(Matrix papan, char mark)
{
    int i = 0;
    boolean win = true;
    do
    {
        if (MATRIXELMT(papan, i, i) != mark)
        {
            win = false;
        }

        i++;
    } while (i < ROWS(papan) && win);

    i = 0;

    if (!win)
    {
        win = true;
        do
        {
            if (MATRIXELMT(papan, i, COLS(papan) - i - 1) != mark)
            {
                win = false;
            }
            i++;
        } while (i < ROWS(papan) && win);
    }

    return win;
}

/* Mengembalikan true jika semua elemen pada salah satu vertikal papan berisi mark */
boolean isVerticalWin(Matrix papan, char mark)
{
    int i = 0;
    boolean win = false;
    while (i < ROWS(papan) && !win)
    {
        win = true;
        for (int j = 0; j < COLS(papan); j++)
        {
            if (MATRIXELMT(papan, j, i) != mark)
            {
                win = false;
            }
        }
        i++;
    }

    return win;
}

/* Mengembalikan true jika semua elemen pada salah satu horizontal papan berisi mark */
boolean isHorizontalWin(Matrix papan, char mark)
{
    int i = 0;
    boolean win = false;
    while (i < ROWS(papan) && !win)
    {
        win = true;
        for (int j = 0; j < COLS(papan); j++)
        {
            if (MATRIXELMT(papan, i, j) != mark)
            {
                win = false;
            }
        }
        i++;
    }

    return win;
}

/* Mengembalikan true jika seluruh elemen papan berisi X atau O */
boolean isBoardFull(Matrix papan)
{
    boolean full = true;
    int i = 0;
    while (i < count(papan) && full)
    {
        if (MATRIXELMT(papan, i / COLS(papan), i % COLS(papan)) != 'O' && MATRIXELMT(papan, i / COLS(papan), i % COLS(papan)) != 'X')
        {
            full = false;
        }
        i++;
    }
    return full;
}

/* I.S. papan terdefinisi */
/* F.S. Menampilkan tampilan papan */
void board(Matrix papan)
{
    printf("\nTic Tac Toe\n");

    printf("Pemain 1 (X)  -  Pemain 2 (O)\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", MATRIXELMT(papan, 0, 0), MATRIXELMT(papan, 0, 1), MATRIXELMT(papan, 0, 2));
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", MATRIXELMT(papan, 1, 0), MATRIXELMT(papan, 1, 1), MATRIXELMT(papan, 1, 2));
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", MATRIXELMT(papan, 2, 0), MATRIXELMT(papan, 2, 1), MATRIXELMT(papan, 2, 2));
    printf("     |     |     \n\n");
}

void tictactoe(int *score)
{
    int tebakan, langkah;
    char mark;
    boolean gameOn = true;
    Word input;
    Matrix papan;

    langkah = 0;

    CreateMatrix(&papan, 3, 3);
    for (int i = 0; i < count(papan); i++)
    {
        MATRIXELMT(papan, i / COLS(papan), i % COLS(papan)) = i + 1 + '0';
    }

    int player = 1;
    board(papan);

    do
    {
        langkah++;
        player = !player;

        if (player == 0)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        boolean inputValid = false;
        do
        {
            printf("Player %d, silakan memilih angka:  ", player + 1);
            startInputWord();
            akuisisiCommandWord(&input, currentWord, 1);
            tebakan = wordToInt(input);
            int baris = (tebakan - 1) / 3;
            int kolom = (tebakan - 1) % 3;

            if (tebakan >= 1 && tebakan <= 9)
            {
                if (MATRIXELMT(papan, baris, kolom) != 'X' && MATRIXELMT(papan, baris, kolom) != 'O')
                {
                    MATRIXELMT(papan, baris, kolom) = mark;
                    inputValid = true;
                }
            }
            if (!inputValid)
            {
                printf("Input tidak valid\n");
            }

        } while (!inputValid);

        board(papan);

        if (isHorizontalWin(papan, mark) || isVerticalWin(papan, mark) || isDiagonalWin(papan, mark))
        {
            printf("==> \aPlayer %d menang \n", player + 1);

            *score = 10 - langkah;

            gameOn = false;
        }
        else
        {
            if (isBoardFull(papan))
            {
                printf("==> \aDraw");
                *score = 10 - langkah;
                gameOn = false;
            }
        }
    } while (gameOn);
}
