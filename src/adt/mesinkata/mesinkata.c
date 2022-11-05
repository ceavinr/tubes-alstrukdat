#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndWord;
Word currentWord;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
void IgnoreBlanks()
{
    while (currentChar == BLANK && !EOP)
    {
        ADV();
    }
}

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD(char *savefile)
{
    START(savefile);
    IgnoreBlanks();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWORD();
    }
}

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
void ADVWORD()
{
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        UpdateCurrentWord();
        IgnoreBlanks();
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void UpdateCurrentWord()
{
    int i = 0;
    while ((currentChar != BLANK) && i < NMax && !EOP)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();

        i += 1;
    }
    currentWord.Length = i;
}

void startInputWord()
{
    /*Melakukan pengisian pita oleh input user
       I.S pita kosong
       F.S pita diisi oleh user dan dilakukan pemrosesan oleh mesin kata
    */
    startInput();
    IgnoreBlanks();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        UpdateCurrentWord();
    }
}

void akuisisiCommandWord(Word *w, Word command, int kataKe)
{
    /*Mengakuisisi command terkhusus untuk LOAD and SAVE
       I.S. pita kata terdefinisi
       F.S. diakuisisi ke dalam w
    */
    int i = 0, counter = 0, length = 0;
    boolean stop = false;

    while (counter != kataKe - 1 && i < command.Length)
    {
        if (command.TabWord[i] == ' ')
        {
            counter++;
        }

        i++;
        if (i == command.Length)
        {
            counter++;
        }
    }

    while (!stop && i < command.Length)
    {
        if (command.TabWord[i] == ' ')
        {
            stop = true;
        }
        else
        {
            w->TabWord[length] = command.TabWord[i];
            i++;
            length++;
        }
    }
    w->Length = length;
}

char *akuisisiFile(Word command)
{
    /*Mengakuisisi nama file yang dimasukkan dari command user*/
    int i = 0;
    while (command.TabWord[i] != ' ')
    {
        i++;
    }
    i++;

    char *ret = malloc((command.Length - i + 2) * sizeof(char));
    char *p = ret;

    while (i < command.Length)
    {
        *p++ = command.TabWord[i];
        i++;
    }
    *p = '\0';

    return ret;
}
