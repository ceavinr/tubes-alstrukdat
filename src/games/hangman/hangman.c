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
    Word temp, eop, total;
    char* input;
    int i, lower;
    do
    {
        printf("\nMasukkan kata baru (DALAM HURUF BESAR): ");
        startInputWord();
        akuisisiCommandWord(&temp, currentWord, 1);
        input = wordToString(temp);\
        lower = 0;
        for (i = 0; i < stringLength(input); i++)
        {
            lower = isLower(input[i]);
            if (lower == 1)
            {
                break;
            }
        }
    } while (lower == 1);
    
    int count; 
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

    InsertAt(&arrKata, temp, count);
    
    FILE *pita;
    pita = fopen("kata.txt", "w");

    saveDict(arrKata,pita);

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
    printf("Masukan opsi Anda :");
    boolean valid = false;
    while (!valid)
    {
        startInputWord();
        if (stringEQWord(currentWord, "PLAY") || stringEQWord(currentWord, "TAMBAH KATA"))
        {
            valid = true;
        } else
        {
            printf("Input anda salah. Silahkan masukan command yang benar.\n");
        }
    }
    
    if(stringEQWord(currentWord, "PLAY"))
    {
        play();
    }
    else if(stringEQWord(currentWord, "TAMBAH KATA"))
    {
        tambahKata();
    }
}








