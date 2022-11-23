#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

char* kata_random()
{
    int x, total, count;
    ArrayDin arrKata;

    arrKata = MakeArrayDin();
    STARTWORD("kata.txt");

    if (!EOP)
    {
        count = wordToInt(currentWord);
        int i;
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAt(&arrKata, currentWord, i);
        }
        ADVWORD();
    }

    total = count + 1;
    srand(time(NULL));
    x = rand() % total;

    int j,num;
    num = 0;
    char* kata = malloc (sizeof (char) * BUFFER(arrKata)[x].Length+1);
    for (j = 0; j < BUFFER(arrKata)[x].Length; j++)
    {
        kata[j] = BUFFER(arrKata)[x].TabWord[j];
        num++;
    }
    kata[BUFFER(arrKata)[x].Length] = '\0';
    
    return kata;
}

int check(char* kata, char huruf)
{
    int i,length;
    length = stringLength(kata);

    for (i = 0; i < length; i++)
    {
        if (kata[i] == huruf)
        {
            return 1;
        }
    }
    return 0;
}

int isWin(char* kata)
{
    int i,length;
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
    char tebakan[11];
    char* kata;
    int i, j;
    int panjang_kata, found, score, win;

    kata = kata_random();
    panjang_kata = stringLength(kata);
    char word[panjang_kata+1];
    printf("%d %s\n", panjang_kata, kata);

    for (i = 0; i < panjang_kata; i++)
    {
        word[i] = '_';
    }
    word[panjang_kata] = '\0';
    printf("Tebakan sebelumnya: -\n");
    printf("Kata: %s\n", word);
    printf("Kesempatan: %d\n", 10);

    Word temp;
    char* input;
    printf("Masukkan tebakan (DALAM HURUF KAPITAL): ");
    startInputWord();
    akuisisiCommandWord(&temp, currentWord, 1);
    input = wordToString(temp);

    tebakan[0] = *input;
    tebakan[1] = '\0';

    found = check(kata, *input);
    if (found == 1)
    {
        for (i = 0; i < panjang_kata; i++)
        {
            if (kata[i] == *input)
            {
                word[i] = *input;
            }
        }
    }
    printf("\n");

    for (j = 1; j < 10; j++)
    {
        printf("Tebakan sebelumnya: %s\n", tebakan);

        printf("Kata: %s\n", word);

        printf("Kesempatan: %d\n", 10-j);

        printf("Masukkan tebakan (DALAM HURUF KAPITAL): ");
        
        startInputWord();
        akuisisiCommandWord(&temp, currentWord, 1);
        input = wordToString(temp);

        tebakan[j] = *input;
        tebakan[j+1] = '\0';

        found = check(kata, *input);

        if (found == 1)
        {
            for (i = 0; i < panjang_kata; i++)
            {
                if (kata[i] == *input)
                {
                    word[i] = *input;
                }
            }
        }

        win = isWin(word);
        printf("\n");
        if (win == 1)
        {
            break;
        }
    }

    printf("%d\n", j);

    if (win == 1)
    {
        printf("Berhasil menebak kata %s! Kamu mendapatkan poin!\n\n", word);
    }
    else
    {
        printf("Jangan menyerah, silahkan coba bermain lagi!\n\n");
    }

    return 0;

}






