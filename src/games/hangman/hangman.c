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

int isLower(char huruf)
{
    char lower[26] = "abcdefghijklmnopqrstuvwxyz";
    int i;

    for (i = 0; i < 26; i++)
    {
        if (lower[i] == huruf)
        {
            return 1;
        }
    }

    return 0;
}

int play()
{
    char tebakan[11];
    char* kata;
    int i, j, count;
    int panjang_kata, score, win;
    int found, found_input, lower;

    score = 0;
    count = 0;

    while (count <= 10)
    {
        printf("%d\n\n", count);
        count++;
        kata = kata_random();
        panjang_kata = stringLength(kata);

        char word[panjang_kata+1];
        printf("%d %s\n", panjang_kata, kata);

        for (i = 0; i < panjang_kata; i++)
        {
            word[i] = '_';
        }
        word[panjang_kata] = '\0';

        tebakan[0] = '\0';
        
        Word temp;
        char* input;

        win = 0;
        j = 0;

        while (win == 0)
        {
            
            if (tebakan[0] =='\0')
            {
                printf("Tebakan sebelumnya: -\n");
            }
            else
            {
                printf("Tebakan sebelumnya: %s\n", tebakan);
            }
            

            printf("Kata: %s\n", word);

            printf("Kesempatan: %d\n", 10-count+1);

            
            
            do 
            {
                printf("Masukkan tebakan (DALAM HURUF KAPITAL): ");
                startInputWord();
                akuisisiCommandWord(&temp, currentWord, 1);
                input = wordToString(temp);
                printf("\n");
                found_input = check(tebakan, *input);
                lower = isLower(*input);
            }
            while (found_input == 1 || lower == 1);

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

    return 0;

}






